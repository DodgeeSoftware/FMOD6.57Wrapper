#include "Stream2D.h"

Stream2D::Stream2D()
{
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    // Velocity
    this->xVelocity = 0.0f;
    this->yVelocity = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
    // Level
    this->level = 1.0;
    // DopplerLevel
    this->dopplerLevel = 1.0;
    // Distance Filter
    this->distanceFilterFlag = false;
    this->customLevel = 1.0;
    this->centreFrequency = 1500.0f;
}

Stream2D::~Stream2D()
{

}

bool Stream2D::load(std::string filename)
{
    // If there is an existing sound stream then get rid of it
    if (this->pFMODSound != 0)
    {
        // Stop any audio playing
        this->stop();
        // Free any audio
        this->free();
    }
    // Track Result of calling FMOD Functions
    FMOD_RESULT result;
    // Create the FMODSound
    result = FMOD_System_CreateStream(FMODGlobals::pFMODSystem, filename.c_str(), FMOD_LOOP_NORMAL | FMOD_3D, 0, &(this->pFMODSound));
    // If there was a problem
    if (result != FMOD_OK)
    {
        // Send a message to the console
        std::cout << "ERROR: Unable to load stream: " << filename.c_str() << std::endl;
        std::cout << FMOD_ErrorString(result) << std::endl;
        // Failure
        return false;
    }
    // Send a message to the console
    std::cout << "bool Stream::load((" << filename.c_str() << ")" << std::endl;
    std::cout << "bool Stream::load((" << filename.c_str() << ") success" << std::endl;
    // Set the Filename
    this->filename = filename;
    // Success
    return true;
}

void Stream2D::think()
{
    // Call the base think method
    Stream::think();
}

void Stream2D::update(float dTime)
{
    // Call the base update method
    Stream::update(dTime);
}

void Stream2D::clear()
{
    // Call the base clear method
    Stream::clear();
}

void Stream2D::free()
{
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    // Velocity
    this->xVelocity = 0.0f;
    this->yVelocity = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
    // Call free from the base Class
    Stream::free();
}

void Stream2D::play()
{
    // Call the base class Play Method
    Stream::play();
    // Set Position
    this->setPosition(this->x, this->y);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity);
    // Set Min Max Distance
    this->setMinMaxDistance(this->minDistance, this->maxDistance);
    // Set Level
    this->setLevel(this->level);
    // Set Doppler Level
    this->setDopplerLevel(this->dopplerLevel);
    // Set DistanceFilterFlag
    this->setDistanceFilter(this->distanceFilterFlag);;
    // Set Custom Level
    this->setDistanceFilterCustomLevel(this->customLevel);
    // Set Centre Frequency
    this->setDistanceFilterCentreFrequency(this->centreFrequency);
}

void Stream2D::playEx()
{
    // Call the base class Play Method
    Stream::playEx();
    // Set Position
    this->setPosition(this->x, this->y);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity);
    // Set Min Max Distance
    this->setMinMaxDistance(this->minDistance, this->maxDistance);
    // Set Level
    this->setLevel(this->level);
    // Set Doppler Level
    this->setDopplerLevel(this->dopplerLevel);
    // Set DistanceFilterFlag
    this->setDistanceFilter(this->distanceFilterFlag);;
    // Set Custom Level
    this->setDistanceFilterCustomLevel(this->customLevel);
    // Set Centre Frequency
    this->setDistanceFilterCentreFrequency(this->centreFrequency);
}

float Stream2D::getX()
{
    //return x
    return this->x;
}

float Stream2D::getY()
{
    //return y
    return this->y;
}

void Stream2D::setPosition(float x, float y)
{
    // Set Local x
    this->x = x;
    // Set Local y
    this->y = y;
    // Only set Channel Properties when we have a valid channel
    if (this->pChannel == 0)
        return;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = 0.0f;
    // Velocity
    FMOD_VECTOR velocity;
        velocity.x = this->xVelocity;
        velocity.y = this->yVelocity;
        velocity.z = 0.0f;
    // AltPanPos
    FMOD_VECTOR altPanPos;
        altPanPos.x = 0.0f;
        altPanPos.y = 0.0f;
        altPanPos.z = 0.0f;
    // Set Position of the Channel
    FMOD_Channel_Set3DAttributes(this->pChannel, &position, &velocity, &altPanPos);
}

float Stream2D::getXVelocity()
{
    //return xVelocity
    return this->xVelocity;
}

float Stream2D::getYVelocity()
{
    //return yVelocity
    return this->yVelocity;
}

