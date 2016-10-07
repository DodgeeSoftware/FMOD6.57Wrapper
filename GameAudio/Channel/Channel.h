#ifndef CHANNEL_H
#define CHANNEL_H

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

/** Channel **/
class Channel
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        Channel();
        //! Destructor
        virtual ~Channel();

    protected:
        //! Channel Copy constructor
        Channel(const Channel& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // methods and members

    protected:
        //! Channel Assignment operator
        Channel& operator=(const Channel& other) { return *this; }

    // *********************
    // * CHANNEL FUNCTIONS *
    // *********************
    public:
        /** @brief Get system object
          * @return FMOD_SYSTEM **/
        virtual FMOD_SYSTEM* getSystemObject();
        /** @brief Stop the sound **/
        virtual void stop();
        /** @briefIs Paused? **/
        virtual bool isPaused();
        /** @brief Set Paused **/
        virtual void setPaused(bool pausedFlag);
        /** @brief Pause Sound Playback **/
        virtual void pause();
        /** @brief Resume Sound Playback **/
        virtual void resume();
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
        //// TODO: Not sure yet how Reverb works to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetReverbProperties(FMOD_CHANNEL *channel, int instance, float wet);
        //FMOD_RESULT F_API FMOD_Channel_GetReverbProperties(FMOD_CHANNEL *channel, int instance, float *wet);
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
        /** @brief Is this sound still playing?
          * @return true if playing false otherwise **/
        virtual bool isPlaying();
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
        //// Not sure how DPS system works for the new FMOD
        //FMOD_RESULT F_API FMOD_Channel_GetDSP                   (FMOD_CHANNEL *channel, int index, FMOD_DSP **dsp);
        //FMOD_RESULT F_API FMOD_Channel_AddDSP                   (FMOD_CHANNEL *channel, int index, FMOD_DSP *dsp);
        //FMOD_RESULT F_API FMOD_Channel_RemoveDSP                (FMOD_CHANNEL *channel, FMOD_DSP *dsp);
        //FMOD_RESULT F_API FMOD_Channel_GetNumDSPs               (FMOD_CHANNEL *channel, int *numdsps);
        //FMOD_RESULT F_API FMOD_Channel_SetDSPIndex              (FMOD_CHANNEL *channel, FMOD_DSP *dsp, int index);
        //FMOD_RESULT F_API FMOD_Channel_GetDSPIndex              (FMOD_CHANNEL *channel, FMOD_DSP *dsp, int *index);
        //FMOD_RESULT F_API FMOD_Channel_OverridePanDSP           (FMOD_CHANNEL *channel, FMOD_DSP *pan);
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
        /** @brief Is loop mode
          * @return true if looping false otherwise **/
        virtual bool isLoop();
        /** @brief Set the loop mode
          * @param loopFlag **/
        virtual void setLoop(bool loopFlag);
        //FMOD_RESULT F_API FMOD_Channel_SetLoopPoints            (FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
        //FMOD_RESULT F_API FMOD_Channel_GetLoopPoints            (FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);
        /** @brief Is Channel Virtual
          * @return true if channel is virtual otherwise false **/
        virtual bool isChannelVirtual();
        //FMOD_RESULT F_API FMOD_Channel_GetCurrentSound          (FMOD_CHANNEL *channel, FMOD_SOUND **sound);
        //FMOD_RESULT F_API FMOD_Channel_GetIndex                 (FMOD_CHANNEL *channel, int *index);
//        // TODO: Implement these
//        FMOD_RESULT F_API FMOD_Channel_GetDSP                   (FMOD_CHANNEL *channel, int index, FMOD_DSP **dsp);
//        FMOD_RESULT F_API FMOD_Channel_AddDSP                   (FMOD_CHANNEL *channel, int index, FMOD_DSP *dsp);
//        FMOD_RESULT F_API FMOD_Channel_RemoveDSP                (FMOD_CHANNEL *channel, FMOD_DSP *dsp);
//        FMOD_RESULT F_API FMOD_Channel_GetNumDSPs               (FMOD_CHANNEL *channel, int *numdsps);
//        FMOD_RESULT F_API FMOD_Channel_SetDSPIndex              (FMOD_CHANNEL *channel, FMOD_DSP *dsp, int index);
//        FMOD_RESULT F_API FMOD_Channel_GetDSPIndex              (FMOD_CHANNEL *channel, FMOD_DSP *dsp, int *index);
//        FMOD_RESULT F_API FMOD_Channel_OverridePanDSP           (FMOD_CHANNEL *channel, FMOD_DSP *pan);

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

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // CHANNEL_H
