#include "Music.h"

Music::Music()
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
    // Stream Specific Stuff
    this->pFMODSound = 0;
    this->filename.clear();
    this->enabledFlag = true;
    this->name.clear();
    // Tracker Only
    this->musicSpeed = 1.0f;
}

Music::~Music()
{

}

bool Music::load(std::string filename)
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
    result = FMOD_System_CreateStream(FMODGlobals::pFMODSystem, filename.c_str(), FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &(this->pFMODSound));
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

void Music::think()
{
    // Anything relating to think goes here
}

void Music::update(float dTime)
{
    // Anything relating to update goes here
}

void Music::clear()
{
    // do nothing
}

void Music::free()
{
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
    // Grab the channe; playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // If channel isn't playing then return
    if (playingFlag == true)
    {
        // Stop the channel from playing
        FMOD_Channel_Stop(this->pChannel);
    }
    // Clear the Channel Pointer
    this->pChannel = 0;
    // Don't do anything unless we have loaded a soundstream
    if (this->pFMODSound != 0)
    {
        // Release our FMODSound
        FMOD_Sound_Release(this->pFMODSound);
        // Reset the FMODSound pointer
        this->pFMODSound = 0;
    }
    // Clear the filename
    this->filename.clear();
    // Clear the Name
    this->name.clear();
}

void Music::play()
{
    // There must be a SoundSample to play
    if (this->pFMODSound == 0)
        return;
    // Don't play a Sound that is already playing
    if (this->isPlaying() == true)
        return;
    // Track result of FMOD Function calls
    FMOD_RESULT result;
    // Play the sound
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pFMODSound, FMODGlobals::pMusicChannelGroup, false, &(this->pChannel));
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
    // Set the balance
    this->setBalance(this->balance);
    // Set the volume
    this->setVolume(this->volume);
    // Set the priority
    this->setPriority(this->priority);
    // Set Volume Ramping
    this->setVolumeRamping(this->volumeRampFlag);
}

void Music::playEx()
{
    // There must be a SoundSample to play
    if (this->pFMODSound == 0)
        return;
    // Don't play a Sound that is already playing
    if (this->isPlaying() == true)
        return;
    // Track result of FMOD Function calls
    FMOD_RESULT result;
    // Play the sound
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pFMODSound, FMODGlobals::pSoundEffectsChannelGroup, true, &(this->pChannel));
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
    // Set the balance
    this->setBalance(this->balance);
    // Set the volume
    this->setVolume(this->volume);
    // Set the priority
    this->setPriority(this->priority);
    // Set Volume Ramping
    this->setVolumeRamping(this->volumeRampFlag);
}

void Music::start()
{
    this->play();
}

void Music::stop()
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

void Music::reset()
{
    this->stop();
}

bool Music::isPaused()
{
    // Return paused flag
    return this->pausedFlag;
}

