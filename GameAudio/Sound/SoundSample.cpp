#include "SoundSample.h"

SoundSample::SoundSample()
{
    // FMODSound
    this->pFMODSound = 0;
    // Filename
    this->filename.clear();
}

SoundSample::~SoundSample()
{
    // Release the FMODSound if that hasn't happened already
    if (this->pFMODSound != 0)
        FMOD_Sound_Release(this->pFMODSound);
    // Reset the pointer to the FMODSound
    this->pFMODSound = 0;
    // Clear the filename
    this->filename.clear();
}

FMOD_SYSTEM* SoundSample::getSystemObject()
{
    // Grab the FMODSystem associated with this channel
    FMOD_SYSTEM* pFMODSystem = 0;
    FMOD_Sound_GetSystemObject(this->pFMODSound, &pFMODSystem);
    // Return FMODSystem
    return pFMODSystem;
}

void SoundSample::release()
{
    // Release the FMODSound
    FMOD_Sound_Release(this->pFMODSound);
}

void SoundSample::lock(unsigned int offset, unsigned int length, void* ptr1, void* ptr2, unsigned int* len1, unsigned int* len2)
{
    // Lock
    FMOD_Sound_Lock(this->pFMODSound, offset, length, &ptr1, &ptr2, len1, len2);
}

void SoundSample::unlock(void* ptr1, void* ptr2, unsigned int len1, unsigned int len2)
{
//FMOD_RESULT F_API FMOD_Sound_Unlock                     (FMOD_SOUND *sound, void *ptr1, void *ptr2, unsigned int len1, unsigned int len2);
}

float SoundSample::getFrequency()
{
    // Grab Frequency
    float frequency = 0.0f;
    FMOD_Sound_GetDefaults(this->pFMODSound, &frequency, 0);
    // return frequency
    return frequency;
}

void SoundSample::setFrequency(float frequency)
{
    // Set Frequency
    int priority = this->getPriority();
    FMOD_Sound_SetDefaults(this->pFMODSound, frequency, priority);
}

int SoundSample::getPriority()
{
    // Grab priority
    int priority = 0.0f;
    FMOD_Sound_GetDefaults(this->pFMODSound, 0, &priority);
    // return priority
    return priority;
}

float SoundSample::getMinDistance()
{
    // Grab minDistance
    float minDistance = 0.0f;
    FMOD_Sound_Get3DMinMaxDistance(this->pFMODSound, &minDistance, 0);
    // return minDistance
    return minDistance;
}

float SoundSample::getMaxDistance()
{
    // Grab maxDistance
    float maxDistance = 0.0f;
    FMOD_Sound_Get3DMinMaxDistance(this->pFMODSound, 0, &maxDistance);
    // return maxDistance
    return maxDistance;
}

void SoundSample::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set Min Max Distances
    FMOD_Sound_Set3DMinMaxDistance(this->pFMODSound, minDistance, maxDistance);
}


float SoundSample::get3DConeInsideAngle()
{
    // Get Cone Inside Angle
    float insideConeAngle = 0.0f;
    FMOD_Sound_Get3DConeSettings(this->pFMODSound, &insideConeAngle, 0, 0);
    // return insideConeAngle
    return insideConeAngle;
}

float SoundSample::get3DConeOutsideAngle()
{
    // Get Cone Outside Angle
    float outsideConeAngle = 0.0f;
    FMOD_Sound_Get3DConeSettings(this->pFMODSound, 0, &outsideConeAngle, 0);
    // return outsideConeAngle
    return outsideConeAngle;
}

float SoundSample::get3DConeOutsideVolume()
{
    // Get Cone Outside Volume
    float outsideConeVolume = 0.0f;
    FMOD_Sound_Get3DConeSettings(this->pFMODSound, 0, 0, &outsideConeVolume);
    // return outsideConeVolume
    return outsideConeVolume;
}

void SoundSample::set3DConeSettings(float insideConeAngle, float outsideConeAngle, float outsiderVolume)
{
    // Setup the Cone for the Channel
    FMOD_Sound_Set3DConeSettings(this->pFMODSound, insideConeAngle, outsideConeAngle, outsiderVolume);
}

FMOD_SOUND* SoundSample::getSubSound(int index)
{
    // Grab FMOD_SOUND
    FMOD_SOUND* pFMODSound = 0;
    FMOD_Sound_GetSubSound(pFMODSound, index, &pFMODSound);
    //return pFMODSound
    return pFMODSound;
}

FMOD_SOUND* SoundSample::getParentSound()
{
    // Grab FMOD_SOUND
    FMOD_SOUND* pFMODSound = 0;
    FMOD_Sound_GetSubSoundParent(this->pFMODSound, &pFMODSound);
    // return pFMODSound
    return pFMODSound;
}

std::string SoundSample::getName()
{
    // Grab Name
    char name[255];
    FMOD_Sound_GetName(this->pFMODSound, &name[0], 255);
    // return name
    return std::string(name);
}

float SoundSample::getLengthInSeconds()
{
    // Grab Length
    unsigned int length = 0;
    FMOD_Sound_GetLength(this->pFMODSound, &length, FMOD_TIMEUNIT_MS);
    // return length / 1000.0f
    return length / 1000.0f;
}

unsigned int SoundSample::getLengthInMilliseconds()
{
    // Grab Length
    unsigned int length = 0;
    FMOD_Sound_GetLength(this->pFMODSound, &length, FMOD_TIMEUNIT_MS);
    // return length
    return length;
}

