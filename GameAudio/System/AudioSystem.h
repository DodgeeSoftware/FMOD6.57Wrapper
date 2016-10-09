/**
  * @file   AudioSystem.h
  * @Author Sergeant Neipo (sergeant.neipo@gmail.com)
  * @date   August, 2016
  * @brief  AudioSystem is a simple wrapper around the FMOD Audio System
  * and provides basic services like initialisation, shutdown, update
  * pause, resume, volume, DSP Effect management and listener position
*/

#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

// C++ Includes
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>

// FMOD Includes
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>

//// LUA AND LUABIND Includes
//extern "C"
//{
//    #include <lua.h>
//    #include <lualib.h>
//    #include <lauxlib.h>
//}
//#include <luabind/luabind.hpp>

// GAMEAUDIO Includes
#include "FMODGlobals.h"
#include "SoundSample.h"
#include "Sound.h"
#include "Sound2D.h"
#include "Sound3D.h"
#include "Stream.h"
#include "Stream2D.h"
#include "Stream3D.h"
#include "Music.h"
//#include "IDSPEffect.h"

/** The AudioSystem class intialises and shutdowns the audio system along with
    setting important things like volume, balance, allowing you to mute audio,
    get important information about the driver, record audio, play cds and
    add DSP (Digital Signal Processing) to the Audio Pipeline (for effects like
    echo) **/
