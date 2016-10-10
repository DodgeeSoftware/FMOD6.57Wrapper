#ifndef SOUNDGROUP_H
#define SOUNDGROUP_H

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

// GAMEAUDIO Includes
#include "FMODGlobals.h"

/** SoundGroup **/
class SoundGroup
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        SoundGroup();
        //! Destructor
        virtual ~SoundGroup();

    protected:
        //! Copy Constructor
        SoundGroup(SoundGroup& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! SoundGroup Assignment operator
        SoundGroup& operator=(const SoundGroup& other) { return *this; }

    // ************************
    // * SOUNDGROUP FUNCTIONS *
    // ************************
    public:
        /** @brief Get system object
          * @return FMOD_SYSTEM **/
        virtual FMOD_SYSTEM* getSystemObject();
        /** @brief create the SoundGroup
          * @return true on success false otherwise **/
        virtual bool create();
        /** @brief release **/
        virtual void release();
        /** @brief getMaxAudible
          * @return the number of concurrent playbacks of sounds in a sound group to the specified value.
          * If the sounds in the sound group are playing this many times, any attepts to play more of the
          * sounds in the sound group will fail with FMOD_ERR_MAXAUDIBLE **/
        virtual int getMaxAudible();
        /** @brief setMaxAudible
          * @param the number of concurrent playbacks of sounds in a sound group to the specified value.
          * If the sounds in the sound group are playing this many times, any attepts to play more of the
          * sounds in the sound group will fail with FMOD_ERR_MAXAUDIBLE **/
        virtual void setMaxAudible(int maxAudible);
        /** @brief getMaxAudibleBehavour
          * @return max audible behaviour as a FMOD_SOUNDGROUP_BEHAVIOR **/
        virtual FMOD_SOUNDGROUP_BEHAVIOR getMaxAudibleBehaviour();
        /** @brief setMaxAudibleBehaviour
          * @param behaviour as a FMOD_SOUNDGROUP_BEHAVIOR object **/
        virtual void setMaxAudibleBehaviour(FMOD_SOUNDGROUP_BEHAVIOR behaviour);
        /** @brief getMuteFadeSpeed
          * @return mute fade speed in seconds **/
        virtual float getMuteFadeSpeed();
        /** @brief setMuteFadeSpeed
          * @param speed fade speed in seconds **/
        virtual void setMuteFadeSpeed(float speed);
        /** @brief getVolume
          * @return volume **/
        virtual float getVolume();
        /** @brief setVolume
          * @param volume volume of the SoundGroup **/
        virtual void setVolume(float volume);
        /** @brief stop **/
        virtual void stop();
        /** @brief getName
          * @return name **/
        virtual std::string getName();
        /** @brief getNumSounds
          * @return number of sounds in the SoundGroup **/
        virtual int getNumSounds();
        /** @brief getSound
          * @param index index of the Sound in the SoundGroup
          * @return sound as an FMOD_SOUND object **/
        virtual FMOD_SOUND* getSound(int index);
        /** @brief getNumPlaying
          * @return Retrieves the number of currently playing channels for the sound group **/
        virtual int getNumPlaying();

    protected:
        // FMOD_SOUNDGROUP
        FMOD_SOUNDGROUP* pSoundGroup;

};

#endif // SOUNDGROUP_H
