#ifndef DSPCONNECTION_H
#define DSPCONNECTION_H

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
//#include <luabind/operator.hpp>

// GAMEAUDIO Includes
#include "FMODGlobals.h"

/** DSPConnection **/
class DSPConnection
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        DSPConnection();
        //! Destructor
        virtual ~DSPConnection();

    protected:
        //! Copy Constructor
        DSPConnection(DSPConnection& other);

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! DSPConnection Assignment operator
        DSPConnection& operator=(const DSPConnection& other) { return *this; }

    // ***************************
    // * DSPCONNECTION FUNCTIONS *
    // ***************************
    public:
        /** @brief getInputDSP
          * @return input DSP for this connection **/
        virtual FMOD_DSP* getInputDSP();
        /** @brief getOutputDSP
          * @return output DSP for this connection **/
        virtual FMOD_DSP* getOutputDSP();
        /** @brief getMix
          * @return return the volume of the connection so that the input is scaled by this value before being passed to the output **/
        virtual float getMix();
        /** @brief setMix
          * Sets the volume of the connection so that the input is scaled by this value before being passed to the output
          * @param volume between 0.0 - 1.0 to scal ethe incoming DSP audio **/
        virtual void setMix(float volume);
        /** @brief getMatrix
          * @return an array of floating point matrix data, where rows represent output speakers, and columns represent input channels **/
        virtual float* getMatrix();
        /** @brief getNumberOfInChannels
          * @return number of in channels in our matrix **/
        virtual int getNumberOfInChannels();
        /** @brief getNumberOfOutChannels
          * @return number of out channels in our matrix **/
        virtual int getNumberOfOutChannels();
        /** @brief setMatrix
          * @param matrix an array of floating point matrix data, where rows represent output speakers, and columns represent input channels
          * @param outChannels number of outChannels in matrix
          * @param inChannels number of inChannels in matrix **/
        virtual void setMatrix(float* matrix, int outChannels, int inChannels);
        /** @brief getType
          * @return Returns the type of the connection between 2 DSP units.
          * This can be FMOD_DSPCONNECTION_TYPE_STANDARD, FMOD_DSPCONNECTION_TYPE_SIDECHAIN, FMOD_DSPCONNECTION_TYPE_SEND or FMOD_DSPCONNECTION_TYPE_SEND_SIDECHAIN. **/
        virtual FMOD_DSPCONNECTION_TYPE getType();
        /** @brief getUserData
          * @return void* the user data associated with this DSPConnection**/
        virtual void* getUserData();
        /** @brief setUserData
          * @param void* data to be stored with this DSPConnection **/
        virtual void setUserData(void* pUserData);
        /** @brief getDSPConnection
          * @return the FMOD_DSPCONNECTION **/
        virtual FMOD_DSPCONNECTION* getDSPConnection();
        /** @brief setDSPConnection
          * @param the FMOD_DSPCONNECTION **/
        virtual void setDSPConnection(FMOD_DSPCONNECTION* pDSPConnection);

    protected:
        // DSPConnection
        FMOD_DSPCONNECTION* pDSPConnection;

};

#endif // DSPCONNECTION_H
