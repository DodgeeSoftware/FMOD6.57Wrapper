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
        /** @brief Is this sound still playing?
          * @return true if playing false otherwise **/
        virtual bool isPlaying();
        /** @brief Get balance
          * @return balance (-1.0 full left 1.0 full right) **/
        virtual float getBalance();
        /** @brief Set Balance (Pan)
          * @param pan (-1.0 full left 1.0 full right) **/
        virtual void setBalance(float balance);
        // Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsOutput       (FMOD_CHANNEL *channel, float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright);
        //FMOD_RESULT F_API FMOD_Channel_SetMixLevelsInput        (FMOD_CHANNEL *channel, float *levels, int numlevels);
        //FMOD_RESULT F_API FMOD_Channel_SetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int outchannels, int inchannels, int inchannel_hop);
        //FMOD_RESULT F_API FMOD_Channel_GetMixMatrix             (FMOD_CHANNEL *channel, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
        /** @brief getDSPClock
          * Retrieves the DSP clock values which count up by the number of samples per second in the software mixer,
          * i.e. if the default sample rate is 48KHz, the DSP clock increments by 48000 per second
          * @return the DSP clock value for the head DSP node **/
        virtual unsigned long long getDSPClock();
        /** @brief getParentDSPClock
          * Retrieves the DSP clock values which count up by the number of samples per second in the software mixer,
          * i.e. if the default sample rate is 48KHz, the DSP clock increments by 48000 per second
          * @return the DSP clock value for the tail DSP node **/
        virtual unsigned long long getParentDSPClock();
        /** @brief getDelay
          * Retrieves a start (and/or stop) time relative to the parent channel group DSP clock, with sample accuracy
          * @param dspclock_start Address of a variable that receives the DSP clock of the parent channel group
          * to audibly start playing sound at. Optional, specify 0 or NULL to ignore
          * @param dspclock_end Address of a variable that receives the DSP clock of the parent channel group to
          * audibly stop playing sound at. Optional, specify 0 or NULL to ignore
          * @param stopchannels Address of a variable that receives TRUE = stop according to ChannelControl::isPlaying.
          * FALSE = remain 'active' and a new start delay could start playback again at a later time. Optional, specify 0 or NULL to ignore **/
        virtual void getDelay(unsigned long long* dspclock_start, unsigned long long* dspclock_end, FMOD_BOOL* stopchannels);
        /** @brief setDelay
          * Sets a start (and/or stop) time relative to the parent channel group DSP clock, with sample accuracy
          * @param dspclock_start DSP clock of the parent channel group to audibly start playing sound at, a value of 0 indicates no delay
          * @param dspclock_end DSP clock of the parent channel group to audibly stop playing sound at, a value of 0 indicates no delay
          * @param stopchannels TRUE = stop according to ChannelControl::isPlaying. FALSE = remain 'active' and a new start delay could start playback again at a later time **/
        virtual void setDelay(unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels);
        /** @brief addFadePoint
          * @param time DSP clock of the parent channel group to set the fade point volume
          * @param volume Volume level where 0 is silent and 1.0 is normal volume. Amplification is supported **/
        virtual void addFadePoint(unsigned long long dspClock, float volume);
        /** @brief setFadePointRamp
          * @param time DSP clock of the parent channel group to set the fade point volume
          * @param volume Volume level where 0 is silent and 1.0 is normal volume. Amplification is supported **/
        virtual void setFadePointRamp(unsigned long long dspClock, float volume);
        /** @brief removeFadePoints
          * Remove volume fade points on the timeline. This function will remove multiple fade points with a
          * single call if the points lay between the 2 specified clock values (inclusive).
          * @param dspClockStart DSP clock of the parent channel group to start removing fade points from
          * @param dspClockEnd DSP clock of the parent channel group to start removing fade points to **/
        virtual void removeFadePoints(unsigned long long dspClockStart, unsigned long long dspClockEnd);
        /** @brief getFadePoints
          * @param numPoints address of a varible to receive the number of points
          * @param pointDSP Clock address of a variable to receive an array of 64bit clock values. Can be 0 or NULL
          * @param volume address of a variable to recieve an array of volumes **/
        virtual void getFadePoints(unsigned int* numPoints, unsigned long long* pointDSPClock, float* volume);
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
        // Don't need to implement these
        //FMOD_RESULT F_API FMOD_Channel_SetPosition              (FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype);
        //FMOD_RESULT F_API FMOD_Channel_GetPosition              (FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype);
        /** @brief getChannelGroup
          * @return a FMOD_CHANNELGROUP where the Sound is bound to a
          * channel group otherwise 0 **/
        virtual FMOD_CHANNELGROUP* getChannelGroup();
        /** @brief setChannelGroup
          * @param pChannelGroup a FMOD_CHANNELGROUP to place this channel into **/
        virtual void setChannelGroup(FMOD_CHANNELGROUP* pChannelGroup);
        /** @brief Is loop mode
          * @return true if looping false otherwise **/
        virtual bool isLoop();
        /** @brief Set the loop mode
          * @param loopFlag **/
        virtual void setLoop(bool loopFlag);
        // Probably don't need these
        //FMOD_RESULT F_API FMOD_Channel_SetLoopPoints            (FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
        //FMOD_RESULT F_API FMOD_Channel_GetLoopPoints            (FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);
        /** @brief Is Channel Virtual
          * @return true if channel is virtual otherwise false **/
        virtual bool isChannelVirtual();
        /** @brief GetChannelIndex
          * @return channel index **/
        virtual int getChannelIndex();
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

};

#endif // CHANNEL_H