unsigned int SoundSample::getSizeInBytes()
{
    // Grab Length
    unsigned int length = 0;
    FMOD_Sound_GetLength(this->pFMODSound, &length, FMOD_TIMEUNIT_RAWBYTES);
    // return length
    return length;
}

FMOD_SOUND_TYPE SoundSample::getType()
{
    // Grab Type
    FMOD_SOUND_TYPE type;
    FMOD_Sound_GetFormat(this->pFMODSound, &type, 0, 0, 0);
    // return type
    return type;
}

FMOD_SOUND_FORMAT SoundSample::getFormat()
{
    // Grab Format
    FMOD_SOUND_FORMAT format;
    FMOD_Sound_GetFormat(this->pFMODSound, 0, &format, 0, 0);
    // return format
    return format;
}

int SoundSample::getChannels()
{
    // Get Channels
    int channels = 0;
    FMOD_Sound_GetFormat(this->pFMODSound, 0, 0, &channels, 0);
    // return channels
    return channels;
}

int SoundSample::getNumSubSounds()
{
    // Grab number of subsounds
    int numberOfSubSounds = 0;
    FMOD_Sound_GetNumSubSounds(this->pFMODSound, &numberOfSubSounds);
    // return numberOfSubSounds
    return numberOfSubSounds;
}

int SoundSample::getNumTags()
{
    // Grab number of tags
    int numberOfTags = 0;
    FMOD_Sound_GetNumTags(this->pFMODSound, &numberOfTags, 0);
    // return numberOfTags
    return numberOfTags;
}

FMOD_TAG SoundSample::getTag(std::string name)
{
    FMOD_TAG tag;
    FMOD_Sound_GetTag(this->pFMODSound, name.c_str(), 0, &tag);
    // return tag
    return tag;
}

FMOD_TAG SoundSample::getTag(int index)
{
    FMOD_TAG tag;
    FMOD_Sound_GetTag(this->pFMODSound, 0, index, &tag);
    // return tag
    return tag;
}

unsigned int SoundSample::readData(void* pBuffer, unsigned int lengthBytes)
{
    // Read Data
    unsigned int bytesRead = 0;
    FMOD_Sound_ReadData(this->pFMODSound, pBuffer, lengthBytes, &bytesRead);
    // return bytesRead
    return bytesRead;
}

void SoundSample::seekData(unsigned int pcm)
{
    // Seek Data at pcm samples
    FMOD_Sound_SeekData(this->pFMODSound, pcm);
}

FMOD_SOUNDGROUP* SoundSample::getSoundGroup()
{
    // Grab SoundGroup
    FMOD_SOUNDGROUP* pSoundGroup = 0;
    FMOD_Sound_GetSoundGroup(this->pFMODSound, &pSoundGroup);
    //return pSoundGroup
    return pSoundGroup;
}

void SoundSample::setSoundGroup(FMOD_SOUNDGROUP* pSoundGroup)
{
    // Set SoundGroup
    FMOD_Sound_SetSoundGroup(this->pFMODSound, pSoundGroup);
}

FMOD_MODE SoundSample::getMode()
{
    // Get Mode
    FMOD_MODE mode;
    FMOD_Sound_GetMode(this->pFMODSound, &mode);
    // return mode
    return mode;
}

void SoundSample::setMode(FMOD_MODE mode)
{
    // Set mode
    FMOD_Sound_SetMode(this->pFMODSound, mode);
}

int SoundSample::getMusicNumChannels()
{
    // Get number of Channels
    int numberOfChannels = 0;
    FMOD_Sound_GetMusicNumChannels(this->pFMODSound, &numberOfChannels);
    //return numberOfChannels
    return numberOfChannels;
}

float SoundSample::getMusicChannelVolume(int channel)
{
    // Get Music Channel Volume
    float volume = 0.0f;
    FMOD_Sound_GetMusicChannelVolume(this->pFMODSound, channel, &volume);
    //return volume
    return volume;
}

void SoundSample::setMusicChannelVolume(int channel, float volume)
{
    // Set Channel Music Volume
    FMOD_Sound_SetMusicChannelVolume(this->pFMODSound, channel, volume);
}

float SoundSample::getMusicSpeed()
{
    // Get speed
    float speed = 0.0f;
    FMOD_Sound_GetMusicSpeed(this->pFMODSound, &speed);
    // return speed
    return speed;
}

void SoundSample::setMusicSpeed(float speed)
{
    // Set Music Speed
    FMOD_Sound_SetMusicSpeed(this->pFMODSound, speed);
}

FMOD_SOUND* SoundSample::getFMODSound()
{
    // Return the local reference to the FMODSound
    return this->pFMODSound;
}

void SoundSample::setFMODSound(FMOD_SOUND* pFMODSound)
{
    // Set local reference to the FMODSound
    this->pFMODSound = pFMODSound;
    // Set UserData for the FMODSound
    FMOD_Sound_SetUserData(this->pFMODSound, (void*)this);
}

const char* SoundSample::getFilename()
{
    // Return filename
    return this->filename.c_str();
}

void SoundSample::setFilename(const char* filename)
{
    // Set local filename
    this->filename = filename;
}

//void SoundSample::bindToLua(lua_State* pLuaState)
//{
//    // TODO: More bindings
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        /* An FSOUND_SAMPLE is a predeclared datatype from the FMOD Library we have had problems
//        with this design pattern from other 3rd party libraries. I created an intermediatery object
//        called a sound sample which is used in place of an FSOUND_SAMPLE */
//        luabind::class_<SoundSample>("SoundSample")
//        .def(luabind::constructor<>())
//    ];
//}
