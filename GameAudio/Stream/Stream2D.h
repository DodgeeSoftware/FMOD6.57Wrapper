/**
  * @file   Stream2D.h
  * @Author Sergeant Neipo (sergeant.neipo@gmail.com)
  * @date   August, 2016
  * @brief  Stream2D provides the ability to load and buffer
  * audio files in real-time so that an entire file
  * need not be loaded. This massively decreases load time.
*/

#ifndef STREAM2D_H
#define STREAM2D_H

// FMOD Includes
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>

// LUA AND LUABIND Includes
extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}
#include <luabind/luabind.hpp>

// GAMEAUDIO Includes
#include "FMODGlobals.h"
#include "Channel/Channel.h"
#include "Stream/Stream.h"

/** The Stream2D Class creates a 2 dimension (aka x,y) representation of a streaming audio. Streaming in that
    no loading is done, sound is read directly from disc **/
class Stream2D : public Stream
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Default Constructor
        Stream2D();
        //! Destructor
        virtual ~Stream2D();

    protected:
        //! Stream2D Copy constructor
        Stream2D(const Stream2D& other) : Stream() {}

    // ************************        //// TODO: implement this one
        //FMOD_RESULT F_API FMOD_Channel_GetAudibility            (FMOD_CHANNEL *channel, float *audibility);
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Stream2D Assignment operator
        Stream2D& operator=(const Stream2D& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief Load Stream
          * @param filename filename to load
          * @return true on success false on failure **/
        virtual bool load(std::string filename);
        /** @brief Think **/
        virtual void think();
        /** @brief Update
          * @param dTime difference between the last frame and this frame **/
        virtual void update(float dTime);
        /** @brief Clear **/
        virtual void clear();
        /** @brief free the stream **/
        virtual void free();

    public:
        /** @brief Play **/
        virtual void play();
        /** @brief PlayEx (play paused) **/
        virtual void playEx();

    protected:
        // members and methods

    // *****************************
    // * SPACIAL CHANNEL FUNCTIONS *
    // *****************************
    public:
        /** @brief Get X Position
          * @return x x position **/
        virtual float getX();
        /** @brief Get Y Position
          * @return y y position **/
        virtual float getY();
        /** @brief Set Position
          * @param x x position
          * @param y y position **/
        virtual void setPosition(float x, float y);
        /** @brief Get X Velocity
          * @return x velocity **/
        virtual float getXVelocity();
        /** @brief Get Y Velocity
          * @return y velocity **/
        virtual float getYVelocity();
        /** @brief Set Velocity
          * @param xVelocity x velocity
          * @param yVelocity y velocity **/
        virtual void setVelocity(float xVelocity, float yVelocity);
        /** @brief Get min distance
          * @return min Distance the sound can be heard **/
        virtual float getMinDistance();
        /** @brief Get max distance
          * @return max distance the sound can be heard **/
        virtual float getMaxDistance();
        /** @brief Set min distance
          * @param minDistance the min distance the sound is audible **/
        virtual void setMinDistance(float minDistance);
        /** @brief Set max distance
          * @param maxDistance max distance the sound is audible **/
        virtual void setMaxDistance(float maxDistance);
        /** @brief Set min and max distance
          * @param minDisance min distance the sound can be heard
          * @param maxDisance min distance the sound can be heard **/
        virtual void setMinMaxDistance(float minDistance, float maxDistance);
//// NOTE: These functions only work with the FMOD_3D_CUSTOMROLLOFF flag. So I am leaving these unimplemented for now
//        /** @brief Get 3D Custom RollOff Only works when you
//            @return Custom Rolloff in conjunction with the FMOD_3D_CUSTOMROLLOFF flag **/
//        virtual get3DCustomRolloff();
//        FMOD_RESULT F_API FMOD_Channel_Get3DCustomRolloff(FMOD_CHANNEL *channel, FMOD_VECTOR **points, int *numpoints);
//        /** @brief Set 3d Custom RollOff. Only works when you
//          * in conjunction with the FMOD_3D_CUSTOMROLLOFF flag
//          * @param ...
//          * @param ... **/
//        virtual set3DCustomRollOff(float distance, float volume);
//        FMOD_RESULT F_API FMOD_Channel_Set3DCustomRolloff(FMOD_CHANNEL *channel, FMOD_VECTOR *points, int numpoints);
        /** @brief getLevel Gets how much the 3D engine has an effect on the channel, versus that set by 2D panning functions.
          * @return level level from 0.0 (attenuation is ignored and panning as set by 2D panning functions) to 1.0 (pan and attenuate according to 3D position), default = 1.0**/
        virtual float getLevel();
        /** @brief Set Level Sets how much the 3D engine has an effect on the channel, versus that set by 2D panning functions.
          * @param level level from 0.0 (attenuation is ignored and panning as set by 2D panning functions) to 1.0 (pan and attenuate according to 3D position), default = 1.0 **/
        virtual void setLevel(float level);
        /** @brief Get Doppler Level
          * @return (the amount by which doppler is scaled) */
        virtual float getDopplerLevel();
        /** @brief Set Doppler Level
          * @param dopplerLevel (the amount by which doppler is scaled) **/
        virtual void setDopplerLevel(float dopplerLevel);
        /** @brief isDistanceFilter
          * @return true if DistanceFilter is turned on **/
        virtual bool isDistanceFilter();
        /** @brief getCustomLevel
          * @return the manual user attenuation, where 1.0 = no attenuation and 0 = complete attenuation. Default = 1.0. **/
        virtual float getCustomLevel();
        /** @brief getCentreFrequency
          * @return center frequency in hz for the high-pass filter used to simulate distance attenuation, from 10.0 to 22050.0. Default = 1500.0 **/
        virtual float getCentreFrequency();
        /** @brief setDistanceFilter
          * @param distanceFilter true to turn on, false to turn off **/
        virtual void setDistanceFilter(bool distanceFilterFlag);
        /** @brief setDistanceFilterCustomLevel  for the distance filter
          * @param customLevel Specify a attenuation factor manually here, where 1.0 = no attenuation and 0 = complete attenuation. Default = 1.0 **/
        virtual void setDistanceFilterCustomLevel(float customLevel);
        /** @brief setDistanceFilterCentreFrquency
          * @param frequency Specify a center frequency in hz for the high-pass filter used to simulate distance attenuation, from 10.0 to 22050.0. Default = 1500.0 **/
        virtual void setDistanceFilterCentreFrequency(float frequency);
        // Not going to implement these
        //FMOD_RESULT F_API FMOD_Channel_Set3DSpread              (FMOD_CHANNEL *channel, float angle);
        //FMOD_RESULT F_API FMOD_Channel_Get3DSpread              (FMOD_CHANNEL *channel, float *angle);
        /** @brief getAudibility
          * @return returns the combined volume after 3D spatialization
          * and geometry occlusion calculations including any volumes set via the API **/
        virtual float getAudibility();

    protected:
        // Horizontal Position
        float x;
        // Vertical Position
        float y;
        // Horizontal Velocity
        float xVelocity;
        // Vertical Velocity
        float yVelocity;
        // The smaller (0.1f - 0.3f) this value the shorter range the sound is audible
        float minDistance;
        // Usually 100000.0f and safely ignored
        float maxDistance;
        // Level
        float level;
        // DopplerLevel
        float dopplerLevel;
        // Distance Filter
        bool distanceFilterFlag;
        // CustomLevel
        float customLevel;
        // centre frequency
        float centreFrequency;

    // ****************
    // * LUA BINDINGS *
    // ****************
    public:
        /** @brief Bind this class to a lua state
          * @param pLuaState The LuaState to bind this class to **/
        static void bindToLua(lua_State* pLuaState);
};

#endif // STREAM2D_H
