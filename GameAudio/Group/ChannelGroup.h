#ifndef CHANNELGROUP_H
#define CHANNELGROUP_H

// C++ Includes
#include <string>

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

/** The ChannelGroup is a wrapper around the ChannelGroup class**/
class ChannelGroup
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        ChannelGroup();
        //! Destructor
        virtual ~ChannelGroup();

    protected:
        //! Copy Constructor
        ChannelGroup(ChannelGroup& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! ChannelGroup Assignment operator
        ChannelGroup& operator=(const ChannelGroup& other) { return *this; }

    // ***************************
    // * CHANNEL GROUP FUNCTIONS *
    // ***************************
    public:
        /** @brief create creates the ChannelGroup **/
        virtual bool create();
        /** @brief release the ChannelGroup **/
        virtual void release();
        /** @brief Stop **/
        virtual void stop();
        /** @briefIs Paused? **/
        virtual bool isPaused();
        /** @brief Set Paused
          * @param pausedFlag true to pause false to unpause **/
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
        /** @brief getAudibilty
          * @return the combined volume after 3D spatialization and geometry occlusion calculations including any volumes set via the API **/
        virtual float getAudibility();
        /** @brief getReverbProperties
          * @param instance Index of the particular reverb instance to target, from 0 to 3 inclusive
          * @return the wet level (or send level) for a particular reverb instance **/
        virtual float getReverbProperties(int instance);
        /** @brief setReverbProperties
          * @param instance Index of the particular reverb instance to target, from 0 to 3 inclusive
          * @param the wet level (or send level) for a particular reverb instance **/
        virtual void setReverbProperties(int instance, float wet);
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
        /** @brief Is playing?
          * @return true if playing false otherwise **/
        virtual bool isPlaying();
        // NOTE: there is no FMOD_ChannelGroup_GetPan method in FMOD so I don't implement a getBalance method here
        /** @breif setBalance **/
        virtual void setBalance(float balance);
        // Don't need these
        //FMOD_RESULT F_API FMOD_ChannelGroup_SetMixLevelsOutput  (FMOD_CHANNELGROUP *channelgroup, float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright);
        //FMOD_RESULT F_API FMOD_ChannelGroup_SetMixLevelsInput   (FMOD_CHANNELGROUP *channelgroup, float *levels, int numlevels);
        //FMOD_RESULT F_API FMOD_ChannelGroup_GetMixMatrix        (FMOD_CHANNELGROUP *channelgroup, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
        //FMOD_RESULT F_API FMOD_ChannelGroup_SetMixMatrix        (FMOD_CHANNELGROUP *channelgroup, float *matrix, int outchannels, int inchannels, int inchannel_hop);
        // TODO: implement these (tricky)
        //FMOD_RESULT F_API FMOD_System_AttachChannelGroupToPort  (FMOD_SYSTEM *system, FMOD_PORT_TYPE portType, FMOD_PORT_INDEX portIndex, FMOD_CHANNELGROUP *channelgroup, FMOD_BOOL passThru);
        //FMOD_RESULT F_API FMOD_System_DetachChannelGroupFromPort(FMOD_SYSTEM *system, FMOD_CHANNELGROUP *channelgroup);
        //FMOD_RESULT F_API FMOD_ChannelGroup_GetDSPClock         (FMOD_CHANNELGROUP *channelgroup, unsigned long long *dspclock, unsigned long long *parentclock);
        //FMOD_RESULT F_API FMOD_ChannelGroup_SetDelay            (FMOD_CHANNELGROUP *channelgroup, unsigned long long dspclock_start, unsigned long long dspclock_end, FMOD_BOOL stopchannels);
        //FMOD_RESULT F_API FMOD_ChannelGroup_GetDelay            (FMOD_CHANNELGROUP *channelgroup, unsigned long long *dspclock_start, unsigned long long *dspclock_end, FMOD_BOOL *stopchannels);
        //FMOD_RESULT F_API FMOD_ChannelGroup_AddFadePoint        (FMOD_CHANNELGROUP *channelgroup, unsigned long long dspclock, float volume);
        //FMOD_RESULT F_API FMOD_ChannelGroup_SetFadePointRamp    (FMOD_CHANNELGROUP *channelgroup, unsigned long long dspclock, float volume);
        //FMOD_RESULT F_API FMOD_ChannelGroup_RemoveFadePoints    (FMOD_CHANNELGROUP *channelgroup, unsigned long long dspclock_start, unsigned long long dspclock_end);
        //FMOD_RESULT F_API FMOD_ChannelGroup_GetFadePoints       (FMOD_CHANNELGROUP *channelgroup, unsigned int *numpoints, unsigned long long *point_dspclock, float *point_volume);
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
        // TODO: implement this (tricky)
        //FMOD_RESULT F_API FMOD_ChannelGroup_AddGroup            (FMOD_CHANNELGROUP *channelgroup, FMOD_CHANNELGROUP *group, FMOD_BOOL propagatedspclock, FMOD_DSPCONNECTION **connection);
        /** @brief getSubNumGroups
          * @return the number of sub groups under this channel group **/
        virtual int getNumSubGroups();
        /** @brief getChannelGroup
          * @param index Index to specify which sub channel group to receieve
          * @return handle to a specified sub channel group.**/
        virtual FMOD_CHANNELGROUP* getChannelGroup(int index);
        /** @brief getParentGroup
          * @return the parent Group**/
        virtual FMOD_CHANNELGROUP* getParentGroup();
        /** @brief getName
          * @return getName **/
        virtual std::string getName();
        /** @brief getNumChannels
          * @return number of channels **/
        virtual int getNumChannels();
        /** @brief getChannel
          * @param index channel index in the ChannelGroup **/
        virtual FMOD_CHANNEL* getChannel(int index);
        /** @brief Get X Position
          * @return x x position **/
        virtual float getX();
        /** @brief Get Y Position
          * @return y y position **/
        virtual float getY();
        /** @brief Get Z Position
          * @return z z position **/
        virtual float getZ();
        /** @brief Set Position
          * @param x x position
          * @param y y position
          * @param z z position **/
        virtual void setPosition(float x, float y, float z);
        /** @brief Get X Velocity
          * @return x velocity **/
        virtual float getXVelocity();
        /** @brief Get Y Velocity
          * @return y velocity **/
        virtual float getYVelocity();
        /** @brief Get Z Velocity
          * @return z velocity **/
        virtual float getZVelocity();
        /** @brief Set Velocity
          * @param xVelocity x Velocity
          * @param yVelocity y Velocity
          * @param zVelocity z Velocity **/
        virtual void setVelocity(float xVelocity, float yVelocity, float zVelocity);
        /** @brief Get min distance
          * @return min Distance the ChannelGroup can be heard **/
        virtual float getMinDistance();
        /** @brief Get max distance
          * @return max distance the ChannelGroup can be heard **/
        virtual float getMaxDistance();
        /** @brief Set min and max distance
          * @param minDisance min distance the ChannelGroup can be heard
          * @param maxDisance min distance the ChannelGroup can be heard **/
        virtual void setMinMaxDistance(float minDistance, float maxDistance);
        /** @brief Get Inside Cone Angle
          * @return Inside Code Angle in degrees **/
        virtual float get3DConeInsideAngle();
        /** @brief Get OutsideConeAngle
          * @return Inside Cone Angle in degrees **/
        virtual float get3DConeOutsideAngle();
        /** @brief Get Outside Volume (between 0.0 - 1.0; default value is 1.0)
          * @return Outside Volume **/
        virtual float get3DConeOutsideVolume();
        /** @brief Set3DConeSettings
          * @param insideConeAngle angle of the inner cone in degrees
          * @param outsideConeAngle angle of the outer cone in degrees
          * @param outsideVolume between 0.0 and 1.0 (default is 1.0) **/
        virtual void set3DConeSettings(float insideConeAngle, float outsideConeAngle, float outsiderVolume);
        /** @brief getRotationX
          * @return pitch in degrees **/
        virtual float getRotationX();
        /** @brief getRotationY
          * @return yaw in degrees **/
        virtual float getRotationY();
        /** @brief getRotationZ
          * @return pitch in degrees **/
        virtual float getRotationZ();
        /** @brief Set Orientation
          * @param pitch rotation around the xaxis
          * @param yaw rotation around the yaxis
          * @param roll rotation around the zaxis **/
        virtual void setOrientation(float pitch, float yaw, float roll);
        // Not going to implement these
        //FMOD_RESULT F_API FMOD_ChannelGroup_Get3DCustomRolloff  (FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR **points, int *numpoints);
        //FMOD_RESULT F_API FMOD_ChannelGroup_Set3DCustomRolloff  (FMOD_CHANNELGROUP *channelgroup, FMOD_VECTOR *points, int numpoints);
        /** @brief Get Direct Occlusion
          * @return directOcclusion **/
        virtual float getDirectOcclusion();
        /** @brief Set Direct Occlusion
          * @param directOcclusion **/
        virtual void setDirectOcclusion(float directOcclusion);
        /** @brief Get Reverb Occlusion (0.0 not occluded 1.0 occluded; default 0.0)
          * @return directOcclusion **/
        virtual float getReverbOcclusion();
        /** @brief Set Reverb Occlusion (0.0 not occluded 1.0 occluded; default 0.0)
          * @param reverbOcclusion **/
        virtual void setReverbOcclusion(float reverbOcclusion);
        // I don't need these functions
        //FMOD_RESULT F_API FMOD_ChannelGroup_Set3DSpread         (FMOD_CHANNELGROUP *channelgroup, float angle);
        //FMOD_RESULT F_API FMOD_ChannelGroup_Get3DSpread         (FMOD_CHANNELGROUP *channelgroup, float *angle);
        /** @brief getLevel
          * @return Retrieves the current 3D mix level set by setPanLevel **/
        virtual float getLevel();
        /** setLevel
          * @param level how much the 3D engine has an effect on the channel
          * versus that set by 2D panning functions **/
        virtual void setLevel(float level);
        /** @brief getDopplerLevel
          * @return doppler level **/
        virtual float getDopplerLevel();
        /** @brief setDopplerLevel
          * @param dopplerLevel **/
        virtual void setDopplerLevel(float dopplerLevel);
        /** @brief isDistanceFilter
          * @return true if DistanceFilter is turned on **/
        virtual bool isDistanceFilter();
        /** @brief setDistanceFilter
          * @param distanceFilter true to turn on, false to turn off **/
        virtual void setDistanceFilter(bool distanceFilterFlag);
        /** @brief getDistanceFilterCustomLevel
          * @return custom level for attenuation where 1.0 is no attenuation 0 is complete attenuation default is 1.0**/
        virtual float getDistanceFilterCustomLevel();
        /** @brief setDistanceFilterCustomLevel  for the distance filter
          * @param customLevel Specify a attenuation factor manually here, where 1.0 = no attenuation and 0 = complete attenuation. Default = 1.0 **/
        virtual void setDistanceFilterCustomLevel(float customLevel);
        virtual float getDistanceFilterCentreFrequency();
        /** @brief setDistanceFilterCentreFrquency
          * @param frequency Specify a center frequency in hz for the high-pass filter used to simulate distance attenuation, from 10.0 to 22050.0. Default = 1500.0 **/
        virtual void setDistanceFilterCentreFrequency(float frequency);

    public:
        /** @brief Get system object
          * @return FMOD_SYSTEM **/
        virtual FMOD_SYSTEM* getSystemObject();

    public:
        /** @brief getFMODChannelGroup
          * @return a pointer to the FMOD_CHANNELGROUP **/
        virtual FMOD_CHANNELGROUP* getFMODChannelGroup();

    protected:
        // FMOD_CHANNELGROUP
        FMOD_CHANNELGROUP* pChannelGroup;

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // CHANNELGROUP_H
