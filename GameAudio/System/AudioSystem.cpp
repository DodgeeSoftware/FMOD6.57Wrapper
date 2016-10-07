#include "AudioSystem.h"

FMOD_SYSTEM* FMODGlobals::pFMODSystem = 0;

FMOD_CHANNELGROUP* FMODGlobals::pSoundEffectsChannelGroup = 0;

FMOD_CHANNELGROUP* FMODGlobals::pMusicChannelGroup = 0;

AudioSystem::AudioSystem()
{
    // Paused Flag
    this->pausedFlag = false;
    // Maximum number of software channels
    this->maxSoftwareChannels = 4093;
    // SoundEffectsVolume
    this->soundEffectsVolume = 1.0f;
    // MusicVolume
    this->musicVolume = 1.0f;
    // Balance
    this->balance = 0.0f;
    // Mute Flag
    this->muteFlag = false;
    // Max World Size
    this->maxWorldSize = 100000;
}

AudioSystem::~AudioSystem()
{

}

bool AudioSystem::init(int maxChannels)
{
    // If we already have a sound system return true
    if (FMODGlobals::pFMODSystem != 0)
        return true;
    // Track FMOD function call status
    FMOD_RESULT result;
    // Create the SoundSystem
    result = FMOD_System_Create(&(FMODGlobals::pFMODSystem));
    if (result != FMOD_OK)
    {
        std::cout << "ERROR:" << FMOD_ErrorString(result) << std::endl;
        std::cout << "bool AudioSystem::init() failure. " << std::endl;
        return false;
    }
    // Init the Sound System
    result = FMOD_System_Init((FMODGlobals::pFMODSystem), maxChannels, FMOD_INIT_NORMAL, 0);
    if (result != FMOD_OK)
    {
        std::cout << "ERROR:" << FMOD_ErrorString(result) << std::endl;
        std::cout << "bool AudioSystem::init() failure. " << std::endl;
        return false;
    }
    // Set the UserData for the AudioSystem
    FMOD_System_SetUserData(FMODGlobals::pFMODSystem, (void*)this);
    // Create the SoundEffects Channel Group
    FMOD_System_CreateChannelGroup(FMODGlobals::pFMODSystem, "SOUNDEFFECTS", &(FMODGlobals::pSoundEffectsChannelGroup));
    // Create the Music Channel Group
    FMOD_System_CreateChannelGroup(FMODGlobals::pFMODSystem, "MUSIC", &(FMODGlobals::pMusicChannelGroup));
    // Set our local reference to max software channels
    this->maxSoftwareChannels = maxChannels;
    // Success
    return true;
}

int AudioSystem::getNumPlugins(FMOD_PLUGINTYPE pluginType)
{
    //FMOD_RESULT F_API FMOD_System_GetNumPlugins             (FMOD_SYSTEM *system, FMOD_PLUGINTYPE plugintype, int *numplugins);
}

unsigned int AudioSystem::getOutputPluginHandle()
{
    //FMOD_RESULT F_API FMOD_System_GetOutputByPlugin         (FMOD_SYSTEM *system, unsigned int *handle);
}

void AudioSystem::setOutputByPlugin(unsigned int handle)
{
    //FMOD_RESULT F_API FMOD_System_SetOutputByPlugin         (FMOD_SYSTEM *system, unsigned int handle);
}

float AudioSystem::getListenerX()
{
    // Position Vector
    FMOD_VECTOR position;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &position, 0, 0, 0);
    // Return x position
    return position.x;
}

float AudioSystem::getListenerY()
{
    // Position Vector
    FMOD_VECTOR position;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &position, 0, 0, 0);
    // Return y position
    return position.y;
}

float AudioSystem::getListenerZ()
{
    // Position Vector
    FMOD_VECTOR position;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &position, 0, 0, 0);
    // Return z position
    return position.z;
}

void AudioSystem::setListenerPosition(float positionX, float positionY)
{
    // Position Vector
    FMOD_VECTOR position;
        position.x = positionX;
        position.y = positionY;
        position.z = 0.0f;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &position, 0, 0, 0);
}

void AudioSystem::setListenerPosition(float positionX, float positionY, float positionZ)
{
    // Position Vector
    FMOD_VECTOR position;
        position.x = positionX;
        position.y = positionY;
        position.z = positionZ;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &position, 0, 0, 0);
}

float AudioSystem::getListenerUpVectorX()
{
    // Up Vector
    FMOD_VECTOR up;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &up);
    // Return up x
    return up.x;
}

float AudioSystem::getListenerUpVectorY()
{
    // Up Vector
    FMOD_VECTOR up;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &up);
    // Return up y
    return up.y;
}

float AudioSystem::getListenerUpVectorZ()
{
    // Up Vector
    FMOD_VECTOR up;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &up);
    // Return up z
    return up.z;
}

void AudioSystem::setListenerUpVector(float upX, float upY)
{
    // Up Vector
    FMOD_VECTOR up;
        up.x = upX;
        up.y = upY;
        up.z = 0.0f;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &up);
}

void AudioSystem::setListenerUpVector(float upX, float upY, float upZ)
{
    // Up Vector
    FMOD_VECTOR up;
        up.x = upX;
        up.y = upY;
        up.z = upZ;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &up);
}

