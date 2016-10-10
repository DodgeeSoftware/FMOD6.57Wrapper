#include "Stream3D.h"

Stream3D::Stream3D()
{
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    // Velocity
    this->xVelocity = 0.0f;
    this->yVelocity = 0.0f;
    this->zVelocity = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
    //  3D Sound Vars
    this->insideConeAngle = 360.0f;
    this->outsideConeAngle = 360.0f;
    this->outsideVolume = 1.0f;
    this->rotationX = 0.0f;
    this->rotationY = 0.0f;
    this->rotationZ = 0.0f;
    this->directOcclusion = 0.0f;
    this->reverbOcclusion= 0.0f;
    this->level = 1.0f;
    this->dopplerLevel = 1.0f;
    this->distanceFilterFlag = false;
    this->customLevel = 1.0f;
    this->centreFrequency = 1500.0f;
}

Stream3D::~Stream3D()
{

}

bool Stream3D::load(std::string filename)
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

void Stream3D::think()
{
    // Call the base think method
    Stream::think();
}

void Stream3D::update(float dTime)
{
    // Call the base update method
    Stream::update(dTime);
}

void Stream3D::clear()
{
    // Call the base clear method
    Stream::clear();
}

void Stream3D::free()
{
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    // Velocity
    this->xVelocity = 0.0f;
    this->yVelocity = 0.0f;
    this->zVelocity = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
    //  3D Sound Vars
    this->insideConeAngle = 360.0f;
    this->outsideConeAngle = 360.0f;
    this->outsideVolume = 1.0f;
    this->rotationX = 0.0f;
    this->rotationY = 0.0f;
    this->rotationZ = 0.0f;
    this->directOcclusion = 0.0f;
    this->reverbOcclusion= 0.0f;
    this->level = 1.0f;
    this->dopplerLevel = 1.0f;
    this->distanceFilterFlag = false;
    this->customLevel = 1.0f;
    this->centreFrequency = 1500.0f;
    // Call free from the base Class
    Stream::free();
}

void Stream3D::play()
{
    // Call the base class Play Method
    Stream::play();
    // Set Position
    this->setPosition(this->x, this->y, this->z);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity, this->zVelocity);
    // Set Min Max Distance
    this->setMinMaxDistance(this->minDistance, this->maxDistance);
    // Set 3D ConeSettings
    this->set3DConeSettings(this->insideConeAngle, outsideConeAngle, outsideVolume);
    // Set Rotation
    this->setRotation(this->rotationX, this->rotationY, this->rotationZ);
    // Set Direct Occlusion
    this->setDirectOcclusion(this->directOcclusion);
    // Set Reverb Occlusion
    this->setReverbOcclusion(this->reverbOcclusion);
    // Set Level
    this->setLevel(this->level);
    // Set Doppler Level
    this->setDopplerLevel(this->dopplerLevel);
    // Set Distance Filter
    this->setDistanceFilter(this->distanceFilterFlag);
    // Set Distance Filter Custom Level
    this->setDistanceFilterCustomLevel(this->customLevel);
    // Set Distance Filter Centre Frequency
    this->setDistanceFilterCentreFrequency(this->centreFrequency);
}

void Stream3D::playEx()
{
    // Call the base class PlayEx Method
    Stream::playEx();
    // Set Position
    this->setPosition(this->x, this->y, this->z);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity, this->zVelocity);
    // Set Min Max Distance
    this->setMinMaxDistance(this->minDistance, this->maxDistance);
    // Set 3D ConeSettings
    this->set3DConeSettings(this->insideConeAngle, outsideConeAngle, outsideVolume);
    // Set Rotation
    this->setRotation(this->rotationX, this->rotationY, this->rotationZ);
    // Set Direct Occlusion
    this->setDirectOcclusion(this->directOcclusion);
    // Set Reverb Occlusion
    this->setReverbOcclusion(this->reverbOcclusion);
    // Set Level
    this->setLevel(this->level);
    // Set Doppler Level
    this->setDopplerLevel(this->dopplerLevel);
    // Set Distance Filter
    this->setDistanceFilter(this->distanceFilterFlag);
    // Set Distance Filter Custom Level
    this->setDistanceFilterCustomLevel(this->customLevel);
    // Set Distance Filter Centre Frequency
    this->setDistanceFilterCentreFrequency(this->centreFrequency);
}

float Stream3D::getX()
{
    // return x
    return this->x;
}

float Stream3D::getY()
{
    // return y
    return this->y;
}

