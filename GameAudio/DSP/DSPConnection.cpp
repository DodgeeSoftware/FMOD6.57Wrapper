#include "DSPConnection.h"

DSPConnection::DSPConnection()
{
    this->pDSPConnection = 0;
}

DSPConnection::~DSPConnection()
{
    //dtor
}

FMOD_DSP* DSPConnection::getInputDSP()
{
    // Grab DSP
    FMOD_DSP* pDSP = 0;
    FMOD_DSPConnection_GetInput(this->pDSPConnection, &pDSP);
    // Return DSP
    return pDSP;

}

FMOD_DSP* DSPConnection::getOutputDSP()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetOutput          (FMOD_DSPCONNECTION *dspconnection, FMOD_DSP **output);
}

float DSPConnection::getMix()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetMix             (FMOD_DSPCONNECTION *dspconnection, float *volume);
}

void DSPConnection::setMix(float volume)
{
//FMOD_RESULT F_API FMOD_DSPConnection_SetMix             (FMOD_DSPCONNECTION *dspconnection, float volume);
}

float* DSPConnection::getMatrix()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetMixMatrix       (FMOD_DSPCONNECTION *dspconnection, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
}

int DSPConnection::getNumberOfInChannels()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetMixMatrix       (FMOD_DSPCONNECTION *dspconnection, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
}

int DSPConnection::getNumberOfOutChannels()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetMixMatrix       (FMOD_DSPCONNECTION *dspconnection, float *matrix, int *outchannels, int *inchannels, int inchannel_hop);
}

void DSPConnection::setMatrix(float* matrix, int outChannels, int inChannels)
{
//FMOD_RESULT F_API FMOD_DSPConnection_SetMixMatrix       (FMOD_DSPCONNECTION *dspconnection, float *matrix, int outchannels, int inchannels, int inchannel_hop);
}

FMOD_DSPCONNECTION_TYPE DSPConnection::getType()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetType            (FMOD_DSPCONNECTION *dspconnection, FMOD_DSPCONNECTION_TYPE *type);
}

void* DSPConnection::getUserData()
{
//FMOD_RESULT F_API FMOD_DSPConnection_GetUserData        (FMOD_DSPCONNECTION *dspconnection, void **userdata);
}

void DSPConnection::setUserData(void* pUserData)
{
//FMOD_RESULT F_API FMOD_DSPConnection_SetUserData        (FMOD_DSPCONNECTION *dspconnection, void *userdata);
}
