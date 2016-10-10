#include "Channel.h"

Channel::Channel()
{
    this->pChannel = 0;
    this->pausedFlag = false;
    this->volume = 1.0f;
    this->volumeRampFlag = false;
    this->pitch = 1.0f;
    this->muteFlag = false;
    this->lowPassGain = 1.0f;
    this->mode = FMOD_DEFAULT | FMOD_LOOP_NORMAL;
    this->balance = 0.0f;
    this->priority = 0;
    this->loopFlag = false;
}

Channel::~Channel()
{

}

FMOD_SYSTEM* Channel::getSystemObject()
{
    // Grab the FMODSystem associated with this channel
    FMOD_SYSTEM* pFMODSystem = 0;
    FMOD_Channel_GetSystemObject(this->pChannel, &pFMODSystem);
    // Return FMODSystem
    return pFMODSystem;
}

void Channel::stop()
{
    // Sound is no longer paused so set flag
    this->pausedFlag = false;
    // Grab the channe; playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // If channel isn't playing then return
    if (playingFlag == true)
    {
        // Stop the channel from playing
        FMOD_Channel_Stop(this->pChannel);
    }
    // Reset channel pointer
    this->pChannel = 0;
}

bool Channel::isPaused()
{
    // Return paused flag
    return this->pausedFlag;
}