float AudioSystem::getListenerForwardVectorX()
{
    // Forward Vector
    FMOD_VECTOR forward;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, &forward, 0);
    // Return forward x
    return forward.x;
}

float AudioSystem::getListenerForwardVectorY()
{
    // Forward Vector
    FMOD_VECTOR forward;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, &forward, 0);
    // Return forward y
    return forward.y;
}

float AudioSystem::getListenerForwardVectorZ()
{
    // Forward Vector
    FMOD_VECTOR forward;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, &forward, 0);
    // Return forward z
    return forward.z;
}

void AudioSystem::setListenerForwardVector(float forwardX, float forwardY)
{
    // Forward Vector
    FMOD_VECTOR forward;
        forward.x = forwardX;
        forward.y = forwardY;
        forward.z = 0.0f;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, &forward, 0);
}

void AudioSystem::setListenerForwardVector(float forwardX, float forwardY, float forwardZ)
{
    // Forward Vector
    FMOD_VECTOR forward;
        forward.x = forwardX;
        forward.y = forwardY;
        forward.z = forwardZ;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, 0, 0, &forward, 0);
}

float AudioSystem::getListenerXVelocity()
{
    // Velocity Vector
    FMOD_VECTOR velocity;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &velocity, 0, 0, 0);
    // Return velocity x
    return velocity.x;
}

float AudioSystem::getListenerYVelocity()
{
    // Velocity Vector
    FMOD_VECTOR velocity;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &velocity, 0, 0, 0);
    // Return velocity y
    return velocity.y;
}

float AudioSystem::getListenerZVelocity()
{
    // Velocity Vector
    FMOD_VECTOR velocity;
    // Get the Attributes for Listener 0 (default listener)
    FMOD_System_Get3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &velocity, 0, 0, 0);
    // Return velocity z
    return velocity.z;
}

void AudioSystem::setListenerVelocity(float velocityX, float velocityY)
{
    // Velocity Vector
    FMOD_VECTOR velocity;
        velocity.x = velocityX;
        velocity.y = velocityY;
        velocity.z = 0.0f;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &velocity, 0, 0, 0);
}

void AudioSystem::setListenerVelocity(float velocityX, float velocityY, float velocityZ)
{
    // Velocity Vector
    FMOD_VECTOR velocity;
        velocity.x = velocityX;
        velocity.y = velocityY;
        velocity.z = velocityZ;
    // Set the Attributes for Listener 0 (default listener)
    FMOD_System_Set3DListenerAttributes(FMODGlobals::pFMODSystem, 0, &velocity, 0, 0, 0);
}

float AudioSystem::getDopplerScale()
{
    // Doppler Scale
    float dopplerScale = 0.0f;
    // Distance Factor
    float distanceFactor = 0.0f;
    // RollOffScale
    float rollOffScale = 0.0f;
    // Get 3D Settings
    FMOD_System_Get3DSettings(FMODGlobals::pFMODSystem, &dopplerScale, &distanceFactor, &rollOffScale);
    // Return Doppler Scale
    return dopplerScale;
}

float AudioSystem::getDistanceFactor()
{
    // Doppler Scale
    float dopplerScale = 0.0f;
    // Distance Factor
    float distanceFactor = 0.0f;
    // RollOffScale
    float rollOffScale = 0.0f;
    // Get 3D Settings
    FMOD_System_Get3DSettings(FMODGlobals::pFMODSystem, &dopplerScale, &distanceFactor, &rollOffScale);
    // Return distanceFactor
    return distanceFactor;
}

float AudioSystem::getRollOffScale()
{
    // Doppler Scale
    float dopplerScale = 0.0f;
    // Distance Factor
    float distanceFactor = 0.0f;
    // RollOffScale
    float rollOffScale = 0.0f;
    // Get 3D Settings
    FMOD_System_Get3DSettings(FMODGlobals::pFMODSystem, &dopplerScale, &distanceFactor, &rollOffScale);
    // Return rollOffScale
    return rollOffScale;
}

void AudioSystem::set3DSettings(float dopplerScale, float distanceFactor, float rollOffScale)
{
    // Set 3D Settings
    FMOD_System_Set3DSettings(FMODGlobals::pFMODSystem, dopplerScale, distanceFactor, rollOffScale);
}

void AudioSystem::setRollOffCallBack(FMOD_3D_ROLLOFF_CALLBACK pCallBack)
{
    // Set the 3D RollOffCallBack
    FMOD_System_Set3DRolloffCallback(FMODGlobals::pFMODSystem, pCallBack);
}

int AudioSystem::getNumberOfListeners()
{
    // Grab Number of Listeners
    int numListeners = 0;
    FMOD_System_Get3DNumListeners(FMODGlobals::pFMODSystem, &numListeners);
    // Return number of listeners
    return numListeners;
}

void AudioSystem::setNumberOfListeners(int numListeners)
{
    // Set the Number of Listeners
    FMOD_System_Set3DNumListeners(FMODGlobals::pFMODSystem, numListeners);
}

