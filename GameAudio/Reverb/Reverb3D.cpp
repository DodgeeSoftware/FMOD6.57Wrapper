#include "Reverb3D.h"

Reverb3D::Reverb3D()
{
    // FMODRever3D
    this->pFMODReverb3D = 0;
    // Active Flag
    this->activeFlag = true;
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
}

Reverb3D::~Reverb3D()
{

}

bool Reverb3D::create()
{
    // If we already have an FMODReverb3D object then don't make another one
    if (this->pFMODReverb3D != 0)
        return true;
    // Make the FMODRever3DObject
    FMOD_System_CreateReverb3D(FMODGlobals::pFMODSystem, &this->pFMODReverb3D);
    // Make this class the UserData for our FMODReverb3D
    FMOD_Reverb3D_SetUserData(this->pFMODReverb3D, this);
}

void Reverb3D::release()
{
    // If there is a FMODReverb object
    if (this->pFMODReverb3D != 0)
    {
        // Release the Reverb3D
        FMOD_Reverb3D_Release(this->pFMODReverb3D);
    }
    // Clear the Reverb3D pointer
    this->pFMODReverb3D = 0;
}

bool Reverb3D::isActive()
{
    // Return activeFlag
    return this->activeFlag;
}

void Reverb3D::setActive(bool activeFlag)
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, activeFlag);
}

void Reverb3D::activate()
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, true);
}

void Reverb3D::deactivate()
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, false);
}

float Reverb3D::getX()
{
    // Return
    return this->x;
}

float Reverb3D::getY()
{
    // Return
    return this->y;
}

float Reverb3D::getZ()
{
    // Return
    return this->z;
}

void Reverb3D::setPosition(float x, float y, float z)
{
    // Set local x
    this->x = x;
    // Set local y
    this->y = y;
    // Set local z
    this->z = z;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    // Set the 3D Attributes for the Reverb object
    FMOD_Reverb3D_Set3DAttributes(this->pFMODReverb3D, &position, this->minDistance, this->maxDistance);
}

float Reverb3D::getMinDistance()
{
    // Return minDistance
    return this->minDistance;
}

float Reverb3D::getMaxDistance()
{
    // Return maxDistance
    return this->maxDistance;
}

void Reverb3D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    // Set the 3D Attributes for the Reverb object
    FMOD_Reverb3D_Set3DAttributes(this->pFMODReverb3D, &position, this->minDistance, this->maxDistance);
}

//void Reverb3D::bindToLua(lua_State* pLuaState)
//{
//    // TODO: implement me
//}
