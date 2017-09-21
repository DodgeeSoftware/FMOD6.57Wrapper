#include "Geometry.h"

Geometry::Geometry()
{
    // Geometry
    this->pGeometry = 0;
    // Position
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    // Up Vector
    this->xUp = 0.0f;
    this->yUp = 1.0f;
    this->zUp = 0.0f;
    // Forward Vector
    this->xForward = 0.0f;
    this->yForward = 0.0f;
    this->zForward = -1.0f;
    // Scale
    this->xScale = 0.0f;
    this->yScale = 0.0f;
    this->zScale = 0.0f;
}

Geometry::~Geometry()
{

}

Geometry::Geometry(Geometry& other)
{

}

bool Geometry::create(int maxPolygons, int maxVertices)
{
    // Try and Create the Geometry
    FMOD_RESULT result;
    result = FMOD_System_CreateGeometry(FMODGlobals::pFMODSystem, maxPolygons, maxVertices, &(this->pGeometry));
    // Set userdata for the Geometry
    FMOD_Geometry_SetUserData(this->pGeometry, (void*)this);
    // return result
    return result;
}

bool Geometry::load(const void* pData, int dataSize)
{
    // Load the geomatry
    FMOD_RESULT result;
    result = FMOD_System_LoadGeometry(FMODGlobals::pFMODSystem, pData, dataSize, &(this->pGeometry));
    // Result
    return result;
}

bool Geometry::save(void* pData, int dataSize)
{
    // Load the geomatry
    FMOD_RESULT result;
    FMOD_Geometry_Save(this->pGeometry, pData, &dataSize);
    // Result
    return result;
}

void Geometry::release()
{
    // If there is geometry
    if (this->pGeometry != 0)
    {
        // Release the Geometry
        FMOD_Geometry_Release(this->pGeometry);
    }
    // Clear the geometry pointer
    this->pGeometry = 0;
}

float Geometry::getX()
{
    // return x
    return this->x;
}

void Geometry::setX(float x)
{
    // Set local position
    this->x = x;
    // Set the Geometry Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    FMOD_Geometry_SetPosition(this->pGeometry, &position);
}

float Geometry::getY()
{
    // return y
    return this->y;
}

void Geometry::setY(float y)
{
    // Set local position
    this->y = y;
    // Set the Geometry Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    FMOD_Geometry_SetPosition(this->pGeometry, &position);
}

float Geometry::getZ()
{
    // return z
    return this->z;
}

void Geometry::setZ(float z)
{
    // Set local position
    this->z = z;
    // Set the Geometry Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    FMOD_Geometry_SetPosition(this->pGeometry, &position);
}

void Geometry::setPosition(float x, float y, float z)
{
    // Set local position
    this->x = x;
    this->y = y;
    this->z = z;
    // Set the Geometry Position
    FMOD_VECTOR position;
        position.x = this->x;
        position.y = this->y;
        position.z = this->z;
    FMOD_Geometry_SetPosition(this->pGeometry, &position);
}

float Geometry::getXUp()
{
    // return xUp
    return this->xUp;
}

float Geometry::getYUp()
{
    // return yUp
    return this->yUp;
}

float Geometry::getZUp()
{
    // return zUp
    return this->zUp;
}

void Geometry::setUpVector(float xUp, float yUp, float zUp)
{
    // Set local up
    this->xUp = xUp;
    this->yUp = yUp;
    this->zUp = zUp;
    // Set the Geometry Rotation
    FMOD_VECTOR forward;
        forward.x = this->xForward;
        forward.y = this->yForward;
        forward.z = this->zForward;
    FMOD_VECTOR up;
        up.x = this->xUp;
        up.y = this->yUp;
        up.z = this->zUp;
    FMOD_Geometry_SetRotation(this->pGeometry, &forward, &up);
}

void Geometry::setForward(float xForward, float yForward, float zForward)
{
    // Set local forward
    this->xForward = xForward;
    this->yForward = yForward;
    this->zForward = zForward;
    // Set the Geometry Rotation
    FMOD_VECTOR forward;
        forward.x = this->xForward;
        forward.y = this->yForward;
        forward.z = this->zForward;
    FMOD_VECTOR up;
        up.x = this->xUp;
        up.y = this->yUp;
        up.z = this->zUp;
    FMOD_Geometry_SetRotation(this->pGeometry, &forward, &up);
}

float Geometry::getXScale()
{
    // return xScale
     return this->xScale;
}

void Geometry::setXScale(float xScale)
{
    // Set Local Scale
    this->zScale = zScale;
    // Set Geometry Scale
    FMOD_VECTOR scale;
        scale.x = this->xScale;
        scale.y = this->yScale;
        scale.z = this->zScale;
    FMOD_Geometry_SetScale(this->pGeometry, &scale);
}

float Geometry::getYScale()
{
    // return yScale
     return this->yScale;
}

void Geometry::setYScale(float yScale)
{
    // Set Local Scale
    this->yScale = yScale;
    // Set Geometry Scale
    FMOD_VECTOR scale;
        scale.x = this->xScale;
        scale.y = this->yScale;
        scale.z = this->zScale;
    FMOD_Geometry_SetScale(this->pGeometry, &scale);
}

float Geometry::getZScale()
{
    // return zScale
     return this->zScale;
}

void Geometry::setZScale(float zScale)
{
    // Set Local Scale
    this->zScale = zScale;
    // Set Geometry Scale
    FMOD_VECTOR scale;
        scale.x = this->xScale;
        scale.y = this->yScale;
        scale.z = this->zScale;
    FMOD_Geometry_SetScale(this->pGeometry, &scale);
}