float AudioSystem::getGeometryOcclusionDirect(float xStart, float yStart, float zStart, float xFinish, float yFinish, float zFinish)
{
    // Grab Occlusion Information
    float directOcclusion = 1.0f;
    float reverbOcclusion = 1.0f;
    FMOD_VECTOR start;
        start.x = xStart;
        start.y = yStart;
        start.z = zStart;
    FMOD_VECTOR finish;
        finish.x = xFinish;
        finish.y = yFinish;
        finish.z = zFinish;
    FMOD_System_GetGeometryOcclusion(FMODGlobals::pFMODSystem, &start, &finish, &directOcclusion, &reverbOcclusion);
    // return directOcclusion
    return directOcclusion;
}

float AudioSystem::getGeometryOcclusionReverb(float xStart, float yStart, float zStart, float xFinish, float yFinish, float zFinish)
{
    // Grab Occlusion Information
    float directOcclusion = 1.0f;
    float reverbOcclusion = 1.0f;
    FMOD_VECTOR start;
        start.x = xStart;
        start.y = yStart;
        start.z = zStart;
    FMOD_VECTOR finish;
        finish.x = xFinish;
        finish.y = yFinish;
        finish.z = zFinish;
    FMOD_System_GetGeometryOcclusion(FMODGlobals::pFMODSystem, &start, &finish, &directOcclusion, &reverbOcclusion);
    // return reverbOcclusion
    return reverbOcclusion;
}

void AudioSystem::think()
{
    // Don't update unless we have an FMODSystem
    if (FMODGlobals::pFMODSystem == 0)
        return;
    // Any code required to think for the AudioSystem goes here
}

void AudioSystem::update()
{
    // Don't update unless we have an FMODSystem
    if (FMODGlobals::pFMODSystem == 0)
        return;
    // Update Sound System
    FMOD_System_Update(FMODGlobals::pFMODSystem);
}

void AudioSystem::shutdown()
{
    // Maximum number of software channels
    this->maxSoftwareChannels = 4093;
    // Release the Sound Effects Channel group
    FMOD_ChannelGroup_Release(FMODGlobals::pSoundEffectsChannelGroup);
    // Clear the sound channel group pointer
    FMODGlobals::pSoundEffectsChannelGroup = 0;
    // Release the Music Channel group
    FMOD_ChannelGroup_Release(FMODGlobals::pMusicChannelGroup);
    // Clear the music channel group pointer
    FMODGlobals::pMusicChannelGroup = 0;
    // Close the FMODSoundSystem
    FMOD_System_Close(FMODGlobals::pFMODSystem);
    // Release the FMODSoundSystem
    FMOD_System_Release(FMODGlobals::pFMODSystem);
    // Clear the FMODSystem pointer
    FMODGlobals::pFMODSystem = 0;
}

void AudioSystem::pause()
{
    // Set pausedflag
    this->pausedFlag = true;
    // Stop the SoundEffects Channel Group
    FMOD_ChannelGroup_SetPaused(FMODGlobals::pSoundEffectsChannelGroup, true);
    // Stop the Music Channel Group
    FMOD_ChannelGroup_SetPaused(FMODGlobals::pMusicChannelGroup, true);
    // Suspend the FMODSystem
    FMOD_System_MixerSuspend(FMODGlobals::pFMODSystem);
}

void AudioSystem::resume()
{
    // Set pausedflag
    this->pausedFlag = false;
    // Stop the SoundEffects Channel Group
    FMOD_ChannelGroup_SetPaused(FMODGlobals::pSoundEffectsChannelGroup, false);
    // Stop the Music Channel Group
    FMOD_ChannelGroup_SetPaused(FMODGlobals::pMusicChannelGroup, false);
    // Resume the FMODSystem
    FMOD_System_MixerResume(FMODGlobals::pFMODSystem);
}

void AudioSystem::start()
{
    // Do nothing
}

void AudioSystem::stop()
{
    // Stop the SoundEffects Channel Group
    FMOD_ChannelGroup_Stop(FMODGlobals::pSoundEffectsChannelGroup);
    // Stop the Music Channel Group
    FMOD_ChannelGroup_Stop(FMODGlobals::pMusicChannelGroup);
}

void AudioSystem::debugInit(FMOD_DEBUG_FLAGS flags, FMOD_DEBUG_MODE mode, FMOD_DEBUG_CALLBACK pCallBack, const char* filename)
{
    // When using fmodL (the logging version of FMOD) this function sets information about how logging is used
    FMOD_Debug_Initialize(flags, mode, pCallBack, filename);
}

int AudioSystem::getOutput()
{
    // Grab Output
    FMOD_OUTPUTTYPE output = FMOD_OUTPUTTYPE_AUTODETECT;
    FMOD_System_GetOutput(FMODGlobals::pFMODSystem, &output);
    // return output
    return (int)output;
}

void AudioSystem::setOutput(int output)
{
    // Set the Output mode for the System
    FMOD_System_SetOutput(FMODGlobals::pFMODSystem, (FMOD_OUTPUTTYPE)output);
}

int AudioSystem::getNumDrivers()
{
    // Grab Number of Drivers
    int numDrivers = 0;
    FMOD_System_GetNumDrivers(FMODGlobals::pFMODSystem, &numDrivers);
    // return num Drivers
    return numDrivers;
}

