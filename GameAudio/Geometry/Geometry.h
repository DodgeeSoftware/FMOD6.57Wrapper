#ifndef GEOMETRY_H
#define GEOMETRY_H

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

/** The Geometry is a wrapper around FMOD_GEOMETRY and is basically a mesh **/
class Geometry
{
    // *****************************
    // * CONSTRUCTORS / DESTRUCTOR *
    // *****************************
    public:
        //! Constructor
        Geometry();
        //! Destructor
        virtual ~Geometry();

    protected:
        //! Copy Constructor
        Geometry(Geometry& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // Members and methods

    protected:
        // Members and methods

    // **********************
    // * GEOMETRY FUNCTIONS *
    // **********************
    public:
        /** @brief create the Geometry
          * @param maxPolygons maximum number of polygons
          * @param maxVertices maximum number of vertices
          * @return true on success false otherwise **/
        virtual bool create(int maxPolygons, int maxVertices);
        /** @brief loadGeometry
          * @param pData address with the geometry data
          * @param dataSize size of the data block in bytes **/
        virtual bool load(const void* pData, int dataSize);
        /** @brief saveGeometry
          * @param pData address with the geometry data
          * @param dataSize size of the data block in bytes **/
        virtual bool save(void* pData, int dataSize);
        /** @brief release **/
        virtual void release();
        /** @brief getX
          * @return Horizontal coordinate **/
        virtual float getX();
        /** @brief setX
          * @return Horizontal coordinate **/
        virtual void setX(float x);
        /** @brief getY
          * @return Vertical coordinate **/
        virtual float getY();
        /** @brief setY
          * @return Vertical coordinate **/
        virtual void setY(float y);
        /** @brief getZ
          * @return Depth coordinate **/
        virtual float getZ();
        /** @brief setZ
          * @return Depth coordinate **/
        virtual void setZ(float z);
        /** @brief setPosition
          * @param x horizontal position
          * @param y horizontal position
          * @param z horizontal position  **/
        virtual void setPosition(float x, float y, float z);
        /** @brief getXUp
          * @return x component of the up vector **/
        virtual float getXUp();
        /** @brief getYUp
          * @return y component of the up vector **/
        virtual float getYUp();
        /** @brief getZUp
          * @return z component of the up vector **/
        virtual float getZUp();
        /** @brief setUpVector
          * @param xUp
          * @param yUp
          * @param zUp **/
        virtual void setUpVector(float xUp, float yUp, float zUp);
        /** @brief setForward
          * @param xForward
          * @param yForward
          * @param zForward **/
        virtual void setForward(float xForward, float yForward, float zForward);
        /** @brief getXScale
          * @return Horizontal Scale **/
        virtual float getXScale();
        /** @brief setXScale
          * @return Horizontal Scale **/
        virtual void setXScale(float xScale);
        /** @brief getYScale
          * @return Vertical Scale **/
        virtual float getYScale();
        /** @brief setYScale
          * @return Vertical Scale **/
        virtual void setYScale(float yScale);
        /** @brief getZScale
          * @return Depth Scale **/
        virtual float getZScale();
        /** @brief setZScale
          * @return Depth Scale **/
        virtual void setZScale(float zScale);
        /** @brief setScale
          * @param xScale horizontal scale
          * @param yScale horizontal scale
          * @param zScale horizontal scale **/
        virtual void setScale(float xScale, float yScale, float zScale);
        /** @brief isActive
          * @return true if active false otherwise**/
        virtual bool isActive();
        /** @brief setActive
          * @brief setActive
          * @param activeFlag set to true to activate false to deactivate **/
        virtual void setActive(bool activeFlag);
        /** @brief getPolyCount
          * @return polyCount **/
        virtual int getPolyCount();
        /** @brief getMaxPolygons
          * @return maxPolygons **/
        virtual int getMaxPolygons();
        /** @brief getMaxVertices
          * @return maxVertices **/
        virtual int getMaxVertices();
        // TODO: Consider implementing 2D versions of the geometry functions where the z axis is simply set to 0
        /** @brief addPolygon
          * @param directOcclusion
          * @param reverbOcclusion
          * @param doubleSidedFlag
          * @param numVertices
          * @param vertices an array containing vertices
          * @param indices an array containing indices
          * @return polygon index **/
        virtual int addPolygon(float directOcclusion, float reverbOcclusion, bool doubleSidedFlag, int numVertices, float* vertices);
        /** @brief getPolygonNumVertices
          * @param index index of a polygon in the mesh
          * @return number of vertices in the polygon */
        virtual int getPolygonNumVertices(int index);
        /** @brief setPolygonVertex
          * change the positions of a polygon's vertex
          * @param polygonIndex is the polygon index
          * @param vertexIndex is the index of the vertex in the polygon
          * @param x is the new horizontal position component
          * @param y is the new horizontal position component
          * @param z is the new horizontal position component **/
        virtual void setPolygonVertex(int polygonIndex, int vertexIndex, float x, float y, float z);
        /** @brief getPolygonVertex
          * @param polygonIndex index of the polygon in the mesh
          * @param vertexIndex index of the vertex in the polygon **/
        virtual FMOD_VECTOR getPolygonVertex(int polygonIndex, int vertexIndex);
        /** @brief setPolygonAttributes
          * @param polygonIndex index of the polygon in the mesh
          * @param directOcclusion direct occlusion for the polygon
          * @param reverbOcclusion reverb occlusion for the polygon
          * @param doubleSidedFlag is the polygon double sided or not **/
        virtual void setPolygonAttributes(int polygonIndex, float directOcclusion, float reverbOcclusion, bool doubleSidedFlag);
        /** @brief getPolygonAttributeDirectOcclusion
          * @param index index of the polygon in the mesh
          * @return direct occlusion of the polygon **/
        virtual float getPolygonAttributeDirectOcclusion(int polygonIndex);
        /** @brief getPolygonAttributeReverbOcclusion
          * @param index index of the polygon in the mesh
          * @return reverb occlusion of the polygon **/
        virtual float getPolygonAttributeReverbOcclusion(int polygonIndex);
        /** @brief getPolygonAttributeDoubleSided
          * @param index index of the polygon in the mesh
          * @return double sided polygon flag **/
        virtual bool getPolygonAttributeDoubleSided(bool polygonIndex);

    protected:
        // FMOD_GEOMETRY
        FMOD_GEOMETRY* pGeometry;
        // Horizontal coordinate
        float x;
        // Vertical coordinate
        float y;
        // Depth coordinate
        float z;
        // UpVector Horizontal cooridate
        float upX;
        // UpVector Vertical cooridate
        float upY;
        // UpVector Depth cooridate
        float upZ;
        // forwardVector Horizontal cooridate
        float xForward;
        // forwardVector Vertical cooridate
        float yForward;
        // forwardVector Depth cooridate
        float zForward;
        // xUp
        float xUp;
        // yUp
        float yUp;
        // zUp
        float zUp;
        // xScale
        float xScale;
        // yScale
        float yScale;
        // zScale
        float zScale;

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        /** @brief Bind this class to a lua state
//          * @param pLuaState The LuaState to bind this class to **/
//        static void bindToLua(lua_State* pLuaState);
};

#endif // GEOMETRY_H
