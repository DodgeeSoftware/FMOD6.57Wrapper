#ifndef DSP_H
#define DSP_H

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
// TODO: what do I do with this function
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
//        FMOD_System_PlayDSP
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
        /** @brief getPrewet
          * @return prewet floating point value from 0 to 1, describing a linear scale of the 'wet'
          * (pre-processed signal) mix of the effect. Default = 1.0. Scale can be lower than 0 (negating) and higher than 1 (amplifying) **/
        virtual float getPrewet();
        /** @brief getPostwet
          * @return Floating point value from 0 to 1, describing a linear scale of the 'wet'
          * (post-processed signal) mix of the effect. Default = 1.0. Scale can be lower than 0 (negating) and higher than 1 (amplifying) **/
        virtual float getPostwet();
        /** @brief getDry
          * @return Floating point value from 0 to 1, describing a linear scale of the 'dry' (pre-processed signal) mix of the effect.
          * Default = 0.0. Scale can be lower than 0 and higher than 1 (amplifying) **/
        virtual float getDry();
        /** @brief setWetDryMix
          * Allows the user to scale the affect of a DSP effect, through control of the 'wet' mix,
          * which is the post-processed signal and the 'dry' which is the pre-processed signal.
          * @param prewet floating point value from 0 to 1, describing a linear scale of the 'wet'
          * (pre-processed signal) mix of the effect. Default = 1.0. Scale can be lower than 0 (negating) and higher than 1 (amplifying).
          * @param postwet Floating point value from 0 to 1, describing a linear scale of the 'wet'
          * (post-processed signal) mix of the effect. Default = 1.0. Scale can be lower than 0 (negating) and higher than 1 (amplifying).
          * @param dry Floating point value from 0 to 1, describing a linear scale of the 'dry' (pre-processed signal) mix of the effect.
          * Default = 0.0. Scale can be lower than 0 and higher than 1 (amplifying) **/
        virtual void setWetDryMix(float prewet, float postwet, float dry);
        // TODO: implement these
        //FMOD_RESULT F_API FMOD_DSP_SetChannelFormat             (FMOD_DSP *dsp, FMOD_CHANNELMASK channelmask, int numchannels, FMOD_SPEAKERMODE source_speakermode);
        //FMOD_RESULT F_API FMOD_DSP_GetChannelFormat             (FMOD_DSP *dsp, FMOD_CHANNELMASK *channelmask, int *numchannels, FMOD_SPEAKERMODE *source_speakermode);
        //FMOD_RESULT F_API FMOD_DSP_GetOutputChannelFormat       (FMOD_DSP *dsp, FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE inspeakermode, FMOD_CHANNELMASK *outmask, int *outchannels, FMOD_SPEAKERMODE *outspeakermode);
        /** @brief reset
          * Calls the DSP unit's reset function, which will clear internal buffers and reset the unit back to an initial state.
          * This reset Function can be a custom CallBack if you used a FMOD_DSP_DESCRIPTION when making it **/
        virtual void reset();
        /** @brief getParameterFloat
          * @return the value of the float at index **/
        virtual float getParameterFloat(int index);
        /** @brief setParameterFloat
          * @param index index of the float
          * @param value to set the float to **/
        virtual void setParameterFloat(int index, float value);
        /** @brief getParameterInt
          * @param index index of the int  **/
        virtual int getParameterInt(int index);
        /** @brief setParameterInt
          * @param index index of the int
          * @param value to set the int to **/
        virtual void setParameterInt(int index, int value);
        /** @brief getParameterBool
          * @param int index of the bool **/
        virtual bool getParameterBool(int index);
        /** @brief setParameterBool
          * @param index index of the bool
          * @param value to set the bool to **/
        virtual void setParameterBool(int index, bool value);
        /** @brief getParameterData
          * @param index index of the void* pointer
          * @param length size of the data **/
        virtual void* getParameterData(int index);
        /** @brief getParameterDataSize
          * @param index index of the data pointer
          * @return size of the void* data **/
        virtual unsigned int getParameterDataSize(int index);
        /** @brief setParameterData
          * @param index index of the void* pointer
          * @param length length of the **/
        virtual void setParameterData(int index, void* pData, unsigned int length);
        /** @brief getNumParameters
          * @return number of parameters **/
        virtual int getNumParameters();
        /** @brief getParameterInfo
          * @return FMOD_DSP_PARAMETER_DESC object **/
        virtual FMOD_DSP_PARAMETER_DESC* getParameterInfo(int index);
        /** @brief  getDataParameterIndex
          * @param dataType FMOD_DSP_PARAMETER_DATA_TYPE
          * @return the index of the first data parameter of a particular data type. **/
        virtual int getDataParameterIndex(int dataType);
        /** @brief isConfigDialogBoxVisible
          * @return true if visible false otherwise **/
        virtual bool isConfigDialogBoxVisible();
        /** @brief showConfigDialog
          * @param hwnd handle to a window **/
        virtual void showConfigDialog(void* hwnd);
        /** @brief hideConfigDialog
          * @param hwnd handle to a window **/
        virtual void hideConfigDialog(void* hwnd);
        /** @brief getName
          * @return the name of the unit. This will be a maximum of 32bytes.
          * If the DSP unit has filled all 32 bytes with the name with no terminating \0 null character it is
          * up to the caller to append a null character. Optional. Specify 0 or NULL to ignore. **/
        virtual std::string getName();
        /** @brief getVersion
          * @return the version number of the DSP unit. Version number is
          * usually formated as hex AAAABBBB where the AAAA is the major version number and the BBBB is the
          * minor version number **/
        virtual unsigned int getVersion();
        /** @brief getConfigWidth
          * @return the width of an optional configuration dialog box that can be displayed with
          * DSP::showConfigDialog **/
        virtual int getConfigWidth();
        /** @brief getConfigHeight
          * @return the height of an optional configuration dialog box that can be displayed with
          * DSP::showConfigDialog **/
        virtual int getConfigHeight();
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
        // Config Diaglog Flag
        bool configDialogFlag;
};

#endif // DSP_H