void Geometry::setScale(float xScale, float yScale, float zScale)
{
    // Set Local Scale
    this->xScale = xScale;
    this->yScale = yScale;
    this->zScale = zScale;
    // Set Geometry Scale
    FMOD_VECTOR scale;
        scale.x = this->xScale;
        scale.y = this->yScale;
        scale.z = this->zScale;
    FMOD_Geometry_SetScale(this->pGeometry, &scale);
}

bool Geometry::isActive()
{
    // Grab activeFlag
    FMOD_BOOL activeFlag = false;
    FMOD_Geometry_GetActive(this->pGeometry, &activeFlag);
    // return activeFlag
    return activeFlag;
}

void Geometry::setActive(bool activeFlag)
{
    // Set activeFlag for the FMOD_GEOMETRY
    FMOD_Geometry_SetActive(this->pGeometry, activeFlag);
}

int Geometry::getPolyCount()
{
    // Grab PolyCount
    int polyCount = 0;
    FMOD_Geometry_GetNumPolygons(this->pGeometry, &polyCount);
    // return polyCount
    return polyCount;
}

int Geometry::getMaxPolygons()
{
    // Get MaxPolygons and maxVetices
    int maxPoly = 0;
    int maxVertices = 0;
    FMOD_Geometry_GetMaxPolygons(this->pGeometry, &maxPoly, &maxVertices);
    // Return maxPoly
    return maxPoly;
}

int Geometry::getMaxVertices()
{
    // Get MaxPolygons and maxVetices
    int maxPoly = 0;
    int maxVertices = 0;
    FMOD_Geometry_GetMaxPolygons(this->pGeometry, &maxPoly, &maxVertices);
    // Return maxVertices
    return maxVertices;
}

int Geometry::addPolygon(float directOcclusion, float reverbOcclusion, bool doubleSidedFlag, int numVertices, float* vertices)
{
    // Add our polygon to the Geometry
    int polygonIndex = 0;
    // Create an array of FMOD_VECTORs on the heap
    FMOD_VECTOR* pVertices = new FMOD_VECTOR[numVertices];
        // Build the array
        for(int i = 0; i < numVertices; i++)
        {
            pVertices[i].x = vertices[i * 3 + 0];
            pVertices[i].y = vertices[i * 3 + 1];
            pVertices[i].z = vertices[i * 3 + 2];
        }
        FMOD_Geometry_AddPolygon(this->pGeometry, directOcclusion, reverbOcclusion, doubleSidedFlag, numVertices, pVertices, &polygonIndex);
    // Release heap memory for the Vertices
    delete pVertices;
    // return polygonIndex
    return polygonIndex;
}

int Geometry::getPolygonNumVertices(int index)
{
    // Get Number of Vertices
    int numberOfVertices = 0;
    FMOD_Geometry_GetPolygonNumVertices(this->pGeometry, index, &numberOfVertices);
    // return numberOfVertices
    return numberOfVertices;
}

void Geometry::setPolygonVertex(int polygonIndex, int vertexIndex, float x, float y, float z)
{
    // Build our vertex structure
    FMOD_VECTOR vertex;
        vertex.x = x;
        vertex.y = y;
        vertex.z = z;
    // Set Polygon Vertex
    FMOD_Geometry_SetPolygonVertex(this->pGeometry, polygonIndex, vertexIndex, &vertex);
}

FMOD_VECTOR Geometry::getPolygonVertex(int polygonIndex, int vertexIndex)
{
    // Grab vertex
    FMOD_VECTOR vertex;
    FMOD_Geometry_GetPolygonVertex(this->pGeometry, polygonIndex, vertexIndex, &vertex);
    // return vertex
    return vertex;
}

void Geometry::setPolygonAttributes(int polygonIndex, float directOcclusion, float reverbOcclusion, bool doubleSidedFlag)
{
    // Set Polygon Atrtibutes
    FMOD_Geometry_SetPolygonAttributes(this->pGeometry, polygonIndex, directOcclusion, reverbOcclusion, doubleSidedFlag);
}

float Geometry::getPolygonAttributeDirectOcclusion(int polygonIndex)
{
    // Polygon Attributes
    float directOcclusion = 0.0f;
    float reverbOcclusion = 0.0f;
    FMOD_BOOL doubleSidedFlag = false;
    FMOD_Geometry_GetPolygonAttributes(this->pGeometry, polygonIndex, &directOcclusion, &reverbOcclusion, &doubleSidedFlag);
    // return directOcclusion
    return directOcclusion;
}

float Geometry::getPolygonAttributeReverbOcclusion(int polygonIndex)
{
    // Polygon Attributes
    float directOcclusion = 0.0f;
    float reverbOcclusion = 0.0f;
    FMOD_BOOL doubleSidedFlag = false;
    FMOD_Geometry_GetPolygonAttributes(this->pGeometry, polygonIndex, &directOcclusion, &reverbOcclusion, &doubleSidedFlag);
    // return reverbOcclusion
    return reverbOcclusion;
}

bool Geometry::getPolygonAttributeDoubleSided(bool polygonIndex)
{
    // Polygon Attributes
    float directOcclusion = 0.0f;
    float reverbOcclusion = 0.0f;
    FMOD_BOOL doubleSidedFlag = false;
    FMOD_Geometry_GetPolygonAttributes(this->pGeometry, polygonIndex, &directOcclusion, &reverbOcclusion, &doubleSidedFlag);
    // return doubleSidedFlag
    return doubleSidedFlag;
}

//void Geometry::bindToLua(lua_State* pLuaState)
//{
//
//}
