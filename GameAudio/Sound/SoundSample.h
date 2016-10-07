#ifndef SOUNDSAMPLE_H
#define SOUNDSAMPLE_H

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

// GAMEAUDIO Includes
#include "FMODGlobals.h"

/** The Sound Sample class is a wrapper around an FSOUND_SAMPLE object.
    This class is used because the FSOUND_SAMPLE object is actually a predeclaration and using is
    as anything other than a pointer will create compile errors. So it becomes impossible to bind
    the FSOUND_SAMPLE to any scripting language because the object isn't defined **/
class SoundSample
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        SoundSample();
        //! Destructor
        virtual ~SoundSample();

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! SoundSample Assignment operator
        SoundSample& operator=(const SoundSample& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief getSystemObject
          * @return FMOD_SYSTEM **/
        virtual FMOD_SYSTEM* getSystemObject();
        /* TODO: consider a loading function here, so that we can use samples without the AudioManager  and implement the release method here*/
        /** @brief releast **/
        virtual void release();
        /** @brief lock
          * @param offset
          * @param length
          * @param ptr1
          * @param ptr2
          * @param len1
          * @param len2 **/
        virtual void lock(unsigned int offset, unsigned int length, void *ptr1, void *ptr2, unsigned int *len1, unsigned int *len2);
        /** @brief unlock
          * @param ptr1
          * @param ptr2
          * @param len1
          * @param len2 **/
        virtual void unlock(void *ptr1, void *ptr2, unsigned int len1, unsigned int len2);
        /** @brief getFrequency
          * @return the Frequency of the sound **/
        virtual float getFrequency();
        /** @brief setFrequency
          * @param frequency for the sound **/
        virtual void setFrequency(float frequency);
        /** @brief getPriority
          * @return priority of this sound against others **/
        virtual int getPriority();
        /** @brief Get min distance
          * @return min Distance the sound can be heard **/
        virtual float getMinDistance();
        /** @brief Get max distance
          * @return max distance the sound can be heard **/
        virtual float getMaxDistance();
        /** @brief Set min and max distance
          * @param minDisance min distance the sound can be heard
          * @param maxDisance min distance the sound can be heard **/
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
        // These functions only work with the FMOD_3D_CUSTOMROLLOFF flag. So I am leaving these unimplemented for now
        //FMOD_RESULT F_API FMOD_Sound_Set3DCustomRolloff         (FMOD_SOUND *sound, FMOD_VECTOR *points, int numpoints);
        //FMOD_RESULT F_API FMOD_Sound_Get3DCustomRolloff         (FMOD_SOUND *sound, FMOD_VECTOR **points, int *numpoints);
        /** @brief getSubSound
          * @param index index of the subsound to get
          * @return subsound as an FMOD_SOUND object **/
        virtual FMOD_SOUND* getSubSound(int index);
        /** @brief getParentSound
          * @return parent sound FMOD_SOUND **/
        virtual FMOD_SOUND* getParentSound();
        /** @brief getName
          * @return name **/
        virtual std::string getName();
        /** @brief getLengthInSeconds
          * @return the length in seconds **/
        virtual float getLengthInSeconds();
        /** @brief getLengthInMilliseconds
          * @return length in milliseconds **/
        virtual unsigned int getLengthInMilliseconds();
        /** @brief getSizeInBytes
          * @return the size of the sound in bytes **/
        virtual unsigned int getSizeInBytes();
        /** @brief getType
          * @return type of the sound as an FMOD_SOUND_TYPE object **/
        virtual FMOD_SOUND_TYPE getType();
        /** @brief getFormat
          * @return format of the sound as an FMOD_SOUND_FORMAT object **/
        virtual FMOD_SOUND_FORMAT getFormat();
        /** @brief getChannels
          * @return 1 for mono and 2 for stereo **/
        virtual int getChannels();
        /** @brief getNumSubSounds
          * @return number of Subsounds **/
        virtual int getNumSubSounds();
        /** @breif getNumTags
          * @return the number of tags for the FMOD_SOUND **/
        virtual int getNumTags();
        /** @brief getTag
          * @param name name of the tag
          * @return FMOD_TAG associated with the name **/
        virtual FMOD_TAG getTag(std::string name);
        /** @brief getTag
          * @param index of the Tag
          * @return FMOD_TAG associated with the index **/
        virtual FMOD_TAG getTag(int index);
        // I don't think this function is necessary
        //FMOD_RESULT F_API FMOD_Sound_GetOpenState               (FMOD_SOUND *sound, FMOD_OPENSTATE *openstate, unsigned int *percentbuffered, FMOD_BOOL *starving, FMOD_BOOL *diskbusy);
        /** @brief readData
          * @param pBuffer
          * @param lengthBytes
          * @return number of btes read **/
        virtual unsigned int readData(void* pBuffer, unsigned int lengthBytes);
        /** @brief seekData
          * @param pcm Offset to seek to in PCM samples (1 x pcm seconds = rate * channels) **/
        virtual void seekData(unsigned int pcm);
        /** @brief getSoundGroup
          * @return the SoundGroup this FMODSound belongs to **/
        virtual FMOD_SOUNDGROUP* getSoundGroup();
        /** @brief setSoundGroup
          * @param SoundGroup **/
        virtual void setSoundGroup(FMOD_SOUNDGROUP* pSoundGroup);
        // I don't think I need these
        //FMOD_RESULT F_API FMOD_Sound_GetNumSyncPoints           (FMOD_SOUND *sound, int *numsyncpoints);
        //FMOD_RESULT F_API FMOD_Sound_GetSyncPoint               (FMOD_SOUND *sound, int index, FMOD_SYNCPOINT **point);
        //FMOD_RESULT F_API FMOD_Sound_GetSyncPointInfo           (FMOD_SOUND *sound, FMOD_SYNCPOINT *point, char *name, int namelen, unsigned int *offset, FMOD_TIMEUNIT offsettype);
        //FMOD_RESULT F_API FMOD_Sound_AddSyncPoint               (FMOD_SOUND *sound, unsigned int offset, FMOD_TIMEUNIT offsettype, const char *name, FMOD_SYNCPOINT **point);
        //FMOD_RESULT F_API FMOD_Sound_DeleteSyncPoint            (FMOD_SOUND *sound, FMOD_SYNCPOINT *point);
        /** @brief getMode
          * @return the mode for this sound **/
        virtual FMOD_MODE getMode();
        /** @brief setMode
          * @param mode the mode for this sound **/
        virtual void setMode(FMOD_MODE mode);
        // I don't think I need these
        //FMOD_RESULT F_API FMOD_Sound_SetLoopCount               (FMOD_SOUND *sound, int loopcount);
        //FMOD_RESULT F_API FMOD_Sound_GetLoopCount               (FMOD_SOUND *sound, int *loopcount);
        //FMOD_RESULT F_API FMOD_Sound_SetLoopPoints              (FMOD_SOUND *sound, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
        //FMOD_RESULT F_API FMOD_Sound_GetLoopPoints              (FMOD_SOUND *sound, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);

    /* NOTE: tracker music only */
    public:
        virtual int getMusicNumChannels();
        /** @brief getMusicChannelVolume
          * @param channel channel to get the volume from **/
        virtual float getMusicChannelVolume(int channel);
        /** @brief setMusicChannelVolume
          * set the volume for a channel of the tracker music
          * @param channel channel to set the volume for
          * @param volume for the channel **/
        virtual void setMusicChannelVolume(int channel, float volume);
        /** @brief getSpeed
          * @return the relative speed of MOD/S3M/XM/IT/MIDI music **/
        virtual float getMusicSpeed();
        /** @brief setSpeed
          * @param speed the relative speed of MOD/S3M/XM/IT/MIDI music **/
        virtual void setMusicSpeed(float speed);

    protected:
        // Members and methods

    // **************************
    // * SOUND SAMPLE FUNCTIONS *
    // **************************
    public:
        /** @brief Get the sound sample
          * @return FMOD_SOUND pointer **/
        virtual FMOD_SOUND* getFMODSound();
        /** @brief Set the FMODSound
          * @param pFMODSound the FMOD_SOUND pointer for this SoundSample **/
        virtual void setFMODSound(FMOD_SOUND* pFMODSound);

    protected:
        // Handle to the FMOD_SOUND
        FMOD_SOUND* pFMODSound;

    // **********************
    // * FILENAME FUNCTIONS *
    // **********************
    public:
        /** @brief Get filename
          * @return filename **/
        virtual const char* getFilename();
        /** @brief Set filename
          * @param filename **/
        virtual void setFilename(const char* filename);

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

#endif // SOUNDSAMPLE_H
