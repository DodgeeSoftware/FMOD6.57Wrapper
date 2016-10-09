#include "ChannelGroup.h"

ChannelGroup::ChannelGroup()
{
    // ChannelGroup
    this->pChannelGroup = 0;
}

ChannelGroup::~ChannelGroup()
{
    // If we have a channel group release it
    if (this->pChannelGroup != 0)
    {
        // Release the ChannelGroup
        FMOD_ChannelGroup_Release(this->pChannelGroup);
    }
    // Reset class Pointer
    this->pChannelGroup = 0;
}

bool ChannelGroup::create()
{
    // Create the ChannelGroup
    FMOD_RESULT result;
    result = FMOD_System_CreateChannelGroup(FMODGlobals::pFMODSystem, 0, &(this->pChannelGroup));
    // Set UserData for the Channel group as this class
    FMOD_ChannelGroup_SetUserData(this->pChannelGroup, (void*)this);
    // return result
    return result;
}

void ChannelGroup::release()
{
    // If we have a channel group release it
    if (this->pChannelGroup != 0)
    {
        // Release the ChannelGroup
        FMOD_ChannelGroup_Release(this->pChannelGroup);
    }
    // Reset class Pointer
    this->pChannelGroup = 0;
}

void ChannelGroup::stop()
{
    // Stop ChannelGroup
    FMOD_ChannelGroup_Stop(this->pChannelGroup);
}

bool ChannelGroup::isPaused()
{
    // Grab pausedFlag
    FMOD_BOOL pausedFlag = false;
    FMOD_ChannelGroup_GetPaused(this->pChannelGroup, &pausedFlag);
    // return pausedFlag
    return pausedFlag;
}

void ChannelGroup::setPaused(bool pausedFlag)
{
    // Set Paused Flag for the Channel
    FMOD_ChannelGroup_SetPaused(this->pChannelGroup, pausedFlag);
}

void ChannelGroup::pause()
{
    // Set Paused Flag for the Channel
    FMOD_ChannelGroup_SetPaused(this->pChannelGroup, true);
}

void ChannelGroup::resume()
{
    // Set Paused Flag for the Channel
    FMOD_ChannelGroup_SetPaused(this->pChannelGroup, false);
}

float ChannelGroup::getVolume()
{
    // Get volume for the ChannelGroup
    float volume = 0.0f;
    FMOD_ChannelGroup_GetVolume(this->pChannelGroup, &volume);
    // return volume
    return volume;
}

void ChannelGroup::setVolume(float volume)
{
    // Set volume for the ChannelGroup
    FMOD_ChannelGroup_SetVolume(this->pChannelGroup, volume);
}

bool ChannelGroup::isVolumeRamping()
{
    // Get Volume Ramping
    FMOD_BOOL volumeRampingFlag = false;
    FMOD_ChannelGroup_GetVolumeRamp(this->pChannelGroup, &volumeRampingFlag);
    // return volumeRampingFlag
    return volumeRampingFlag;
}

void ChannelGroup::setVolumeRamping(bool volumeRampFlag)
{
    // Set Volume Ramp Flag for the Channel
    FMOD_ChannelGroup_SetVolumeRamp(this->pChannelGroup, volumeRampFlag);
}

float ChannelGroup::getPitch()
{
    // Get pitch
    float pitch = 0.0f;
    FMOD_ChannelGroup_GetPitch(this->pChannelGroup, &pitch);
    // return pitch
    return pitch;
}

void ChannelGroup::setPitch(float pitch)
{
    // Set pitch for the ChannelGroup
    FMOD_ChannelGroup_SetPitch(this->pChannelGroup, pitch);
}

bool ChannelGroup::isMute()
{
    // Grab muteFlag
    FMOD_BOOL muteFlag;
    FMOD_ChannelGroup_GetMute(this->pChannelGroup, &muteFlag);
    // return muteFlag
    return muteFlag;
}

void ChannelGroup::setMute(bool muteFlag)
{
    // Set mute for the ChannelGroup
    FMOD_ChannelGroup_SetMute(this->pChannelGroup, muteFlag);
}

void ChannelGroup::mute()
{
    // Set mute for the ChannelGroup
    FMOD_ChannelGroup_SetMute(this->pChannelGroup, true);
}

void ChannelGroup::unmute()
{
    // Set mute for the ChannelGroup
    FMOD_ChannelGroup_SetMute(this->pChannelGroup, false);
}

float ChannelGroup::getAudibility()
{
    // Grab Audibility
    float audibility = 0.0f;
    FMOD_ChannelGroup_GetAudibility(this->pChannelGroup, &audibility);
    // return audibility
    return audibility;
}