int AudioSystem::getMaxSoftwareChannel()
{
    // Grab Max Software Channels from the System
    int maxSoftwareChannels = 0;
    FMOD_System_GetSoftwareChannels(FMODGlobals::pFMODSystem, &maxSoftwareChannels);
    // return maxSoftwareChannels
    return maxSoftwareChannels;
}

void AudioSystem::setMaxSoftwareChannels(int maxSoftwareChannels)
{
    // Set Max Software Channels for the Syste,
    FMOD_System_SetSoftwareChannels(FMODGlobals::pFMODSystem, maxSoftwareChannels);
}

unsigned int AudioSystem::getDSPBufferSize()
{
    // Grab the Buffer Sizes
    unsigned int bufferLength = 1024;
    int numBuffers = 4;
    FMOD_System_GetDSPBufferSize(FMODGlobals::pFMODSystem, &bufferLength, &numBuffers);
    // Return Buffer Length
    return bufferLength;
}

int AudioSystem::getDSPNumberBuffers()
{
    // Grab the Buffer Sizes
    unsigned int bufferLength = 1024;
    int numBuffers = 4;
    FMOD_System_GetDSPBufferSize(FMODGlobals::pFMODSystem, &bufferLength, &numBuffers);
    // Return Buffer Length
    return numBuffers;
}

void AudioSystem::setDSPBufferSize(unsigned int bufferLength, int numBuffers)
{
    // Set the BufferSize for the FMODSystem
    FMOD_System_SetDSPBufferSize(FMODGlobals::pFMODSystem, bufferLength, numBuffers);
}

void AudioSystem::setFileSystem(FMOD_FILE_OPEN_CALLBACK pUserOpen, FMOD_FILE_CLOSE_CALLBACK pUserClose, FMOD_FILE_READ_CALLBACK pUserRead, FMOD_FILE_SEEK_CALLBACK pUserSeek, FMOD_FILE_ASYNCREAD_CALLBACK pUserSyncRead, FMOD_FILE_ASYNCCANCEL_CALLBACK pUserSyncCancel, int blockAlign)
{
    // Set the FileSystem CallBacks for the FMODSystem
    FMOD_System_SetFileSystem(FMODGlobals::pFMODSystem, pUserOpen, pUserClose, pUserRead, pUserSeek, pUserSyncRead, pUserSyncCancel, blockAlign);
}

void AudioSystem::attachFileSystem(FMOD_FILE_OPEN_CALLBACK pUserOpen, FMOD_FILE_CLOSE_CALLBACK pUserClose, FMOD_FILE_READ_CALLBACK pUserRead, FMOD_FILE_SEEK_CALLBACK pUserSeek)
{
    // Attach a FileSystem of Callbacks to the FMODSystem
    FMOD_System_AttachFileSystem(FMODGlobals::pFMODSystem, pUserOpen, pUserClose, pUserRead, pUserSeek);
}

int AudioSystem::getDiskBusy()
{
    // Grab Busy
    int busy = 0;
    FMOD_File_GetDiskBusy(&busy);
    // return busy
    return busy;
}

void AudioSystem::setDiskBusy(int busy)
{
    // Set Disk Busy
    FMOD_File_SetDiskBusy(busy);
}

unsigned int AudioSystem::getFileStreamBufferSize()
{
    // Grab the StreamBuffer Size
    unsigned int fileBufferSize = 0;
    FMOD_TIMEUNIT fileBufferSizeType = 0;
    FMOD_System_GetStreamBufferSize(FMODGlobals::pFMODSystem, &fileBufferSize, &fileBufferSizeType);
    // Return fileBufferSize
    return fileBufferSize;
}

int AudioSystem::getFileStreamBufferUnitType()
{
    // Grab the StreamBuffer Size
    unsigned int fileBufferSize = 0;
    FMOD_TIMEUNIT fileBufferSizeType = 0;
    FMOD_System_GetStreamBufferSize(FMODGlobals::pFMODSystem, &fileBufferSize, &fileBufferSizeType);
    // Return fileBufferSizeType
    return fileBufferSizeType;
}

void AudioSystem::setFileStreammBufferSize(unsigned int fileBufferSize, int fileBufferSizeType)
{
    // Set Stream Buffer Size
    FMOD_System_SetStreamBufferSize(FMODGlobals::pFMODSystem, fileBufferSize, fileBufferSizeType);
}

unsigned int AudioSystem::getVersion()
{
    // Version
    unsigned int version = 0;
    // Grab the Version
    FMOD_System_GetVersion(FMODGlobals::pFMODSystem, &version);
    // Return the Version
    return version;
}

void* AudioSystem::getOutputHandle()
{
    // Grab the Output Handle
    void* pOutputHandle = 0;
    FMOD_System_GetOutputHandle(FMODGlobals::pFMODSystem, &pOutputHandle);
    // return OutputHandle
    return pOutputHandle;
}

long long AudioSystem::getTotalSampleBytesRead()
{
    // Grab File Usage Data
    long long sampleBytesRead = 0;
    long long streamBytesRead = 0;
    long long otherBytesRead = 0;
    FMOD_System_GetFileUsage(FMODGlobals::pFMODSystem, &sampleBytesRead, &streamBytesRead, &otherBytesRead);
    // return sampleBytesRead
    return sampleBytesRead;
}