void Channel::setPaused(bool pausedFlag)
{
    // Set local paused flag
    this->pausedFlag = pausedFlag;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Channel::pause()
{
    // Set local paused flag
    this->pausedFlag = true;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Channel::resume()
{
    // Set local paused flag
    this->pausedFlag = false;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

float Channel::getVolume()
{
    // Return Volume
    return this->volume;
}

void Channel::setVolume(float volume)
{
    // Set local volume
    this->volume = volume;
    // Set channel volume
    FMOD_Channel_SetVolume(this->pChannel, this->volume);
}

bool Channel::isVolumeRamping()
{
    // Grab Volume Ramp Flag
    FMOD_BOOL volumeRampFlag = false;
    FMOD_Channel_GetVolumeRamp(this->pChannel, &volumeRampFlag);
    // Return Volume Ramp Flag
    return volumeRampFlag;
}

void Channel::setVolumeRamping(bool volumeRampFlag)
{
    // Set local ramp flag
    this->volumeRampFlag = volumeRampFlag;
    // Set channel ramp flag
    FMOD_Channel_SetVolumeRamp(this->pChannel, this->volumeRampFlag);
}

float Channel::getPitch()
{
    // Return pitch
    return pitch;
}

void Channel::setPitch(float pitch)
{
    // Set local pitch
    this->pitch = pitch;
    // Set channel pitch
    FMOD_Channel_SetPitch(this->pChannel, this->pitch);
}

bool Channel::isMute()
{
    // return mute flag
    return this->muteFlag;
}

void Channel::setMute(bool muteFlag)
{
    // Set mute flag
    this->muteFlag = muteFlag;
    // Set channel mute flag
    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
}

void Channel::mute()
{
    // Set mute flag
    this->muteFlag = true;
    // Set channel mute flag
    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
}

void Channel::unmute()
{
    // Set local mute flag
    this->muteFlag = false;
    // Set channel mute flag
    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
}

float Channel::getReverbWet(int instance)
{
    // Get Reverb Wet
    float wet = 1.0f;
    FMOD_Channel_GetReverbProperties(this->pChannel, instance, &wet);
    // return wet
    return wet;
}

void Channel::setReverbWet(int instance, float wet)
{
    // Set the wetness for and instance of Reverb associated with this channel
    FMOD_Channel_SetReverbProperties(this->pChannel, instance, wet);
}

float Channel::getLowPassGain()
{
    // return local lowpass gain
    return this->lowPassGain;
}

void Channel::setLowPassGain(float lowPassGain)
{
    // Set local lowPassGain
    this->lowPassGain = lowPassGain;
    // Set Low Pass Gain for the Channel
    FMOD_Channel_SetLowPassGain(this->pChannel, lowPassGain);
}

unsigned int Channel::getMode()
{
    // return mode
    return this->mode;
}

void Channel::setMode(unsigned int mode)
{
    // Set local mode
    this->mode = mode;
    // Set mode for the Channel
    FMOD_Channel_SetMode(this->pChannel, mode);
}

void Channel::setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack)
{
    // Set the Control callback for the channel
    FMOD_Channel_SetCallback(this->pChannel, pCallBack);
}

bool Channel::isPlaying()
{
    // Grab playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // Return the playing flag
    return playingFlag;
}

float Channel::getBalance()
{
    // return balance
    return this->balance;
}

void Channel::setBalance(float balance)
{
    // Set local balance
    this->balance = balance;
    // Set Channel Pan
    FMOD_Channel_SetPan(this->pChannel, this->balance);
}

unsigned long long Channel::getDSPClock()
{
    // Get DSP Clock
    unsigned long long dspClock = 0;
    FMOD_Channel_GetDSPClock(this->pChannel, &dspClock, 0);
    // return dspClock
    return dspClock;
}

unsigned long  long Channel::getParentDSPClock()
{
    // Get DSP Clock
    unsigned long long parentDSPClock = 0;
    FMOD_Channel_GetDSPClock(this->pChannel, 0, &parentDSPClock);
    // return parentDSPClock
    return parentDSPClock;
}

void Channel::getDelay(unsigned long long* dspclock_start, unsigned long long* dspclock_end, FMOD_BOOL* stopchannels)
{
    // Get Delay
    FMOD_Channel_GetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
}

void Channel::setDelay(unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels)
{
    // Set Delay
    FMOD_Channel_SetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
}

void Channel::addFadePoint(unsigned long long dspClock, float volume)
{
    // Add Fade Point
    FMOD_Channel_AddFadePoint(this->pChannel, dspClock, volume);
}

void Channel::setFadePointRamp(unsigned long long dspClock, float volume)
{
    // Set Fade Point Ramp
    FMOD_Channel_SetFadePointRamp(this->pChannel, dspClock, volume);
}

void Channel::removeFadePoints(unsigned long long dspClockStart, unsigned long long dspClockEnd)
{
    // Remove Fade Points
    FMOD_Channel_RemoveFadePoints(this->pChannel, dspClockStart, dspClockEnd);
}

void Channel::getFadePoints(unsigned int* numPoints, unsigned long long* pointDSPClock, float* volume)
{
    // Get Fade Points
    FMOD_Channel_GetFadePoints(this->pChannel, numPoints, pointDSPClock, volume);
}

void* Channel::getUserData()
{
    // Grab user data for the channel
    void* pUserData = 0;
    FMOD_Channel_GetUserData(this->pChannel, &pUserData);
    // return pUserData
    return pUserData;
}

void Channel::setUserData(void* pUserData)
{
    // Set the user data for the channel
    FMOD_Channel_SetUserData(this->pChannel, pUserData);
}

float Channel::getFrequency()
{
    /* NOTE: I can't shadow this parameter as there is no
        default value for frequency so I ask the channel direcly for information */
    // Grab channel frequency
    float frequency = 0;
    FMOD_Channel_GetFrequency(this->pChannel, &frequency);
    // Return frequency
    return frequency;
}

void Channel::setFrequency(float frequency)
{
    /* NOTE: I can't shadow this parameter as there is no
        default value for frequency so I set the channel direcly */
    // Set the Channel
    FMOD_Channel_SetFrequency(this->pChannel, frequency);
}

int Channel::getPriority()
{
    // return priority
    return this->priority;
}

void Channel::setPriority(int priority)
{
    // Set local priority
    this->priority = priority;
    // Set channel priority
    FMOD_Channel_SetPriority(this->pChannel, this->priority);
}

FMOD_CHANNELGROUP* Channel::getChannelGroup()
{
    // Grab ChannelGroup
    FMOD_CHANNELGROUP* pChannelGroup = 0;
    FMOD_Channel_GetChannelGroup(this->pChannel, &pChannelGroup);
    // return pChannelGroup
    return pChannelGroup;
}

void Channel::setChannelGroup(FMOD_CHANNELGROUP* pChannelGroup)
{
    // Set the ChannelGroup for this Channel
    FMOD_Channel_SetChannelGroup(this->pChannel, pChannelGroup);
}

bool Channel::isLoop()
{
    // return loop flag
    return this->loopFlag;
}

void Channel::setLoop(bool loopFlag)
{
    // Set local loop flag
    this->loopFlag = loopFlag;
    if (this->pChannel != 0)
    {
        // Set channel loop flag
        FMOD_Channel_SetLoopCount(this->pChannel, ((this->loopFlag == true) ? -1 : 0));
    }
}

bool Channel::isChannelVirtual()
{
    // Grab virtual flag from the channel
    FMOD_BOOL isVirtual = false;
    FMOD_Channel_IsVirtual(this->pChannel, &isVirtual);
    // Return is Virtual
    return isVirtual;
}

int Channel::getChannelIndex()
{
    // Grab channel index
    int channelIndex = 0;
    FMOD_Channel_GetIndex(this->pChannel, &channelIndex);
    // return channelIndex
    return channelIndex;
}

FMOD_DSP* Channel::getDSP(int index)
{
    // Grab DSP
    FMOD_DSP* pDSP = 0;
    FMOD_Channel_GetDSP(this->pChannel, index, &pDSP);
    // return DSP
    return pDSP;
}

bool Channel::addDSP(int index, FMOD_DSP* pDSP)
{
    // Add DSP to the Channel at Index
    FMOD_RESULT result;
    result = FMOD_Channel_AddDSP(this->pChannel, index, pDSP);
    // return result
     return result;
}

void Channel::removeDSP(FMOD_DSP* pDSP)
{
    // Remove DSP from the Channel
    FMOD_Channel_RemoveDSP(this->pChannel, pDSP);
}

int Channel::getNumDSPs()
{
    // Grab Number of DSPs associated with the channel
    int numDSPs = -1;
    FMOD_Channel_GetNumDSPs(this->pChannel, &numDSPs);
    // return numDSPs
    return numDSPs;
}

int Channel::getDSPIndex(FMOD_DSP* pDSP)
{
    // Grab the DSP Index
    int index = -1;
    FMOD_Channel_GetDSPIndex(this->pChannel, pDSP, &index);
    // return index
    return index;
}

void Channel::setDSPIndex(FMOD_DSP* pDSP, int index)
{
    // Set the index for the DSP on the Channel
    FMOD_Channel_SetDSPIndex(this->pChannel, pDSP, index);
}

void Channel::overridePanDSP(FMOD_DSP* pDSP)
{
    /* Override FMOD's default pan with a new DSP or
        if 0 restore to default */
    FMOD_Channel_OverridePanDSP(this->pChannel, pDSP);
}