void Stream2D::setVelocity(float xVelocity, float yVelocity)
{
    // Set local xVelocity
    this->xVelocity = xVelocity;
    // Set local yVelocity
    this->yVelocity = yVelocity;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = 0.0f;
    // Velocity
    FMOD_VECTOR velocity;
        velocity.x = this->xVelocity;
        velocity.y = this->yVelocity;
        velocity.z = 0.0f;
    // AltPanPos
    FMOD_VECTOR altPanPos;
        altPanPos.x = 0.0f;
        altPanPos.y = 0.0f;
        altPanPos.z = 0.0f;
    // Set Position of the Channel
    FMOD_Channel_Set3DAttributes(this->pChannel, &position, &velocity, &altPanPos);
}

float Stream2D::getMinDistance()
{
    //return minDistance;
    return this->minDistance;
}

float Stream2D::getMaxDistance()
{
    //return maxDistance
    return this->maxDistance;
}

void Stream2D::setMinDistance(float minDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Stream2D::setMaxDistance(float maxDistance)
{
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Stream2D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

float Stream2D::getLevel()
{
    // return level
    return this->level;
}

void Stream2D::setLevel(float level)
{
    // Set Local Level
    this->level = level;
    // Set the Level for the Channel
    FMOD_Channel_Set3DLevel(this->pChannel, this->level);
}

float Stream2D::getDopplerLevel()
{
    // return doppler level
    return this->dopplerLevel;
}

void Stream2D::setDopplerLevel(float dopplerLevel)
{
    // Set local doppler level
    this->dopplerLevel = dopplerLevel;
    // Set Doppler Level
    FMOD_Channel_Set3DDopplerLevel(this->pChannel, dopplerLevel);
}

bool Stream2D::isDistanceFilter()
{
    // return distanceFilterFlag
    return this->distanceFilterFlag;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Stream2D::getCustomLevel()
{
    // Return custom level
    return this->customLevel;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Stream2D::getCentreFrequency()
{
    // Return centre frequency
    return this->centreFrequency;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

void Stream2D::setDistanceFilter(bool distanceFilterFlag)
{
    // Set Local distance Filter Flag
    this->distanceFilterFlag = distanceFilterFlag;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Stream2D::setDistanceFilterCustomLevel(float customLevel)
{
    // Set Local distance custom level
    this->customLevel = customLevel;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Stream2D::setDistanceFilterCentreFrequency(float frequency)
{
    // Set local frequency
    this->centreFrequency = frequency;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

float Stream2D::getAudibility()
{
    // Get Audibility
    float audibility = 1.0f;
    FMOD_Channel_GetAudibility(this->pChannel, &audibility);
    // return audibility
    return audibility;
}

void Stream2D::bindToLua(lua_State* pLuaState)
{
    // Bind functions to lua state
    luabind::module(pLuaState)
    [
        luabind::class_<Stream2D>("Stream2D")
        .def(luabind::constructor<>())
        // GENERAL
        .def("load", (bool (Stream2D::*)(std::string)) &Stream2D::load)
        .def("play", (void (Stream2D::*)()) &Stream2D::play)
        .def("playEx", (void (Stream2D::*)()) &Stream2D::playEx)
        .def("start", (void (Stream2D::*)()) &Stream2D::start)
        .def("stop", (void (Stream2D::*)()) &Stream2D::stop)
        .def("reset", (void (Stream2D::*)()) &Stream2D::reset)
        .def("isPaused", (bool(Stream2D::*)()) &Stream2D::isPaused)
        .def("setPaused", (void (Stream2D::*)(bool)) &Stream2D::setPaused)
        .def("pause", (void (Stream2D::*)()) &Stream2D::pause)
        .def("resume", (void (Stream2D::*)()) &Stream2D::resume)
        .def("isPlaying", (bool(Stream2D::*)()) &Stream2D::isPlaying)
        .def("clear", (void (Stream2D::*)()) &Stream2D::clear)
        .def("free", (void(Stream2D::*)()) &Stream2D::free)
        .def("getVolume", (float (Stream2D::*)()) &Stream2D::getVolume)
        .def("setVolume", (void (Stream2D::*)(float)) &Stream2D::setVolume)
        .def("isVolumeRamping", (bool(Stream2D::*)()) &Stream2D::isVolumeRamping)
        .def("setVolumeRamping", (void (Stream2D::*)(bool)) &Stream2D::setVolumeRamping)
        .def("getPitch", (float (Stream2D::*)()) &Stream2D::getPitch)
        .def("setPitch", (void (Stream2D::*)(float)) &Stream2D::setPitch)
        .def("isMute", (bool(Stream2D::*)()) &Stream2D::isMute)
        .def("setMute", (void (Stream2D::*)(bool)) &Stream2D::setMute)
        .def("mute", (void (Stream2D::*)()) &Stream2D::mute)
        .def("unmute", (void (Stream2D::*)()) &Stream2D::unmute)
        .def("getReverbWet", (float (Stream2D::*)(int)) &Stream2D::getReverbWet)
        .def("setReverbWet", (void (Stream2D::*)(int, float)) &Stream2D::setReverbWet)
        .def("getLowPassGain", (float (Stream2D::*)()) &Stream2D::getLowPassGain)
        .def("setLowPassGain", (void (Stream2D::*)(float)) &Stream2D::setLowPassGain)
        .def("getMode", (unsigned int (Stream2D::*)()) &Stream2D::getMode)
        .def("setMode", (void (Stream2D::*)(unsigned int)) &Stream2D::setMode)
        .def("getBalance", (float (Stream2D::*)()) &Stream2D::getBalance)
        .def("setBalance", (void (Stream2D::*)(float)) &Stream2D::setBalance)
        .def("getFrequency", (float (Stream2D::*)()) &Stream2D::getFrequency)
        .def("setFrequency", (void (Stream2D::*)(float)) &Stream2D::setFrequency)
        .def("getPriority", (int (Stream2D::*)()) &Stream2D::getPriority)
        .def("setPriority", (void (Stream2D::*)(int)) &Stream2D::setPriority)
        .def("isLoop", (bool(Stream2D::*)()) &Stream2D::isLoop)
        .def("setLoop", (void (Stream2D::*)(bool)) &Stream2D::setLoop)
        .def("isChannelVirtual", (bool(Stream2D::*)()) &Stream2D::isChannelVirtual)
        // FILENAME
        .def("getFilename", (std::string (Stream2D::*)()) &Stream2D::getFilename)
        // ENABLED
        .def("isEnabled", (bool(Stream2D::*)()) &Stream2D::isEnabled)
        .def("setEnabled", (void (Stream2D::*)(bool)) &Stream2D::setEnabled)
        .def("enable", (void (Stream2D::*)()) &Stream2D::enable)
        .def("disable", (void (Stream2D::*)()) &Stream2D::disable)
        // NAME
        .def("getName", (std::string (Stream2D::*)()) &Stream2D::getName)
        .def("setName", (void (Stream2D::*)(std::string)) &Stream2D::setName)
        .def("isNamed", (bool(Stream2D::*)()) &Stream2D::isNamed)
        .def("clearName", (void (Stream2D::*)()) &Stream::clearName)
        // SPACIAL CHANNEL FUNCTIONS
        .def("getX", (float (Stream2D::*)()) &Stream2D::getX)
        .def("getY", (float (Stream2D::*)()) &Stream2D::getY)
        .def("setPosition", (float (Stream2D::*)(float, float)) &Stream2D::setPosition)
        .def("getXVelocity", (float (Stream2D::*)()) &Stream2D::getXVelocity)
        .def("getYVelocity", (float (Stream2D::*)()) &Stream2D::getYVelocity)
        .def("setVelocity", (float (Stream2D::*)(float, float)) &Stream2D::setVelocity)
        .def("getMinDistance", (float (Stream2D::*)()) &Stream2D::getMinDistance)
        .def("getMaxDistance", (float (Stream2D::*)()) &Stream2D::getMaxDistance)
        .def("setMinMaxDistance", (float (Stream2D::*)(float, float)) &Stream2D::setMinMaxDistance)
        .def("getLevel", (float (Stream2D::*)()) &Stream2D::getLevel)
        .def("setLevel", (void (Stream2D::*)(float)) &Stream2D::setLevel)
        .def("getDopplerLevel", (float (Stream2D::*)()) &Stream2D::getDopplerLevel)
        .def("setDopplerLevel", (void (Stream2D::*)(float)) &Stream2D::setDopplerLevel)
        .def("isDistanceFilter", (bool(Stream2D::*)()) &Stream2D::isDistanceFilter)
        .def("getCustomLevel", (float (Stream2D::*)()) &Stream2D::getCustomLevel)
        .def("getCentreFrequency", (float (Stream2D::*)()) &Stream2D::getCentreFrequency)
        .def("setDistanceFilter", (void (Stream2D::*)(bool)) &Stream2D::setDistanceFilter)
        .def("setDistanceFilterCustomLevel", (void (Stream2D::*)(float)) &Stream2D::setDistanceFilterCustomLevel)
        .def("setDistanceFilterCentreFrequency", (void (Stream2D::*)(float)) &Stream2D::setDistanceFilterCentreFrequency)
        .def("getAudibility", (float (Stream2D::*)()) &Stream2D::getAudibility)
    ];
}
