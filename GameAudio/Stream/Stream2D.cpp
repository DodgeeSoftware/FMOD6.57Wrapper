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

//void Stream2D::bindToLua(lua_State* pLuaState)
//{
//    // TODO: More bindings
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Stream2D>("Stream2D")
//        .def(luabind::constructor<>())
//        .def("play", (void(Stream2D::*)()) &Stream2D::play)
//        .def("playEx", (void(Stream2D::*)()) &Stream2D::playEx)
//        .def("stop", (void(Stream2D::*)()) &Stream2D::stop)
////        .def("getLength", (int(Stream::*)()) &Stream::getLength)
////        .def("getLengthMs", (int(Stream::*)()) &Stream::getLengthMs)
////        .def("getMode", (unsigned int(Stream::*)()) &Stream::getMode)
////        .def("getSubStreamCount", (int(Stream::*)()) &Stream::getSubStreamCount)
////        .def("getOpenState", (int(Stream::*)()) &Stream::getOpenState)
////        .def("getTime", (int(Stream::*)()) &Stream::getTime)
////        .def("setLoopCount", (void(Stream::*)(int)) &Stream::setLoopCount)
////        .def("setMode", (void(Stream::*)(unsigned int)) &Stream::setLoopCount)
////        .def("setPosition", (void(Stream::*)(unsigned int)) &Stream::setPosition)
////        .def("setSubStream", (void(Stream::*)(int)) &Stream::setSubStream)
////        .def("setSubStreamSentence", (void(Stream::*)(const int* sentenceList, int numItems)) &Stream::setSubStreamSentence)
////        .def("setTime", (void(Stream::*)(int)) &Stream::setTime)
//    ];
//}