float ChannelGroup::getReverbProperties(int instance)
{
    // Grab wet for the reverb instance
    float wet = 0.0f;
    FMOD_ChannelGroup_GetReverbProperties(this->pChannelGroup, instance, &wet);
    // return wet
    return wet;
}

void ChannelGroup::setReverbProperties(int instance, float wet)
{
    // Set wet for the reverb instance
    FMOD_ChannelGroup_SetReverbProperties(this->pChannelGroup, instance, wet);
}

float ChannelGroup::getLowPassGain()
{
    // Grab lowPassGain
    float lowPassGain = 0.0f;
    FMOD_ChannelGroup_GetLowPassGain(this->pChannelGroup, &lowPassGain);
    // return lowPassGain
    return lowPassGain;
}

void ChannelGroup::setLowPassGain(float lowPassGain)
{
    // Set Low Pass Gain
    FMOD_ChannelGroup_SetLowPassGain(this->pChannelGroup, lowPassGain);
}

unsigned int ChannelGroup::getMode()
{
    // Get Mode
    FMOD_MODE mode;
    FMOD_ChannelGroup_GetMode(this->pChannelGroup, &mode);
    // return mode
    return mode;
}

void ChannelGroup::setMode(unsigned int mode)
{
    // Set Mode for the ChannelGroup
    FMOD_ChannelGroup_SetMode(this->pChannelGroup, mode);
}

void ChannelGroup::setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack)
{
    // Set ChannelGroup CallBack
    FMOD_ChannelGroup_SetCallback(this->pChannelGroup, pCallBack);
}

bool ChannelGroup::isPlaying()
{
    // Grab isPlayingFlag for the ChannelGroup
    FMOD_BOOL isPlayingFlag = false;
    FMOD_ChannelGroup_IsPlaying(this->pChannelGroup, &isPlayingFlag);
    //return isPlayingFlag
    return isPlayingFlag;
}

void ChannelGroup::setBalance(float balance)
{
    // Set Balance for the ChannelGroup
    FMOD_ChannelGroup_SetPan(this->pChannelGroup, balance);
}

FMOD_DSP* ChannelGroup::getDSP(int index)
{
    // Grab DSP
    FMOD_DSP* pDSP = 0;
    FMOD_ChannelGroup_GetDSP(this->pChannelGroup, index, &pDSP);
    // return DSP
    return pDSP;
}

bool ChannelGroup::addDSP(int index, FMOD_DSP* pDSP)
{
    // Add DSP to the ChannelGroup at Index
    FMOD_ChannelGroup_AddDSP(this->pChannelGroup, index, pDSP);
}

void ChannelGroup::removeDSP(FMOD_DSP* pDSP)
{
    // Remove the DSP
    FMOD_ChannelGroup_RemoveDSP(this->pChannelGroup, pDSP);
}

int ChannelGroup::getNumDSPs()
{
    // Grab Number of DSPs
    int numberOfDSPs = 0;
    FMOD_ChannelGroup_GetNumDSPs(this->pChannelGroup, &numberOfDSPs);
    //return numberOfDSPs
    return numberOfDSPs;
}

int ChannelGroup::getDSPIndex(FMOD_DSP* pDSP)
{
    // Grab Index
    int index = 0;
    FMOD_ChannelGroup_GetDSPIndex(this->pChannelGroup, pDSP, &index);
    // return index
    return index;
}

void ChannelGroup::setDSPIndex(FMOD_DSP* pDSP, int index)
{
    // Set DSP Index
    FMOD_ChannelGroup_SetDSPIndex(this->pChannelGroup, pDSP, index);
}

void ChannelGroup::overridePanDSP(FMOD_DSP* pDSP)
{
    // Set the DSP to override the Pan / Balance
    FMOD_ChannelGroup_OverridePanDSP(this->pChannelGroup, pDSP);
}

FMOD_DSPCONNECTION* ChannelGroup::addChildChannelGroup(FMOD_CHANNELGROUP* pChildChannelGroup, bool inheritParentDSPClock)
{
    // Add the ChildChannel Group and grab the DSPConnection
    FMOD_DSPCONNECTION* pDSPConnection = 0;
    FMOD_ChannelGroup_AddGroup(this->pChannelGroup, pChildChannelGroup, inheritParentDSPClock, &pDSPConnection);
    // return pDSPConnection
    return pDSPConnection;
}

