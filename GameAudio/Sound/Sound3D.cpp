#include "Sound3D.h"

Sound3D::Sound3D()
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

Sound3D::~Sound3D()
{

}

void Sound3D::think()
{
    // Call the Base think method
    Sound::think();
}

void Sound3D::update(float dTime)
{
    // Call the base update  method
    Sound::update(dTime);
    // Set Position
    this->setPosition(this->x, this->y, this->z);
}

void Sound3D::clear()
{
    // Call the base Clear method
    Sound::clear();
}

void Sound3D::free()
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
    // Call the base free method
    Sound::free();
}

void Sound3D::reset()
{
    // Reset
    Sound::reset();
    // Reset Position
    this->x = startX;
    this->y = startY;
    this->z = startZ;
    // Reset Velocity
    this->xVelocity = this->startXVelocity;
    this->yVelocity = this->startYVelocity;
    this->zVelocity = this->startZVelocity;
}

void Sound3D::start()
{
    // Start Position
    this->x = startX;
    this->y = startY;
    this->z = startZ;
    // Start Velocity
    this->xVelocity = this->startXVelocity;
    this->yVelocity = this->startYVelocity;
    this->zVelocity = this->startZVelocity;
    // Start
    Sound3D::play();
}

void Sound3D::play()
{
    // Call the base class Play Method
    Sound::play();
    // Set Position
    this->setPosition(this->x, this->y, this->z);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity, this->zVelocity);
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

void Sound3D::playEx()
{
    // Call the base class PlayEx Method
    Sound::playEx();
    // Set Position
    this->setPosition(this->x, this->y, this->z);
    // Set Veocity
    this->setVelocity(this->xVelocity, this->yVelocity, this->zVelocity);
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

float Sound3D::getX()
{
    //return x;
    return this->x;
}

float Sound3D::getY()
{
    //return y
    return this->y;
}

float Sound3D::getZ()
{
    //return z;
    return this->z;
}

void Sound3D::setPosition(float x, float y, float z)
{
    // Set Local x
    this->x = x;
    // Set Local y
    this->y = y;
    // Set Local z
    this->z = z;
    // Only set Channel Properties when we have a valid channel
    if (this->pChannel == 0)
        return;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    // Velocity
    FMOD_VECTOR velocity;
        velocity.x = this->xVelocity;
        velocity.y = this->yVelocity;
        velocity.z = this->zVelocity;;
    // AltPanPos
    FMOD_VECTOR altPanPos;
        altPanPos.x = 0.0f;
        altPanPos.y = 0.0f;
        altPanPos.z = 0.0f;
    // Set Position of the Channel
    FMOD_Channel_Set3DAttributes(this->pChannel, &position, &velocity, &altPanPos);
}

float Sound3D::getStartX()
{
    return this->startX;
}

float Sound3D::getStartY()
{
    return this->startY;
}

float Sound3D::getStartZ()
{
    return this->startZ;
}

void Sound3D::setStartPosition(float startX, float startY, float startZ)
{
    this->startX = startX;
    this->startY = startY;
    this->startZ = startZ;
}

float Sound3D::getXVelocity()
{
    //return xVelocity[
    return this->xVelocity;
}

float Sound3D::getYVelocity()
{
    //return yVelocity
    return this->yVelocity;
}

float Sound3D::getZVelocity()
{
    //return zVelocity
    return this->zVelocity;
}

void Sound3D::setVelocity(float xVelocity, float yVelocity, float zVelocity)
{
    // Set local xVelocity
    this->xVelocity = xVelocity;
    // Set local yVelocity
    this->yVelocity = yVelocity;
    // Set local zVelocity
    this->zVelocity = zVelocity;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    // Velocity
    FMOD_VECTOR velocity;
        velocity.x = this->xVelocity;
        velocity.y = this->yVelocity;
        velocity.z = this->zVelocity;
    // AltPanPos
    FMOD_VECTOR altPanPos;
        altPanPos.x = 0.0f;
        altPanPos.y = 0.0f;
        altPanPos.z = 0.0f;
    // Set Position of the Channel
    FMOD_Channel_Set3DAttributes(this->pChannel, &position, &velocity, &altPanPos);
}

float Sound3D::getStartXVelocity()
{
    return this->startXVelocity;
}

float Sound3D::getStartYVelocity()
{
    return this->startYVelocity;
}

float Sound3D::getStartZVelocity()
{
    return this->startZVelocity;
}

void Sound3D::setStartVelocity(float startXVelocity, float startYVelocity, float startZVelocity)
{
    this->startXVelocity = startXVelocity;
    this->startYVelocity = startYVelocity;
    this->startZVelocity = startZVelocity;
}

float Sound3D::getMinDistance()
{
    // return minDistance
    return this->minDistance;
}

float Sound3D::getMaxDistance()
{
    // return maxDistance
    return this->maxDistance;
}

void Sound3D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // return minDistance
    this->minDistance = minDistance;
    // return maxDistance
    this->maxDistance = maxDistance;
    //  Set MinMax Distance
    FMOD_Channel_Set3DMinMaxDistance(this->pChannel, this->minDistance, this->maxDistance);
}