long long AudioSystem::getTotalStreamBytesRead()
{
    // Grab File Usage Data
    long long sampleBytesRead = 0;
    long long streamBytesRead = 0;
    long long otherBytesRead = 0;
    FMOD_System_GetFileUsage(FMODGlobals::pFMODSystem, &sampleBytesRead, &streamBytesRead, &otherBytesRead);
    // return streamBytesRead
    return streamBytesRead;
}

long long AudioSystem::getTotalOtherBytesRead()
{
    // Grab File Usage Data
    long long sampleBytesRead = 0;
    long long streamBytesRead = 0;
    long long otherBytesRead = 0;
    FMOD_System_GetFileUsage(FMODGlobals::pFMODSystem, &sampleBytesRead, &streamBytesRead, &otherBytesRead);
    // return otherBytesRead
    return otherBytesRead;
}

int AudioSystem::getCurrentAllocatedRam()
{
    // Grab Ram Usage Info
    int currentAllocated = 0;
    int maxAllocated = 0;
    int totalRam = 0;
    FMOD_System_GetSoundRAM(FMODGlobals::pFMODSystem, &currentAllocated, &maxAllocated, &totalRam);
    //return currentAllocated
    return currentAllocated;
}

int AudioSystem::getMaxAllocatableRam()
{
    // Grab Ram Usage Info
    int currentAllocated = 0;
    int maxAllocated = 0;
    int totalRam = 0;
    FMOD_System_GetSoundRAM(FMODGlobals::pFMODSystem, &currentAllocated, &maxAllocated, &totalRam);
    //return maxAllocated
    return maxAllocated;
}

int AudioSystem::getTotalRamOnDevice()
{
    // Grab Ram Usage Info
    int currentAllocated = 0;
    int maxAllocated = 0;
    int totalRam = 0;
    FMOD_System_GetSoundRAM(FMODGlobals::pFMODSystem, &currentAllocated, &maxAllocated, &totalRam);
    //return totalRam
    return totalRam;
}

float AudioSystem::getSoundEffectsVolume()
{
    // Return sound effects volume
    return this->soundEffectsVolume;
}

void AudioSystem::setSoundEffectsVolume(float volume)
{
    // Keep local record of the sound effects volume
    this->soundEffectsVolume = volume;
    // Set Volume
    FMOD_ChannelGroup_SetVolume(FMODGlobals::pSoundEffectsChannelGroup, volume);
}

float AudioSystem::getMusicVolume()
{
    // Return music volume
    return this->musicVolume;
}

void AudioSystem::setMusicVolume(float volume)
{
    // Set local music Volume
    this->musicVolume = volume;
    // Set Volume
    FMOD_ChannelGroup_SetVolume(FMODGlobals::pMusicChannelGroup, volume);
}

float AudioSystem::getBalance()
{
    // return Balance (-1.0f left 0.0 middle 1.0 right)
    return this->balance;
}

void AudioSystem::setBalance(float balance)
{
    // Set local balance
    this->balance = balance;
    // Set SoundEffects Balance
    FMOD_ChannelGroup_SetPan(FMODGlobals::pSoundEffectsChannelGroup, this->balance);
    // Set Music Balance
    FMOD_ChannelGroup_SetPan(FMODGlobals::pMusicChannelGroup, this->balance);
}

void AudioSystem::setMute(bool state)
{
    if (state == true)
    {
        // Mute
        this->mute();
    }
    else
    {
        // Unmute
        this->unmute();
    }
}

void AudioSystem::mute()
{
    // Set Mute Flag
    this->muteFlag = true;
    // Set Volume for SoundEffects Channel
    FMOD_ChannelGroup_SetMute(FMODGlobals::pSoundEffectsChannelGroup, true);
    // Set Volume for Music Channel
    FMOD_ChannelGroup_SetMute(FMODGlobals::pMusicChannelGroup, true);
}

void AudioSystem::unmute()
{
    // Set Mute Flag
    this->muteFlag = false;
    // Set Volume for SoundEffects Channel
    FMOD_ChannelGroup_SetMute(FMODGlobals::pSoundEffectsChannelGroup, false);
    // Set Volume for Music Channel
    FMOD_ChannelGroup_SetMute(FMODGlobals::pMusicChannelGroup, false);
}

int AudioSystem::getNumberOfDrivers()
{
    // Grab the Number of Drivers and number of connected devices
    int numberOfDrivers = 0;
    int numConnectedDevices = 0;
    FMOD_System_GetRecordNumDrivers(FMODGlobals::pFMODSystem, &numberOfDrivers, &numConnectedDevices);
    // return numberOfDrivers
    return numberOfDrivers;
}

int AudioSystem::getNumberOfConnectedRecordingDevices()
{
    // Grab the Number of Drivers and number of connected devices
    int numberOfDrivers = 0;
    int numConnectedDevices = 0;
    FMOD_System_GetRecordNumDrivers(FMODGlobals::pFMODSystem, &numberOfDrivers, &numConnectedDevices);
    // return numConnectedDevices
    return numConnectedDevices;
}

