#include "Sound2D.h"

Sound2D::Sound2D()
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

Sound2D::~Sound2D()
{

}

void Sound2D::think()
{
    // Call the Base think method
    Sound::think();
}

void Sound2D::update(float dTime)
{
    // Call the base update  method
    Sound::update(dTime);
}

void Sound2D::clear()
{
    // Call the base Clear method
    Sound::clear();
}

void Sound2D::free()
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
    // Call the base Free method
    Sound::free();
}

void Sound2D::play()
{
    // Call the base class Play Method
    Sound::play();
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

void Sound2D::playEx()
{
    // Call the base class PlayEx Method
    Sound::playEx();
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

float Sound2D::getX()
{
    // Return x
    return this->x;
}

float Sound2D::getY()
{
    // Return y
    return this->y;
}

void Sound2D::setPosition(float x, float y)
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

float Sound2D::getXVelocity()
{
    // Return xVelocity
    return this->xVelocity;
}

float Sound2D::getYVelocity()
{
    // Return yVelocity
    return this->yVelocity;
}

void Sound2D::setVelocity(float xVelocity, float yVelocity)
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

float Sound2D::getMinDistance()
{
    //return minDistance;
    return this->minDistance;
}

float Sound2D::getMaxDistance()
{
    //return maxDistance;
    return this->maxDistance;
}

void Sound2D::setMinDistance(float minDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Sound2D::setMaxDistance(float maxDistance)
{
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

void Sound2D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set local min distance
    this->minDistance = minDistance;
    // Set local max distance
    this->maxDistance = maxDistance;
        // Set 3d min distance and max distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

float Sound2D::getLevel()
{
    // return level
    return this->level;
}

void Sound2D::setLevel(float level)
{
    // Set Local Level
    this->level = level;
    // Set the Level for the Channel
    FMOD_Channel_Set3DLevel(this->pChannel, this->level);
}

float Sound2D::getDopplerLevel()
{
    // return doppler level
    return this->dopplerLevel;
}

void Sound2D::setDopplerLevel(float dopplerLevel)
{
    // Set local doppler level
    this->dopplerLevel = dopplerLevel;
    // Set Doppler Level
    FMOD_Channel_Set3DDopplerLevel(this->pChannel, dopplerLevel);
}

bool Sound2D::isDistanceFilter()
{
    // return distanceFilterFlag
    return this->distanceFilterFlag;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Sound2D::getCustomLevel()
{
    // return customLevel
    return this->customLevel;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Sound2D::getCentreFrequency()
{
    // return centreFrequency
    return this->centreFrequency;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

void Sound2D::setDistanceFilter(bool distanceFilterFlag)
{
    // Set Local distance Filter Flag
    this->distanceFilterFlag = distanceFilterFlag;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Sound2D::setDistanceFilterCustomLevel(float customLevel)
{
    // Set Local distance custom level
    this->customLevel = customLevel;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Sound2D::setDistanceFilterCentreFrequency(float frequency)
{
    // Set local frequency
    this->centreFrequency = frequency;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

float Sound2D::getAudibility()
{
    // Get Audibility
    float audibility = 1.0f;
    FMOD_Channel_GetAudibility(this->pChannel, &audibility);
    // return audibility
    return audibility;
}

void Sound2D::bindToLua(lua_State* pLuaState)
{
    // Bind functions to lua state
    luabind::module(pLuaState)
    [
        luabind::class_<Sound2D>("Sound2D")
        .def(luabind::constructor<>())
        // GENERAL
        .def("play", (void (Sound2D::*)()) &Sound2D::play)
        .def("playEx", (void (Sound2D::*)()) &Sound2D::playEx)
        .def("start", (void (Sound2D::*)()) &Sound2D::start)
        .def("stop", (void (Sound2D::*)()) &Sound2D::stop)
        .def("reset", (void (Sound2D::*)()) &Sound2D::reset)
        .def("isPaused", (bool(Sound2D::*)()) &Sound2D::isPaused)
        .def("setPaused", (void (Sound2D::*)(bool)) &Sound2D::setPaused)
        .def("pause", (void (Sound2D::*)()) &Sound2D::pause)
        .def("resume", (void (Sound2D::*)()) &Sound2D::resume)
        .def("isPlaying", (bool(Sound2D::*)()) &Sound2D::isPlaying)
        .def("clear", (void (Sound2D::*)()) &Sound2D::clear)
        .def("free", (void(Sound2D::*)()) &Sound2D::free)
        .def("getVolume", (float (Sound2D::*)()) &Sound2D::getVolume)
        .def("setVolume", (void (Sound2D::*)(float)) &Sound2D::setVolume)
        .def("isVolumeRamping", (bool(Sound2D::*)()) &Sound2D::isVolumeRamping)
        .def("setVolumeRamping", (void (Sound2D::*)(bool)) &Sound2D::setVolumeRamping)
        .def("getPitch", (float (Sound2D::*)()) &Sound2D::getPitch)
        .def("setPitch", (void (Sound2D::*)(float)) &Sound2D::setPitch)
        .def("isMute", (bool(Sound2D::*)()) &Sound2D::isMute)
        .def("setMute", (void (Sound2D::*)(bool)) &Sound2D::setMute)
        .def("mute", (void (Sound2D::*)()) &Sound2D::mute)
        .def("unmute", (void (Sound2D::*)()) &Sound2D::unmute)
        .def("getReverbWet", (float (Sound2D::*)(int)) &Sound2D::getReverbWet)
        .def("setReverbWet", (void (Sound2D::*)(int, float)) &Sound2D::setReverbWet)
        .def("getLowPassGain", (float (Sound2D::*)()) &Sound2D::getLowPassGain)
        .def("setLowPassGain", (void (Sound2D::*)(float)) &Sound2D::setLowPassGain)
        .def("getMode", (unsigned int (Sound2D::*)()) &Sound2D::getMode)
        .def("setMode", (void (Sound2D::*)(unsigned int)) &Sound2D::setMode)
        .def("getBalance", (float (Sound2D::*)()) &Sound2D::getBalance)
        .def("setBalance", (void (Sound2D::*)(float)) &Sound2D::setBalance)
        .def("getFrequency", (float (Sound2D::*)()) &Sound2D::getFrequency)
        .def("setFrequency", (void (Sound2D::*)(float)) &Sound2D::setFrequency)
        .def("getPriority", (int (Sound2D::*)()) &Sound2D::getPriority)
        .def("setPriority", (void (Sound2D::*)(int)) &Sound2D::setPriority)
        .def("isLoop", (bool(Sound2D::*)()) &Sound2D::isLoop)
        .def("setLoop", (void (Sound2D::*)(bool)) &Sound2D::setLoop)
        .def("isChannelVirtual", (bool(Sound2D::*)()) &Sound2D::isChannelVirtual)
        // FILENAME
        .def("getFilename", (std::string (Sound2D::*)()) &Sound2D::getFilename)
        // SOUND SAMPLE
        .def("getSoundSample", (SoundSample* (Sound::*)()) &Sound::getSoundSample)
        .def("setSoundSample", (void (Sound::*)(SoundSample*)) &Sound::setSoundSample)
        // ENABLED
        .def("isEnabled", (bool(Sound2D::*)()) &Sound2D::isEnabled)
        .def("setEnabled", (void (Sound2D::*)(bool)) &Sound2D::setEnabled)
        .def("enable", (void (Sound2D::*)()) &Sound2D::enable)
        .def("disable", (void (Sound2D::*)()) &Sound2D::disable)
        // NAME
        .def("getName", (std::string (Sound2D::*)()) &Sound2D::getName)
        .def("setName", (void (Sound2D::*)(std::string)) &Sound2D::setName)
        .def("isNamed", (bool(Sound2D::*)()) &Sound2D::isNamed)
        .def("clearName", (void (Sound2D::*)()) &Sound2D::clearName)
        // SPACIAL CHANNEL FUNCTIONS
        .def("getX", (float (Sound2D::*)()) &Sound2D::getX)
        .def("getY", (float (Sound2D::*)()) &Sound2D::getY)
        .def("setPosition", (float (Sound2D::*)(float, float)) &Sound2D::setPosition)
        .def("getXVelocity", (float (Sound2D::*)()) &Sound2D::getXVelocity)
        .def("getYVelocity", (float (Sound2D::*)()) &Sound2D::getYVelocity)
        .def("setVelocity", (float (Sound2D::*)(float, float)) &Sound2D::setVelocity)
        .def("getMinDistance", (float (Sound2D::*)()) &Sound2D::getMinDistance)
        .def("getMaxDistance", (float (Sound2D::*)()) &Sound2D::getMaxDistance)
        .def("setMinMaxDistance", (float (Sound2D::*)(float, float)) &Sound2D::setMinMaxDistance)
        .def("getLevel", (float (Sound2D::*)()) &Sound2D::getLevel)
        .def("setLevel", (void (Sound2D::*)(float)) &Sound2D::setLevel)
        .def("getDopplerLevel", (float (Sound2D::*)()) &Sound2D::getDopplerLevel)
        .def("setDopplerLevel", (void (Sound2D::*)(float)) &Sound2D::setDopplerLevel)
        .def("isDistanceFilter", (bool(Sound2D::*)()) &Sound2D::isDistanceFilter)
        .def("getCustomLevel", (float (Sound2D::*)()) &Sound2D::getCustomLevel)
        .def("getCentreFrequency", (float (Sound2D::*)()) &Sound2D::getCentreFrequency)
        .def("setDistanceFilter", (void (Sound2D::*)(bool)) &Sound2D::setDistanceFilter)
        .def("setDistanceFilterCustomLevel", (void (Sound2D::*)(float)) &Sound2D::setDistanceFilterCustomLevel)
        .def("setDistanceFilterCentreFrequency", (void (Sound2D::*)(float)) &Sound2D::setDistanceFilterCentreFrequency)
        .def("getAudibility", (float (Sound2D::*)()) &Sound2D::getAudibility)
    ];
}

