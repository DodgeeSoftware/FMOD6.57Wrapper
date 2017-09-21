#include "Sound.h"

Sound::Sound()
{
    // Channel Stuff
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
    // Sound Specific Stuff
    this->pSoundSample = 0; // Clear the soundsample pointer
    this->filename.clear();
    this->name.clear();
}

Sound::~Sound()
{

}

void Sound::think()
{
    // operations relating to think
}

void Sound::update(float dTime)
{
    // operations relating to update
}

void Sound::clear()
{
    this->pausedFlag = false;
    this->loopFlag = false;
    this->muteFlag = false;
    this->balance = 0.0f;
    this->volume = 1.0f;
    this->volumeRampFlag = false;
    this->priority = 0;
    this->pSoundSample = 0;
    this->pChannel = 0;
    this->filename.clear();
    this->name.clear();
}

void Sound::free()
{
    this->pausedFlag = false;
    this->loopFlag = false;
    this->muteFlag = false;
    this->balance = 0.0f;
    this->volume = 1.0f;
    this->volumeRampFlag = false;
    this->priority = 0;
    this->pSoundSample = 0;
    this->pChannel = 0;
    this->filename.clear();
    this->name.clear();
}

void Sound::play()
{
    // There must be a SoundSample to play
    if (this->pSoundSample == 0)
        return;
    // The SoundSample must have a valid FMODSound
    if (this->pSoundSample->getFMODSound() == 0)
        return;
    // Don't play a Sound that is already playing
    if (this->isPlaying() == true)
        return;
    // Track result of FMOD Function calls
    FMOD_RESULT result;
    // Play the sound
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pSoundSample->getFMODSound(), FMODGlobals::pSoundEffectsChannelGroup, false, &(this->pChannel));
    // If playback failed return
    if (result != FMOD_OK)
        return;
    // Set User Data for the Channel
    FMOD_Channel_SetUserData(this->pChannel, (void*)this);
    // Set Paused (if the sound has been paused)
    this->setPaused(this->pausedFlag);
    // Set if playback should loop or not
    this->setLoop(this->loopFlag);
    // Set if the Sound should be muted or not
    this->setMute(this->muteFlag);
    // Set the speak balance
    this->setBalance(this->balance);
    // Set the volume
    this->setVolume(this->volume);
    // Set the priority
    this->setPriority(this->priority);
    // Set Volume Ramping
    this->setVolumeRamping(this->volumeRampFlag);
}

void Sound::playEx()
{
    // There must be a SoundSample to play
    if (this->pSoundSample == 0)
        return;
    // The SoundSample must have a valid FMODSound
    if (this->pSoundSample->getFMODSound() == 0)
        return;
    // Don't play a Sound that is already playing
    if (this->isPlaying() == true)
        return;
    // Track result of FMOD Function calls
    FMOD_RESULT result;
    // Play the sound
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pSoundSample->getFMODSound(), FMODGlobals::pSoundEffectsChannelGroup, true, &(this->pChannel));
    // If playback failed return
    if (result != FMOD_OK)
        return;
    // Set User Data for the Channel
    FMOD_Channel_SetUserData(this->pChannel, (void*)this);
    // Set Paused (if the sound has been paused)
    this->setPaused(this->pausedFlag);
    // Set if playback should loop or not
    this->setLoop(this->loopFlag);
    // Set if the Sound should be muted or not
    this->setMute(this->muteFlag);
    // Set the speak balance
    this->setBalance(this->balance);
    // Set the volume
    this->setVolume(this->volume);
    // Set the priority
    this->setPriority(this->priority);
    // Set Volume Ramping
    this->setVolumeRamping(this->volumeRampFlag);
}

void Sound::start()
{
    // Play the sound
    this->play();
}

void Sound::stop()
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

void Sound::reset()
{
    // Stop
    this->stop();
}

bool Sound::isPaused()
{
    // Return paused flag
    return this->pausedFlag;
}

