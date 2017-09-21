#ifndef RECORDING_H
#define RECORDING_H

// C++ Includes
#include <iostream>

// FMOD Includes
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>

//// LUA Includes
//extern "C"
//{
//    #include <lua.h>
//    #include <lualib.h>
//    #include <lauxlib.h>
//}
//// LUABIND Includes
//#include <luabind/luabind.hpp>
//#include <luabind/operator.hpp>

// GAMEAUDIO Includes
#include "FMODGlobals.h"
#include "Channel/Channel.h"

/** @class Recording
  * @brief Use to record and playback recorded audio
  * @detail Description The Recording is a wrapper around an FMOD_CHANNEL an FMOD_SOUND,
    along with recording and playback functions **/
class Recording : public Channel
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        Recording();
        //! Destructor
        virtual ~Recording();

    protected:
        //! Copy Constructor
        Recording(Recording& other);

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Recording Assignment operator
        Recording& operator=(const Recording& other) { return *this; }

    // ***********************
    // * RECORDING FUNCTIONS *
    // ***********************
    public:
        /** @brief create
          * Create the FMOD_SOUND for recording
          * @param size of the audio in seconds
          * @return true on success otherwise false **/
        virtual bool create(float seconds);
        /** @brief think **/
        virtual void think();
        /** @brief update
          * @param dTime difference between this frame and the last **/
        virtual void update(float dTime);
        /** @brief Play Stream **/
        virtual void play();
        /** @bief Play StreamEx (stream starts paused) **/
        virtual void playEx();
        /** @brief release Recording **/
        virtual void release();
        /** @brief getRecordingDeviceID
          * @return recordingDeviceID **/
        virtual int getRecordingDeviceID();
        /** @brief setRecordingDevice
          * @param id id for the recording device**/
        virtual void setRecordingDeviceID(int id);
        /** @brief startRecording
          * Starts the recording of the FMOD_SOUND
          * @param index a number from between 0 and the number of conected **/
        virtual void startRecording();
        /** @brief stopRecording
          * stops the recording of the FMOD_SOUND
          * @param index a number from between 0 and the number of conected devices **/
        virtual void stopRecording();
        /** @brief isRecording
          * @param index a number from between 0 and the number of conected devices
          * @return tue if recording false otherwise **/
        virtual bool isRecording();
        /** @brief getRecordPosition
          * @param index a number from between 0 and the number of conected devices
          * @return Retrieves the current recording position of the record buffer in PCM samples **/
        virtual unsigned int getRecordPosition();

    protected:
        // Recording Device ID
        int deviceID;

    // ***********************************
    // * RECORDING DRIVER INFO FUNCTIONS *
    // ***********************************
    public:
        /** @brief getDeviceName
          * recording devices
          * @return the name of the device corresponding to index**/
        virtual std::string getDeviceName();
        /** @brief getDeviceGUID
          * @return the FMOD_GUID for the device corresponding to index**/
        virtual FMOD_GUID* getDeviceGUID();
        /** @brief getSystemRate
          * @return the rate the device will record in **/
        virtual int getSystemRate();
        /** @brief getSpeakerMode
          * @return FMOD_SPEAKERMODE speaker mode **/
        virtual FMOD_SPEAKERMODE getSpeakerMode();
        /** @brief getSpeakerModeChannels
          * @return number of channels in the speaker setup for the driver at index **/
        virtual int getSpeakerModeChannels();
        /** @brief getDriverState
          * @return The Driver State for the driver at index **/
        virtual FMOD_DRIVER_STATE getDriverState();

    protected:
        // Memthods and members

    // ******************************
    // * FMOD SOUNDSTREAM FUNCTIONS *
    // ******************************
    public:
        /** @brief Get the FMODSound (aquired from load method)
          * @return pointer the the FMOD_SOUND **/
        virtual FMOD_SOUND* getFMODSound() { return this->pFMODSound; }

    protected:
        // A pointer to the FMOD_SOUND
        FMOD_SOUND* pFMODSound;

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // RECORDING_H
