#ifndef DSP_H
#define DSP_H

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

/** The DSP Class is a wrapper around the FMOD_DSP object in FMOD.
    **/
class DSP
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        DSP();
        //! Destructor
        virtual ~DSP();

    protected:
        //! Copy Constructor
        DSP(DSP& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! DSP Assignment operator
        DSP& operator=(const DSP& other) { return *this; }

    // *********************
    // * GENERAL FUNCTIONS *
    // *********************
    public:
        /** @brief create this function will create our DSP
          * @param description description of the DSP *
          * @return true on success false on failure */
        virtual bool create(FMOD_DSP_DESCRIPTION description);
        /** @brief create DSP by Type
          * @param type the type of DSP to create.
          * Type is a Predefined type setup by FMOD **/
        virtual bool create(FMOD_DSP_TYPE type);
        /** @brief create DSP from plugin
          * @param pluginHandle a handle to a DSP Plugin **/
        virtual bool create(unsigned int pluginHandle);
//        /** @brief play
//          * Plays a DSP unit object and its input network on a
//          * particular channel
//          * @param channel **/
//        virtual void play(FMOD_CHANNEL** pChannel);
//        /** @brief play
//          * Plays a DSP unit object and its input network on a
//          * particular ChannelGroup
//          * @param channelGroup **/
//        virtual void play(FMOD_CHANNELGROUP* channelGroup);
////        FMOD_System_PlayDSP
// TODO: what do I do with this function
        /** @brief release **/
        virtual void release();
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_AddInput                     (FMOD_DSP *dsp, FMOD_DSP *input, FMOD_DSPCONNECTION **connection, FMOD_DSPCONNECTION_TYPE type);
//FMOD_RESULT F_API FMOD_DSP_DisconnectFrom               (FMOD_DSP *dsp, FMOD_DSP *target, FMOD_DSPCONNECTION *connection);
//FMOD_RESULT F_API FMOD_DSP_DisconnectAll                (FMOD_DSP *dsp, FMOD_BOOL inputs, FMOD_BOOL outputs);
        /** @brief getNumberOfInputs
          * @return Retrieves the number of inputs connected to the DSP unit **/
        virtual int getNumberOfInputs();
        /** @brief getNumberOfOutputs
          * @return number of outputs **/
        virtual int getNumberOfOutputs();
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_GetInput                     (FMOD_DSP *dsp, int index, FMOD_DSP **input, FMOD_DSPCONNECTION **inputconnection);
//FMOD_RESULT F_API FMOD_DSP_GetOutput                    (FMOD_DSP *dsp, int index, FMOD_DSP **output, FMOD_DSPCONNECTION **outputconnection);
        /** @brief getActive
          * @return true if active false if not active **/
        virtual bool getActive();
        /** @brief setActive
          * @param activeFlag true to activate false to deactivate **/
        virtual void setActive(bool activeFlag);
        /** @brief getBypass
          * @return the bypass state of the DSP unit **/
        virtual bool getBypass();
        /** @brief setBypass
          * Enables or disables the read callback of a DSP unit so that it does or doesn't process the data coming into it.
          * A DSP unit that is disabled still processes its inputs, it will just be 'dry'.
          * @param bypassFlag **/
        virtual void setBypass(bool bypassFlag);
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_SetWetDryMix                 (FMOD_DSP *dsp, float prewet, float postwet, float dry);
//FMOD_RESULT F_API FMOD_DSP_GetWetDryMix                 (FMOD_DSP *dsp, float *prewet, float *postwet, float *dry);
//FMOD_RESULT F_API FMOD_DSP_SetChannelFormat             (FMOD_DSP *dsp, FMOD_CHANNELMASK channelmask, int numchannels, FMOD_SPEAKERMODE source_speakermode);
//FMOD_RESULT F_API FMOD_DSP_GetChannelFormat             (FMOD_DSP *dsp, FMOD_CHANNELMASK *channelmask, int *numchannels, FMOD_SPEAKERMODE *source_speakermode);
//FMOD_RESULT F_API FMOD_DSP_GetOutputChannelFormat       (FMOD_DSP *dsp, FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE inspeakermode, FMOD_CHANNELMASK *outmask, int *outchannels, FMOD_SPEAKERMODE *outspeakermode);
        /** @brief reset
          * Calls the DSP unit's reset function, which will clear internal buffers and reset the unit back to an initial state.
          * This reset Function can be a custom CallBack if you used a FMOD_DSP_DESCRIPTION when making it **/
        virtual void reset();
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_SetParameterFloat            (FMOD_DSP *dsp, int index, float value);
//FMOD_RESULT F_API FMOD_DSP_SetParameterInt              (FMOD_DSP *dsp, int index, int value);
//FMOD_RESULT F_API FMOD_DSP_SetParameterBool             (FMOD_DSP *dsp, int index, FMOD_BOOL value);
//FMOD_RESULT F_API FMOD_DSP_SetParameterData             (FMOD_DSP *dsp, int index, void *data, unsigned int length);
//FMOD_RESULT F_API FMOD_DSP_GetParameterFloat            (FMOD_DSP *dsp, int index, float *value, char *valuestr, int valuestrlen);
//FMOD_RESULT F_API FMOD_DSP_GetParameterInt              (FMOD_DSP *dsp, int index, int *value, char *valuestr, int valuestrlen);
//FMOD_RESULT F_API FMOD_DSP_GetParameterBool             (FMOD_DSP *dsp, int index, FMOD_BOOL *value, char *valuestr, int valuestrlen);
//FMOD_RESULT F_API FMOD_DSP_GetParameterData             (FMOD_DSP *dsp, int index, void **data, unsigned int *length, char *valuestr, int valuestrlen);
        /** @brief getNumParameters
          * @return number of parameters **/
        virtual int getNumParameters();
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_GetParameterInfo             (FMOD_DSP *dsp, int index, FMOD_DSP_PARAMETER_DESC **desc);
//FMOD_RESULT F_API FMOD_DSP_GetDataParameterIndex        (FMOD_DSP *dsp, int datatype, int *index);
//FMOD_RESULT F_API FMOD_DSP_ShowConfigDialog             (FMOD_DSP *dsp, void *hwnd, FMOD_BOOL show);
//FMOD_RESULT F_API FMOD_DSP_GetInfo                      (FMOD_DSP *dsp, char *name, unsigned int *version, int *channels, int *configwidth, int *configheight);
        /** @brief getType
          * @return the FMOD_DSP_TYPE **/
        virtual FMOD_DSP_TYPE getType();
        /** @brief isIdle
          * @return true if idle false otherwise **/
        virtual bool isIdle();
// TODO: implement these
//FMOD_RESULT F_API FMOD_DSP_SetMeteringEnabled           (FMOD_DSP *dsp, FMOD_BOOL inputEnabled, FMOD_BOOL outputEnabled);
//FMOD_RESULT F_API FMOD_DSP_GetMeteringEnabled           (FMOD_DSP *dsp, FMOD_BOOL *inputEnabled, FMOD_BOOL *outputEnabled);
//FMOD_RESULT F_API FMOD_DSP_GetMeteringInfo              (FMOD_DSP *dsp, FMOD_DSP_METERING_INFO *inputInfo, FMOD_DSP_METERING_INFO *outputInfo);
        /** @brief getFMODDSP
          * @return FMOD_DSP object **/
        virtual FMOD_DSP* getFMODDSP();

    protected:
        // FMOD DSP
        FMOD_DSP* pDSP;
};

#endif // DSP_H