void Sound::setPaused(bool pausedFlag)
{
    // Set local paused flag
    this->pausedFlag = pausedFlag;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Sound::pause()
{
    // Set local paused flag
    this->pausedFlag = true;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Sound::resume()
{
    // Set local paused flag
    this->pausedFlag = false;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

bool Sound::isPlaying()
{
    // Grab playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // Return the playing flag
    return playingFlag;
}

//FMOD_SYSTEM* Sound::getSystemObject()
//{
//    // Grab the FMODSystem associated with this channel
//    FMOD_SYSTEM* pFMODSystem = 0;
//    FMOD_Channel_GetSystemObject(this->pChannel, &pFMODSystem);
//    // Return FMODSystem
//    return pFMODSystem;
//}
//
//float Sound::getVolume()
//{
//    // Return Volume
//    return this->volume;
//}
//
//void Sound::setVolume(float volume)
//{
//    // Set local volume
//    this->volume = volume;
//    // Set channel volume
//    FMOD_Channel_SetVolume(this->pChannel, this->volume);
//}
//
//bool Sound::isVolumeRamping()
//{
//    // Grab Volume Ramp Flag
//    FMOD_BOOL volumeRampFlag = false;
//    FMOD_Channel_GetVolumeRamp(this->pChannel, &volumeRampFlag);
//    // Return Volume Ramp Flag
//    return volumeRampFlag;
//}
//
//void Sound::setVolumeRamping(bool volumeRampFlag)
//{
//    // Set local ramp flag
//    this->volumeRampFlag = volumeRampFlag;
//    // Set channel ramp flag
//    FMOD_Channel_SetVolumeRamp(this->pChannel, this->volumeRampFlag);
//}
//
//float Sound::getPitch()
//{
//    // Return pitch
//    return pitch;
//}
//
//void Sound::setPitch(float pitch)
//{
//    // Set local pitch
//    this->pitch = pitch;
//    // Set channel pitch
//    FMOD_Channel_SetPitch(this->pChannel, this->pitch);
//}
//
//bool Sound::isMute()
//{
//    // return mute flag
//    return this->muteFlag;
//}
//
//void Sound::setMute(bool muteFlag)
//{
//    // Set mute flag
//    this->muteFlag = muteFlag;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Sound::mute()
//{
//    // Set mute flag
//    this->muteFlag = true;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Sound::unmute()
//{
//    // Set local mute flag
//    this->muteFlag = false;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//float Sound::getReverbWet(int instance)
//{
//    // Get Reverb Wet
//    float wet = 1.0f;
//    FMOD_Channel_GetReverbProperties(this->pChannel, instance, &wet);
//    // return wet
//    return wet;
//}
//
//void Sound::setReverbWet(int instance, float wet)
//{
//    // Set the wetness for and instance of Reverb associated with this channel
//    FMOD_Channel_SetReverbProperties(this->pChannel, instance, wet);
//}
//
//float Sound::getLowPassGain()
//{
//    // return local lowpass gain
//    return this->lowPassGain;
//}
//
//void Sound::setLowPassGain(float lowPassGain)
//{
//    // Set local lowPassGain
//    this->lowPassGain = lowPassGain;
//    // Set Low Pass Gain for the Channel
//    FMOD_Channel_SetLowPassGain(this->pChannel, lowPassGain);
//}
//
//unsigned int Sound::getMode()
//{
//    // return mode
//    return this->mode;
//}
//
//void Sound::setMode(unsigned int mode)
//{
//    // Set local mode
//    this->mode = mode;
//    // Set mode for the Channel
//    FMOD_Channel_SetMode(this->pChannel, mode);
//}
//
//void Sound::setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack)
//{
//    // Set the Control callback for the channel
//    FMOD_Channel_SetCallback(this->pChannel, pCallBack);
//}
//
//float Sound::getBalance()
//{
//    // Return local balance
//    return this->balance;
//}
//
//void Sound::setBalance(float balance)
//{
//    // Set local balance
//    this->balance = balance;
//    // Set Channel Pan
//    FMOD_Channel_SetPan(this->pChannel, this->balance);
//}
//
//unsigned long long Sound::getDSPClock()
//{
//    // Get DSP Clock
//    unsigned long long dspClock = 0;
//    FMOD_Channel_GetDSPClock(this->pChannel, &dspClock, 0);
//    // return dspClock
//    return dspClock;
//}
//
//unsigned long long Sound::getParentDSPClock()
//{
//    // Get DSP Clock
//    unsigned long long parentDSPClock = 0;
//    FMOD_Channel_GetDSPClock(this->pChannel, 0, &parentDSPClock);
//    // return parentDSPClock
//    return parentDSPClock;
//}
//
//void Sound::getDelay(unsigned long long* dspclock_start, unsigned long long* dspclock_end, FMOD_BOOL* stopchannels)
//{
//    // Get Delay
//    FMOD_Channel_GetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
//}
//
//void Sound::setDelay(unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels)
//{
//    // Set Delay
//    FMOD_Channel_SetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
//}
//
//void Sound::addFadePoint(unsigned long long dspClock, float volume)
//{
//    // Add Fade Point
//    FMOD_Channel_AddFadePoint(this->pChannel, dspClock, volume);
//}
//
//void Sound::setFadePointRamp(unsigned long long dspClock, float volume)
//{
//    // Set Fade Point Ramp
//    FMOD_Channel_SetFadePointRamp(this->pChannel, dspClock, volume);
//}
//
//void Sound::removeFadePoints(unsigned long long dspClockStart, unsigned long long dspClockEnd)
//{
//    // Remove Fade Points
//    FMOD_Channel_RemoveFadePoints(this->pChannel, dspClockStart, dspClockEnd);
//}
//
//void Sound::getFadePoints(unsigned int* numPoints, unsigned long long* pointDSPClock, float* volume)
//{
//    // Get Fade Points
//    FMOD_Channel_GetFadePoints(this->pChannel, numPoints, pointDSPClock, volume);
//}
//
//float Sound::getFrequency()
//{
//    /* NOTE: I can't shadow this parameter as there is no
//        default value for frequency so I ask the channel direcly for information */
//    // Grab channel frequency
//    float frequency = 0;
//    FMOD_Channel_GetFrequency(this->pChannel, &frequency);
//    // Return frequency
//    return frequency;
//}
//
//void Sound::setFrequency(float frequency)
//{
//    /* NOTE: I can't shadow this parameter as there is no
//        default value for frequency so I set the channel direcly */
//    // Set the Channel
//    FMOD_Channel_SetFrequency(this->pChannel, frequency);
//}
//
//int Sound::getPriority()
//{
//    // return priority
//    return this->priority;
//}
//
//void Sound::setPriority(int priority)
//{
//    // Set local priority
//    this->priority = priority;
//    // Set channel priority
//    FMOD_Channel_SetPriority(this->pChannel, this->priority);
//}
//
//FMOD_CHANNELGROUP* Sound::getChannelGroup()
//{
//    // Grab ChannelGroup
//    FMOD_CHANNELGROUP* pChannelGroup = 0;
//    FMOD_Channel_GetChannelGroup(this->pChannel, &pChannelGroup);
//    // return pChannelGroup
//    return pChannelGroup;
//}
//
//void Sound::setChannelGroup(FMOD_CHANNELGROUP* pChannelGroup)
//{
//    // Set the ChannelGroup for this Channel
//    FMOD_Channel_SetChannelGroup(this->pChannel, pChannelGroup);
//}
//
//bool Sound::isLoop()
//{
//    // return loop flag
//    return this->loopFlag;
//}
//
//void Sound::setLoop(bool loopFlag)
//{
//    // Set local loop flag
//    this->loopFlag = loopFlag;
//    if (this->pChannel != 0)
//    {
//        // Set channel loop flag
//        FMOD_Channel_SetLoopCount(this->pChannel, ((this->loopFlag == true) ? -1 : 0));
//    }
//}
//
//bool Sound::isChannelVirtual()
//{
//    // Grab virtual flag from the channel
//    FMOD_BOOL isVirtual = false;
//    FMOD_Channel_IsVirtual(this->pChannel, &isVirtual);
//    // Return is Virtual
//    return isVirtual;
//}
//
//int Sound::getChannelIndex()
//{
//    // Grab channel index
//    int channelIndex = 0;
//    FMOD_Channel_GetIndex(this->pChannel, &channelIndex);
//    // return channelIndex
//    return channelIndex;
//}
//
//FMOD_DSP* Sound::getDSP(int index)
//{
//    // Grab DSP
//    FMOD_DSP* pDSP = 0;
//    FMOD_Channel_GetDSP(this->pChannel, index, &pDSP);
//    // return DSP
//    return pDSP;
//}
//
//bool Sound::addDSP(int index, FMOD_DSP* pDSP)
//{
//    // Add DSP to the Channel at Index
//    FMOD_RESULT result;
//    result = FMOD_Channel_AddDSP(this->pChannel, index, pDSP);
//    // return result
//     return result;
//}
//
//void Sound::removeDSP(FMOD_DSP* pDSP)
//{
//    // Remove DSP from the Channel
//    FMOD_Channel_RemoveDSP(this->pChannel, pDSP);
//}
//
//int Sound::getNumDSPs()
//{
//    // Grab Number of DSPs associated with the channel
//    int numDSPs = -1;
//    FMOD_Channel_GetNumDSPs(this->pChannel, &numDSPs);
//    // return numDSPs
//    return numDSPs;
//}
//
//int Sound::getDSPIndex(FMOD_DSP* pDSP)
//{
//    // Grab the DSP Index
//    int index = -1;
//    FMOD_Channel_GetDSPIndex(this->pChannel, pDSP, &index);
//    // return index
//    return index;
//}
//
//void Sound::setDSPIndex(FMOD_DSP* pDSP, int index)
//{
//    // Set the index for the DSP on the Channel
//    FMOD_Channel_SetDSPIndex(this->pChannel, pDSP, index);
//}
//
//void Sound::overridePanDSP(FMOD_DSP* pDSP)
//{
//    /* Override FMOD's default pan with a new DSP or
//        if 0 restore to default */
//    FMOD_Channel_OverridePanDSP(this->pChannel, pDSP);
//}

SoundSample* Sound::getSoundSample()
{
    return this->pSoundSample;
}

void Sound::setSoundSample(SoundSample* pSoundSample)
{
    this->pSoundSample = pSoundSample;
}

//void Sound::bindToLua(lua_State* pLuaState)
//{
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Sound>("Sound")
//        .def(luabind::constructor<>())
//        // GENERAL
//        .def("play", (void (Sound::*)()) &Sound::play)
//        .def("playEx", (void (Sound::*)()) &Sound::playEx)
//        .def("start", (void (Sound::*)()) &Sound::start)
//        .def("stop", (void (Sound::*)()) &Sound::stop)
//        .def("reset", (void (Sound::*)()) &Sound::reset)
//        .def("isPaused", (bool(Sound::*)()) &Sound::isPaused)
//        .def("setPaused", (void (Sound::*)(bool)) &Sound::setPaused)
//        .def("pause", (void (Sound::*)()) &Sound::pause)
//        .def("resume", (void (Sound::*)()) &Sound::resume)
//        .def("isPlaying", (bool(Sound::*)()) &Sound::isPlaying)
//        .def("clear", (void (Sound::*)()) &Sound::clear)
//        .def("free", (void(Sound::*)()) &Sound::free)
//        .def("getVolume", (float (Sound::*)()) &Sound::getVolume)
//        .def("setVolume", (void (Sound::*)(float)) &Sound::setVolume)
//        .def("isVolumeRamping", (bool(Sound::*)()) &Sound::isVolumeRamping)
//        .def("setVolumeRamping", (void (Sound::*)(bool)) &Sound::setVolumeRamping)
//        .def("getPitch", (float (Sound::*)()) &Sound::getPitch)
//        .def("setPitch", (void (Sound::*)(float)) &Sound::setPitch)
//        .def("isMute", (bool(Sound::*)()) &Sound::isMute)
//        .def("setMute", (void (Sound::*)(bool)) &Sound::setMute)
//        .def("mute", (void (Sound::*)()) &Sound::mute)
//        .def("unmute", (void (Sound::*)()) &Sound::unmute)
//        .def("getReverbWet", (float (Sound::*)(int)) &Sound::getReverbWet)
//        .def("setReverbWet", (void (Sound::*)(int, float)) &Sound::setReverbWet)
//        .def("getLowPassGain", (float (Sound::*)()) &Sound::getLowPassGain)
//        .def("setLowPassGain", (void (Sound::*)(float)) &Sound::setLowPassGain)
//        .def("getMode", (unsigned int (Sound::*)()) &Sound::getMode)
//        .def("setMode", (void (Sound::*)(unsigned int)) &Sound::setMode)
//        .def("getBalance", (float (Sound::*)()) &Sound::getBalance)
//        .def("setBalance", (void (Sound::*)(float)) &Sound::setBalance)
//        .def("getFrequency", (float (Sound::*)()) &Sound::getFrequency)
//        .def("setFrequency", (void (Sound::*)(float)) &Sound::setFrequency)
//        .def("getPriority", (int (Sound::*)()) &Sound::getPriority)
//        .def("setPriority", (void (Sound::*)(int)) &Sound::setPriority)
//        .def("isLoop", (bool(Sound::*)()) &Sound::isLoop)
//        .def("setLoop", (void (Sound::*)(bool)) &Sound::setLoop)
//        .def("isChannelVirtual", (bool(Sound::*)()) &Sound::isChannelVirtual)
//        // SOUND SAMPLE
//        .def("getSoundSample", (SoundSample* (Sound::*)()) &Sound::getSoundSample)
//        .def("setSoundSample", (void (Sound::*)(SoundSample*)) &Sound::setSoundSample)
//        // ENABLED
//        .def("isEnabled", (bool(Sound::*)()) &Sound::isEnabled)
//        .def("setEnabled", (void (Sound::*)(bool)) &Sound::setEnabled)
//        .def("enable", (void (Sound::*)()) &Sound::enable)
//        .def("disable", (void (Sound::*)()) &Sound::disable)
//        // NAME
//        .def("getName", (std::string (Sound::*)()) &Sound::getName)
//        .def("setName", (void (Sound::*)(std::string)) &Sound::setName)
//        .def("isNamed", (bool(Sound::*)()) &Sound::isNamed)
//        .def("clearName", (void (Sound::*)()) &Sound::clearName)
//        // FILENAME
//        .def("getFilename", (std::string (Sound::*)()) &Sound::getFilename)
//    ];
//}
