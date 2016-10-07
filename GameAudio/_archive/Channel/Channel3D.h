#ifndef CHANNEL3D_H
#define CHANNEL3D_H

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
#include "Channel.h"

/** Channel2D **/
class Channel3D : public Channel
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        Channel3D() : Channel()
        {

        }
        //! Destructor
        virtual ~Channel3D() {}

    protected:
        //! Channel Copy constructor
        Channel3D(const Channel3D& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // methods and members

    protected:
        //! Channel3D Assignment operator
        Channel3D& operator=(const Channel3D& other) { return *this; }

    // *********************
    // * SPACIAL FUNCTIONS *
    // *********************
    public:
        //FMOD_RESULT F_API FMOD_Channel_GetAudibility            (FMOD_CHANNEL *channel, float *audibility);
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

    protected:
        // Horizontal Position
        float x;
        // Vertical Position
        float y;
        // Depth Position
        float z;
        // Horizontal Velocity
        float xVelocity;
        // Vertical Velocity
        float yVelocity;
        // Depth Velocity
        float zVelocity;
};

#endif // CHANNEL3D_H
