#ifndef CHANNEL2D_H
#define CHANNEL2D_H

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
class Channel2D : public Channel
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Default Constructor
        Channel2D() : Channel()
        {

        }
        //! Destructor
        virtual ~Channel2D() {}

    protected:
        //! Channel Copy constructor
        Channel2D(const Channel2D& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // methods and members

    protected:
        //! Channel2D Assignment operator
        Channel2D& operator=(const Channel2D& other) { return *this; }

    // *********************
    // * SPACIAL FUNCTIONS *
    // *********************
    //FMOD_RESULT F_API FMOD_Channel_GetAudibility            (FMOD_CHANNEL *channel, float *audibility);
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
          * @param xVelocity x Velocity
          * @param yVelocity y Velocity **/
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

};

#endif // CHANNEL2D_H
