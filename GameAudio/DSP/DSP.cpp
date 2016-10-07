#include "DSP.h"

DSP::DSP()
{
    // DSP
    this->pDSP = 0;
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

void DSP::reset()
{
    // Only work when we have a DSP
    if (this->pDSP == 0)
        return;
    // Reset the DSP
    FMOD_DSP_Reset(this->pDSP);
}

int DSP::getNumParameters()
{
    // Get Number of Parameters
    int numberOfParameters = 0;
    FMOD_DSP_GetNumParameters(this->pDSP, &numberOfParameters);
    // return numberOfParameters
    return numberOfParameters;
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
