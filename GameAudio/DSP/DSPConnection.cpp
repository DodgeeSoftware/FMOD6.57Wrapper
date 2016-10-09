#include "DSPConnection.h"

DSPConnection::DSPConnection()
{
    this->pDSPConnection = 0;
}

DSPConnection::~DSPConnection()
{

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
    // Grab DSP
    FMOD_DSP* pDSP = 0;
    FMOD_DSPConnection_GetOutput(this->pDSPConnection, &pDSP);
    // return pDSP
    return pDSP;
}

float DSPConnection::getMix()
{
    // Get Volume
    float volume = 0.0f;
    FMOD_DSPConnection_GetMix(this->pDSPConnection, &volume);
    // return volume
    return volume;
}

void DSPConnection::setMix(float volume)
{
    // Set Volume
    FMOD_DSPConnection_SetMix(this->pDSPConnection, volume);
}

float* DSPConnection::getMatrix()
{
    // Get Matrix
    float* matrix = 0;
    FMOD_DSPConnection_GetMixMatrix(this->pDSPConnection, matrix, 0, 0, 0); // TODO: the last value here int inchannel_hop is incorrect, I don't know how to calc the correct value
    // return matrix
    return matrix;
}

int DSPConnection::getNumberOfInChannels()
{
    // Get in Channels
    int inChannels = 0;
    FMOD_DSPConnection_GetMixMatrix(this->pDSPConnection, 0, 0, &inChannels, 0); // TODO: the last value here int inchannel_hop is incorrect, I don't know how to calc the correct value
    // return inChannels
    return inChannels;
}

int DSPConnection::getNumberOfOutChannels()
{
    // Get number of out channels
    int outChannels = 0;
    FMOD_DSPConnection_GetMixMatrix(this->pDSPConnection, 0, &outChannels, 0, 0); // TODO: the last value here int inchannel_hop is incorrect, I don't know how to calc the correct value
}

void DSPConnection::setMatrix(float* matrix, int outChannels, int inChannels)
{
    // Set matrix
    FMOD_DSPConnection_SetMixMatrix(this->pDSPConnection, matrix, this->getNumberOfOutChannels(), this->getNumberOfInChannels(), 0); // TODO: the last value here int inchannel_hop is incorrect, I don't know how to calc the correct value
}

FMOD_DSPCONNECTION_TYPE DSPConnection::getType()
{
    // Grab type
    FMOD_DSPCONNECTION_TYPE type;
    FMOD_DSPConnection_GetType(this->pDSPConnection, &type);
    //return type
    return type;
}

void* DSPConnection::getUserData()
{
    // Grab User Data
    void* pUserData = 0;
    FMOD_DSPConnection_GetUserData(this->pDSPConnection, &pUserData);
    // return pUserData
    return pUserData;
}

void DSPConnection::setUserData(void* pUserData)
{
    // Set user data for the DSP Connection
    FMOD_DSPConnection_SetUserData(this->pDSPConnection, pUserData);
}