float Stream3D::getZ()
{
    //return z
    return this->z;
}

void Stream3D::setPosition(float x, float y, float z)
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

float Stream3D::getXVelocity()
{
    //return xVelocity
    return this->xVelocity;
}

float Stream3D::getYVelocity()
{
    //return yVelocity
    return this->yVelocity;
}

float Stream3D::getZVelocity()
{
    //return zVelocity
    return this->zVelocity;
}

void Stream3D::setVelocity(float xVelocity, float yVelocity, float zVelocity)
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

float Stream3D::getMinDistance()
{
    //return minDistance;
    return this->minDistance;
}

float Stream3D::getMaxDistance()
{
    //return maxDistance;
    return this->maxDistance;
}

void Stream3D::setMinDistance(float minDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Stream3D::setMaxDistance(float maxDistance)
{
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Stream3D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

float Stream3D::get3DConeInsideAngle()
{
    // Return inside cone angle
    return this->insideConeAngle;
}

float Stream3D::get3DConeOutsideAngle()
{
    // Return outside cone angle
    return this->outsideConeAngle;
}

float Stream3D::get3DConeOutsideVolume()
{
    // Return outside cone angle
    return this->outsideVolume;
}

void Stream3D::set3DConeSettings(float insideConeAngle, float outsideConeAngle, float outsideVolume)
{
    // Set local inside cone angle
    this->insideConeAngle = insideConeAngle;
    // Set local outside cone angle
    this->outsideConeAngle = outsideConeAngle;
    // Set local outsider volume
    this->outsideVolume = outsideVolume;
    // Setup the Cone for the Channel
    FMOD_Channel_Set3DConeSettings(this->pChannel, insideConeAngle, outsideConeAngle, outsideVolume);
}

float Stream3D::getRotationX()
{
    // Return rotationX
    return this->rotationX;
}

float Stream3D::getRotationY()
{
    // Return rotationY
    return this->rotationY;
}

float Stream3D::getRotationZ()
{
    // Return rotationZ
    return this->rotationZ;
}

void Stream3D::setRotation(float rotationX, float rotationY, float rotationZ)
{
    // Set local rotation
    this->rotationX = rotationX;
    this->rotationY = rotationY;
    this->rotationZ = rotationZ;
    // Rotation Vector
    FMOD_VECTOR rotation;
        rotation.x = this->rotationX;
        rotation.y = this->rotationY;
        rotation.z = this->rotationZ;
    // Set Rotation
    FMOD_Channel_Set3DConeOrientation(this->pChannel, &rotation);
}

float Stream3D::getDirectOcclusion()
{
    // Return Direct Occlusion
    return this->directOcclusion;
}

void Stream3D::setDirectOcclusion(float directOcclusion)
{
    // Set local Direct Occlusion
    this->directOcclusion = directOcclusion;
    // Set the Occlusion for the Channel
    FMOD_Channel_Set3DOcclusion(this->pChannel, this->directOcclusion, this->reverbOcclusion);
}

float Stream3D::getReverbOcclusion()
{
    // Return Reverb Occlusion
    return this->reverbOcclusion;
}

void Stream3D::setReverbOcclusion(float reverbOcclusion)
{
    // Set local Rever Occlusion
    this->reverbOcclusion = reverbOcclusion;
    // Set the Occlusion for the Channel
    FMOD_Channel_Set3DOcclusion(this->pChannel, this->directOcclusion, this->reverbOcclusion);
}

float Stream3D::getLevel()
{
    // return level
    return this->level;
}

void Stream3D::setLevel(float level)
{
    // Set Local Level
    this->level = level;
    // Set the Level for the Channel
    FMOD_Channel_Set3DLevel(this->pChannel, this->level);
}

float Stream3D::getDopplerLevel()
{
    // return doppler level
    return this->dopplerLevel;
}

void Stream3D::setDopplerLevel(float dopplerLevel)
{
    // Set local doppler level
    this->dopplerLevel = dopplerLevel;
    // Set Doppler Level
    FMOD_Channel_Set3DDopplerLevel(this->pChannel, dopplerLevel);
}

bool Stream3D::isDistanceFilter()
{
    // return distanceFilterFlag
    return this->distanceFilterFlag;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Stream3D::getCustomLevel()
{
    // return customLevel
    return this->customLevel;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Stream3D::getCentreFrequency()
{
    // return centreFrequency
    return this->centreFrequency;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

void Stream3D::setDistanceFilter(bool distanceFilterFlag)
{
    // Set Local distance Filter Flag
    this->distanceFilterFlag = distanceFilterFlag;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Stream3D::setDistanceFilterCustomLevel(float customLevel)
{
    // Set Local distance custom level
    this->customLevel = customLevel;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Stream3D::setDistanceFilterCentreFrequency(float frequency)
{
    // Set local frequency
    this->centreFrequency = frequency;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

float Stream3D::getAudibility()
{
    // Get Audibility
    float audibility = 0.0f;
    FMOD_Channel_GetAudibility(this->pChannel, &audibility);
    // return audibility
    return audibility;
}

void Stream3D::bindToLua(lua_State* pLuaState)
{
    // Bind functions to lua state
    luabind::module(pLuaState)
    [
        luabind::class_<Stream3D>("Stream3D")
        .def(luabind::constructor<>())
        // GENERAL
        .def("load", (bool (Stream3D::*)(std::string)) &Stream3D::load)
        .def("play", (void (Stream3D::*)()) &Stream3D::play)
        .def("playEx", (void (Stream3D::*)()) &Stream3D::playEx)
        .def("start", (void (Stream3D::*)()) &Stream3D::start)
        .def("stop", (void (Stream3D::*)()) &Stream3D::stop)
        .def("reset", (void (Stream3D::*)()) &Stream3D::reset)
        .def("isPaused", (bool(Stream3D::*)()) &Stream3D::isPaused)
        .def("setPaused", (void (Stream3D::*)(bool)) &Stream3D::setPaused)
        .def("pause", (void (Stream3D::*)()) &Stream3D::pause)
        .def("resume", (void (Stream3D::*)()) &Stream3D::resume)
        .def("isPlaying", (bool(Stream3D::*)()) &Stream3D::isPlaying)
        .def("clear", (void (Stream3D::*)()) &Stream3D::clear)
        .def("free", (void(Stream3D::*)()) &Stream3D::free)
        .def("getVolume", (float (Stream3D::*)()) &Stream3D::getVolume)
        .def("setVolume", (void (Stream3D::*)(float)) &Stream3D::setVolume)
        .def("isVolumeRamping", (bool(Stream3D::*)()) &Stream3D::isVolumeRamping)
        .def("setVolumeRamping", (void (Stream3D::*)(bool)) &Stream3D::setVolumeRamping)
        .def("getPitch", (float (Stream3D::*)()) &Stream3D::getPitch)
        .def("setPitch", (void (Stream3D::*)(float)) &Stream3D::setPitch)
        .def("isMute", (bool(Stream3D::*)()) &Stream3D::isMute)
        .def("setMute", (void (Stream3D::*)(bool)) &Stream3D::setMute)
        .def("mute", (void (Stream3D::*)()) &Stream3D::mute)
        .def("unmute", (void (Stream3D::*)()) &Stream3D::unmute)
        .def("getReverbWet", (float (Stream3D::*)(int)) &Stream3D::getReverbWet)
        .def("setReverbWet", (void (Stream3D::*)(int, float)) &Stream3D::setReverbWet)
        .def("getLowPassGain", (float (Stream3D::*)()) &Stream3D::getLowPassGain)
        .def("setLowPassGain", (void (Stream3D::*)(float)) &Stream3D::setLowPassGain)
        .def("getMode", (unsigned int (Stream3D::*)()) &Stream3D::getMode)
        .def("setMode", (void (Stream3D::*)(unsigned int)) &Stream3D::setMode)
        .def("getBalance", (float (Stream3D::*)()) &Stream3D::getBalance)
        .def("setBalance", (void (Stream3D::*)(float)) &Stream3D::setBalance)
        .def("getFrequency", (float (Stream3D::*)()) &Stream3D::getFrequency)
        .def("setFrequency", (void (Stream3D::*)(float)) &Stream3D::setFrequency)
        .def("getPriority", (int (Stream3D::*)()) &Stream3D::getPriority)
        .def("setPriority", (void (Stream3D::*)(int)) &Stream3D::setPriority)
        .def("isLoop", (bool(Stream3D::*)()) &Stream3D::isLoop)
        .def("setLoop", (void (Stream3D::*)(bool)) &Stream3D::setLoop)
        .def("isChannelVirtual", (bool(Stream3D::*)()) &Stream3D::isChannelVirtual)
        // FILENAME
        .def("getFilename", (std::string (Stream3D::*)()) &Stream3D::getFilename)
        // ENABLED
        .def("isEnabled", (bool(Stream3D::*)()) &Stream3D::isEnabled)
        .def("setEnabled", (void (Stream3D::*)(bool)) &Stream3D::setEnabled)
        .def("enable", (void (Stream3D::*)()) &Stream3D::enable)
        .def("disable", (void (Stream3D::*)()) &Stream3D::disable)
        // NAME
        .def("getName", (std::string (Stream3D::*)()) &Stream3D::getName)
        .def("setName", (void (Stream3D::*)(std::string)) &Stream3D::setName)
        .def("isNamed", (bool(Stream3D::*)()) &Stream3D::isNamed)
        .def("clearName", (void (Stream3D::*)()) &Stream::clearName)
        // SPACIAL CHANNEL FUNCTIONS
        .def("getX", (float (Stream3D::*)()) &Stream3D::getX)
        .def("getY", (float (Stream3D::*)()) &Stream3D::getY)
        .def("getZ", (float (Stream3D::*)()) &Stream3D::getZ)
        .def("setPosition", (float (Stream3D::*)(float, float, float)) &Stream3D::setPosition)
        .def("getXVelocity", (float (Stream3D::*)()) &Stream3D::getXVelocity)
        .def("getYVelocity", (float (Stream3D::*)()) &Stream3D::getYVelocity)
        .def("getZVelocity", (float (Stream3D::*)()) &Stream3D::getZVelocity)
        .def("setVelocity", (float (Stream3D::*)(float, float, float)) &Stream3D::setVelocity)
        .def("getMinDistance", (float (Stream3D::*)()) &Stream3D::getMinDistance)
        .def("getMaxDistance", (float (Stream3D::*)()) &Stream3D::getMaxDistance)
        .def("setMinMaxDistance", (float (Stream3D::*)(float, float)) &Stream3D::setMinMaxDistance)
        .def("get3DConeInsideAngle", (float (Stream3D::*)()) &Stream3D::get3DConeInsideAngle)
        .def("get3DConeOutsideAngle", (float (Stream3D::*)()) &Stream3D::get3DConeOutsideAngle)
        .def("get3DConeOutsideVolume", (float (Stream3D::*)()) &Stream3D::get3DConeOutsideVolume)
        .def("set3DConeSettings", (void (Stream3D::*)(float, float, float)) &Stream3D::set3DConeSettings)
        .def("getRotationX", (float (Stream3D::*)()) &Stream3D::getRotationX)
        .def("getRotationY", (float (Stream3D::*)()) &Stream3D::getRotationY)
        .def("getRotationZ", (float (Stream3D::*)()) &Stream3D::getRotationZ)
        .def("setRotation", (void (Stream3D::*)(float, float, float)) &Stream3D::setRotation)
        .def("getDirectOcclusion", (float (Stream3D::*)()) &Stream3D::getDirectOcclusion)
        .def("setDirectOcclusion", (void (Stream3D::*)(float)) &Stream3D::setDirectOcclusion)
        .def("getReverbOcclusion", (float (Stream3D::*)()) &Stream3D::getReverbOcclusion)
        .def("setReverbOcclusion", (void (Stream3D::*)(float)) &Stream3D::setReverbOcclusion)
        .def("getLevel", (float (Stream3D::*)()) &Stream3D::getLevel)
        .def("setLevel", (void (Stream3D::*)(float)) &Stream3D::setLevel)
        .def("getDopplerLevel", (float (Stream3D::*)()) &Stream3D::getDopplerLevel)
        .def("setDopplerLevel", (void (Stream3D::*)(float)) &Stream3D::setDopplerLevel)
        .def("isDistanceFilter", (bool(Stream3D::*)()) &Stream3D::isDistanceFilter)
        .def("getCustomLevel", (float (Stream3D::*)()) &Stream3D::getCustomLevel)
        .def("getCentreFrequency", (float (Stream3D::*)()) &Stream3D::getCentreFrequency)
        .def("setDistanceFilter", (void (Stream3D::*)(bool)) &Stream3D::setDistanceFilter)
        .def("setDistanceFilterCustomLevel", (void (Stream3D::*)(float)) &Stream3D::setDistanceFilterCustomLevel)
        .def("setDistanceFilterCentreFrequency", (void (Stream3D::*)(float)) &Stream3D::setDistanceFilterCentreFrequency)
        .def("getAudibility", (float (Stream3D::*)()) &Stream3D::getAudibility)
    ];
}
