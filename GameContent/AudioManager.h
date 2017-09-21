#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

// C/C++ Includes
#include <map>

// Macro which asks TinyXML to use the TICPP Wrapper
#define TIXML_USE_TICPP
// header for TinyXML
#include <ticpp.h>

//// LUA / LUABIND INCLUDES
//extern "C"
//{
//    #include <lua.h>
//    #include <lualib.h>
//    #include <lauxlib.h>
//}
//#include <luabind/luabind.hpp>
//#include <luabind/operator.hpp>

// FMOD Includes
#include <fmod.h>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_dsp.h>
#include <fmod_dsp_effects.h>
#include <fmod_errors.h>
#include <fmod_output.h>

// Include GameAudio related headers
#include "Sound/SoundSample.h"

/** The AudioManager class loads instancable sounds assets **/
class AudioManager
{
    // ****************************
    // * CONSTRUCTOR / DESTRUCTOR *
    // ****************************
    public:
        //! Constructor
        AudioManager()
        {
            this->version = std::string("1.0");
            this->soundSampleMap.clear();
            this->soundSample3DMap.clear();
        }
        //! Destructor
        virtual ~AudioManager() {}

    protected:
        //! AudioManager Copy constructor
        AudioManager(const AudioManager& other) {}

    // ***********
    // * VERSION *
    // ***********
    public:
        //! get the version information
        virtual std::string getVersion() { return this->version; }

    protected:
        // Version of the AudioManager
        std::string version;

    // **************************
    // * CORE MANAGER FUNCTIONS *
    // **************************
    public:
        //! Get SoundSample
        virtual SoundSample* getSoundSample(std::string filename);
        //! Get SoundSample
        virtual SoundSample* getSoundSample(std::string filename, bool addToMap);

        //! Get SoundSample2D
        virtual SoundSample* getSoundSample2D(std::string filename);
        //! Get SoundSample2D
        virtual SoundSample* getSoundSample2D(std::string filename, bool addToMap);

        //! Get SoundSample3D
        virtual SoundSample* getSoundSample3D(std::string filename);
        //! Get SoundSample3D
        virtual SoundSample* getSoundSample3D(std::string filename, bool addToMap);

    public:
        //! Destroy a SoundSample (use only on SoundSamples not added to the Map)
        virtual void destroySoundSample(SoundSample* pSoundSample);

    public:
        //! Clear the AudioManager
        virtual void clear();

    protected:
        // SoundSample Map
        std::map<std::string, SoundSample*> soundSampleMap;
        // SoundSample3D Map
        std::map<std::string, SoundSample*> soundSample3DMap;

    // *********************
    // * UTILITY FUNCTIONS *
    // *********************
    public:
        //! Get relative path from filename
        virtual std::string getLocalPath(std::string filename)
        {
            std::string relativePath = filename;
            unsigned int pos = relativePath.find_last_of('/');
            if (pos == std::string::npos)
                return std::string();
            relativePath = relativePath.substr(0, pos + 1);
            return relativePath;
        }
        //! Get filename from file path
        virtual std::string getFilename(std::string filepath)
        {
            std::string filename = filepath;
            unsigned int pos = filename.find_last_of('/');
            if (pos == std::string::npos)
                return std::string();
            filename = filename.substr(pos + 1, std::string::npos);
        }
        //! Convert a string to upper case
        virtual std::string toUpperCase(std::string text)
        {
            std::string uppercase(text);
            for (std::string::iterator p = uppercase.begin(); p != uppercase.end(); p++)
                *p = std::toupper(*p);
            return uppercase;
        }
        //! Convert a string to lower case
        virtual std::string toLowerCase(std::string text)
        {
            std::string uppercase(text);
            for (std::string::iterator p = uppercase.begin(); p != uppercase.end(); p++)
                *p = std::tolower(*p);
            return uppercase;
        }
        //! Convert a bool to a string
        virtual std::string convertBoolToString(bool value)
        {
            return (value == true) ? "TRUE": "FALSE";
        }
        //! Convert a string to a bool
        virtual bool convertStringToBool(std::string value)
        {
            return (this->toUpperCase(value) == "TRUE") ? true: false;
        }

//    // ****************
//    // * LUA BINDINGS *
//    // ****************
//    public:
//        //! Bind this class to a lua state
//        static void bindToLua(lua_State* pLuaState);
};

#endif // AUDIOMANAGER_H
