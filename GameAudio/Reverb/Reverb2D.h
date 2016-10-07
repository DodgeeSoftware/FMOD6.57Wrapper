#ifndef REVERB2D_H
#define REVERB2D_H

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

/** A Reverb3D... TODO: Comment me **/
class Reverb2D
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        Reverb2D();
        //! Destructor
        virtual ~Reverb2D();

    protected:
        //! Reverb2D Copy constructor
        Reverb2D(const Reverb2D& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Reverb2D Assignment operator
        Reverb2D& operator=(const Reverb2D& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief Create **/
        virtual bool create();
        /** @brief Release **/
        virtual void release();

    public:
        /** @brief isActive*
          * @return true if active otherwise false */
        virtual bool isActive();
        /** @brief setActive
          * @param activeFlag true to activate, false to deactivate **/
        virtual void setActive(bool activeFlag);
        /** @brief activate **/
        virtual void activate();
        /** @brief deactivate **/
        virtual void deactivate();

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

    protected:
        // FMODRever3D Object
        FMOD_REVERB3D* pFMODReverb3D;
        // Active Flag
        bool activeFlag;
        // Horizontal Position
        float x;
        // Vertical Position
        float y;
        // The smaller (0.1f - 0.3f) this value the shorter range the sound is audible
        float minDistance;
        // Usually 100000.0f and safely ignored
        float maxDistance;

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // REVERB2D_H
