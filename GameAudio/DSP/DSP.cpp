#include "DSP.h"

DSP::DSP()
{
    // DSP
    this->pDSP = 0;
    // Config Dialog Flag
    this->configDialogFlag = false;
}

DSP::~DSP()
{

}

bool DSP::create(FMOD_DSP_DESCRIPTION description)
{
    // Try and create the DSP
    FMOD_RESULT result;
    result = FMOD_System_CreateDSP(FMODGlobals::pFMODSystem, &description, &(this->pDSP));
    if (this->pDSP != 0)
    {
        // Set userdata as this class for out DSP Object
        FMOD_DSP_SetUserData(this->pDSP, (void*)this);
    }
    // Return result
    return result;
}

bool DSP::create(FMOD_DSP_TYPE type)
{
    // Try and create the DSP
    FMOD_RESULT result;
    result = FMOD_System_CreateDSPByType(FMODGlobals::pFMODSystem, type, &(this->pDSP));
    if (this->pDSP != 0)
    {
        // Set userdata as this class for out DSP Object
        FMOD_DSP_SetUserData(this->pDSP, (void*)this);
    }
    // Return result
    return result;
}

bool DSP::create(unsigned int pluginNandle)
{
    // Try and create the DSP
    FMOD_RESULT result;
    result = FMOD_System_CreateDSPByPlugin(FMODGlobals::pFMODSystem, pluginNandle, &(this->pDSP));
    if (this->pDSP != 0)
    {
        // Set userdata as this class for out DSP Object
        FMOD_DSP_SetUserData(this->pDSP, (void*)this);
    }
    // Return result
    return result;
}

FMOD_CHANNEL* DSP::playChannel()
{
    // Play our DSP on a channel
    FMOD_CHANNEL* pChannel = 0;
    FMOD_System_PlayDSP(FMODGlobals::pFMODSystem, this->pDSP, 0, false, &pChannel);
    // return pChannel
    return pChannel;
}

FMOD_CHANNEL* DSP::playChannelEx()
{
    // Play our DSP on a channel
    FMOD_CHANNEL* pChannel = 0;
    FMOD_System_PlayDSP(FMODGlobals::pFMODSystem, this->pDSP, 0, true, &pChannel);
    // return pChannel
    return pChannel;
}

FMOD_CHANNEL* DSP::playChannelGroup(FMOD_CHANNELGROUP* pChannelGroup)
{
    // Play our DSP on a channel
    FMOD_CHANNEL* pChannel = 0;
    FMOD_System_PlayDSP(FMODGlobals::pFMODSystem, this->pDSP, pChannelGroup, false, &pChannel);
    // return pChannel
    return pChannel;
}

FMOD_CHANNEL* DSP::playChannelGroupEx(FMOD_CHANNELGROUP* pChannelGroup)
{
    // Play our DSP on a channel
    FMOD_CHANNEL* pChannel = 0;
    FMOD_System_PlayDSP(FMODGlobals::pFMODSystem, this->pDSP, pChannelGroup, true, &pChannel);
    // return pChannel
    return pChannel;
}

void DSP::release()
{
    // If we have an FMOD_DSP then Release it
    if (this->pDSP != 0)
    {
        FMOD_DSP_Release(this->pDSP);
    }
    // Clean up the FMOD_DSP Pointer
    this->pDSP = 0;
}

FMOD_DSPCONNECTION* DSP::addInput(FMOD_DSP* pInputDSP, FMOD_DSPCONNECTION_TYPE type)
{
    // Add Input from another DSP
    FMOD_DSPCONNECTION* pDSPConnection = 0;
    FMOD_DSP_AddInput(this->pDSP, pInputDSP, &pDSPConnection, type);
    //return pDSPConnection
    return pDSPConnection;
}

void DSP::disconnectFrom(FMOD_DSP* pTargetDSP, FMOD_DSPCONNECTION* pDSPConnection)
{
    // Disconnect From
    FMOD_DSP_DisconnectFrom(this->pDSP, pTargetDSP, pDSPConnection);
}

void DSP::disconnectAll(bool inputs, bool outputs)
{
    // Disconnect All
    FMOD_DSP_DisconnectAll(this->pDSP, inputs, outputs);
}

int DSP::getNumberOfInputs()
{
    // Grab the Number of Inputs
    int numberOfInputs = 0;
    FMOD_DSP_GetNumInputs(this->pDSP, &numberOfInputs);
    //return numberOfInputs
    return numberOfInputs;
}

