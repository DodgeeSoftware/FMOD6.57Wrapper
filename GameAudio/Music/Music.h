/**
  * @file   Music.h
  * @Author Sergeant Neipo (sergeant.neipo@gmail.com)
  * @date   August, 2016
  * @brief  Music streams a tracker file (xm, s3m, it, mod) from disk
*/

#ifndef MUSIC_H
#define MUSIC_H

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

// GAMEAUDIO Includes
#include "FMODGlobals.h"

/** @class Music
    @brief The Music class is a container around a Music Module (tracker music)
    @detail Tracker music is 8bit - 16bit music and is usually in the format xm,
    s3m, mod, it etc **/
class Music
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        Music();
        //! Destructor
        virtual ~Music();

    protected:
        //! Copy constructor
        Music(const Music& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Music Assignment operator
        Music& operator=(const Music& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief Load a song
          * @param filename the location of the tracker file to load**/
        virtual bool load(std::string filename);
        /** @brief Think **/
        virtual void think();
        /** @brief Update
          * @param dTime difference between last frame and this one **/
        virtual void update(float dTime);
        /** @brief Clear the song **/
        virtual void clear();
        /** @brief Free the song **/
        virtual void free();

    public:
        /** @brief Play Stream **/
        virtual void play();
        /** @bief Play StreamEx (stream starts paused) **/
        virtual void playEx();
        /** @brief Start **/
        virtual void start();
        /** @brief Stop Stream **/
        virtual void stop();
        /** @brief Reset Stream **/
        virtual void reset();
        /** @brief Is Paused?
          * @return true if paused false otherwise **/
        virtual bool isPaused();
        /** @brief Set Paused
          * @param true to pause, false to resume **/
        virtual void setPaused(bool pausedFlag);
        /** @brief Pause Sound Playback **/
        virtual void pause();
        /** @brief Resume Sound Playback **/
        virtual void resume();
        /** @brief Is this sound still playing?
          * @return true if stream is playing false otherwise **/
        virtual bool isPlaying();

    protected:
        // methods and members

    // *********************
    // * CHANNEL FUNCTIONS *
    // *********************
    public:
        /** @brief Get system object
          * @return FMOD_SYSTEM **/
        virtual FMOD_SYSTEM* getSystemObject();
        /** @brief Get Volume
          * @return volume (0.0 silent 1.0 fullblast) **/
        virtual float getVolume();
        /** @brief Set Volume
          * @param volume (0.0 silent 1.0 fullblast) **/
        virtual void setVolume(float volume);
        /** @brief is volume ramping enabled?
          * @return state true if enabled, false otherwise **/
        virtual bool isVolumeRamping();
        /** @brief set volume ramp
          * @param volumeRampFlag true to turn on false to turn off **/
        virtual void setVolumeRamping(bool volumeRampFlag);
        /** @brief Get the Pitch of the Sound (0.5 half pitch, 2.0 double pitch, 1.0 default pitch)
          * @return the pitch of the sound **/
        virtual float getPitch();
        /** @brief Set the Pitch of the sound (0.5 half pitch, 2.0 double pitch, 1.0 default pitch)
          * @param **/
        virtual void setPitch(float pitch);
        /** @brief Is mute?
          * @return true if mute false otherwise **/
        virtual bool isMute();
        /** @brief Set Mute for this sound
          * @param muteFlag true to mute false to unmute **/
        virtual void setMute(bool muteFlag);
        /** @brief Mute this sound **/
        virtual void mute();
        /** @brief Unmute this sound **/
        virtual void unmute();
        /** @brief getReverbWet
          * Gets the wet level (or send level) of a particular reverb instance for the Channel
          * @param instance Index of the particular reverb instance to target, from 0 to 3.
          * @return Wettness of a reverb instance for the channel **/
        virtual float getReverbWet(int instance);
        /** @brief setReverbWet
          * @param instance Index of the particular reverb instance to target, from 0 to 3.
          * @param Wettness of a reverb instance for the channel **/
        virtual void setReverbWet(int instance, float wet);
        /** @brief Get Low Pass Gain
          * @return LowPass Gain**/
        virtual float getLowPassGain();
        /** @brief Set Low Pass Gain
          * @param lowPassGain low pass gain (default is 1.0f) **/
        virtual void setLowPassGain(float lowPassGain);
        /** @brief Get Mode
          * @return mode see FMOD_MODE for documentation on values. Values are contatinated with | operator **/
        virtual unsigned int getMode();
        /** @brief Set Mode
          * @param mode see FMOD_MODE for documentation on values. Should be contatinated with | operator **/
        virtual void setMode(unsigned int mode);
        /** @brief Set Control Callback
          * @param callback of signature FMOD_CHANNELCONTROL_CALLBACK (see fmod documentation) **/
        virtual void setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack);
        /** @brief Get balance
          * @return balance (-1.0 full left 1.0 full right) **/
        virtual float getBalance();
        /** @brief Set Balance (Pan)
          * @param pan (-1.0 full left 1.0 full right) **/
        virtual void setBalance(float balance);
        //// Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsOutput       (FMOD_CHANNEL *channel, float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright);
        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsInput        (FMOD_CHANNEL *channel, float *levels, int numlevels);
        //FMOD_RESULT F_API FMOD_Channel_SetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int outchannels, int inchannels, int inchannel_hop);
        //FMOD_RESULT F_API FMOD_Channel_GetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
        //// Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_GetDSPClock              (FMOD_CHANNEL *channel, unsigned long long *dspclock, unsigned long long *parentclock);
        //FMOD_RESULT F_API FMOD_Channel_SetDelay                 (FMOD_CHANNEL *channel, unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels);
        //FMOD_RESULT F_API FMOD_Channel_GetDelay                 (FMOD_CHANNEL *channel, unsigned long long *dspclock_start, unsigned long long *dspclock_end, FMOD_BOOL *stopchannels);
        //FMOD_RESULT F_API FMOD_Channel_AddFadePoint             (FMOD_CHANNEL *channel, unsigned long long dspclock, float volume);
        //FMOD_RESULT F_API FMOD_Channel_SetFadePointRamp         (FMOD_CHANNEL *channel, unsigned long long dspclock, float volume);
        //FMOD_RESULT F_API FMOD_Channel_RemoveFadePoints         (FMOD_CHANNEL *channel, unsigned long long dspclock_start, unsigned long long dspclock_end);
        //FMOD_RESULT F_API FMOD_Channel_GetFadePoints            (FMOD_CHANNEL *channel, unsigned int *numpoints, unsigned long long *point_dspclock, float *point_volume);
        /** @brief Get User Data
          * @return userData associated with the channel as a void* **/
        virtual void* getUserData();
        /** @brief Set User Data
          * @param pUserData user data associated with the channel */
        virtual void setUserData(void* pUserData);
        /** @brief Get Frequency
          * @return frequency **/
        virtual float getFrequency();
        /** @brief Set Frequency
          * @param Frequency **/
        virtual void setFrequency(float frequency);
        /** @brief Get Priority
          * @return Priority (0 Highest priority, 255 lowest) **/
        virtual int getPriority();
        /** @brief Set Priority (0 Highest priority, 255 lowest)
          * @param priority (0 Highest priority, 255 lowest) **/
        virtual void setPriority(int priority);
        //// Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetPosition              (FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype);
        //FMOD_RESULT F_API FMOD_Channel_GetPosition              (FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype);
        //FMOD_RESULT F_API FMOD_Channel_SetChannelGroup          (FMOD_CHANNEL *channel, FMOD_CHANNELGROUP *channelgroup);
        //FMOD_RESULT F_API FMOD_Channel_GetChannelGroup          (FMOD_CHANNEL *channel, FMOD_CHANNELGROUP **channelgroup);
        //// Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetPosition              (FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype);
        //FMOD_RESULT F_API FMOD_Channel_GetPosition              (FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype);
        //FMOD_RESULT F_API FMOD_Channel_SetChannelGroup          (FMOD_CHANNEL *channel, FMOD_CHANNELGROUP *channelgroup);
        //FMOD_RESULT F_API FMOD_Channel_GetChannelGroup          (FMOD_CHANNEL *channel, FMOD_CHANNELGROUP **channelgroup);
        /** @brief Get loop mode
          * @return true if looping false otherwise **/
        virtual bool isLoop();
        /** @brief Set the loop mode
          * @param loopFlag **/
        virtual void setLoop(bool loopFlag);
        // Don't think I need these
        //FMOD_RESULT F_API FMOD_Channel_SetLoopPoints            (FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
        //FMOD_RESULT F_API FMOD_Channel_GetLoopPoints            (FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype
        /** @brief Is Channel Virtual
          * @return true if channel is virtual otherwise false **/
        virtual bool isChannelVirtual();
        // Don't think I need these
        //FMOD_RESULT F_API FMOD_Channel_GetCurrentSound          (FMOD_CHANNEL *channel, FMOD_SOUND **sound);
        //FMOD_RESULT F_API FMOD_Channel_GetIndex                 (FMOD_CHANNEL *channel, int *index);
        /** @brief getDSP
          * @param index see FMOD_CHANNELCONTROL_DSP_INDEX for
          * special offsets
          * @return FMOD_DSP object or 0 **/
        virtual FMOD_DSP* getDSP(int index);
        /** @brief addDSP
          * @param index DSP offset in the Channel
          * @param pDSP pointer to an FMOD_DSP Object
          * @return true on success false otherwise **/
        virtual bool addDSP(int index, FMOD_DSP* pDSP);
        /** @brief removeDSP
          * @param pDSP pointer to an FMOD_DSP-DSP Object to remove **/
        virtual void removeDSP(FMOD_DSP* pDSP);
        /** @brief getNumDSPs
          * @return the number of DSPs in use for the channel **/
        virtual int getNumDSPs();
        /** @brief getDSPIndex
          * @param pDSP pointer to an FMOD_DSP Object
          * @return index of the FMOD_DSP relative to the channel **/
        virtual int getDSPIndex(FMOD_DSP* pDSP);
        /** @brief setDSPIndex
          * @param pDSP pointer to an FMOD_DSP Object
          * @param index index of the FMOD_DSP relative to the channel **/
        virtual void setDSPIndex(FMOD_DSP* pDSP, int index);
        /** @brief overridePanDSP
          * Replaces the built in panner unit FMOD uses per ChannelGroup and Channel, with a user selected panner.
          * Can also be used to revert the panner back to the built in panner.
          * @param pDSP pointer to an FMOD_DSP Object **/
        virtual void overridePanDSP(FMOD_DSP* pDSP);

    protected:
        // FMOD Channel
        FMOD_CHANNEL* pChannel;
        // Paused Flag
        bool pausedFlag;
        // Volume 0 silent 1.0 full voltume
        float volume;
        // Volume Ramp Flag
        bool volumeRampFlag;
        // Pitch value 0.5 half pitch, 2.0 double pitch, 1.0 default pitch
        float pitch;
        // Mute Flag
        bool muteFlag;
        // Low pass Gain
        float lowPassGain;
        // Mode
        unsigned int mode;
        // Balance 0.0 equal -1.0 hard left 1.0 hard right
        float balance;
        // Priority
        int priority;
        // Loop flag
        bool loopFlag;

    // ***************************************
    // * TRACKER ONLY FUNCTIONS MOD, IT, S3M *
    // ***************************************
    public:
        /** @brief Get Tracker Music Speed
          * @return speed as percentage. 2.0 is twice speed and 0.5 is half speed default is 1.0 **/
        virtual float getTrackerMusicSpeed();
        /** @brief Set Tracker Music Speed
          * @param speed as percentage. 2.0 is twice speed and 0.5 is half speed default is 1.0 **/
        virtual void setTrackerMusicSpeed(float speed);
        /** @brief Get Tracker Music Number of Channels
          * @return numChannels number of channels used in the tracker file **/
        virtual int getTrackerNumberChannels();
        /** @brief Get Tracker  Music Channel Volume
          * @param channel channel to get the volume of **/
        virtual float getTrackerMusicChannelVolume(int channel);
        /** @brief Set Tracker Music Channel Volume
          * @param channel channel to set the volume of
          * @param volume the volume of the channel **/
        virtual void setTrackerChannelVolume(int channel, float volume);

    protected:
        // music Speed
        float musicSpeed;

    // ********
    // * NAME *
    // ********
    public:
        /** @brief Get Name
          * @return name **/
        virtual std::string getName() { return this->name; }
        /** @brief Set Name
          * @param name **/
        virtual void setName(std::string name) { this->name = name; }
        /** @brief Is Named
          * @return true if named, false otherwise **/
        virtual bool isNamed() { return (this->name.size() > 0); }
        /** @brief Clear Name **/
        virtual void clearName() { this->name.clear(); }

    protected:
        // unique name
        std::string name;

    // ***********
    // * ENABLED * // TODO: This needs to actually effect the Stream at the moment it doesn't
    // ***********
    public:
        /** @breif Is Enabled
          * @return true if is enabled false otherwise **/
        virtual bool isEnabled() { return this->enabledFlag; }
        /** @brief Set Enabled
          * @param state true to enable false to disable **/
        virtual void setEnabled(bool state) { this->enabledFlag = state; }
        /** @brief Enable the Sound **/
        virtual void enable() { this->enabledFlag = true; }
        /** @brief Disable the Sound **/
        virtual void disable() { this->enabledFlag = false; }

    protected:
        // Enabled Flag
        bool enabledFlag;

    // **********************
    // * FILENAME FUNCTIONS *
    // **********************
    public:
        /** @brief Get filename
          * @return filename **/
        virtual std::string getFilename() { return this->filename; }

    protected:
        // Music filename
        std::string filename;

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

#endif // MUSIC_H
