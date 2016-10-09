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

//void DSP::play(FMOD_CHANNEL** pChannel)
//{
//
//}
//
//void DSP::play(FMOD_CHANNELGROUP* channelGroup)
//{
//
//}

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

FMOD_DSP* DSP::getFMODDSP()
{
    // Return FMOD-DSP
    return this->pDSP;
}