int DSP::getNumberOfOutputs()
{
    // Grab the Number of Outputs
    int numberOfOutputs = 0;
    FMOD_DSP_GetNumOutputs(this->pDSP, &numberOfOutputs);
    //return numberOfOutputs
    return numberOfOutputs;
}

FMOD_DSP* DSP::getDSPInput(int index)
{
    FMOD_DSP* pDSPInput = 0;
    FMOD_DSP_GetInput(this->pDSP, index, &pDSPInput, 0);
    // return pDSPInput
    return pDSPInput;
}

FMOD_DSPCONNECTION* DSP::getDSPInputConnection(int index)
{
    // Grab DSPConnection
    FMOD_DSPCONNECTION* pDSPConnection = 0;
    FMOD_DSP_GetInput(this->pDSP, index, 0, &pDSPConnection);
    // return pDSPConnection
    return pDSPConnection;
}

FMOD_DSP* DSP::getDSPOutput(int index)
{
    FMOD_DSP* pDSPOutput = 0;
    FMOD_DSP_GetOutput(this->pDSP, index, &pDSPOutput, 0);
    // return pDSPOutput
    return pDSPOutput;
}

FMOD_DSPCONNECTION* DSP::getDSPOutputConnection(int index)
{
    // Grab DSPConnection
    FMOD_DSPCONNECTION* pDSPConnection = 0;
    FMOD_DSP_GetOutput(this->pDSP, index, 0, &pDSPConnection);
    // return pDSPConnection
    return pDSPConnection;
}

bool DSP::getActive()
{
    // Grab activeFlag
    FMOD_BOOL activeFlag = false;
    FMOD_DSP_GetActive(this->pDSP, &activeFlag);
    // return activeFlag
    return activeFlag;
}

void DSP::setActive(bool activeFlag)
{
    // Only work when we have a DSP
    if (this->pDSP == 0)
        return;
    // Set Active Flag
    FMOD_DSP_SetActive(this->pDSP, activeFlag);
}

bool DSP::getBypass()
{
    // Grab bypassFlag
    FMOD_BOOL bypassFlag = false;
    FMOD_DSP_GetBypass(this->pDSP, &bypassFlag);
    // return bypassFlag
    return bypassFlag;
}

void DSP::setBypass(bool bypassFlag)
{
    // Set the Bypass Flag
    FMOD_DSP_SetBypass(this->pDSP, bypassFlag);
}

float DSP::getPrewet()
{
    // Grab WetDryMix
    float prewet = 0.0f;
    float postwet = 0.0f;
    float dry = 0.0f;
    FMOD_DSP_GetWetDryMix(this->pDSP, &prewet, &postwet, &dry);
    // return prewet
    return prewet;
}

float DSP::getPostwet()
{
    // Grab WetDryMix
    float prewet = 0.0f;
    float postwet = 0.0f;
    float dry = 0.0f;
    FMOD_DSP_GetWetDryMix(this->pDSP, &prewet, &postwet, &dry);
    // return postwet
    return postwet;
}

float DSP::getDry()
{
    // Grab WetDryMix
    float prewet = 0.0f;
    float postwet = 0.0f;
    float dry = 0.0f;
    FMOD_DSP_GetWetDryMix(this->pDSP, &prewet, &postwet, &dry);
    // return dry
    return dry;
}

void DSP::setWetDryMix(float prewet, float postwet, float dry)
{
    // Set Wet Dry Mix
    FMOD_DSP_SetWetDryMix(this->pDSP, prewet, postwet, dry);
}

FMOD_CHANNELMASK* DSP::getChannelMask()
{
    // Grab Channel Mask
    FMOD_CHANNELMASK* pChannelMask = 0;
    FMOD_DSP_GetChannelFormat(this->pDSP, pChannelMask, 0, 0);
    //return pChannelMask
    return pChannelMask;
}

int DSP::getNumChannels()
{
    // Grab number of channels
    int numberOfChannels = 0;
    FMOD_DSP_GetChannelFormat(this->pDSP, 0, &numberOfChannels, 0);
    //return numberOfChannels
    return numberOfChannels;
}

FMOD_SPEAKERMODE* DSP::getSpeakerMode()
{
    // Grab SpeakerMode
    FMOD_SPEAKERMODE* pSpeakerMode = 0;
    FMOD_DSP_GetChannelFormat(this->pDSP, 0, 0, pSpeakerMode);
    //return pSpeakerMode
    return pSpeakerMode;
}