float Sound3D::get3DConeInsideAngle()
{
    // Return inside cone angle
    return this->insideConeAngle;
}

float Sound3D::get3DConeOutsideAngle()
{
    // Return outside cone angle
    return this->outsideConeAngle;
}

float Sound3D::get3DConeOutsideVolume()
{
    // Return outside cone angle
    return this->outsideConeAngle;
}

void Sound3D::set3DConeSettings(float insideConeAngle, float outsideConeAngle, float outsiderVolume)
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

float Sound3D::getRotationX()
{
    // Return rotationX
    return this->rotationX;
}

float Sound3D::getRotationY()
{
    // Return rotationY
    return this->rotationY;
}

float Sound3D::getRotationZ()
{
    // Return rotationZ
    return this->rotationX;
}

void Sound3D::setRotation(float rotationX, float rotationY, float rotationZ)
{
    // Set local orientation
    this->rotationX = rotationX;
    this->rotationY = rotationY;
    this->rotationZ = rotationZ;
    // rotation Vector
    FMOD_VECTOR rotation;
        rotation.x = this->rotationX;
        rotation.y = this->rotationY;
        rotation.z = this->rotationZ;
    // Set rotation
    FMOD_Channel_Set3DConeOrientation(this->pChannel, &rotation);
}

float Sound3D::getDirectOcclusion()
{
    // Return Direct Occlusion
    return this->directOcclusion;
}

void Sound3D::setDirectOcclusion(float directOcclusion)
{
    // Set local Direct Occlusion
    this->directOcclusion = directOcclusion;
    // Set the Occlusion for the Channel
    FMOD_Channel_Set3DOcclusion(this->pChannel, this->directOcclusion, this->reverbOcclusion);
}

float Sound3D::getReverbOcclusion()
{
    // Return Reverb Occlusion
    return this->reverbOcclusion;
}

void Sound3D::setReverbOcclusion(float reverbOcclusion)
{
    // Set local Rever Occlusion
    this->reverbOcclusion = reverbOcclusion;
    // Set the Occlusion for the Channel
    FMOD_Channel_Set3DOcclusion(this->pChannel, this->directOcclusion, this->reverbOcclusion);
}

float Sound3D::getLevel()
{
    // return level
    return this->level;
}

void Sound3D::setLevel(float level)
{
    // Set Local Level
    this->level = level;
    // Set the Level for the Channel
    FMOD_Channel_Set3DLevel(this->pChannel, this->level);
}

float Sound3D::getDopplerLevel()
{
    // return doppler level
    return this->dopplerLevel;
}

void Sound3D::setDopplerLevel(float dopplerLevel)
{
    // Set local doppler level
    this->dopplerLevel = dopplerLevel;
    // Set Doppler Level
    FMOD_Channel_Set3DDopplerLevel(this->pChannel, dopplerLevel);
}

