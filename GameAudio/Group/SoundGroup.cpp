#include "SoundGroup.h"

SoundGroup::SoundGroup()
{
    // SoungGroup
    this->pSoundGroup = 0;
}

SoundGroup::~SoundGroup()
{

}

FMOD_SYSTEM* SoundGroup::getSystemObject()
{
    // Get System Object for the SoundGroup
    FMOD_SoundGroup_GetSystemObject(this->pSoundGroup, &(FMODGlobals::pFMODSystem));
}

bool SoundGroup::create()
{
    // Create SoundGroup
    FMOD_RESULT result;
    result = FMOD_System_CreateSoundGroup(FMODGlobals::pFMODSystem, "", &(this->pSoundGroup));
    // Set UserData
    FMOD_SoundGroup_SetUserData(this->pSoundGroup, (void*)this);
    // return result
    return result;
}

void SoundGroup::release()
{
    // If we have a Soundgroup
    if (this->pSoundGroup != 0)
    {
        // Release the SoundGroup
        FMOD_SoundGroup_Release(this->pSoundGroup);
    }
    // Clear SoungGroup Pointer
    this->pSoundGroup = 0;
}

int SoundGroup::getMaxAudible()
{
    // Grab maxAudible
    int maxAudible = 0;
    FMOD_SoundGroup_GetMaxAudible(this->pSoundGroup, &maxAudible);
    // return maxAudible
    return maxAudible;
}

void SoundGroup::setMaxAudible(int maxAudible)
{
    // Set MaxAudible for the SoundGroup
    FMOD_SoundGroup_SetMaxAudible(this->pSoundGroup, maxAudible);
}

FMOD_SOUNDGROUP_BEHAVIOR SoundGroup::getMaxAudibleBehaviour()
{
    // Grab behaviour
    FMOD_SOUNDGROUP_BEHAVIOR behaviour;
    FMOD_SoundGroup_GetMaxAudibleBehavior(this->pSoundGroup, &behaviour);
    // return behaviour
    return behaviour;
}

void SoundGroup::setMaxAudibleBehaviour(FMOD_SOUNDGROUP_BEHAVIOR behaviour)
{
    FMOD_SoundGroup_SetMaxAudibleBehavior(this->pSoundGroup, behaviour);
}

float SoundGroup::getMuteFadeSpeed()
{
    // Grab speed in seconds
    float speed = 0.0f;
    FMOD_SoundGroup_GetMuteFadeSpeed(this->pSoundGroup, &speed);
    // return speed
    return speed;
}

void SoundGroup::setMuteFadeSpeed(float speed)
{
    // Set Fade Speed for the SoundGroup
    FMOD_SoundGroup_SetMuteFadeSpeed(this->pSoundGroup, speed);
}

float SoundGroup::getVolume()
{
    // Grab Volume
    float volume = 0.0f;
    FMOD_SoundGroup_GetVolume(this->pSoundGroup, &volume);
    // return volume
    return volume;
}

void SoundGroup::setVolume(float volume)
{
    // Set Volume for the Sound Group
    FMOD_SoundGroup_SetVolume(this->pSoundGroup, volume);
}

void SoundGroup::stop()
{
    // Stop SoundGroup
    FMOD_SoundGroup_Stop(this->pSoundGroup);
}

std::string SoundGroup::getName()
{
    // Grab name
    char name[255];
    FMOD_SoundGroup_GetName(this->pSoundGroup, &name[0], 255);
    //return name
    return std::string(name);
}

int SoundGroup::getNumSounds()
{
    // Grab number of sounds in the sound group
    int numberOfSounds = 0;
    FMOD_SoundGroup_GetNumSounds(this->pSoundGroup, &numberOfSounds);
    //return numberOfSounds
    return numberOfSounds;
}

FMOD_SOUND* SoundGroup::getSound(int index)
{
    // Grab Sound
    FMOD_SOUND* pFMODSound = 0;
    FMOD_SoundGroup_GetSound(this->pSoundGroup, index, &pFMODSound);
    // return pFMODSound
    return pFMODSound;
}

int SoundGroup::getNumPlaying()
{
    // Get Number playing
    int numberPlaying = 0;
    FMOD_SoundGroup_GetNumPlaying(this->pSoundGroup, &numberPlaying);
    // return numberPlaying
    return numberPlaying;
}

//void SoundGroup::bindToLua(lua_State* pLuaState)
//{
//
//}