void DSP::setChannelFormat(FMOD_CHANNELMASK channelMask, int numChannels, FMOD_SPEAKERMODE speakerMode)
{
    // Set Channel Format
    FMOD_DSP_SetChannelFormat(this->pDSP, channelMask, numChannels, speakerMode);
}

FMOD_CHANNELMASK* DSP::getOutputChannelFormatOutputMask(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode)
{
    // Grab ChannelMask
    FMOD_CHANNELMASK* pChannelMask = 0;
    FMOD_DSP_GetOutputChannelFormat(this->pDSP, inputChannelMask, inputChannels, inputSpeakerMode, pChannelMask, 0, 0);
    // return pChannelMask
    return pChannelMask;
}

int DSP::getOutputChannelFormatOutputChannels(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode)
{
    // Grab output channels
    int outputChannels = 0;
    FMOD_DSP_GetOutputChannelFormat(this->pDSP, inputChannelMask, inputChannels, inputSpeakerMode, 0, &outputChannels, 0);
    // return outputChannels
    return outputChannels;
}

FMOD_SPEAKERMODE* DSP::getOutputChannelFormatOutputSpeakerMode(FMOD_CHANNELMASK inputChannelMask, int inputChannels, FMOD_SPEAKERMODE inputSpeakerMode)
{
    // Grab Output Speaker Mode
    FMOD_SPEAKERMODE* pOutputSpeakerMode = 0;
    FMOD_DSP_GetOutputChannelFormat(this->pDSP, inputChannelMask, inputChannels, inputSpeakerMode, 0, 0, pOutputSpeakerMode);
    // return pOutputSpeakerMode
    return pOutputSpeakerMode;
}

void DSP::reset()
{
    // Only work when we have a DSP
    if (this->pDSP == 0)
        return;
    // Reset the DSP
    FMOD_DSP_Reset(this->pDSP);
}

float DSP::getParameterFloat(int index)
{
    // Grab float value
    float value = 0.0f;
    FMOD_DSP_GetParameterFloat(this->pDSP, index, &value, 0, 0);
    //return value
    return value;
}

void DSP::setParameterFloat(int index, float value)
{
    // Set Float Parameter for the DSP
    FMOD_DSP_SetParameterFloat(this->pDSP, index, value);
}

int DSP::getParameterInt(int index)
{
    // Grab int value
    int value = 0.0f;
    FMOD_DSP_GetParameterInt(this->pDSP, index, &value, 0, 0);
    //return value
    return value;
}

void DSP::setParameterInt(int index, int value)
{
    // Set int Parameter for the DSP
    FMOD_DSP_SetParameterInt(this->pDSP, index, value);
}

bool DSP::getParameterBool(int index)
{
    // Grab bool value
    FMOD_BOOL value = 0.0f;
    FMOD_DSP_GetParameterBool(this->pDSP, index, &value, 0, 0);
    //return value
    return value;
}

void DSP::setParameterBool(int index, bool value)
{
    // Set bool Parameter for the DSP
    FMOD_DSP_SetParameterBool(this->pDSP, index, value);
}

void* DSP::getParameterData(int index)
{
    // Grab Data
    void* pData = 0;
    FMOD_DSP_GetParameterData(this->pDSP, index, &pData, 0, 0, 0);
    //return pData
    return pData;
}

unsigned int DSP::getParameterDataSize(int index)
{
    // Grab Data Size
    unsigned int dataSize = 0;
    FMOD_DSP_GetParameterData(this->pDSP, index, 0, &dataSize, 0, 0);
    // return dataSize
    return dataSize;
}

void DSP::setParameterData(int index, void* pData, unsigned int length)
{
    // Set Data by undex for the DSP
    FMOD_DSP_SetParameterData(this->pDSP, index, pData, length);
}

int DSP::getNumParameters()
{
    // Get Number of Parameters
    int numberOfParameters = 0;
    FMOD_DSP_GetNumParameters(this->pDSP, &numberOfParameters);
    // return numberOfParameters
    return numberOfParameters;
}

FMOD_DSP_PARAMETER_DESC* DSP::getParameterInfo(int index)
{
    // Get Descriptions
    FMOD_DSP_PARAMETER_DESC* pDescription;
    FMOD_DSP_GetParameterInfo(this->pDSP, index, &pDescription);
    // return pDescription
    return pDescription;
}

