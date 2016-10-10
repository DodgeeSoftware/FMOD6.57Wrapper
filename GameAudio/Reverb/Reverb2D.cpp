#include "Reverb2D.h"

Reverb2D::Reverb2D()
{
    // FMODRever3D
    this->pFMODReverb3D = 0;
    // Active Flag
    this->activeFlag = true;
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    // Min and Max Distance
    this->minDistance = 0.1f;
    this->maxDistance = 10000.0f;
}

Reverb2D::~Reverb2D()
{

}

bool Reverb2D::create()
{
    // If we already have an FMODReverb3D object then don't make another one
    if (this->pFMODReverb3D != 0)
        return true;
    // Make the FMODRever3DObject
    FMOD_System_CreateReverb3D(FMODGlobals::pFMODSystem, &this->pFMODReverb3D);
    // Make this class the UserData for our FMODReverb3D
    FMOD_Reverb3D_SetUserData(this->pFMODReverb3D, this);
}

void Reverb2D::release()
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

bool Reverb2D::isActive()
{
    // Return activeFlag
    return this->activeFlag;
}

void Reverb2D::setActive(bool activeFlag)
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, activeFlag);
}

void Reverb2D::activate()
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, true);
}

void Reverb2D::deactivate()
{
    // Set the Active Flag
    FMOD_Reverb3D_SetActive(this->pFMODReverb3D, false);
}

float Reverb2D::getX()
{
    // Return x
    return this->x;
}

float Reverb2D::getY()
{
    // Return y
    return this->y;
}

void Reverb2D::setPosition(float x, float y)
{
    // Set local x
    this->x = x;
    // Set local y
    this->y = y;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = 0.0f;
    // Set the 3D Attributes for the Reverb object
    FMOD_Reverb3D_Set3DAttributes(this->pFMODReverb3D, &position, this->minDistance, this->maxDistance);
}

float Reverb2D::getMinDistance()
{
    // Return minDistance
    return this->minDistance;
}

float Reverb2D::getMaxDistance()
{
    // Return maxDistance
    return this->maxDistance;
}

void Reverb2D::setMinMaxDistance(float minDistance, float maxDistance)
{
    // Set local minDistance
    this->minDistance = minDistance;
    // Set local maxDistance
    this->maxDistance = maxDistance;
    // Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = 0.0f;
    // Set the 3D Attributes for the Reverb object
    FMOD_Reverb3D_Set3DAttributes(this->pFMODReverb3D, &position, this->minDistance, this->maxDistance);
}

void Reverb2D::bindToLua(lua_State* pLuaState)
{
    // Bind functions to lua state
    luabind::module(pLuaState)
    [
        luabind::class_<Reverb2D>("Reverb2D")
        .def(luabind::constructor<>())
        // GENERAL
        .def("create", (void (Reverb2D::*)()) &Reverb2D::create)
        .def("release", (void (Reverb2D::*)()) &Reverb2D::release)
        .def("isActive", (bool(Reverb2D::*)()) &Reverb2D::isActive)
        .def("setActive", (void (Reverb2D::*)(bool)) &Reverb2D::setActive)
        .def("activate", (void (Reverb2D::*)()) &Reverb2D::activate)
        .def("deactivate", (void (Reverb2D::*)()) &Reverb2D::deactivate)
        .def("getX", (float (Reverb2D::*)()) &Reverb2D::getX)
        .def("getY", (float (Reverb2D::*)()) &Reverb2D::getY)
        .def("setPosition", (float (Reverb2D::*)(float, float)) &Reverb2D::setPosition)
        .def("getMinDistance", (float (Reverb2D::*)()) &Reverb2D::getMinDistance)
        .def("getMaxDistance", (float (Reverb2D::*)()) &Reverb2D::getMaxDistance)
        .def("setMinMaxDistance", (float (Reverb2D::*)(float, float)) &Reverb2D::setMinMaxDistance)
    ];
}
