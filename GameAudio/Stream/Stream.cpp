#include "Stream.h"

Stream::Stream()
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
    this->loopCount = -1;
    // Stream Specific Stuff
    this->pFMODSound = 0;
    this->filename.clear();
    this->enabledFlag = true;
    this->name.clear();
}

Stream::~Stream()
{

}

Stream::Stream(const Stream& other)
{

}

bool Stream::load(std::string filename)
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
    result = FMOD_System_CreateSound(FMODGlobals::pFMODSystem, filename.c_str(), FMOD_CREATESTREAM, 0, &(this->pFMODSound));
    // If there was a problem
    if (result != FMOD_OK)
    {
        // Send a message to the console
        std::cout << "ERROR: Unable to load stream: " << filename.c_str() << std::endl;
        std::cout << FMOD_ErrorString(result) << std::endl;
        // Failure
        return false;
    }
    // 8888888888888
    // Grab the current mode
    FMOD_MODE mode = (FMOD_MODE)0;
    FMOD_Sound_GetMode(this->pFMODSound, &mode);
    if (this->loopFlag == true)
    {
        // TURN LOOP ON
        mode = mode & !FMOD_LOOP_OFF;
        mode = mode & !FMOD_LOOP_NORMAL;
        mode = mode | FMOD_LOOP_NORMAL;
        FMOD_Sound_SetMode(this->pFMODSound, mode);
    }
    if (this->loopFlag == false)
    {
        // TURN LOOP OFF
        {
            mode = mode & !FMOD_LOOP_OFF;
            mode = mode & !FMOD_LOOP_NORMAL;
            mode = mode | FMOD_LOOP_OFF;
            FMOD_Sound_SetMode(this->pFMODSound, mode);
        }
    }
    // 88888888888888888
    // Send a message to the console
    std::cout << "bool Stream::load((" << filename.c_str() << ")" << std::endl;
    std::cout << "bool Stream::load((" << filename.c_str() << ") success" << std::endl;
    // Set the Filename
    this->filename = filename;

    // Success
    return true;
}

void Stream::think()
{
    // NOTE: Implement me if needed
}

void Stream::update(float dTime)
{
    // NOTE: Implement me if needed
}

void Stream::clear()
{
    // NOTE: Implement me if needed
}

void Stream::free()
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
    }
    // Reset the FMODSound pointer
    this->pFMODSound = 0;
    // Clear the filename
    this->filename.clear();
    // Clear the Name
    this->name.clear();
}

void Stream::play()
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
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pFMODSound, FMODGlobals::pSoundEffectsChannelGroup, false, &(this->pChannel));
    // If playback failed return
    if (result != FMOD_OK)
        return;


    // Set User Data for the Channel
    FMOD_Channel_SetUserData(this->pChannel, (void*)this);
    // Set Paused (if the sound has been paused)
    this->setPaused(this->pausedFlag);
        // Set if playback should loop or not
        this->setLoop(this->loopFlag);
        // 888888888
        //// Set the Loop Count
        //this->setLoopCount(this->loopCount);
        //8888888888
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

void Stream::playEx()
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
        // 888888888
        //// Set the Loop Count
        //this->setLoopCount(this->loopCount);
        //8888888888
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

void Stream::start()
{
    // Play the Stream
    this->play();
}

void Stream::stop()
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

void Stream::reset()
{
    this->stop();
}

bool Stream::isPaused()
{
    // Return paused flag
    return this->pausedFlag;
}