int ChannelGroup::getNumSubGroups()
{
    // Grab the number of subgroups
    int numberOfSubGroups = 0;
    FMOD_ChannelGroup_GetNumGroups(this->pChannelGroup, &numberOfSubGroups);
    //return numberOfSubGroups
    return numberOfSubGroups;
}

FMOD_CHANNELGROUP* ChannelGroup::getChannelGroup(int index)
{
    // Grab ChannelGroup
    FMOD_CHANNELGROUP* pChannelGroup = 0;
    FMOD_ChannelGroup_GetGroup(this->pChannelGroup, index, &pChannelGroup);
    // return pChannelGroup
    return pChannelGroup;
}

FMOD_CHANNELGROUP* ChannelGroup::getParentGroup()
{
    // Get Parent ChannelGroup
    FMOD_CHANNELGROUP* pParentChannelGroup = 0;
    FMOD_ChannelGroup_GetParentGroup(this->pChannelGroup, &pParentChannelGroup);
    // return pParentChannelGroup
    return pParentChannelGroup;
}

std::string ChannelGroup::getName()
{
    // Grab name
    char name[255];
    FMOD_ChannelGroup_GetName(this->pChannelGroup, &name[0], 255);
    // return name
    return std::string(name);
}

int ChannelGroup::getNumChannels()
{
    // Get Number of Channels
    int numberOfChannels = 0;
    FMOD_ChannelGroup_GetNumChannels(this->pChannelGroup, &numberOfChannels);
    // return numberOfChannels
    return numberOfChannels;
}

FMOD_CHANNEL* ChannelGroup::getChannel(int index)
{
    // Get Channel
    FMOD_CHANNEL* pChannel = 0;
    FMOD_ChannelGroup_GetChannel(this->pChannelGroup, index, &pChannel);
    // return pChannel
    return pChannel;
}

float ChannelGroup::getX()
{
    // Grab Position
    FMOD_VECTOR position;
    FMOD_ChannelGroup_Get3DAttributes(this->pChannelGroup, &position, 0, 0);
    // return position.x
    return position.x;
}

float ChannelGroup::getY()
{
    // Grab Position
    FMOD_VECTOR position;
    FMOD_ChannelGroup_Get3DAttributes(this->pChannelGroup, &position, 0, 0);
    // return position.y
    return position.y;
}

float ChannelGroup::getZ()
{
    // Grab Position
    FMOD_VECTOR position;
    FMOD_ChannelGroup_Get3DAttributes(this->pChannelGroup, &position, 0, 0);
    // return position.z
    return position.z;
}

void ChannelGroup::setPosition(float x, float y, float z)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DAttributes     (FMOD_CHANNELGROUP *channelgroup, const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *alt_pan_pos);
}

float ChannelGroup::getXVelocity()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DAttributes     (FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *alt_pan_pos);
}

float ChannelGroup::getYVelocity()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DAttributes     (FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *alt_pan_pos);
}

float ChannelGroup::getZVelocity()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DAttributes     (FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *alt_pan_pos);
}

void ChannelGroup::setVelocity(float xVelocity, float yVelocity, float zVelocity)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DAttributes     (FMOD_CHANNELGROUP *channelgroup, const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *alt_pan_pos);
}

float ChannelGroup::getMinDistance()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DMinMaxDistance (FMOD_CHANNELGROUP *channelgroup, float *mindistance, float *maxdistance);
}

float ChannelGroup::getMaxDistance()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DMinMaxDistance (FMOD_CHANNELGROUP *channelgroup, float *mindistance, float *maxdistance);
}

void ChannelGroup::setMinMaxDistance(float minDistance, float maxDistance)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DMinMaxDistance (FMOD_CHANNELGROUP *channelgroup, float mindistance, float maxdistance);
}

float ChannelGroup::get3DConeInsideAngle()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeSettings   (FMOD_CHANNELGROUP *channelgroup, float *insideconeangle, float *outsideconeangle, float *outsidevolume);
}

float ChannelGroup::get3DConeOutsideAngle()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeSettings   (FMOD_CHANNELGROUP *channelgroup, float *insideconeangle, float *outsideconeangle, float *outsidevolume);
}

float ChannelGroup::get3DConeOutsideVolume()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeSettings   (FMOD_CHANNELGROUP *channelgroup, float *insideconeangle, float *outsideconeangle, float *outsidevolume);
}

void ChannelGroup::set3DConeSettings(float insideConeAngle, float outsideConeAngle, float outsiderVolume)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DConeSettings   (FMOD_CHANNELGROUP *channelgroup, float insideconeangle, float outsideconeangle, float outsidevolume);
}

float ChannelGroup::getRotationX()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeOrientation(FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *orientation);
}