bool AudioSystem::isRecording(int index)
{
    // Grab recordingFlag
    FMOD_BOOL recordingFlag = false;
    FMOD_System_IsRecording(FMODGlobals::pFMODSystem, index, &recordingFlag);
    //return recordingFlag
    return recordingFlag;
}

float AudioSystem::getDSPUsage()
{
    // How much of the CPU is used for DSP (0 - 100);
    float dspUsage = -1.0f;
    // Grab the usage
    FMOD_System_GetCPUUsage(FMODGlobals::pFMODSystem, &dspUsage, 0, 0, 0, 0);
    // Return dspUsage
    return dspUsage;
}

float AudioSystem::getStreamUsage()
{
    // How much of the CPU is used for Streaming (0 - 100);
    float streamUsage = -1.0f;
    // Grab the usage
    FMOD_System_GetCPUUsage(FMODGlobals::pFMODSystem, 0, &streamUsage, 0, 0, 0);
    // Return streamUsage
    return streamUsage;
}

float AudioSystem::getGeomteryUsage()
{
    // How much of the CPU is used for Geometry (0 - 100);
    float geometryUsage = -1.0f;
    // Grab the usage
    FMOD_System_GetCPUUsage(FMODGlobals::pFMODSystem, 0, 0, &geometryUsage, 0, 0);
    // Return geometryUsage
    return geometryUsage;
}

float AudioSystem::getUpdateUsage()
{
    // How much of the CPU is used for update (0 - 100);
    float updateUsage = -1.0f;
    // Grab the usage
    FMOD_System_GetCPUUsage(FMODGlobals::pFMODSystem, 0, 0, 0, &updateUsage, 0);
    // Return updateUsage
    return updateUsage;
}

float AudioSystem::getCPUUsage()
{
    // How much of the CPU is used (0 - 100);
    float cpuUsage = -1.0f;
    // Grab the usage
    FMOD_System_GetCPUUsage(FMODGlobals::pFMODSystem, 0, 0, 0, 0, &cpuUsage);
    // Return CPUUsage
    return cpuUsage;
}

int AudioSystem::getChannelsPlaying()
{
    // Number of channels in our array
    int channelCount = -1;
    // Get the number of Channels
    FMOD_System_GetChannelsPlaying(FMODGlobals::pFMODSystem, 0, &channelCount);
    // Return channel count
    return channelCount;
}

//int AudioSystem::getDriver()
//{
//    return FSOUND_GetDriver();
//}
//
//std::string AudioSystem::getDriverCapabilities(int driverID)
//{
//    std::string capsBuffer;
//    unsigned int caps = 0;
//    FSOUND_GetDriverCaps(driverID, &caps);
//    if (caps & FSOUND_CAPS_HARDWARE)
//        capsBuffer.append("This driver supports hardware accelerated 3d sound. \n" );
//    if (caps & FSOUND_CAPS_EAX2)
//        capsBuffer.append("This driver supports EAX 2 reverb  \n" );
//    if (caps & FSOUND_CAPS_EAX3)
//        capsBuffer.append("This driver supports EAX 3 reverb  \n" );
//    return capsBuffer;
//}
//
//std::string AudioSystem::getDriverName(int driverID)
//{
//    return std::string(FSOUND_GetDriverName(driverID));
//}
//
//int AudioSystem::getMaxSamples()
//{
//    return FSOUND_GetMaxSamples();
//}
//
//int AudioSystem::getFrequency()
//{
//    return this->frequency;
//}
//
//int AudioSystem::getMaxSoftwareChannels()
//{
//    return this->maxSoftwareChannels;
//}
//
//int AudioSystem::getMaxChannels()
//{
//    return FSOUND_GetMaxChannels();
//}
//
//std::string AudioSystem::getMemoryStatistics()
//{
//    unsigned int currentAllocated = 0;
//    unsigned int maxAllocated = 0;
//    FSOUND_GetMemoryStats(&currentAllocated, &maxAllocated);
//    char* currentlyAllocatedString = 0;
//    itoa(currentAllocated, currentlyAllocatedString, 10);
//    char* maxAllocatedString = 0;
//    itoa(maxAllocated, maxAllocatedString, 10);
//
//    std::string buffer;
//    buffer.append("Currently Allocated: ");
//    buffer.append(currentlyAllocatedString);
//    buffer.append(", ");
//    buffer.append("Max Allocated: ");
//    buffer.append(maxAllocatedString);
//    return buffer;
//}
//
//int AudioSystem::getDrivers()
//{
//    return FSOUND_GetNumDrivers();
//}
//
//signed char AudioSystem::getNumHWChannels()
//{
//    int num2d = 0;
//    int num3d = 0;
//    int total = 0;
//    FSOUND_GetNumHWChannels(&num2d, &num3d, &total);
//    return total;
//}
//
//int AudioSystem::getOutput()
//{
//    return FSOUND_GetOutput();
//}
//
//void* AudioSystem::getOutputHandle()
//{
//    return FSOUND_GetOutputHandle();
//}
//
//int AudioSystem::getOutputRate()
//{
//    return FSOUND_GetOutputRate();
//}
//void AudioSystem::addDSPEffect(std::string name, IDSPEffect* pDSPEffect)
//{
//    // Validate Incoming DSP Effect Pointer
//    if (pDSPEffect == 0)
//        return;
//    // Try and Find the DSP Effect
//    std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.find(name);
//    // if there is already an effect with this name then return
//    if (i != this->dspEffects.end())
//        return;
//    // Add the DSP Effect to the Map
//    this->dspEffects[name] = pDSPEffect;
//}
//
//IDSPEffect* AudioSystem::getDSPEffect(std::string name)
//{
//    // Try and Find the DSP Effect
//    std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.find(name);
//    // If we didn't find it then return a null pointer
//    if (i == this->dspEffects.end())
//        return 0;
//    // Return the DSP Effect
//    return (IDSPEffect*)i->second;
//}
//
//void AudioSystem::removeDSPEffect(std::string name)
//{
//    // Try and Find the DSP Effect
//    std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.find(name);
//    // If we didn't find it then return a null pointer
//    if (i == this->dspEffects.end())
//        return;
//    // Grab the DSP Effect
//    IDSPEffect* pDSPEffect = (IDSPEffect*) i->second;
//    // Deactive the DSP Effect
//    pDSPEffect->deactivate();
//    // Destroy the DSP Effect
//    pDSPEffect->destroy();
//    // Remove the dspEffect from our Map
//    this->dspEffects.erase(i);
//    // Delete the DSPEffect
//    delete pDSPEffect;
//}
//
//void AudioSystem::enableDSPEffect(std::string name)
//{
//    // Try and Find the DSP Effect
//    std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.find(name);
//    // If we didn't find it then return a null pointer
//    if (i == this->dspEffects.end())
//        return;
//    // Grab the DSP Effect
//    IDSPEffect* pDSPEffect = (IDSPEffect*) i->second;
//    // Enable DSPEffect
//    pDSPEffect->activate();
//}
//
//void AudioSystem::disableDSPEffect(std::string name)
//{
//    // Try and Find the DSP Effect
//    std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.find(name);
//    // If we didn't find it then return a null pointer
//    if (i == this->dspEffects.end())
//        return;
//    // Grab the DSP Effect
//    IDSPEffect* pDSPEffect = (IDSPEffect*) i->second;
//    // Deactivate DSPEffect
//    pDSPEffect->deactivate();
//}
//
//void AudioSystem::freeDSPEffects()
//{
//    // Go through all the DSP Effects
//    for (std::map<std::string, IDSPEffect*>::iterator i = this->dspEffects.begin(); i != this->dspEffects.end(); i++)
//    {
//        // Grab the DSP Effect
//        IDSPEffect* pDSPEffect = (IDSPEffect*) i->second;
//        // Deactivate DSPEffect
//        pDSPEffect->deactivate();
//        // Destroy the DSP Effect
//        pDSPEffect->destroy();
//        // Delete DSP Effect
//        delete pDSPEffect;
//    }
//    // Empty DSPEffects Map
//    this->dspEffects.clear();
//}

