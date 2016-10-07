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

//void Sound2D::bindToLua(lua_State* pLuaState)
//{
//    // TODO: More bindings
//    // TODO: Not all functions are bound, double check and abound accordingly
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Sound2D>("Sound2D")
//        .def(luabind::constructor<>())
//        .def("play", (void(Sound2D::*)()) &Sound2D::play)
//        .def("playEx", (void(Sound2D::*)()) &Sound2D::playEx)
//        .def("stop", (void(Sound2D::*)()) &Sound2D::stop)
////        .def("setFrequency", (void(Sound2D::*)(int)) &Sound2D::setFrequency)
////        .def("setLoop", (void(Sound2D::*)(bool)) &Sound2D::setLoop)
////        .def("setMute", (void(Sound2D::*)(bool)) &Sound2D::setMute)
////        .def("setPan", (void(Sound2D::*)(int)) &Sound2D::setPan)
////        .def("setPaused", (void(Sound2D::*)(bool)) &Sound2D::setPaused)
////        .def("setPriority", (void(Sound2D::*)(int)) &Sound2D::setPriority)
////        .def("setReserved", (void(Sound2D::*)(bool)) &Sound2D::setReserved)
////        .def("setSurround", (void(Sound2D::*)(bool)) &Sound2D::setSurround)
////        .def("setVolume", (void(Sound2D::*)(int)) &Sound2D::setVolume)
////        .def("setVolumeAbsolute", (void(Sound2D::*)(int)) &Sound2D::setVolumeAbsolute)
////        .def("getVolume", (int(Sound2D::*)()) &Sound2D::getVolume)
////        .def("getAmplitude", (int(Sound2D::*)()) &Sound2D::getAmplitude)
////        .def("setCurrentPosition", (void(Sound2D::*)(unsigned int)) &Sound2D::setCurrentPosition)
////        .def("getCurrentPosition", (unsigned int(Sound2D::*)()) &Sound2D::getCurrentPosition)
////        .def("isLoop", (bool(Sound2D::*)()) &Sound2D::isLoop)
////        .def("isMute", (bool(Sound2D::*)()) &Sound2D::isMute)
////        .def("getSubChannelCount", (int(Sound2D::*)()) &Sound2D::getSubChannelCount)
////        .def("getPan", (int(Sound2D::*)()) &Sound2D::getPan)
////        .def("isPaused", (bool(Sound2D::*)()) &Sound2D::isPaused)
////        .def("setPaused", (void(Sound2D::*)(bool)) &Sound2D::setPaused)
////        .def("pause", (void(Sound2D::*)()) &Sound2D::pause)
////        .def("resume", (void(Sound2D::*)()) &Sound2D::resume)
////        .def("getPriority", (int(Sound2D::*)()) &Sound2D::getPriority)
////        .def("getReserved", (bool(Sound2D::*)()) &Sound2D::getReserved)
////        .def("getSurround", (bool(Sound2D::*)()) &Sound2D::getSurround)
////        .def("isPlaying", (bool(Sound2D::*)()) &Sound2D::isPlaying)
////        .def("getX", (float(Sound2D::*)()) &Sound2D::getX)
////        .def("getY", (float(Sound2D::*)()) &Sound2D::getY)
////        .def("setPosition", (float(Sound2D::*)(float, float)) &Sound2D::setPosition)
////        .def("getXVelocity", (float(Sound2D::*)()) &Sound2D::getXVelocity)
////        .def("getYVelocity", (float(Sound2D::*)()) &Sound2D::getYVelocity)
////        .def("setVelocity", (float(Sound2D::*)(float, float)) &Sound2D::setVelocity)
////        .def("setMinMaxDistance", (float(Sound2D::*)(float, float)) &Sound2D::setMinMaxDistance)
////        .def("getMinDistance", (float(Sound2D::*)()) &Sound2D::getMinDistance)
////        .def("getMaxDistance", (float(Sound2D::*)()) &Sound2D::getMaxDistance)
//    ];
//}