void Stream::setPaused(bool pausedFlag)
{
    // Set local paused flag
    this->pausedFlag = pausedFlag;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Stream::pause()
{
    // Set local paused flag
    this->pausedFlag = true;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

void Stream::resume()
{
    // Set local paused flag
    this->pausedFlag = false;
    // Set channel paused flag
    FMOD_Channel_SetPaused(this->pChannel, this->pausedFlag);
}

bool Stream::isPlaying()
{
    // Grab the channe; playing flag
    FMOD_BOOL playingFlag = false;
    FMOD_Channel_IsPlaying(this->pChannel, &playingFlag);
    // Return playingFlag
    return playingFlag;
}

bool Stream::isLoop()
{
    return this->loopFlag;
}

/* TODO: If this fixes the stream loop problem, radiate this change to the Sound Classes too*/
void Stream::setLoop(bool loopFlag)
{
    // Set local loop flag
    this->loopFlag = loopFlag;

    if (this->pFMODSound == 0)
        return;

    // Grab the current mode
    FMOD_MODE mode = (FMOD_MODE)0;
    FMOD_Sound_GetMode(this->pFMODSound, &mode);
    if (this->loopFlag == true)
    {
        // TURN LOOP ON
        mode = mode & !FMOD_LOOP_OFF;
        mode = mode & !FMOD_LOOP_NORMAL;
        mode = mode | FMOD_LOOP_NORMAL;
        FMOD_Sound_SetMode(this->pFMODSound, mode);
    }
    if (this->loopFlag == false)
    {
        // TURN LOOP OFF
        {
            mode = mode & !FMOD_LOOP_OFF;
            mode = mode & !FMOD_LOOP_NORMAL;
            mode = mode | FMOD_LOOP_OFF;
            FMOD_Sound_SetMode(this->pFMODSound, mode);
        }
    }
}

int Stream::getLoopCount()
{
    // Return our loop COunt
    return this->loopCount;
}

void Stream::setLoopCount(int loopCount)
{
    // Set the local loopCount
    this->loopCount = loopCount;

    // Channel::setLoopCount(loopCount); // TODO: Should this be here? Why does stream and channel loop have to be in conflict what were Fireflight thinking?

    if (this->pFMODSound != 0)
    {
        // Set the FMOD Sound Loop Count
        FMOD_Sound_SetLoopCount(this->pFMODSound, this->loopCount);
    }
}


//FMOD_SYSTEM* Stream::getSystemObject()
//{
//    // Grab the FMODSystem associated with this channel
//    FMOD_SYSTEM* pFMODSystem = 0;
//    FMOD_Channel_GetSystemObject(this->pChannel, &pFMODSystem);
//    // Return FMODSystem
//    return pFMODSystem;
//}
//
//float Stream::getVolume()
//{
//    // return volume
//    return this->volume;
//}
//
//void Stream::setVolume(float volume)
//{
//    // Set local volume
//    this->volume = volume;
//    // Set channel volume
//    FMOD_Channel_SetVolume(this->pChannel, this->volume);
//}
//
//bool Stream::isVolumeRamping()
//{
//    // Grab Volume Ramp Flag
//    FMOD_BOOL volumeRampFlag = false;
//    FMOD_Channel_GetVolumeRamp(this->pChannel, &volumeRampFlag);
//    // Return Volume Ramp Flag
//    return volumeRampFlag;
//}
//
//void Stream::setVolumeRamping(bool volumeRampFlag)
//{
//    // Set local ramp flag
//    this->volumeRampFlag = volumeRampFlag;
//    // Set channel ramp flag
//    FMOD_Channel_SetVolumeRamp(this->pChannel, this->volumeRampFlag);
//}
//
//float Stream::getPitch()
//{
//    // Return pitch
//    return pitch;
//}
//
//void Stream::setPitch(float pitch)
//{
//    // Set local pitch
//    this->pitch = pitch;
//    // Set channel pitch
//    FMOD_Channel_SetPitch(this->pChannel, this->pitch);
//}
//
//bool Stream::isMute()
//{
//    // return mute flag
//    return this->muteFlag;
//}
//
//void Stream::setMute(bool state)
//{
//    // Set mute flag
//    this->muteFlag = muteFlag;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Stream::mute()
//{
//    // Set mute flag
//    this->muteFlag = true;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//void Stream::unmute()
//{
//    // Set local mute flag
//    this->muteFlag = false;
//    // Set channel mute flag
//    FMOD_Channel_SetMute(this->pChannel, this->muteFlag);
//}
//
//float Stream::getReverbWet(int instance)
//{
//    // Get Reverb Wet
//    float wet = 1.0f;
//    FMOD_Channel_GetReverbProperties(this->pChannel, instance, &wet);
//    // return wet
//    return wet;
//}
//
//void Stream::setReverbWet(int instance, float wet)
//{
//    // Set the wetness for and instance of Reverb associated with this channel
//    FMOD_Channel_SetReverbProperties(this->pChannel, instance, wet);
//}
//
//float Stream::getLowPassGain()
//{
//    // return local lowpass gain
//    return this->lowPassGain;
//}
//
//void Stream::setLowPassGain(float lowPassGain)
//{
//    // Set local lowPassGain
//    this->lowPassGain = lowPassGain;
//    // Set Low Pass Gain for the Channel
//    FMOD_Channel_SetLowPassGain(this->pChannel, lowPassGain);
//}
//
//unsigned int Stream::getMode()
//{
//    // return mode
//    return this->mode;
//}
//
//void Stream::setMode(unsigned int mode)
//{
//    // Set local mode
//    this->mode = mode;
//    // Set mode for the Channel
//    FMOD_Channel_SetMode(this->pChannel, mode);
//}
//
//void Stream::setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack)
//{
//    // Set the Control callback for the channel
//    FMOD_Channel_SetCallback(this->pChannel, pCallBack);
//}
//
//float Stream::getBalance()
//{
//    // Return balance
//    return this->balance;
//}
//
//void Stream::setBalance(float balance)
//{
//    // Set local balance
//    this->balance = balance;
//    // Set Channel Pan
//    FMOD_Channel_SetPan(this->pChannel, this->balance);
//}
//
//void* Stream::getUserData()
//{
//    // Grab user data for the channel
//    void* pUserData = 0;
//    FMOD_Channel_GetUserData(this->pChannel, &pUserData);
//    // return pUserData
//    return pUserData;
//}
//
//void Stream::setUserData(void* pUserData)
//{
//    // Set the user data for the channel
//    FMOD_Channel_SetUserData(this->pChannel, pUserData);
//}
//
//float Stream::getFrequency()
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
//void Stream::setFrequency(float frequency)
//{
//    /* NOTE: I can't shadow this parameter as there is no
//        default value for frequency so I set the channel direcly */
//    // Set the Channel
//    FMOD_Channel_SetFrequency(this->pChannel, frequency);
//}
//
//int Stream::getPriority()
//{
//    // return priority;
//    return this->priority;
//}
//
//void Stream::setPriority(int priority)
//{
//    // Set local priority
//    this->priority = priority;
//    // Set channel priority
//    FMOD_Channel_SetPriority(this->pChannel, this->priority);
//}
//
//FMOD_CHANNELGROUP* Stream::getChannelGroup()
//{
//    // Grab ChannelGroup
//    FMOD_CHANNELGROUP* pChannelGroup = 0;
//    FMOD_Channel_GetChannelGroup(this->pChannel, &pChannelGroup);
//    // return pChannelGroup
//    return pChannelGroup;
//}
//
//void Stream::setChannelGroup(FMOD_CHANNELGROUP* pChannelGroup)
//{
//    // Set the ChannelGroup for this Channel
//    FMOD_Channel_SetChannelGroup(this->pChannel, pChannelGroup);
//}
//
//bool Stream::isLoop()
//{
//    // Return Loop Flag
//    return this->loopFlag;
//}
//
//void Stream::setLoop(bool loopFlag)
//{
//    // Set local loop flag
//    this->loopFlag = loopFlag;
//    // Set channel loop flag
//    FMOD_Channel_SetLoopCount(this->pChannel, ((this->loopFlag == true) ? -1 : 0));
//}
//
//bool Stream::isChannelVirtual()
//{
//    // Grab virtual flag from the channel
//    FMOD_BOOL isVirtual = false;
//    FMOD_Channel_IsVirtual(this->pChannel, &isVirtual);
//    // Return is Virtual
//    return isVirtual;
//}
//
//FMOD_DSP* Stream::getDSP(int index)
//{
//    // Grab DSP
//    FMOD_DSP* pDSP = 0;
//    FMOD_Channel_GetDSP(this->pChannel, index, &pDSP);
//    // return DSP
//    return pDSP;
//}
//
//bool Stream::addDSP(int index, FMOD_DSP* pDSP)
//{
//    // Add DSP to the Channel at Index
//    FMOD_RESULT result;
//    result = FMOD_Channel_AddDSP(this->pChannel, index, pDSP);
//    // return result
//     return result;
//}
//
//void Stream::removeDSP(FMOD_DSP* pDSP)
//{
//    // Remove DSP from the Channel
//    FMOD_Channel_RemoveDSP(this->pChannel, pDSP);
//}
//
//int Stream::getNumDSPs()
//{
//    // Grab Number of DSPs associated with the channel
//    int numDSPs = -1;
//    FMOD_Channel_GetNumDSPs(this->pChannel, &numDSPs);
//    // return numDSPs
//    return numDSPs;
//}
//
//int Stream::getDSPIndex(FMOD_DSP* pDSP)
//{
//    // Grab the DSP Index
//    int index = -1;
//    FMOD_Channel_GetDSPIndex(this->pChannel, pDSP, &index);
//    // return index
//    return index;
//}
//
//void Stream::setDSPIndex(FMOD_DSP* pDSP, int index)
//{
//    // Set the index for the DSP on the Channel
//    FMOD_Channel_SetDSPIndex(this->pChannel, pDSP, index);
//}
//
//void Stream::overridePanDSP(FMOD_DSP* pDSP)
//{
//    /* Override FMOD's default pan with a new DSP or
//        if 0 restore to default */
//    FMOD_Channel_OverridePanDSP(this->pChannel, pDSP);
//}

//void Stream::bindToLua(lua_State* pLuaState)
//{
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Stream>("Stream")
//        .def(luabind::constructor<>())
//        // GENERAL
//        .def("load", (bool (Stream::*)(std::string)) &Stream::load)
//        .def("play", (void (Stream::*)()) &Stream::play)
//        .def("playEx", (void (Stream::*)()) &Stream::playEx)
//        .def("start", (void (Stream::*)()) &Stream::start)
//        .def("stop", (void (Stream::*)()) &Stream::stop)
//        .def("reset", (void (Stream::*)()) &Stream::reset)
//        .def("isPaused", (bool(Stream::*)()) &Stream::isPaused)
//        .def("setPaused", (void (Stream::*)(bool)) &Stream::setPaused)
//        .def("pause", (void (Stream::*)()) &Stream::pause)
//        .def("resume", (void (Stream::*)()) &Stream::resume)
//        .def("isPlaying", (bool(Stream::*)()) &Stream::isPlaying)
//        .def("clear", (void (Stream::*)()) &Stream::clear)
//        .def("free", (void(Stream::*)()) &Stream::free)
//        .def("getVolume", (float (Stream::*)()) &Stream::getVolume)
//        .def("setVolume", (void (Stream::*)(float)) &Stream::setVolume)
//        .def("isVolumeRamping", (bool(Stream::*)()) &Stream::isVolumeRamping)
//        .def("setVolumeRamping", (void (Stream::*)(bool)) &Stream::setVolumeRamping)
//        .def("getPitch", (float (Stream::*)()) &Stream::getPitch)
//        .def("setPitch", (void (Stream::*)(float)) &Stream::setPitch)
//        .def("isMute", (bool(Stream::*)()) &Stream::isMute)
//        .def("setMute", (void (Stream::*)(bool)) &Stream::setMute)
//        .def("mute", (void (Stream::*)()) &Stream::mute)
//        .def("unmute", (void (Stream::*)()) &Stream::unmute)
//        .def("getReverbWet", (float (Stream::*)(int)) &Stream::getReverbWet)
//        .def("setReverbWet", (void (Stream::*)(int, float)) &Stream::setReverbWet)
//        .def("getLowPassGain", (float (Stream::*)()) &Stream::getLowPassGain)
//        .def("setLowPassGain", (void (Stream::*)(float)) &Stream::setLowPassGain)
//        .def("getMode", (unsigned int (Stream::*)()) &Stream::getMode)
//        .def("setMode", (void (Stream::*)(unsigned int)) &Stream::setMode)
//        .def("getBalance", (float (Stream::*)()) &Stream::getBalance)
//        .def("setBalance", (void (Stream::*)(float)) &Stream::setBalance)
//        .def("getFrequency", (float (Stream::*)()) &Stream::getFrequency)
//        .def("setFrequency", (void (Stream::*)(float)) &Stream::setFrequency)
//        .def("getPriority", (int (Stream::*)()) &Stream::getPriority)
//        .def("setPriority", (void (Stream::*)(int)) &Stream::setPriority)
//        .def("isLoop", (bool(Stream::*)()) &Stream::isLoop)
//        .def("setLoop", (void (Stream::*)(bool)) &Stream::setLoop)
//        .def("isChannelVirtual", (bool(Stream::*)()) &Stream::isChannelVirtual)
//        // FILENAME
//        .def("getFilename", (std::string (Stream::*)()) &Stream::getFilename)
//        // ENABLED
//        .def("isEnabled", (bool(Stream::*)()) &Stream::isEnabled)
//        .def("setEnabled", (void (Stream::*)(bool)) &Stream::setEnabled)
//        .def("enable", (void (Stream::*)()) &Stream::enable)
//        .def("disable", (void (Stream::*)()) &Stream::disable)
//        // NAME
//        .def("getName", (std::string (Stream::*)()) &Stream::getName)
//        .def("setName", (void (Stream::*)(std::string)) &Stream::setName)
//        .def("isNamed", (bool(Stream::*)()) &Stream::isNamed)
//        .def("clearName", (void (Stream::*)()) &Stream::clearName)
//    ];
//}