const std::string& AudioSystem::getPluginPath() const
{
    // Return plugin path
    return this->pluginPath;
}

void AudioSystem::setPluginPath(const std::string& pluginPath)
{
    // Set the local plugin Path
    this->pluginPath = pluginPath;
    // Set the Plugin Path
    FMOD_System_SetPluginPath(FMODGlobals::pFMODSystem, pluginPath.c_str());
}

FMOD_REVERB_PROPERTIES AudioSystem::getGlobalReverbProperites()
{
    // Grab Properties
    FMOD_REVERB_PROPERTIES properties;
    FMOD_System_GetReverbProperties(FMODGlobals::pFMODSystem, 0, &properties);
    // Return Properties
    return properties;
}

void AudioSystem::setGlobalReverbProperties(FMOD_REVERB_PROPERTIES properties)
{
    // Set Global Reverb Properties (index 0 only)
    FMOD_System_SetReverbProperties(FMODGlobals::pFMODSystem, 0, &properties);
}

float AudioSystem::getMaxWorldSize()
{
    // return maxWorldSize
    return this->maxWorldSize;
}

void AudioSystem::setMaxWorldSize(float maxWorldSize)
{
    // Set local maxWorldSize
    this->maxWorldSize = maxWorldSize;
    FMOD_System_SetGeometrySettings(FMODGlobals::pFMODSystem, this->maxWorldSize);
}

std::string AudioSystem::getNetworkProxy()
{
    // Grab the Proxy Url
    char proxy[255] = {0};
    FMOD_System_GetNetworkProxy(FMODGlobals::pFMODSystem, proxy, 255);
    // Return proxy
    return std::string(proxy);
}

void AudioSystem::setNetworkProxy(std::string proxy)
{
    // Set Network Proxy
    FMOD_System_SetNetworkProxy(FMODGlobals::pFMODSystem, proxy.c_str());
}

int AudioSystem::getNetworkTimeOut()
{
    // Grab TimeOut
    int timeOut = 0;
    FMOD_System_GetNetworkTimeout(FMODGlobals::pFMODSystem, &timeOut);
    // Return TimeOut
    return timeOut;
}

void AudioSystem::setNetworkTimeOut(int timeOut)
{
    // Set Network Timeout
    FMOD_System_SetNetworkTimeout(FMODGlobals::pFMODSystem, timeOut);
}

