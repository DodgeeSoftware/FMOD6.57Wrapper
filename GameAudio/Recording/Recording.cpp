#include "Recording.h"

Recording::Recording() : Channel()
{
    // FMODSound
    this->pFMODSound = 0;
    // recording Device ID
    this->deviceID = 0;
}

Recording::~Recording()
{
    // Don't do anything unless we have loaded a soundstream
    if (this->pFMODSound != 0)
    {
        // Release our FMODSound
        FMOD_Sound_Release(this->pFMODSound);
    }
    // Reset the FMODSound pointer
    this->pFMODSound = 0;
}

Recording::Recording(Recording& other)
{

}

bool Recording::create(float seconds)
{
    // Track Result of calling FMOD Functions
    FMOD_RESULT result;
    // Grab some information about the Recording device we want to tuse
    int systemRate = 0;
    int channels = 0;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, 0, 0, 0, &systemRate, 0, &channels, 0);
    std::cout << std::endl;
    std::cout << "Trying to create the FMODSound using the following info" << std::endl;
    std::cout << "DeviceID: " << this->deviceID << std::endl;
    std::cout << "Channels: " << channels << std::endl;
    std::cout << "SystemRate: " << systemRate << std::endl;
    std::cout << std::endl;
    // Create the FMODSound
    FMOD_CREATESOUNDEXINFO exinfo = {0};
        exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
        exinfo.numchannels      = channels;
        exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
        exinfo.defaultfrequency = systemRate;
        exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * seconds;
    result = FMOD_System_CreateSound(FMODGlobals::pFMODSystem, 0, FMOD_OPENUSER, &exinfo, &(this->pFMODSound));
    // If there was a problem
    if (result != FMOD_OK)
    {
        // Send a message to the console
        std::cout << "ERROR: Unable to Create Stream for recording: " << std::endl;
        std::cout << FMOD_ErrorString(result) << std::endl;
        // Failure
        return false;
    }
    // Success
    return true;
}

void Recording::think()
{
    // Think operations
}

void Recording::update(float dTime)
{
    // Update operations
}

void Recording::play()
{
    // Track result of FMOD Function calls
    FMOD_RESULT result;
    // Play the sound
    result = FMOD_System_PlaySound(FMODGlobals::pFMODSystem, this->pFMODSound, FMODGlobals::pSoundEffectsChannelGroup, false, &(this->pChannel));
}

void Recording::playEx()
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
}

void Recording::release()
{
    // Reset Local members
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
}

int Recording::getRecordingDeviceID()
{
    // Return DeviceID
    return this->deviceID;
}

void Recording::setRecordingDeviceID(int id)
{
    // Set local deviceID
    this->deviceID = id;
}

void Recording::startRecording()
{
    // Stop recorindg from the driver at index
    FMOD_System_RecordStop(FMODGlobals::pFMODSystem, this->deviceID);
    // Start recording using the device at index to the stream at pFMODSound and don't loop the recording
    FMOD_System_RecordStart(FMODGlobals::pFMODSystem, this->deviceID, this->pFMODSound, false);
}

void Recording::stopRecording()
{
    // Don't stop recording when we aren't recording
    if (this->isRecording() == false)
        return;
    // Stop recorindg from the driver at index
    FMOD_System_RecordStop(FMODGlobals::pFMODSystem, this->deviceID);
}

bool Recording::isRecording()
{
    // Get isRecordingFlag
    FMOD_BOOL isRecordingFlag = false;
    FMOD_System_IsRecording(FMODGlobals::pFMODSystem, this->deviceID, &isRecordingFlag);
    // return isRecordingFlag
    return isRecordingFlag;
}

unsigned int Recording::getRecordPosition()
{
    // Grab Record Position
    unsigned int position = 0;
    FMOD_System_GetRecordPosition(FMODGlobals::pFMODSystem, this->deviceID, &position);
    // Return position
    return position;
}

std::string Recording::getDeviceName()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return deviceName
    return std::string(deviceName);
}

FMOD_GUID* Recording::getDeviceGUID()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return pDeviceGUID
    return pDeviceGUID;
}

int Recording::getSystemRate()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return deviceSystemRate
    return deviceSystemRate;
}

FMOD_SPEAKERMODE Recording::getSpeakerMode()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return deviceSpeakerMode
    return deviceSpeakerMode;
}

int Recording::getSpeakerModeChannels()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return deviceSpeakerModeChannels
    return deviceSpeakerModeChannels;
}

FMOD_DRIVER_STATE Recording::getDriverState()
{
    /* Grab Info about the Device associated with
        this index */
    char* deviceName = 0;
    FMOD_GUID* pDeviceGUID = 0;
    int deviceSystemRate = 0;
    FMOD_SPEAKERMODE deviceSpeakerMode;
    int deviceSpeakerModeChannels = 0;
    FMOD_DRIVER_STATE pDeviceDriverState;
    FMOD_System_GetRecordDriverInfo(FMODGlobals::pFMODSystem, this->deviceID, deviceName, 255, pDeviceGUID, &deviceSystemRate, &deviceSpeakerMode, &deviceSpeakerModeChannels, &pDeviceDriverState);
    // return pDeviceDriverState
    return pDeviceDriverState;
}

//void Recording::bindToLua(lua_State* pLuaState)
//{
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<Recording>("Recording")
//        .def(luabind::constructor<>())
//        // RECORDING FUNCTIONS
//        .def("create", (void (Recording::*)()) &Recording::create)
//        .def("play", (void (Recording::*)()) &Recording::play)
//        .def("playEx", (void (Recording::*)()) &Recording::playEx)
//        .def("release", (void (Recording::*)()) &Recording::release)
//        .def("getRecordingDeviceID", (int (Recording::*)()) &Recording::getRecordingDeviceID)
//        .def("setRecordingDeviceID", (void (Recording::*)(int)) &Recording::setRecordingDeviceID)
//        .def("startRecording", (void (Recording::*)()) &Recording::startRecording)
//        .def("stopRecording", (void (Recording::*)()) &Recording::stopRecording)
//        .def("isRecording", (bool (Recording::*)()) &Recording::isRecording)
//        .def("getRecordPosition", (unsigned int (Recording::*)()) &Recording::getRecordPosition)
//        // RECORDING DRIVER INFO FUNCTIONS
//        .def("getDeviceName", (std::string (Recording::*)()) &Recording::getDeviceName)
//        .def("getSystemRate", (int (Recording::*)()) &Recording::getSystemRate)
//        .def("getSpeakerModeChannels", (int (Recording::*)()) &Recording::getSpeakerModeChannels)
//    ];
//}