void Music::setPaused(bool pausedFlag)
{
    // Set local paused flag
    this->pausedFlag = pausedFlag;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Music::pause()
{
    // Set local paused flag
    this->pausedFlag = true;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Music::resume()
{
    // Set local paused flag
    this->pausedFlag = false;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

bool Music::isPlaying()
{
    // Grab the channe; playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // Return playingFlag
    return playingFlag;
}

//FMOD_SYSTEM* Music::getSystemObject()
//{
//    // Grab the FMODSystem associated with this channel
//    FMOD_SYSTEM* pFMODSystem = 0;
//    FMOD_Channel_GetSystemObject(this->pChannel, &pFMODSystem);
//    // Return FMODSystem
//    return pFMODSystem;
//}
//
//float Music::getVolume()
//{
//    // return volume
//    return this->volume;
//}
//
//void Music::setVolume(float value)
//{
//    // Set local volume
//    this->volume = volume;
//    // Set channel volume
//    FMOD_Channel_SetVolume(this->pChannel, this->volume);
//}
//
//bool Music::isVolumeRamping()
//{
//    // Return volumRampFlag
//    return this->volumeRampFlag;
//}
//
//void Music::setVolumeRamping(bool volumeRampFlag)
//{
//    // Set local ramp flag
//    this->volumeRampFlag = volumeRampFlag;
//    // Set channel ramp flag
//    FMOD_Channel_SetVolumeRamp(this->pChannel, this->volumeRampFlag);
//}
//
//float Music::getPitch()
//{
//    // Return pitch
//    return pitch;
//}
//
//void Music::setPitch(float pitch)
//{
//    // Set local pitch
//    this->pitch = pitch;
//    // Set channel pitch
//    FMOD_Channel_SetPitch(this->pChannel, this->pitch);
//}
//
//bool Music::isMute()
//{
//    // Return mute flag
//    return this->muteFlag;
//}
//
//void Music::setMute(bool state)
//{
//    // Set mute flag
//    this->muteFlag = state;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Music::mute()
//{
//    // Set mute flag
//    this->muteFlag = true;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Music::unmute()
//{
//    // Set mute flag
//    this->muteFlag = false;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//float Music::getReverbWet(int instance)
//{
//    // Get Reverb Wet
//    float wet = 1.0f;
//    FMOD_Channel_GetReverbProperties(this->pChannel, instance, &wet);
//    // return wet
//    return wet;
//}
//
//void Music::setReverbWet(int instance, float wet)
//{
//    // Set the wetness for and instance of Reverb associated with this channel
//    FMOD_Channel_SetReverbProperties(this->pChannel, instance, wet);
//}
//
//float Music::getLowPassGain()
//{
//    // return local lowpass gain
//    return this->lowPassGain;
//}
//
//void Music::setLowPassGain(float lowPassGain)
//{
//    // Set local lowPassGain
//    this->lowPassGain = lowPassGain;
//    // Set Low Pass Gain for the Channel
//    FMOD_Channel_SetLowPassGain(this->pChannel, lowPassGain);
//}
//
//unsigned int Music::getMode()
//{
//    // return mode
//    return this->mode;
//}
//
//void Music::setMode(unsigned int mode)
//{
//    // Set local mode
//    this->mode = mode;
//    // Set mode for the Channel
//    FMOD_Channel_SetMode(this->pChannel, mode);
//}
//
//void Music::setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack)
//{
//    // Set the Control callback for the channel
//    FMOD_Channel_SetCallback(this->pChannel, pCallBack);
//}
//
//float Music::getBalance()
//{
//    // Return balance
//    return this->balance;
//}
//
//void Music::setBalance(float balance)
//{
//    // Set local balance
//    this->balance = balance;
//    // Set Channel Pan
//    FMOD_Channel_SetPan(this->pChannel, this->balance);
//}
//
//unsigned long long Music::getDSPClock()
//{
//    // Grab DSP Clock
//    unsigned long long dspClock = 0;
//    FMOD_Channel_GetDSPClock(this->pChannel, &dspClock, 0);
//    // return dspClock
//    return dspClock;
//}
//
//unsigned long long Music::getParentDSPClock()
//{
//    // Grab Parent Clock
//    unsigned long long parentClock = 0;
//    FMOD_Channel_GetDSPClock(this->pChannel, 0, &parentClock);
//    // return parentClock
//    return parentClock;
//}
//
//void Music::getDelay(unsigned long long* dspclock_start, unsigned long long* dspclock_end, FMOD_BOOL* stopchannels)
//{
//    // Get Delay
//    FMOD_Channel_GetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
//}
//
//void Music::setDelay(unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels)
//{
//    // Set Delay
//    FMOD_Channel_SetDelay(this->pChannel, dspclock_start, dspclock_end, stopchannels);
//}
//
//void Music::addFadePoint(unsigned long long dspClock, float volume)
//{
//    // Add Fade Point
//    FMOD_Channel_AddFadePoint(this->pChannel, dspClock, volume);
//}
//
//void Music::setFadePointRamp(unsigned long long dspClock, float volume)
//{
//    // Set Fade Point Ramp
//    FMOD_Channel_SetFadePointRamp(this->pChannel, dspClock, volume);
//}
//
//void Music::removeFadePoints(unsigned long long dspClockStart, unsigned long long dspClockEnd)
//{
//    // Remove Fade Points
//    FMOD_Channel_RemoveFadePoints(this->pChannel, dspClockStart, dspClockEnd);
//}
//
//void Music::getFadePoints(unsigned int* numPoints, unsigned long long* pointDSPClock, float* volume)
//{
//    // Grab Fade Points
//    FMOD_Channel_GetFadePoints(this->pChannel, numPoints, pointDSPClock, volume);
//}
//
//void* Music::getUserData()
//{
//    // Grab user data for the channel
//    void* pUserData = 0;
//    FMOD_Channel_GetUserData(this->pChannel, &pUserData);
//    // return pUserData
//    return pUserData;
//}
//
//void Music::setUserData(void* pUserData)
//{
//    // Set the user data for the channel
//    FMOD_Channel_SetUserData(this->pChannel, pUserData);
//}
//
//float Music::getFrequency()
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
//void Music::setFrequency(float frequency)
//{
//    /* NOTE: I can't shadow this parameter as there is no
//        default value for frequency so I set the channel direcly */
//    // Set the Channel
//    FMOD_Channel_SetFrequency(this->pChannel, frequency);
//}
//
//int Music::getPriority()
//{
//    // return priority;
//    return this->priority;
//}
//
//void Music::setPriority(int priority)
//{
//    // Set local priority
//    this->priority = priority;
//    // Set channel priority
//    FMOD_Channel_SetPriority(this->pChannel, this->priority);
//}
//
//bool Music::isLoop()
//{
//    return this->loopFlag;
//}
//
//void Music::setLoop(bool state)
//{
//    // Set local loop flag
//    this->loopFlag = state;
//    std::cout << "void Music::setLoop(bool state)" << ((this->loopFlag == true) ? "TRUE" : "FALSE") << std::endl;
//    // Set channel loop flag
//    FMOD_Channel_SetLoopCount(this->pChannel, ((this->loopFlag == true) ? -1 : 0));
//}
//
//bool Music::isChannelVirtual()
//{
//    // Grab virtual flag from the channel
//    FMOD_BOOL isVirtual = false;
//    FMOD_Channel_IsVirtual(this->pChannel, &isVirtual);
//    // Return is Virtual
//    return isVirtual;
//}
//
//FMOD_DSP* Music::getDSP(int index)
//{
//    // Grab DSP
//    FMOD_DSP* pDSP = 0;
//    FMOD_Channel_GetDSP(this->pChannel, index, &pDSP);
//    // return DSP
//    return pDSP;
//}
//
//bool Music::addDSP(int index, FMOD_DSP* pDSP)
//{
//    // Add DSP to the Channel at Index
//    FMOD_RESULT result;
//    result = FMOD_Channel_AddDSP(this->pChannel, index, pDSP);
//    // return result
//     return result;
//}
//
//void Music::removeDSP(FMOD_DSP* pDSP)
//{
//    // Remove DSP from the Channel
//    FMOD_Channel_RemoveDSP(this->pChannel, pDSP);
//}
//
//int Music::getNumDSPs()
//{
//    // Grab Number of DSPs associated with the channel
//    int numDSPs = -1;
//    FMOD_Channel_GetNumDSPs(this->pChannel, &numDSPs);
//    // return numDSPs
//    return numDSPs;
//}
//
//int Music::getDSPIndex(FMOD_DSP* pDSP)
//{
//    // Grab the DSP Index
//    int index = -1;
//    FMOD_Channel_GetDSPIndex(this->pChannel, pDSP, &index);
//    // return index
//    return index;
//}
//
//void Music::setDSPIndex(FMOD_DSP* pDSP, int index)
//{
//    // Set the index for the DSP on the Channel
//    FMOD_Channel_SetDSPIndex(this->pChannel, pDSP, index);
//}
//
//void Music::overridePanDSP(FMOD_DSP* pDSP)
//{
//    /* Override FMOD's default pan with a new DSP or
//        if 0 restore to default */
//    FMOD_Channel_OverridePanDSP(this->pChannel, pDSP);
//}

float Music::getTrackerMusicSpeed()
{
    // return music speed
    return this->musicSpeed;
}

void Music::setTrackerMusicSpeed(float speed)
{
    // Set local music speed
    this->musicSpeed = speed;
    // Set Channel Music Speed
    FMOD_Sound_SetMusicSpeed(this->pFMODSound, this->musicSpeed);
}

int Music::getTrackerNumberChannels()
{
    // Grab Number of Channels
    int numChannels = 0;
    FMOD_Sound_GetMusicNumChannels(this->pFMODSound, &numChannels);
    // return numChannels
    return numChannels;
}

float Music::getTrackerMusicChannelVolume(int channel)
{
    // Grab volume
    float volume = 0.0f;
    FMOD_Sound_GetMusicChannelVolume(this->pFMODSound, channel, &volume);
    // Return volume
    return volume;
}

void Music::setTrackerChannelVolume(int channel, float volume)
{
    /* NOTE: Not shadowing any properties here
        as a result this function may only be called after loading */
    // Set Music Channel Volume
    FMOD_Sound_SetMusicChannelVolume(this->pFMODSound, channel, volume);
}

void Music::bindToLua(lua_State* pLuaState)
{
    // Bind functions to lua state
    luabind::module(pLuaState)
    [
        luabind::class_<Music>("Music")
        .def(luabind::constructor<>())
        // GENERAL
        .def("load", (bool (Music::*)(std::string)) &Music::load)
        .def("play", (void (Music::*)()) &Music::play)
        .def("playEx", (void (Music::*)()) &Music::playEx)
        .def("start", (void (Music::*)()) &Music::start)
        .def("stop", (void (Music::*)()) &Music::stop)
        .def("reset", (void (Music::*)()) &Music::reset)
        .def("isPaused", (bool(Music::*)()) &Music::isPaused)
        .def("setPaused", (void (Music::*)(bool)) &Music::setPaused)
        .def("pause", (void (Music::*)()) &Music::pause)
        .def("resume", (void (Music::*)()) &Music::resume)
        .def("isPlaying", (bool(Music::*)()) &Music::isPlaying)
        .def("clear", (void (Music::*)()) &Music::clear)
        .def("free", (void(Music::*)()) &Music::free)
        .def("getVolume", (float (Music::*)()) &Music::getVolume)
        .def("setVolume", (void (Music::*)(float)) &Music::setVolume)
        .def("isVolumeRamping", (bool(Music::*)()) &Music::isVolumeRamping)
        .def("setVolumeRamping", (void (Music::*)(bool)) &Music::setVolumeRamping)
        .def("getPitch", (float (Music::*)()) &Music::getPitch)
        .def("setPitch", (void (Music::*)(float)) &Music::setPitch)
        .def("isMute", (bool(Music::*)()) &Music::isMute)
        .def("setMute", (void (Music::*)(bool)) &Music::setMute)
        .def("mute", (void (Music::*)()) &Music::mute)
        .def("unmute", (void (Music::*)()) &Music::unmute)
        .def("getReverbWet", (float (Music::*)(int)) &Music::getReverbWet)
        .def("setReverbWet", (void (Music::*)(int, float)) &Music::setReverbWet)
        .def("getLowPassGain", (float (Music::*)()) &Music::getLowPassGain)
        .def("setLowPassGain", (void (Music::*)(float)) &Music::setLowPassGain)
        .def("getMode", (unsigned int (Music::*)()) &Music::getMode)
        .def("setMode", (void (Music::*)(unsigned int)) &Music::setMode)
        .def("getBalance", (float (Music::*)()) &Music::getBalance)
        .def("setBalance", (void (Music::*)(float)) &Music::setBalance)
        .def("getFrequency", (float (Music::*)()) &Music::getFrequency)
        .def("setFrequency", (void (Music::*)(float)) &Music::setFrequency)
        .def("getPriority", (int (Music::*)()) &Music::getPriority)
        .def("setPriority", (void (Music::*)(int)) &Music::setPriority)
        .def("isLoop", (bool(Music::*)()) &Music::isLoop)
        .def("setLoop", (void (Music::*)(bool)) &Music::setLoop)
        .def("isChannelVirtual", (bool(Music::*)()) &Music::isChannelVirtual)
        // FILENAME
        .def("getFilename", (std::string (Music::*)()) &Music::getFilename)
        // ENABLED
        .def("isEnabled", (bool(Music::*)()) &Music::isEnabled)
        .def("setEnabled", (void (Music::*)(bool)) &Music::setEnabled)
        .def("enable", (void (Music::*)()) &Music::enable)
        .def("disable", (void (Music::*)()) &Music::disable)
        // TRACKER ONLY FUNCTIONS MOD, IT, S3M
        .def("getTrackerMusicSpeed", (float (Music::*)()) &Music::getTrackerMusicSpeed)
        .def("setTrackerMusicSpeed", (void (Music::*)(float)) &Music::setTrackerMusicSpeed)
        .def("getTrackerNumberChannels", (int (Music::*)()) &Music::getTrackerNumberChannels)
        .def("getTrackerMusicChannelVolume", (float (Music::*)(int)) &Music::getTrackerMusicChannelVolume)
        .def("setTrackerChannelVolume", (void (Music::*)(int, float)) &Music::setTrackerChannelVolume)
        // NAME
        .def("getName", (std::string (Music::*)()) &Music::getName)
        .def("setName", (void (Music::*)(std::string)) &Music::setName)
        .def("isNamed", (bool(Music::*)()) &Music::isNamed)
        .def("clearName", (void (Music::*)()) &Music ::clearName)
    ];
}