bool Sound3D::isDistanceFilter()
{
    // return distanceFilterFlag
    return this->distanceFilterFlag;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Sound3D::getCustomLevel()
{
    //return customLevel
    return this->customLevel;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

float Sound3D::getCentreFrequency()
{
    // return centreFrequency
    return this->centreFrequency;
    // Alternative:  FMOD_Channel_Get3DDistanceFilter
}

void Sound3D::setDistanceFilter(bool distanceFilterFlag)
{
    // Set Local distance Filter Flag
    this->distanceFilterFlag = distanceFilterFlag;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Sound3D::setDistanceFilterCustomLevel(float customLevel)
{
    // Set Local distance custom level
    this->customLevel = customLevel;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

void Sound3D::setDistanceFilterCentreFrequency(float frequency)
{
    // Set local frequency
    this->centreFrequency = frequency;
    // Set Distance Filter for the Channel
    FMOD_Channel_Set3DDistanceFilter(this->pChannel, this->distanceFilterFlag, this->customLevel, this->centreFrequency);
}

float Sound3D::getAudibility()
{
    // Get Audibility
    float audibility = 0.0f;
    FMOD_Channel_GetAudibility(this->pChannel, &audibility);
    // return audibility
    return audibility;
}

//void Sound3D::bindToLua(lua_State* pLuaState)
//{
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Sound3D>("Sound3D")
//        .def(luabind::constructor<>())
//        // GENERAL
//        .def("play", (void (Sound3D::*)()) &Sound3D::play)
//        .def("playEx", (void (Sound3D::*)()) &Sound3D::playEx)
//        .def("start", (void (Sound3D::*)()) &Sound3D::start)
//        .def("stop", (void (Sound3D::*)()) &Sound3D::stop)
//        .def("reset", (void (Sound3D::*)()) &Sound3D::reset)
//        .def("isPaused", (bool(Sound3D::*)()) &Sound3D::isPaused)
//        .def("setPaused", (void (Sound3D::*)(bool)) &Sound3D::setPaused)
//        .def("pause", (void (Sound3D::*)()) &Sound3D::pause)
//        .def("resume", (void (Sound3D::*)()) &Sound3D::resume)
//        .def("isPlaying", (bool(Sound3D::*)()) &Sound3D::isPlaying)
//        .def("clear", (void (Sound3D::*)()) &Sound3D::clear)
//        .def("free", (void(Sound3D::*)()) &Sound3D::free)
//        .def("getVolume", (float (Sound3D::*)()) &Sound3D::getVolume)
//        .def("setVolume", (void (Sound3D::*)(float)) &Sound3D::setVolume)
//        .def("isVolumeRamping", (bool(Sound3D::*)()) &Sound3D::isVolumeRamping)
//        .def("setVolumeRamping", (void (Sound3D::*)(bool)) &Sound3D::setVolumeRamping)
//        .def("getPitch", (float (Sound3D::*)()) &Sound3D::getPitch)
//        .def("setPitch", (void (Sound3D::*)(float)) &Sound3D::setPitch)
//        .def("isMute", (bool(Sound3D::*)()) &Sound3D::isMute)
//        .def("setMute", (void (Sound3D::*)(bool)) &Sound3D::setMute)
//        .def("mute", (void (Sound3D::*)()) &Sound3D::mute)
//        .def("unmute", (void (Sound3D::*)()) &Sound3D::unmute)
//        .def("getReverbWet", (float (Sound3D::*)(int)) &Sound3D::getReverbWet)
//        .def("setReverbWet", (void (Sound3D::*)(int, float)) &Sound3D::setReverbWet)
//        .def("getLowPassGain", (float (Sound3D::*)()) &Sound3D::getLowPassGain)
//        .def("setLowPassGain", (void (Sound3D::*)(float)) &Sound3D::setLowPassGain)
//        .def("getMode", (unsigned int (Sound3D::*)()) &Sound3D::getMode)
//        .def("setMode", (void (Sound3D::*)(unsigned int)) &Sound3D::setMode)
//        .def("getBalance", (float (Sound3D::*)()) &Sound3D::getBalance)
//        .def("setBalance", (void (Sound3D::*)(float)) &Sound3D::setBalance)
//        .def("getFrequency", (float (Sound3D::*)()) &Sound3D::getFrequency)
//        .def("setFrequency", (void (Sound3D::*)(float)) &Sound3D::setFrequency)
//        .def("getPriority", (int (Sound3D::*)()) &Sound3D::getPriority)
//        .def("setPriority", (void (Sound3D::*)(int)) &Sound3D::setPriority)
//        .def("isLoop", (bool(Sound3D::*)()) &Sound3D::isLoop)
//        .def("setLoop", (void (Sound3D::*)(bool)) &Sound3D::setLoop)
//        .def("isChannelVirtual", (bool(Sound3D::*)()) &Sound3D::isChannelVirtual)
//        // FILENAME
//        .def("getFilename", (std::string (Sound3D::*)()) &Sound3D::getFilename)
//        // SOUND SAMPLE
//        .def("getSoundSample", (SoundSample* (Sound::*)()) &Sound::getSoundSample)
//        .def("setSoundSample", (void (Sound::*)(SoundSample*)) &Sound::setSoundSample)
//        // ENABLED
//        .def("isEnabled", (bool(Sound3D::*)()) &Sound3D::isEnabled)
//        .def("setEnabled", (void (Sound3D::*)(bool)) &Sound3D::setEnabled)
//        .def("enable", (void (Sound3D::*)()) &Sound3D::enable)
//        .def("disable", (void (Sound3D::*)()) &Sound3D::disable)
//        // NAME
//        .def("getName", (std::string (Sound3D::*)()) &Sound3D::getName)
//        .def("setName", (void (Sound3D::*)(std::string)) &Sound3D::setName)
//        .def("isNamed", (bool(Sound3D::*)()) &Sound3D::isNamed)
//        .def("clearName", (void (Sound3D::*)()) &Sound3D::clearName)
//        // SPACIAL CHANNEL FUNCTIONS
//        .def("getX", (float (Sound3D::*)()) &Sound3D::getX)
//        .def("getY", (float (Sound3D::*)()) &Sound3D::getY)
//        .def("getZ", (float (Sound3D::*)()) &Sound3D::getZ)
//        .def("setPosition", (float (Sound3D::*)(float, float, float)) &Sound3D::setPosition)
//        .def("getXVelocity", (float (Sound3D::*)()) &Sound3D::getXVelocity)
//        .def("getYVelocity", (float (Sound3D::*)()) &Sound3D::getYVelocity)
//        .def("getZVelocity", (float (Sound3D::*)()) &Sound3D::getZVelocity)
//        .def("setVelocity", (float (Sound3D::*)(float, float, float)) &Sound3D::setVelocity)
//        .def("getMinDistance", (float (Sound3D::*)()) &Sound3D::getMinDistance)
//        .def("getMaxDistance", (float (Sound3D::*)()) &Sound3D::getMaxDistance)
//        .def("setMinMaxDistance", (float (Sound3D::*)(float, float)) &Sound3D::setMinMaxDistance)
//        .def("get3DConeInsideAngle", (float (Sound3D::*)()) &Sound3D::get3DConeInsideAngle)
//        .def("get3DConeOutsideAngle", (float (Sound3D::*)()) &Sound3D::get3DConeOutsideAngle)
//        .def("get3DConeOutsideVolume", (float (Sound3D::*)()) &Sound3D::get3DConeOutsideVolume)
//        .def("set3DConeSettings", (void (Sound3D::*)(float, float, float)) &Sound3D::set3DConeSettings)
//        .def("getRotationX", (float (Sound3D::*)()) &Sound3D::getRotationX)
//        .def("getRotationY", (float (Sound3D::*)()) &Sound3D::getRotationY)
//        .def("getRotationZ", (float (Sound3D::*)()) &Sound3D::getRotationZ)
//        .def("setRotation", (void (Sound3D::*)(float, float, float)) &Sound3D::setRotation)
//        .def("getDirectOcclusion", (float (Sound3D::*)()) &Sound3D::getDirectOcclusion)
//        .def("setDirectOcclusion", (void (Sound3D::*)(float)) &Sound3D::setDirectOcclusion)
//        .def("getReverbOcclusion", (float (Sound3D::*)()) &Sound3D::getReverbOcclusion)
//        .def("setReverbOcclusion", (void (Sound3D::*)(float)) &Sound3D::setReverbOcclusion)
//        .def("getLevel", (float (Sound3D::*)()) &Sound3D::getLevel)
//        .def("setLevel", (void (Sound3D::*)(float)) &Sound3D::setLevel)
//        .def("getDopplerLevel", (float (Sound3D::*)()) &Sound3D::getDopplerLevel)
//        .def("setDopplerLevel", (void (Sound3D::*)(float)) &Sound3D::setDopplerLevel)
//        .def("isDistanceFilter", (bool(Sound3D::*)()) &Sound3D::isDistanceFilter)
//        .def("getCustomLevel", (float (Sound3D::*)()) &Sound3D::getCustomLevel)
//        .def("getCentreFrequency", (float (Sound3D::*)()) &Sound3D::getCentreFrequency)
//        .def("setDistanceFilter", (void (Sound3D::*)(bool)) &Sound3D::setDistanceFilter)
//        .def("setDistanceFilterCustomLevel", (void (Sound3D::*)(float)) &Sound3D::setDistanceFilterCustomLevel)
//        .def("setDistanceFilterCentreFrequency", (void (Sound3D::*)(float)) &Sound3D::setDistanceFilterCentreFrequency)
//        .def("getAudibility", (float (Sound3D::*)()) &Sound3D::getAudibility)
//    ];
//}