void AudioSystem::setMemoryCallBacks(void* pPoolMemory, int poolLength, FMOD_MEMORY_ALLOC_CALLBACK pUserAllocCallBack, FMOD_MEMORY_REALLOC_CALLBACK pUserReallocCallBack, FMOD_MEMORY_FREE_CALLBACK pUserFree, FMOD_MEMORY_TYPE memmoryTypeFlags)
{
    /* Initialise memory pool and or memory management callbacks
        for implementing your own memory management stuff */
    FMOD_Memory_Initialize(pPoolMemory, poolLength, pUserAllocCallBack, pUserReallocCallBack, pUserFree, memmoryTypeFlags);
}

void AudioSystem::setDeviceListChangedCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_DEVICELISTCHANGED);
}

void AudioSystem::setDeviceLostCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_DEVICELOST);
}

void AudioSystem::setMemoryAllocationFailedCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_MEMORYALLOCATIONFAILED);
}

void AudioSystem::setThreadCreatedCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_THREADCREATED);
}

void AudioSystem::setBadDSPConnectionCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_BADDSPCONNECTION);
}

void AudioSystem::setPremixCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_PREMIX);
}

void AudioSystem::setPostmixCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_POSTMIX);
}

void AudioSystem::setErrorCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_ERROR);
}

void AudioSystem::setMidMixCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_MIDMIX);
}

void AudioSystem::setThreadDestroyedCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_THREADDESTROYED);
}

void AudioSystem::setPreupdateCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_PREUPDATE);
}

void AudioSystem::setPostupdateCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_POSTUPDATE);
}

void AudioSystem::setRecordListChangedCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_RECORDLISTCHANGED);
}

void AudioSystem::setAllCallBack(FMOD_SYSTEM_CALLBACK pCallBack)
{
    // Set CallBack
    FMOD_System_SetCallback(FMODGlobals::pFMODSystem, pCallBack, FMOD_SYSTEM_CALLBACK_ALL);
}

//void AudioSystem::bindToLua(lua_State* pLuaState)
//{
//    // TODO: More bindings
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<AudioSystem>("AudioSystem")
//        .def(luabind::constructor<>())
////        // REVERB
////        .def("reverbOff", (void(AudioSystem::*)()) &AudioSystem::reverbOff)
////        .def("reverbGeneric", (void(AudioSystem::*)()) &AudioSystem::reverbGeneric)
////        .def("reverbPaddedCell", (void(AudioSystem::*)()) &AudioSystem::reverbPaddedCell)
////        .def("reverbRoom", (void(AudioSystem::*)()) &AudioSystem::reverbRoom)
////        .def("reverbBathRoom", (void(AudioSystem::*)()) &AudioSystem::reverbBathRoom)
////        .def("reverbLivingRoom", (void(AudioSystem::*)()) &AudioSystem::reverbLivingRoom)
////        .def("reverbStoneRoom", (void(AudioSystem::*)()) &AudioSystem::reverbStoneRoom)
////        .def("reverbAuditorium", (void(AudioSystem::*)()) &AudioSystem::reverbAuditorium)
////        .def("reverbConcertHall", (void(AudioSystem::*)()) &AudioSystem::reverbConcertHall)
////        .def("reverbCave", (void(AudioSystem::*)()) &AudioSystem::reverbCave)
////        .def("reverbArena", (void(AudioSystem::*)()) &AudioSystem::reverbArena)
////        .def("reverbHanger", (void(AudioSystem::*)()) &AudioSystem::reverbHanger)
////        .def("reverbCarpetedHallway", (void(AudioSystem::*)()) &AudioSystem::reverbCarpetedHallway)
////        .def("reverbHallway", (void(AudioSystem::*)()) &AudioSystem::reverbHallway)
////        .def("reverbCorridor", (void(AudioSystem::*)()) &AudioSystem::reverbCorridor)
////        .def("reverbAlley", (void(AudioSystem::*)()) &AudioSystem::reverbAlley)
////        .def("reverbForest", (void(AudioSystem::*)()) &AudioSystem::reverbForest)
////        .def("reverbCity", (void(AudioSystem::*)()) &AudioSystem::reverbCity)
////        .def("reverbMountains", (void(AudioSystem::*)()) &AudioSystem::reverbMountains)
////        .def("reverbQuarry", (void(AudioSystem::*)()) &AudioSystem::reverbQuarry)
////        .def("reverbPlain", (void(AudioSystem::*)()) &AudioSystem::reverbPlain)
////        .def("reverbParkingLot", (void(AudioSystem::*)()) &AudioSystem::reverbParkingLot)
////        .def("reverbSewerPipe", (void(AudioSystem::*)()) &AudioSystem::reverbSewerPipe)
////        .def("reverbUnderWater", (void(AudioSystem::*)()) &AudioSystem::reverbUnderWater)
////        .def("reverbDrugged", (void(AudioSystem::*)()) &AudioSystem::reverbDrugged)
////        .def("reverbDizzy", (void(AudioSystem::*)()) &AudioSystem::reverbDizzy)
////        .def("reverbPsychotic", (void(AudioSystem::*)()) &AudioSystem::reverbPsychotic)
//    ];
//}