class AudioSystem
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default constructor
        AudioSystem();
        //! Destructor
        virtual ~AudioSystem();

    protected:
        //! Copy constructor
        AudioSystem(const AudioSystem& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // Methods and members

    protected:
        //! Assignment operator
        AudioSystem& operator=(const AudioSystem& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief Start the audiosystem
          * @param maxChannels the maximum number of channels for the audio system
          * to use **/
        virtual bool init(int maxChannels);
        /** @brief Think **/
        virtual void think();
        /** @brief Advance to the next audio frame **/
        virtual void update();
        /** @brief shutdown **/
        virtual void shutdown();

    public:
        /** @brief Pause the audiosystem **/
        virtual void pause();
        /** @brief Resume the audiosystem **/
        virtual void resume();
        /** @brief Start the audiosystem **/
        virtual void start();
        /** @brief Stop the audiosystem **/
        virtual void stop();

    protected:
        // pausedFlag
        bool pausedFlag;
        // MaxSoftwareChannels
        int maxSoftwareChannels;

    // ****************************************
    // * DEBUG VERSION ONLY FUNCTIONS (fmodL) *
    // ****************************************
    public:
        /** @brief debugInit
          * @param flags see FMOD_DEBUG_FLAGS for valid flags to use. Should be concatenated with the | operator
          * @param mode see FMOD_DEBUG_MODE for valid flags to use. Should be concatenated with the | operator
          * @param pCallBack a function which matches the signature FMOD_DEBUG_CALLBACK
          * @param filename ony used when our mode is set to file **/
        virtual void debugInit(FMOD_DEBUG_FLAGS flags, FMOD_DEBUG_MODE mode, FMOD_DEBUG_CALLBACK pCallBack, const char *filename);

    protected:
        // methods and members

    // *******************
    // * SETUP FUNCTIONS *
    // *******************
    public:
        /** @brief get the version information
          * @return the version **/
        virtual unsigned int getVersion();
        /** @brief getOutputHandle
          * Retrieves a pointer to the system level output device module.
          * This means a pointer to a DirectX "LPDIRECTSOUND", or a WINMM handle,
          * or with something like with FMOD_OUTPUTTYPE_NOSOUND output, the handle will be null or 0. **/
        virtual void* getOutputHandle();
        /** @brief getTotalSampleBytesRead
          * @return the total bytes read from file for loading sample data **/
        virtual long long getTotalSampleBytesRead();
        /** @brief getTotalStreamBytesRead
          * @return the total bytes read from file for streaming sounds **/
        virtual long long getTotalStreamBytesRead();
        /** @brief getTotalOtherBytesRead
          * @return the total bytes read for non-audio data such as FMOD Studio banks **/
        virtual long long getTotalOtherBytesRead();
        /** @brief getCurrentAllocatedRam
          * @return the currently allocated sound ram memory at time of call **/
        virtual int getCurrentAllocatedRam();
        /** @brief getMaxAllocatableRam
          * @return the maximum allocated sound ram memory since System::init **/
        virtual int getMaxAllocatableRam();
        /** @brief getTotalRamOnDevice
          * @return  total amount of sound ram available on this device **/
        virtual int getTotalRamOnDevice();
        /* NOTE: Although this function is available
            it seems to duplicate the functionality of
            FMOD_System_GetSoundRAM. For this reason I
            haven't implemented it */
        // FMOD_RESULT F_API FMOD_Memory_GetStats             (int *currentalloced, int *maxalloced, FMOD_BOOL blocking);
        /** @brief How much processing power the DSP is using
          * @return DSP Usage **/
        virtual float getDSPUsage();
        /** @brief How much processing power Streaming is using
          * @return Stream Usage **/
        virtual float getStreamUsage();
        /** @brief How much processing power Geomtery is using
          * @return Geomtery Usage **/
        virtual float getGeomteryUsage();
        /** @brief How much processing power System::update is using
          * @return System::update Usage **/
        virtual float getUpdateUsage();
        /** @brief How much processing power is audio taking
          * @return CPU Usage **/
        virtual float getCPUUsage();
        /** @brief Get how many channels are currently playing
          * @return number of channels in use **/
        virtual int getChannelsPlaying();
        /** @brief Get Output
          * @return Output output mode for the platform (DSound, Pulse, XAudio, WinMM etc **/
        virtual int getOutput();
        /** @brief Set Output This function selects the output mode for the platform. This is for selecting different OS specific APIs which might have different features.
          * @param output See FMOD_OUTPUTTYPE for more info, default is FMOD_OUTPUTTYPE_AUTODETECT **/
        virtual void setOutput(int output);
        /** @brief Get Num Drivers
          * @return numDrivers **/
        virtual int getNumDrivers();
        /* Not going to Wrap these functions they relate to choosing
            which SoundDriver / Card to use and the default will do */
        //FMOD_RESULT F_API FMOD_System_GetDriverInfo             (FMOD_SYSTEM *system, int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels);
        //FMOD_RESULT F_API FMOD_System_SetDriver                 (FMOD_SYSTEM *system, int driver);
        //FMOD_RESULT F_API FMOD_System_GetDriver                 (FMOD_SYSTEM *system, int *driver);
        /** @brief Get Max Software Channels
          * @return softwareChannels Get the maximum number of software mixed channels possible. **/
        virtual int getMaxSoftwareChannel();
        /** @brief Set Max Software Channels
          * @param softwareChannels Sets the maximum number of software mixed channels possible. **/
        virtual void setMaxSoftwareChannels(int maxSoftwareChannels);
        /* Not going to Wrap these they are unnecessary */
        //FMOD_RESULT F_API FMOD_System_SetSoftwareFormat         (FMOD_SYSTEM *system, int samplerate, FMOD_SPEAKERMODE speakermode, int numrawspeakers);
        //FMOD_RESULT F_API FMOD_System_GetSoftwareFormat         (FMOD_SYSTEM *system, int *samplerate, FMOD_SPEAKERMODE *speakermode, int *numrawspeakers);
        /** @brief Get DSP Buffer Size
          * @return The mixer engine block size in samples. (Default 1024) **/
        virtual unsigned int getDSPBufferSize();
        /** @brief Get DSP Buffer Number of Buffers (Default 4)
          * @return Get DSP Number Buffers **/
        virtual int getDSPNumberBuffers();
        /** @brief Set DSP Buffer Size
          * @param bufferLength the mixer engine block size in samples (Default 1024)
          * @param numBuffers The Number of Buffers used by the mixer for DSP **/
        virtual void setDSPBufferSize(unsigned int bufferLength, int numBuffers);
        /** @brief Set FileSystem
          * @param pUserOpen a function with the signature FMOD_FILE_OPEN_CALLBACK
          * @param pUserClose a function with the signature FMOD_FILE_CLOSE_CALLBACK
          * @param pUserRead a function with the signature FMOD_FILE_READ_CALLBACK
          * @param pUserSeek a function with the signature FMOD_FILE_SEEK_CALLBACK
          * @param pUserSyncRead a function with the signature FMOD_FILE_ASYNCREAD_CALLBACK
          * @param pUserSyncCancel a function with the signature FMOD_FILE_ASYNCCANCEL_CALLBACK
          * @param blockAlign Internal minimum file block alignment. FMOD will read data in at least chunks of this size if you ask it to. Specifying 0 means there is no file buffering at all  **/
        virtual void setFileSystem(FMOD_FILE_OPEN_CALLBACK pUserOpen,
                                   FMOD_FILE_CLOSE_CALLBACK pUserClose,
                                   FMOD_FILE_READ_CALLBACK pUserRead,
                                   FMOD_FILE_SEEK_CALLBACK pUserSeek,
                                   FMOD_FILE_ASYNCREAD_CALLBACK pUserSyncRead,
                                   FMOD_FILE_ASYNCCANCEL_CALLBACK pUserSyncCancel,
                                   int blockAlign);
        /** @brief Attach FileSystem
          * @param pUserOpen a function with the signature FMOD_FILE_OPEN_CALLBACK
          * @param pUserClose a function with the signature FMOD_FILE_CLOSE_CALLBACK
          * @param pUserRead a function with the signature FMOD_FILE_READ_CALLBACK
          * @param pUserSeek a function with the signature FMOD_FILE_SEEK_CALLBACK
          * @param pUserSyncRead a function with the signature FMOD_FILE_ASYNCREAD_CALLBACK
          * @param pUserSyncCancel a function with the signature FMOD_FILE_ASYNCCANCEL_CALLBACK
          * @param blockAlign Internal minimum file block alignment. FMOD will read data in at least chunks of this size if you ask it to. Specifying 0 means there is no file buffering at all  **/
        virtual void attachFileSystem(FMOD_FILE_OPEN_CALLBACK pUserOpen,
                                   FMOD_FILE_CLOSE_CALLBACK pUserClose,
                                   FMOD_FILE_READ_CALLBACK pUserRead,
                                   FMOD_FILE_SEEK_CALLBACK pUserSeek);
        /* NOTE: Do NOT use this function with MINGW. MINGW doesn't support threading */
        /** @brief Get Disk Busy
          * @return 0 if Disk isn't busy 1 if Disk is Busy **/
        virtual int getDiskBusy();
        /* NOTE: Do NOT use this function with MINGW. MINGW doesn't support threading */
        /** @brief Set Disk Busy, Mutex function to synchronize user file reads with FMOD's file reads. This function tells fmod that you are using the disk so that it will block until you are finished with it.
          * This function also blocks if FMOD is already using the disk, so that you cannot do a read at the same time FMOD is reading.
          * @param busy 0 to set disk as not busy 1 to set disk as busy **/
        virtual void setDiskBusy(int busy);
        /* Not going to wrap these they are unimportant for my purposes anyway */
        //FMOD_RESULT F_API FMOD_System_SetAdvancedSettings       (FMOD_SYSTEM *system, FMOD_ADVANCEDSETTINGS *settings);
        //FMOD_RESULT F_API FMOD_System_GetAdvancedSettings       (FMOD_SYSTEM *system, FMOD_ADVANCEDSETTINGS *settings);
        /** @brief Get File Stream Buffer Size
          * @return size of the FileBuffer in units**/
        virtual unsigned int getFileStreamBufferSize();
        /** @brief Get the Type of Unit for the System
          * @return the Type of Unit our file stream will grab PCM, PCMByte, Etc see FMOD_TIMEUNIT for more info **/
        virtual int getFileStreamBufferUnitType();
        /** @brief Set File Stream Buffer Size
          * @param fileBufferSize a measure in units
          * @param fileBufferSizeType is the type of unit see FMOD_TIMEUNIT for more info **/
        virtual void setFileStreammBufferSize(unsigned int fileBufferSize, int fileBufferSizeType);

    protected:
        // members and methods

    // ********************
    // * PLUGIN FUNCTIONS *
    // ********************
    public:
        /** @brief Get the Plugin Path
          * @return the plugin path **/
        virtual const std::string& getPluginPath() const;
        /** @brief Set the plugin Path
          * @param pluginPath the path to the plugin **/
        virtual void setPluginPath(const std::string& pluginPath);
        /** @brief Get Number Plugins
          * @param pluginType see FMOD_PLUGINTYPE for more info
          * @return number of plugins of the type loaded **/
        virtual int getNumPlugins(FMOD_PLUGINTYPE pluginType);
        /** @brief getOutputPluginhandle
          * @return handle to the current output plugin in use **/
        virtual unsigned int getOutputPluginHandle();
        /** @brief setOutput By Plugin Handle
          * where a plugin is an output type we can activate it
          * with this function **/
        virtual void setOutputByPlugin(unsigned int handle);

    protected:
        // plugin Path
        std::string pluginPath;

    // ******************************
    // * POSITIONAL AUDIO FUNCTIONS *
    // ******************************
    /* NOTE: I don't recommend making the listerner a
        part of the camera tempting as though that might be.
        The reason is its better to set the listener to the
        camera position in your game scape, this makes
        your camera reusable */
    public:
        /** @brief get ListernerX
          * @return Listerner X **/
        virtual float getListenerX();
        /** @brief get ListernerY
          * @return Listerner Y **/
        virtual float getListenerY();
        /** @brief get ListernerZ
          * @return Listerner Z **/
        virtual float getListenerZ();
        /** @brief Set the listeners position
          * @param positionX x position of the listener
          * @param positionY y position of the listener **/
        virtual void setListenerPosition(float positionX, float positionY);
        /** @brief Set the listeners position
          * @param positionX x position of the listener
          * @param positionY y position of the listener
          * @param positionZ z position of the listener **/
        virtual void setListenerPosition(float x, float y, float z);
        /** @brief getListenerUpVectorX
          * @return x part of the Listenerup vector **/
        virtual float getListenerUpVectorX();
        /** @brief getListenerUpVectorY
          * @return y part of the Listener up vector **/
        virtual float getListenerUpVectorY();
        /** @brief getListenerUpVectorZ
          * @return z part of the Listener up vector **/
        virtual float getListenerUpVectorZ();
        /** @brief setListenerUpVector
          * @param xUp x part of the Listener up vector
          * @param yUp y part of the Listener up vector **/
        virtual void setListenerUpVector(float xUp, float yUp);
        /** @brief setListenerUpVector
          * @param upX x part of the Listener up vector
          * @param upY y part of the Listener up vector
          * @param upZ z part of the Listener up vector **/
        virtual void setListenerUpVector(float upX, float upY, float upZ);
        /** @brief getListenerForwardVectorX
          * @return x part of the Listener Forward vector **/
        virtual float getListenerForwardVectorX();
        /** @brief getListenerForwardVectorY
          * @return y part of the Listener Forward vector **/
        virtual float getListenerForwardVectorY();
        /** @brief getListenerForwardVectorZ
          * @return z part of the Listener Forward vector **/
        virtual float getListenerForwardVectorZ();
        /** @brief setListenerForwardVector
          * @param forwardX x part of the Listener Forward vector
          * @param forwardY y part of the Listener Forward vector **/
        virtual void setListenerForwardVector(float forwardX, float forwardY);
        /** @brief setListenerForwardVector
          * @param forwardX x part of the Forward vector
          * @param forwardY y part of the Forward vector
          * @param forwardZ z part of the Forward vector **/
        virtual void setListenerForwardVector(float forwardX, float forwardY, float forwardZ);
        /** @brief get ListernerXVelocity
          * @return Listerner X Velocity**/
        virtual float getListenerXVelocity();
        /** @brief get ListernerYVelocity
          * @return Listerner YVelocity **/
        virtual float getListenerYVelocity();
        /** @brief get ListernerZVelocity
          * @return Listerner Z Velocity **/
        virtual float getListenerZVelocity();
        /** @brief Set the listeners Velocity
          * @param x x Velocity of the listener
          * @param y y Velocity of the listener **/
        virtual void setListenerVelocity(float velocityX, float velocityY);
        /** @brief Set the listeners Velocity
          * @param velocityX x Velocity of the listener
          * @param velocityY y Velocity of the listener
          * @param velocityZ z Velocity of the listener **/
        virtual void setListenerVelocity(float velocityX, float velocityY, float velocityZ);

    public:
        /* Not necessary to implement these functions*/
        //FMOD_RESULT F_API FMOD_System_SetSpeakerPosition        (FMOD_SYSTEM *system, FMOD_SPEAKER speaker, float x, float y, FMOD_BOOL active);
        //FMOD_RESULT F_API FMOD_System_GetSpeakerPosition        (FMOD_SYSTEM *system, FMOD_SPEAKER speaker, float *x, float *y, FMOD_BOOL *active);
        /** @brief Get the Doppler Scale
            @return the Doppler Scale **/
        virtual float getDopplerScale();
        /** @brief Get the Distance Factor
            @return the Doppler Scale **/
        virtual float getDistanceFactor();
        /** @brief Get the RollOffScale
            @return the Roll Off Scale **/
        virtual float getRollOffScale();
        /** @brief Set the 3DSettings
          * @param dopplerScale Doppler Scale
          * @param distanceFactor DistanceFactor
          * @param rollOffScale **/
        virtual void set3DSettings(float dopplerScale, float distanceFactor, float rollOffScale);
        /** @brief Set the RollOffCallBack
          * @param pCallback a callback function with the signature FMOD_3D_ROLLOFF_CALLBACK **/
        virtual void setRollOffCallBack(FMOD_3D_ROLLOFF_CALLBACK pCallBack);
        /** @brief Get Number of Listeners
          * @return The number of Listeners **/
        virtual int getNumberOfListeners();
        /** @brief Set Number of Listeners
          * @param numListeners Number f Listeners **/
        virtual void setNumberOfListeners(int numListeners);
        /* Don't need to implmement these functions */
        //FMOD_RESULT F_API FMOD_System_GetDefaultMixMatrix       (FMOD_SYSTEM *system, FMOD_SPEAKERMODE sourcespeakermode, FMOD_SPEAKERMODE targetspeakermode, float *matrix, int matrixhop);
        //FMOD_RESULT F_API FMOD_System_GetSpeakerModeChannels    (FMOD_SYSTEM *system, FMOD_SPEAKERMODE mode, int *channels);
        /** @brief getGeometryOcclusionDirect
          * It is essentially what 'raycasting' is to physics
          * in that it tells you direct occclusion as a percentage
          * and reverb occlusion as a percentage
          * @param xStart horizontal start position
          * @param yStart vertical start position
          * @param zStart depth start position
          * @param xFinish horizontal start position
          * @param yFinish vertical start position
          * @param zFinish depth start position  **/
        virtual float getGeometryOcclusionDirect(float xStart, float yStart, float zStart, float xFinish, float yFinish, float zFinish);
        /** @brief getGeometryOcclusionReverb
          * It is essentially what 'raycasting' is to physics
          * in that it tells you direct occclusion as a percentage
          * and reverb occlusion as a percentage
          * @param xStart horizontal start position
          * @param yStart vertical start position
          * @param zStart depth start position
          * @param xFinish horizontal start position
          * @param yFinish vertical start position
          * @param zFinish depth start position  **/
          virtual float getGeometryOcclusionReverb(float xStart, float yStart, float zStart, float xFinish, float yFinish, float zFinish);

    protected:
        // methods and members

    // **********
    // * VOLUME *
    // **********
    public:
        /** @brief Get the sound effects volume
          * @return Sound Effects Volume  in range 0.0 - 1.0 **/
        virtual float getSoundEffectsVolume();
        /** @brief Set the sound effects volume
          * @param volume in range 0 - 1.0 **/
        virtual void setSoundEffectsVolume(float volume);
        /** @brief Get the music volume
          * @return volume in range 0.0 - 1.0 **/
        virtual float getMusicVolume();
        /** @brief Set the music volume
          * @param volume In range 0.0 - 1.0 **/
        virtual void setMusicVolume(float volume);
        /** @brief Get the Balance
          * @return the balance (-1.0 left 0.0 middle 1.0 right) **/
        virtual float getBalance();
        /** @brief Set the Stereo Balance
          * @param value -1.0 for full left pan, 0.0 for centre and 1.0 for full right **/
        virtual void setBalance(float balance);
        /** @brief Is the AudioSystem muted
          * @return true if mute otherwise false **/
        virtual bool isMute() { return this->muteFlag; }
        /** @brief Set MuteState for the AudioSystem
          * @param state true to mute, false to unmute **/
        virtual void setMute(bool state);
        /** @brief Mute the AudioSystem **/
        virtual void mute();
        /** @brief Unmute the AudioSystem **/
        virtual void unmute();

    protected:
        // Sound Effects Volume
        int soundEffectsVolume;
        // Music Volume
        int musicVolume;
        // balance
        float balance;
        // Mute Flag
        bool muteFlag;

    // *************
    // * RECORDING *
    // *************
    /* NOTE: I am not implementing these. Entirely unnecessary for simple game audio */
    public:
        /** @brief getNumberOfDrivers
          * Retrieves the number of recording devices available for this output mode. Use this to enumerate all recording devices possible so that the user can select one.
          * @return **/
        virtual int getNumberOfDrivers();
        /** @brief getNumberOfConnectedRecordingDevices
          * @return numberOfConnectedRecordingDevices **/
        virtual int getNumberOfConnectedRecordingDevices();
        // We don't need these
        //FMOD_RESULT F_API FMOD_System_GetRecordDriverInfo       (FMOD_SYSTEM *system, int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels, FMOD_DRIVER_STATE *state);
        //FMOD_RESULT F_API FMOD_System_GetRecordPosition         (FMOD_SYSTEM *system, int id, unsigned int *position);
        //FMOD_RESULT F_API FMOD_System_RecordStart               (FMOD_SYSTEM *system, int id, FMOD_SOUND *sound, FMOD_BOOL loop);
        //FMOD_RESULT F_API FMOD_System_RecordStop                (FMOD_SYSTEM *system, int id);
        /** @brief isRecording
          * @return true if the device is busy false otherwise **/
        virtual bool isRecording(int index);

    protected:
        // members and methods

    // ********************
    // * REVERB FUNCTIONS *
    // ********************
    /* NOTE: I did a hack job here mainly because I only need one gloabl Reverb hence I only use instance 1 (out of 4)*/
    public:
        /** @brief Get Global Reverb Properties
          * @return as FMOD_REVERB_PROPERTIES (for instance 0 only) **/
        virtual FMOD_REVERB_PROPERTIES getGlobalReverbProperites();
        /** @brief Set Global Reverb Properties (for instance 0 only)
          * @param properties and instance of FMOD_REVERB_PROPERTIES can
          * be a preset from FMOD_Common.h **/
        virtual void setGlobalReverbProperties(FMOD_REVERB_PROPERTIES properties);

    protected:
        // methods and members

    // *******************
    // * WORLD FUNCTIONS *
    // *******************
    public:
        /** @brief getMaxWorldSize
          * @return Maximum World Size  of the world **/
        virtual float getMaxWorldSize();
        /** @brief setMaxWorldSize
          * @param maxWorldSize the maximum size of the world in unity **/
        virtual void setMaxWorldSize(float maxWorldSize);

    protected:
        // maxWorldSize
        float maxWorldSize;

    // ************************
    // * NETWORKING FUNCTIONS *
    // ************************
    public:
        /** @brief Get Network Proxy,
          * @return return the url for the proxy server used when streaming **/
        virtual std::string getNetworkProxy();
        /** @brief Set Network Proxy
          * @param proxy The name of a proxy server encoded as a UTF-8 string in host:port format e.g. www.fmod.org:8888 (defaults to port 80 if no port is specified). **/
        virtual void setNetworkProxy(std::string proxy);
        /** @brief Get Network TimeOut
          * @return network TimeOut in miliseconds **/
        virtual int getNetworkTimeOut();
        /** @brief Set Network TimeOut
          * @param timeOut time out in milliseconds **/
        virtual void setNetworkTimeOut(int timeOut);

    protected:
        // methods and members

    // **********************
    // * CALLBACK FUNCTIONS *
    // **********************
    public:
        /** @brief setMemoryCallBacks
          * @param pPoolMemory If you want a fixed block of memory for FMOD to use, pass it in here. Specify the length in poollen. Specifying NULL doesn't use internal management and it relies on callbacks.
          * @param poolLength Length in bytes of the pool of memory for FMOD to use specified in poolmem. Specifying 0 turns off internal memory management and relies purely on callbacks. Length must be a multiple of 512
          * @param pUserAllocCallBack Only supported if pool is NULL. Otherwise it overrides the FMOD internal calls to alloc. Compatible with ansi malloc()
          * @param pUserReallocCallBack Only supported if pool is NULL. Otherwise it overrides the FMOD internal calls to realloc. Compatible with ansi realloc()
          * @param pUserFree Only supported if pool is NULL. Otherwise it overrides the FMOD internal calls to free. Compatible with ansi free()
          * @param memtypeflags FMOD_MEMORY_TYPE flags you wish to receive through your memory callbacks. See FMOD_MEMORY_TYPE. Bitwise OR these together for multiple types **/
        virtual void setMemoryCallBacks(void* pPoolMemory, int poolLength, FMOD_MEMORY_ALLOC_CALLBACK pUserAllocCallBack, FMOD_MEMORY_REALLOC_CALLBACK pUserReallocCallBack, FMOD_MEMORY_FREE_CALLBACK pUserFree, FMOD_MEMORY_TYPE memmoryTypeFlags);
        /** @brief Set Device List Changed CallBack is a callback
          * called from the FMOD_SYSTEM's update function and fired
          * when the enumerated list of devices has changes
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setDeviceListChangedCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Device Lost CallBack is a callback
          * called from the FMOD_SYSTEM's update function and fired
          * when an output device is lost due to control parameters
          * changing and FMOD cannot automatically recover
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setDeviceLostCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Memory Allocation Failed CallBack
          * Called directly when a memory allocation fails somewhere in FMOD. (NOTE - 'system' will be NULL in this callback type.)
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setMemoryAllocationFailedCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Thread CreatedCallBack
          * Called directly when a thread is created.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setThreadCreatedCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Bad DSP Connection Callback
          * Called when a bad connection was made with DSP::addInput. Usually called from mixer thread because that is where the connections are made.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setBadDSPConnectionCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Premix CallBack
          * Called each tick before a mix update happens.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setPremixCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Postmix Callback
          * Called each tick after a mix update happens.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setPostmixCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set ErrorCallBack
          * Called when each API function returns an error code, including delayed async functions.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setErrorCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set MidMix CallBack
          * Called each tick in mix update after clocks have been updated before the main mix occurs.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setMidMixCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Thred Destroyed CallBack
          * Called directly when a thread is destroyed.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setThreadDestroyedCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Preupdate Callback
          * Called at start of System::update function.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setPreupdateCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Postupdate CallBack
          * Called at end of System::update function.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setPostupdateCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set Record List Changed CallBack
          * Called from System::update when the enumerated list of recording devices has changed.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setRecordListChangedCallBack(FMOD_SYSTEM_CALLBACK pCallback);
        /** @brief Set All CallBack
          * Pass this mask to System::setCallback to receive all callback types.
          * @param pCallback a function callback with the signature
          * FMOD_RESULT (F_CALLBACK *FMOD_SYSTEM_CALLBACK)(FMOD_SYSTEM *system, FMOD_SYSTEM_CALLBACK_TYPE type, void *commanddata1, void *commanddata2, void *userdata); **/
        virtual void setAllCallBack(FMOD_SYSTEM_CALLBACK pCallback);

    protected:
        // Members and methods

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);

};

#endif // AUDIOSYSTEM_H