float ChannelGroup::getRotationY()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeOrientation(FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *orientation);
}

float ChannelGroup::getRotationZ()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DConeOrientation(FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *orientation);
}

void ChannelGroup::setOrientation(float pitch, float yaw, float roll)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DConeOrientation(FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *orientation);
}

float ChannelGroup::getDirectOcclusion()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DOcclusion      (FMOD_CHANNELGROUP *channelgroup, float *directocclusion, float *reverbocclusion);
}

void ChannelGroup::setDirectOcclusion(float directOcclusion)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DOcclusion      (FMOD_CHANNELGROUP *channelgroup, float directocclusion, float reverbocclusion);
}

float ChannelGroup::getReverbOcclusion()
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Get3DOcclusion      (FMOD_CHANNELGROUP *channelgroup, float *directocclusion, float *reverbocclusion);
}

void ChannelGroup::setReverbOcclusion(float reverbOcclusion)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DOcclusion      (FMOD_CHANNELGROUP *channelgroup, float directocclusion, float reverbocclusion);
}

float ChannelGroup::getLevel()
{
    // Grab level
    float level = 0.0f;
    FMOD_ChannelGroup_Get3DLevel(this->pChannelGroup, &level);
    // return level
    return level;
}

void ChannelGroup::setLevel(float level)
{
    // Set Level for the ChannelGroup
    FMOD_ChannelGroup_Set3DLevel(this->pChannelGroup, level);
}

float ChannelGroup::getDopplerLevel()
{
    // Grab Doppler Level
    float dopplerLevel = 0.0f;
    FMOD_ChannelGroup_Get3DDopplerLevel(this->pChannelGroup, &dopplerLevel);
    // return dopplerLevel
    return dopplerLevel;
}

void ChannelGroup::setDopplerLevel(float dopplerLevel)
{
    // Set Dopppler Level for the ChannelGroup
    FMOD_ChannelGroup_Set3DDopplerLevel(this->pChannelGroup, dopplerLevel);
}

bool ChannelGroup::isDistanceFilter()
{
    // Grab Distance Filter Flag
    FMOD_BOOL distanceFilterFlag = false;
    FMOD_ChannelGroup_Get3DDistanceFilter(this->pChannelGroup, &distanceFilterFlag, 0, 0);
    // return distanceFilterFlag
    return distanceFilterFlag;
}

void ChannelGroup::setDistanceFilter(bool distanceFilterFlag)
{
    // Set Distance Filter Flag
    FMOD_ChannelGroup_Set3DDistanceFilter(this->pChannelGroup, distanceFilterFlag, this->getDistanceFilterCustomLevel(), this->getDistanceFilterCentreFrequency());
}

float ChannelGroup::getDistanceFilterCustomLevel()
{
    // Grab Distance Filter Flag
    float customLevel = 0.0f;
    FMOD_ChannelGroup_Get3DDistanceFilter(this->pChannelGroup, 0, &customLevel, 0);
    // return customLevel
    return customLevel;
}

void ChannelGroup::setDistanceFilterCustomLevel(float customLevel)
{
    // Set Custom Level
    FMOD_ChannelGroup_Set3DDistanceFilter(this->pChannelGroup, this->isDistanceFilter(), customLevel, this->getDistanceFilterCentreFrequency());
}

float ChannelGroup::getDistanceFilterCentreFrequency()
{
    // Grab Distance Filter Centre Frequency
    float centreFrequency = 0.0f;
    FMOD_ChannelGroup_Get3DDistanceFilter(this->pChannelGroup, 0, 0, &centreFrequency);
    // return centreFrequency
    return centreFrequency;
}

void ChannelGroup::setDistanceFilterCentreFrequency(float frequency)
{
//FMOD_RESULT F_API FMOD_ChannelGroup_Set3DDistanceFilter (FMOD_CHANNELGROUP *channelgroup, FMOD_BOOL custom, float customLevel, float centerFreq);
}

FMOD_SYSTEM* ChannelGroup::getSystemObject()
{
    // Grab the FMODSystem
    FMOD_SYSTEM* pFMODSystem = 0;
    FMOD_ChannelGroup_GetSystemObject(this->pChannelGroup, &pFMODSystem);
    // return pFMODSystem
    return pFMODSystem;
}

FMOD_CHANNELGROUP* ChannelGroup::getFMODChannelGroup()
{
    // Return the FMOD_CHANNELGROUP
    return this->pChannelGroup;
}

//void ChannelGroup::bindToLua(lua_State* pLuaState)
//{
//    // TODO: implement me
//}