int DSP::getDataParameterIndex(int dataType)
{
    // Grab index of the first variable of the data type
    int index = 0;
    FMOD_DSP_GetDataParameterIndex(this->pDSP, dataType, &index);
    // return index
    return index;
}

bool DSP::isConfigDialogBoxVisible()
{
    // return configDialogFlag
    return this->configDialogFlag;
}

void DSP::showConfigDialog(void* hwnd)
{
    // Show Config Dialog
    this->configDialogFlag = true;
    FMOD_DSP_ShowConfigDialog(this->pDSP, hwnd, true);
}

void DSP::hideConfigDialog(void* hwnd)
{
    // Hide Config Dialog
    this->configDialogFlag = false;
    FMOD_DSP_ShowConfigDialog(this->pDSP, hwnd, false);
}

std::string DSP::getName()
{
    // Grab name
    char* name = 0;
    FMOD_DSP_GetInfo(this->pDSP, name, 0, 0, 0, 0);
    // return name
    return std::string(name);
}

unsigned int DSP::getVersion()
{
    //FMOD_RESULT F_API FMOD_DSP_GetInfo                      (FMOD_DSP *dsp, char *name, unsigned int *version, int *channels, int *configwidth, int *configheight);
}

int DSP::getConfigWidth()
{
 //FMOD_RESULT F_API FMOD_DSP_GetInfo                      (FMOD_DSP *dsp, char *name, unsigned int *version, int *channels, int *configwidth, int *configheight);
}

int DSP::getConfigHeight()
{
    //FMOD_RESULT F_API FMOD_DSP_GetInfo                      (FMOD_DSP *dsp, char *name, unsigned int *version, int *channels, int *configwidth, int *configheight);
}

FMOD_DSP_TYPE DSP::getType()
{
    // Get type
    FMOD_DSP_TYPE type;
    FMOD_DSP_GetType(this->pDSP, &type);
    // return type
    return type;
}

bool DSP::isIdle()
{
    // Grab IdleFlag
    FMOD_BOOL idleFlag = false;
    FMOD_DSP_GetIdle(this->pDSP, &idleFlag);
    // return idleFlag
    return idleFlag;
}

bool DSP::isMeteringInputEnabled()
{
    // Grab input enabled flag
    FMOD_BOOL inputEnabledFlag = false;
    FMOD_DSP_GetMeteringEnabled(this->pDSP, &inputEnabledFlag, 0);
    // return inputEnabledFlag
    return inputEnabledFlag;
}

void DSP::setInputMetering(bool state)
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, state, this->isMeteringOutputEnabled());
}

void DSP::enableInputMetering()
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, true, this->isMeteringOutputEnabled());
}

void DSP::disableInputMetering()
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, false, this->isMeteringOutputEnabled());
}

bool DSP::isMeteringOutputEnabled()
{
    // Grab output enabled flag
    FMOD_BOOL outputEnabledFlag = false;
    FMOD_DSP_GetMeteringEnabled(this->pDSP, 0, &outputEnabledFlag);
    // return outputEnabledFlag
    return outputEnabledFlag;
}

void DSP::setOutputMetering(bool state)
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, this->isMeteringInputEnabled(), state);
}

void DSP::enableOutputMetering()
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, this->isMeteringInputEnabled(), true);
}

void DSP::disableOutputMetering()
{
    // Set Metering Enabled
    FMOD_DSP_SetMeteringEnabled(this->pDSP, this->isMeteringInputEnabled(), false);
}

FMOD_DSP_METERING_INFO* DSP::getInputMeteringInfo()
{
    // Grab Metering Info
    FMOD_DSP_METERING_INFO* pDSPMeteringInfo = 0;
    FMOD_DSP_GetMeteringInfo(this->pDSP, pDSPMeteringInfo, 0);
    // return pDSPMeteringInfo
    return pDSPMeteringInfo;
}

FMOD_DSP_METERING_INFO* DSP::getOutputMeteringInfo()
{
    // Grab Metering Info
    FMOD_DSP_METERING_INFO* pDSPMeteringInfo = 0;
    FMOD_DSP_GetMeteringInfo(this->pDSP, 0, pDSPMeteringInfo);
    // return pDSPMeteringInfo
    return pDSPMeteringInfo;
}

FMOD_DSP* DSP::getFMODDSP()
{
    // Return FMOD-DSP
    return this->pDSP;
}
