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
        DSP(DSP& other);

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
        /** @brief playChannel
          * Plays a DSP unit object and its input network on a channel
          * @return the channel the DSP effect is playing on **/
        virtual FMOD_CHANNEL* playChannel();
        /** @brief playChannelEx
          * Plays a DSP unit object and its input network on a channel but pauses it
          * @return the channel the DSP effect is playing on **/
        virtual FMOD_CHANNEL* playChannelEx();
        /** @brief playChannelGroup
          * Plays a DSP unit object and its input network on a particular ChannelGroup
          * @return the channelGroup the dsp is playing on **/
        virtual FMOD_CHANNEL* playChannelGroup(FMOD_CHANNELGROUP* pChannelGroup);
        /** @brief playChannelGroupEx
          * Plays a DSP unit object and its input network on a particular ChannelGroup
          * @return the channelGroup the dsp is playing on **/
        virtual FMOD_CHANNEL* playChannelGroupEx(FMOD_CHANNELGROUP* pChannelGroup);
        /** @brief release **/
        virtual void release();
        /** @brief addInput
          * @param pInputDSP input DSP
          * @param type define the type of connection valid values are FMOD_DSPCONNECTION_TYPE
          * @return a FMOD_DSPCONNECTION **/
        virtual FMOD_DSPCONNECTION* addInput(FMOD_DSP* pInputDSP, FMOD_DSPCONNECTION_TYPE type);
        /** @brief disconnectFrom
          * @param pTargetDSP [optional] use this to disconnect a DSP from this DSP
          * @param pDSPConnection [optional] use this to disconnect a DSPConnection from this DSP **/
        virtual void disconnectFrom(FMOD_DSP* pTargetDSP, FMOD_DSPCONNECTION* pDSPConnection);
        /** @brief disconnectAll
          * @param inputs set to true if you want to disconnect all inputs
          * @param outputs set to true if you want to disconnect all outputs **/
        virtual void disconnectAll(bool inputs, bool outputs);
        /** @brief getNumberOfInputs
          * @return Retrieves the number of inputs connected to the DSP unit **/
        virtual int getNumberOfInputs();
        /** @brief getNumberOfOutputs
          * @return number of outputs **/
        virtual int getNumberOfOutputs();
        /** @brief getDSPInput
          * @param index of the DSP input we want to get
          * @return FMOD_DSP **/
        virtual FMOD_DSP* getDSPInput(int index);
        /** @brief  getDSPInputConnection
        * @param index of the DSPConnection we want to get
        * @return FMOD_DSP **/
        virtual FMOD_DSPCONNECTION* getDSPInputConnection(int index);
        /** @brief getDSPOutput
          * @param index of the DSP input we want to get
          * @return FMOD_DSP **/
        virtual FMOD_DSP* getDSPOutput(int index);
        /** @brief  getDSPOutputConnection
        * @param index of the DSPConnection we want to get
        * @return FMOD_DSP **/
        virtual FMOD_DSPCONNECTION* getDSPOutputConnection(int index);
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
        /** @brief getChannelMask
          * @return Address of a variable that receives the FMOD_CHANNELMASK which
          * determines which speakers are represented by the channels in the input signal **/
        virtual FMOD_CHANNELMASK* getChannelMask();
        /** @brief getNumChannels
          * @return the number of channels to be processed on this unit **/
        virtual int getNumChannels();
        /** @brief getSpeakerMode
          * @return the source speaker mode where the signal came from **/
        virtual FMOD_SPEAKERMODE* getSpeakerMode();
        /** @brief setChannelFormat
          * @param channelMask A series of bits specified by FMOD_CHANNELMASK to determine which speakers are represented by the channels in the signal
          * @param numChannels The number of channels to be processed on this unit and sent to the outputs connected to it. Maximum of FMOD_MAX_CHANNEL_WIDTH
          * @param speakerMode The source speaker mode where the signal came from. See remarks **/
        virtual void setChannelFormat(FMOD_CHANNELMASK channelMask, int numChannels, FMOD_SPEAKERMODE speakerMode);
        /** @brief getOutputChannelFormatOutputMask
          * @param inputChannelMask Channel bitmask representing the speakers enabled for the incoming signal.
          * For example a 5.1 signal could have inchannels 2 that represent FMOD_CHANNELMASK_SURROUND_LEFT and FMOD_CHANNELMASK_SURROUND_RIGHT
          * @param inputChannels Number of channels for the incoming signal
          * @param inputSpeakerMode Speaker mode for the incoming signal
          * @return  the DSP unit's output mask, based on the DSP units preference and settings **/
        virtual FMOD_CHANNELMASK* getOutputChannelFormatOutputMask(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode);
        /** @brief getOutputChannelFormatOutputChannels
          * @param inputChannelMask Channel bitmask representing the speakers enabled for the incoming signal.
          * For example a 5.1 signal could have inchannels 2 that represent FMOD_CHANNELMASK_SURROUND_LEFT and FMOD_CHANNELMASK_SURROUND_RIGHT
          * @param inputChannels Number of channels for the incoming signal
          * @param inputSpeakerMode Speaker mode for the incoming signal
          * @return the DSP unit's output channel count, based on the DSP units preference and settings **/
        virtual int getOutputChannelFormatOutputChannels(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode);
        /** @brief getOutputChannelFormatOutputSpeakerMode
          * @param inputChannelMask Channel bitmask representing the speakers enabled for the incoming signal.
          * For example a 5.1 signal could have inchannels 2 that represent FMOD_CHANNELMASK_SURROUND_LEFT and FMOD_CHANNELMASK_SURROUND_RIGHT
          * @param inputChannels Number of channels for the incoming signal
          * @param inputSpeakerMode Speaker mode for the incoming signal
          * @return the DSP unit's output speaker mode, based on the DSP units preference and settings **/
        virtual FMOD_SPEAKERMODE* getOutputChannelFormatOutputSpeakerMode(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode);
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
        /** @brief isMeteringInputEnabled
          * @return true if input metering is enabled **/
        virtual bool isMeteringInputEnabled();
        /** @brief setInputMetering
          * @param state true to enable input metering otherwise set to false **/
        virtual void setInputMetering(bool state);
        /** @brief enableInputMetering
          * enable Input Metering **/
        virtual void enableInputMetering();
        /** @brief disableInputMetering
          * disable Input Metering **/
        virtual void disableInputMetering();
        /** @brief isMeteringOutputEnabled
          * @return true if output metering is enabled **/
        virtual bool isMeteringOutputEnabled();;
        /** @brief setOutputMetering
          * @param state true to enable output metering otherwise set to false **/
        virtual void setOutputMetering(bool state);
        /** @brief enableOutputMetering
          * enable output metering **/
        virtual void enableOutputMetering();
        /** @brief disableOutputMetering
          * disable output metering **/
        virtual void disableOutputMetering();
        /** @brief getInputMeteringInfo
          * @return input metering info as an FMOD_DSP_METERING_INFO **/
        virtual FMOD_DSP_METERING_INFO* getInputMeteringInfo();
        /** @brief getOutputMeteringInfo
          * @return output metering info as an FMOD_DSP_METERING_INFO **/
        virtual FMOD_DSP_METERING_INFO* getOutputMeteringInfo();
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
