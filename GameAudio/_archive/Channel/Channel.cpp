#include "Channel.h"

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
