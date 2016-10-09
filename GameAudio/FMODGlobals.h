/**
  * @file   FMODGlobals.h
  * @Author Sergeant Neipo (sergeant.neipo@gmail.com)
  * @date   August, 2016
  * @brief  FMODGlobals is a header that we store
  * device globals in such as mute
*/

#ifndef FMOD_GLOBALS_H
#define FMOD_GLOBALS_H

// FMOD Includes
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>

namespace FMODGlobals
{
    // ********************
    // * GLOBAL VARIABLES *
    // ********************
    /* NOTE: our FMOD_SYSTEm here is referenced by the entire sound wrapper
        it is a work around for having to pass an FMOD_System into
        all of our classes. After FMOD3.75 the library lost its way and
        this wrapper is written tobe similar to the old FMOD */
    extern FMOD_SYSTEM* pFMODSystem;
    // System Frequency in hertz (for the DriverID in use) - usually 44100 or 22050
    static int getFrequency()
    {
        // Grab the DriverID
        int driverID = 0;
        FMOD_System_GetDriver(pFMODSystem, &driverID);
        // Grab Frequency
        int frequency = 0;
        FMOD_System_GetDriverInfo(pFMODSystem, driverID, 0, 0, 0, &frequency, 0, 0);
        // return frequency
        return frequency;
    }
    // The number of Channels (for the DriverID in use) - 1 for mono 2 for stereo
    static int getNumberOfChannels()
    {
        // Grab the DriverID
        int driverID = 0;
        FMOD_System_GetDriver(pFMODSystem, &driverID);
        // Grab Channels
        int channels = 0;
        FMOD_System_GetDriverInfo(pFMODSystem, driverID, 0, 0, 0, 0, 0, &channels);
        // return channels
        return channels;
    }
    /* NOTE: These two groups allow us to control channels for sound
        effects and music. */
    // Sound Effects Channel Group
    extern FMOD_CHANNELGROUP* pSoundEffectsChannelGroup;
    extern FMOD_CHANNELGROUP* pSoundEffectsChannelGroup;
    // Music Channel Group
    extern FMOD_CHANNELGROUP* pMusicChannelGroup;
    // ********************
    // * GLOBAL FUNCTIONS *
    // ********************
    /* Get a channel by its index */
    static FMOD_CHANNEL* getChannel(int index)
    {
        // Grab Channel
        FMOD_CHANNEL* pChannel = 0;
        FMOD_System_GetChannel(pFMODSystem, index, &pChannel);
        // Return Channel
        return pChannel;
    }
    /** @brief getMasterChannelGroup
      * @return the Master Channel Group **/
    static FMOD_CHANNELGROUP* getMasterChannelGroup()
    {
        // Grab ChannelGroup
        FMOD_CHANNELGROUP* pChannelGroup = 0;
        FMOD_System_GetMasterChannelGroup(pFMODSystem, &pChannelGroup);
        //return pChannelGroup
        return pChannelGroup;
    }
    /** @brief getMasterSoundGroup
      * @return the Master Sound Group **/
    static FMOD_SOUNDGROUP* getMasterSoundGroup()
    {
        // Grab SoundGroup
        FMOD_SOUNDGROUP* pSoundGroup = 0;
        FMOD_System_GetMasterSoundGroup(pFMODSystem, &pSoundGroup);
        //return pSoundGroup
        return pSoundGroup;
    }
}

#endif // FMOD_GLOBALS_H
