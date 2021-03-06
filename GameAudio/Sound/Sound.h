/**
  * @file   Sound.h
  * @Author Sergeant Neipo (sergeant.neipo@gmail.com)
  * @date   August, 2016
  * @brief  Sound uses a SoundSample and a Channel to play audio
*/

#ifndef SOUND_H
#define SOUND_H

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

//// LUA AND LUABIND Includes
//extern "C"
//{
//    #include <lua.h>
//    #include <lualib.h>
//    #include <lauxlib.h>
//}
//#include <luabind/luabind.hpp>
//#include <luabind/operator.hpp>

// GAMEAUDIO Includes
#include "FMODGlobals.h"
#include "Channel/Channel.h"
#include "Sound/SoundSample.h"

/** The Sound class is used for a non-positional sound source and is effectively a wrapper around a reserved channel
        for an instance of Sound (which is referered to as a channel) **/
class Sound : public Channel
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        Sound();
        //! Destructor
        virtual ~Sound();

    protected:
        //! Sound Copy constructor
        Sound(const Sound& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Sound Assignment operator
        Sound& operator=(const Sound& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief Think **/
        virtual void think();
        /** @brief Update
          * @param dTime difference between last frame and this one **/
        virtual void update(float dTime);
        /** @brief Clear the sound **/
        virtual void clear();
        /** @brief Free **/
        virtual void free();

    public:
        /** @brief Play the sound **/
        virtual void play();
        /** @brief Play the sound paused **/
        virtual void playEx();
        /** @brief Start **/
        virtual void start();
        /** @brief Stop the sound **/
        virtual void stop();
        /** @brief Restart **/
        virtual void reset();
        /** @briefIs Paused? **/
        virtual bool isPaused();
        /** @brief Set Paused **/
        virtual void setPaused(bool pausedFlag);
        /** @brief Pause Sound Playback **/
        virtual void pause();
        /** @brief Resume Sound Playback **/
        virtual void resume();
        /** @brief Is this sound still playing?
          * @return true if playing false otherwise **/
        virtual bool isPlaying();

    protected:
        // methods and members

//    // *********************
//    // * CHANNEL FUNCTIONS *
//    // *********************
//    public:
//        /** @brief Get system object
//          * @return FMOD_SYSTEM **/
//        virtual FMOD_SYSTEM* getSystemObject();
//        /** @brief Get Volume
//          * @return volume (0.0 silent 1.0 fullblast) **/
//        virtual float getVolume();
//        /** @brief Set Volume
//          * @param volume (0.0 silent 1.0 fullblast) **/
//        virtual void setVolume(float volume);
//        /** @brief is volume ramping enabled?
//          * @return state true if enabled, false otherwise **/
//        virtual bool isVolumeRamping();
//        /** @brief set volume ramp
//          * @param volumeRampFlag true to turn on false to turn off **/
//        virtual void setVolumeRamping(bool volumeRampFlag);
//        /** @brief Get the Pitch of the Sound (0.5 half pitch, 2.0 double pitch, 1.0 default pitch)
//          * @return the pitch of the sound **/
//        virtual float getPitch();
//        /** @brief Set the Pitch of the sound (0.5 half pitch, 2.0 double pitch, 1.0 default pitch)
//          * @param **/
//        virtual void setPitch(float pitch);
//        /** @brief Is mute?
//          * @return true if mute false otherwise **/
//        virtual bool isMute();
//        /** @brief Set Mute for this sound
//          * @param muteFlag true to mute false to unmute **/
//        virtual void setMute(bool muteFlag);
//        /** @brief Mute this sound **/
//        virtual void mute();
//        /** @brief Unmute this sound **/
//        virtual void unmute();
//        /** @brief getReverbWet
//          * Gets the wet level (or send level) of a particular reverb instance for the Channel
//          * @param instance Index of the particular reverb instance to target, from 0 to 3.
//          * @return Wettness of a reverb instance for the channel **/
//        virtual float getReverbWet(int instance);
//        /** @brief setReverbWet
//          * @param instance Index of the particular reverb instance to target, from 0 to 3.
//          * @param Wettness of a reverb instance for the channel **/
//        virtual void setReverbWet(int instance, float wet);
//        /** @brief Get Low Pass Gain
//          * @return LowPass Gain**/
//        virtual float getLowPassGain();
//        /** @brief Set Low Pass Gain
//          * @param lowPassGain low pass gain (default is 1.0f) **/
//        virtual void setLowPassGain(float lowPassGain);
//        /** @brief Get Mode
//          * @return mode see FMOD_MODE for documentation on values. Values are contatinated with | operator **/
//        virtual unsigned int getMode();
//        /** @brief Set Mode
//          * @param mode see FMOD_MODE for documentation on values. Should be contatinated with | operator **/
//        virtual void setMode(unsigned int mode);
//        /** @brief Set Control Callback
//          * @param callback of signature FMOD_CHANNELCONTROL_CALLBACK (see fmod documentation) **/
//        virtual void setControlCallBack(FMOD_CHANNELCONTROL_CALLBACK pCallBack);
//        /** @brief Get balance
//          * @return balance (-1.0 full left 1.0 full right) **/
//        virtual float getBalance();
//        /** @brief Set Balance (Pan)
//          * @param pan (-1.0 full left 1.0 full right) **/
//        virtual void setBalance(float balance);
//        //// Don't need to implement these
//        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsOutput       (FMOD_CHANNEL *channel, float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright);
//        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsInput        (FMOD_CHANNEL *channel, float *levels, int numlevels);
//        //FMOD_RESULT F_API FMOD_Channel_SetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int outchannels, int inchannels, int inchannel_hop);
//        //FMOD_RESULT F_API FMOD_Channel_GetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
//        /** @brief getDSPClock
//          * Retrieves the DSP clock values which count up by the number of samples per second in the software mixer,
//          * i.e. if the default sample rate is 48KHz, the DSP clock increments by 48000 per second
//          * @return the DSP clock value for the head DSP node **/
//        virtual unsigned long long getDSPClock();
//        /** @brief getParentDSPClock
//          * Retrieves the DSP clock values which count up by the number of samples per second in the software mixer,
//          * i.e. if the default sample rate is 48KHz, the DSP clock increments by 48000 per second
//          * @return the DSP clock value for the tail DSP node **/
//        virtual unsigned long long getParentDSPClock();
//        /** @brief getDelay
//          * Retrieves a start (and/or stop) time relative to the parent channel group DSP clock, with sample accuracy
//          * @param dspclock_start Address of a variable that receives the DSP clock of the parent channel group
//          * to audibly start playing sound at. Optional, specify 0 or NULL to ignore
//          * @param dspclock_end Address of a variable that receives the DSP clock of the parent channel group to
//          * audibly stop playing sound at. Optional, specify 0 or NULL to ignore
//          * @param stopchannels Address of a variable that receives TRUE = stop according to ChannelControl::isPlaying.
//          * FALSE = remain 'active' and a new start delay could start playback again at a later time. Optional, specify 0 or NULL to ignore **/
//        virtual void getDelay(unsigned long long* dspclock_start, unsigned long long* dspclock_end, FMOD_BOOL* stopchannels);
//        /** @brief setDelay
//          * Sets a start (and/or stop) time relative to the parent channel group DSP clock, with sample accuracy
//          * @param dspclock_start DSP clock of the parent channel group to audibly start playing sound at, a value of 0 indicates no delay
//          * @param dspclock_end DSP clock of the parent channel group to audibly stop playing sound at, a value of 0 indicates no delay
//          * @param stopchannels TRUE = stop according to ChannelControl::isPlaying. FALSE = remain 'active' and a new start delay could start playback again at a later time **/
//        virtual void setDelay(unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels);
//        /** @brief addFadePoint
//          * @param time DSP clock of the parent channel group to set the fade point volume
//          * @param volume Volume level where 0 is silent and 1.0 is normal volume. Amplification is supported **/
//        virtual void addFadePoint(unsigned long long dspClock, float volume);
//        /** @brief setFadePointRamp
//          * @param time DSP clock of the parent channel group to set the fade point volume
//          * @param volume Volume level where 0 is silent and 1.0 is normal volume. Amplification is supported **/
//        virtual void setFadePointRamp(unsigned long long dspClock, float volume);
//        /** @brief removeFadePoints
//          * Remove volume fade points on the timeline. This function will remove multiple fade points with a
//          * single call if the points lay between the 2 specified clock values (inclusive).
//          * @param dspClockStart DSP clock of the parent channel group to start removing fade points from
//          * @param dspClockEnd DSP clock of the parent channel group to start removing fade points to **/
//        virtual void removeFadePoints(unsigned long long dspClockStart, unsigned long long dspClockEnd);
//        /** @brief getFadePoints
//          * @param numPoints address of a varible to receive the number of points
//          * @param pointDSP Clock address of a variable to receive an array of 64bit clock values. Can be 0 or NULL
//          * @param volume address of a variable to recieve an array of volumes **/
//        virtual void getFadePoints(unsigned int* numPoints, unsigned long long* pointDSPClock, float* volume);
//        /** @brief Get Frequency
//          * @return frequency **/
//        virtual float getFrequency();
//        /** @brief Set Frequency
//          * @param Frequency **/
//        virtual void setFrequency(float frequency);
//        /** @brief Get Priority
//          * @return Priority (0 Highest priority, 255 lowest) **/
//        virtual int getPriority();
//        /** @brief Set Priority (0 Highest priority, 255 lowest)
//          * @param priority (0 Highest priority, 255 lowest) **/
//        virtual void setPriority(int priority);
//        //// Don't need to implement these
//        //FMOD_RESULT F_API FMOD_Channel_SetPosition              (FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype);
//        //FMOD_RESULT F_API FMOD_Channel_GetPosition              (FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype);
//        /** @brief getChannelGroup
//          * @return a FMOD_CHANNELGROUP where the Sound is bound to a
//          * channel group otherwise 0 **/
//        virtual FMOD_CHANNELGROUP* getChannelGroup();
//        /** @brief setChannelGroup
//          * @param pChannelGroup a FMOD_CHANNELGROUP to place this channel into **/
//        virtual void setChannelGroup(FMOD_CHANNELGROUP* pChannelGroup);
//        /** @brief Get loop mode
//          * @return true if looping false otherwise **/
//        virtual bool isLoop();
//        /** @brief Set the loop mode
//          * @param loopFlag **/
//        virtual void setLoop(bool loopFlag);
//        // Probably don't need these
//        //FMOD_RESULT F_API FMOD_Channel_SetLoopPoints            (FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
//        //FMOD_RESULT F_API FMOD_Channel_GetLoopPoints            (FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype
//        /** @brief Is Channel Virtual
//          * @return true if channel is virtual otherwise false **/
//        virtual bool isChannelVirtual();
//        // NOTE: we don't need to implement this function
//        //FMOD_RESULT F_API FMOD_Channel_GetCurrentSound          (FMOD_CHANNEL *channel, FMOD_SOUND **sound);
//        /** @brief GetChannelIndex
//          * @return channel index **/
//        virtual int getChannelIndex();
//        /** @brief getDSP
//          * @param index see FMOD_CHANNELCONTROL_DSP_INDEX for
//          * special offsets
//          * @return FMOD_DSP object or 0 **/
//        virtual FMOD_DSP* getDSP(int index);
//        /** @brief addDSP
//          * @param index DSP offset in the Channel
//          * @param pDSP pointer to an FMOD_DSP Object
//          * @return true on success false otherwise **/
//        virtual bool addDSP(int index, FMOD_DSP* pDSP);
//        /** @brief removeDSP
//          * @param pDSP pointer to an FMOD_DSP-DSP Object to remove **/
//        virtual void removeDSP(FMOD_DSP* pDSP);
//        /** @brief getNumDSPs
//          * @return the number of DSPs in use for the channel **/
//        virtual int getNumDSPs();
//        /** @brief getDSPIndex
//          * @param pDSP pointer to an FMOD_DSP Object
//          * @return index of the FMOD_DSP relative to the channel **/
//        virtual int getDSPIndex(FMOD_DSP* pDSP);
//        /** @brief setDSPIndex
//          * @param pDSP pointer to an FMOD_DSP Object
//          * @param index index of the FMOD_DSP relative to the channel **/
//        virtual void setDSPIndex(FMOD_DSP* pDSP, int index);
//        /** @brief overridePanDSP
//          * Replaces the built in panner unit FMOD uses per ChannelGroup and Channel, with a user selected panner.
//          * Can also be used to revert the panner back to the built in panner.
//          * @param pDSP pointer to an FMOD_DSP Object **/
//        virtual void overridePanDSP(FMOD_DSP* pDSP);
//
//    protected:
//        // FMOD Channel
//        FMOD_CHANNEL* pChannel;
//        // Paused Flag
//        bool pausedFlag;
//        // Volume 0 silent 1.0 full voltume
//        float volume;
//        // Volume Ramp Flag
//        bool volumeRampFlag;
//        // Pitch value 0.5 half pitch, 2.0 double pitch, 1.0 default pitch
//        float pitch;
//        // Mute Flag
//        bool muteFlag;
//        // Low pass Gain
//        float lowPassGain;
//        // Mode
//        unsigned int mode;
//        // Balance 0.0 equal -1.0 hard left 1.0 hard right
//        float balance;
//        // Priority
//        int priority;
//        // Loop flag
//        bool loopFlag;

    // **************************
    // * SOUND SAMPLE FUNCTIONS *
    // **************************
    public:
        /** @brief Get the Sound Sample
          * @return SoundSample **/
        virtual SoundSample* getSoundSample();
        /** @brief Get the Sound Sample
          * @param pSoundSample pointer to a SoundSample **/
        virtual void setSoundSample(SoundSample* pSoundSample);

    protected:
        // The sound sample for this sound
        SoundSample* pSoundSample;

    // ***********
    // * ENABLED * // TODO: This needs to actually effect the Sound at the moment it doesn't
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

    // **********************
    // * FILENAME FUNCTIONS *
    // **********************
    public:
        /** @brief Get filename
          * @return filename **/
        virtual std::string getFilename() { return this->filename; }
        /** @brief Set filename
          * @param filename the filename **/
        virtual void setFilename(const char* filename) { this->filename = filename; }

    protected:
        // Sound filename
        std::string filename;

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // SOUND_H
