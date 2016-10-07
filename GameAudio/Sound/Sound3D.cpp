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
//    // TODO: More bindings
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Sound3D>("Sound3D")
//        .def(luabind::constructor<>())
//        .def("play", (void(Sound3D::*)()) &Sound3D::play)
//        .def("playEx", (void(Sound3D::*)()) &Sound3D::playEx)
//        .def("stop", (void(Sound3D::*)()) &Sound3D::stop)
////        .def("setFrequency", (void(Sound3D::*)(int)) &Sound3D::setFrequency)
////        .def("setLoop", (void(Sound3D::*)(bool)) &Sound3D::setLoop)
////        .def("setMute", (void(Sound3D::*)(bool)) &Sound3D::setMute)
////        .def("setPan", (void(Sound3D::*)(int)) &Sound3D::setPan)
////        .def("setPaused", (void(Sound3D::*)(bool)) &Sound3D::setPaused)
////        .def("setPriority", (void(Sound3D::*)(int)) &Sound3D::setPriority)
////        .def("setReserved", (void(Sound3D::*)(bool)) &Sound3D::setReserved)
////        .def("setSurround", (void(Sound3D::*)(bool)) &Sound3D::setSurround)
////        .def("setVolume", (void(Sound3D::*)(int)) &Sound3D::setVolume)
////        .def("setVolumeAbsolute", (void(Sound3D::*)(int)) &Sound3D::setVolumeAbsolute)
////        .def("getVolume", (int(Sound3D::*)()) &Sound3D::getVolume)
////        .def("getAmplitude", (int(Sound3D::*)()) &Sound3D::getAmplitude)
////        .def("setCurrentPosition", (void(Sound3D::*)(unsigned int)) &Sound3D::setCurrentPosition)
////        .def("getCurrentPosition", (unsigned int(Sound3D::*)()) &Sound3D::getCurrentPosition)
////        .def("isLoop", (bool(Sound3D::*)()) &Sound3D::isLoop)
////        .def("isMute", (bool(Sound3D::*)()) &Sound3D::isMute)
////        .def("getSubChannelCount", (int(Sound3D::*)()) &Sound3D::getSubChannelCount)
////        .def("getPan", (int(Sound3D::*)()) &Sound3D::getPan)
////        .def("isPaused", (bool(Sound3D::*)()) &Sound3D::isPaused)
////        .def("setPaused", (void(Sound3D::*)(bool)) &Sound3D::setPaused)
////        .def("pause", (void(Sound3D::*)()) &Sound3D::pause)
////        .def("resume", (void(Sound3D::*)()) &Sound3D::resume)
////        .def("getPriority", (int(Sound3D::*)()) &Sound3D::getPriority)
////        .def("getReserved", (bool(Sound3D::*)()) &Sound3D::getReserved)
////        .def("getSurround", (bool(Sound3D::*)()) &Sound3D::getSurround)
////        .def("isPlaying", (bool(Sound3D::*)()) &Sound3D::isPlaying)
////        .def("getX", (float(Sound3D::*)()) &Sound3D::getX)
////        .def("getY", (float(Sound3D::*)()) &Sound3D::getY)
////        .def("setPosition", (float(Sound3D::*)(float, float)) &Sound3D::setPosition)
////        .def("getXVelocity", (float(Sound3D::*)()) &Sound3D::getXVelocity)
////        .def("getYVelocity", (float(Sound3D::*)()) &Sound3D::getYVelocity)
////        .def("setVelocity", (float(Sound3D::*)(float, float)) &Sound3D::setVelocity)
////        .def("setMinMaxDistance", (float(Sound3D::*)(float, float)) &Sound3D::setMinMaxDistance)
////        .def("getMinDistance", (float(Sound3D::*)()) &Sound3D::getMinDistance)
////        .def("getMaxDistance", (float(Sound3D::*)()) &Sound3D::getMaxDistance)
//    ];
//}
