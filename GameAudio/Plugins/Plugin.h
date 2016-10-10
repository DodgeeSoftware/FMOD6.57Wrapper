#ifndef PLUGIN_H
#define PLUGIN_H

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

// GAMEAUDIO Includes
#include "FMODGlobals.h"

/** The Plugin is a wrapper around an FMOD Plugin**/
class Plugin
{
    // ******************************
    // * CONSTRUCTORS / DESTRUCTORS *
    // ******************************
    public:
        //! Constructor
        Plugin();
        //! Destructor
        virtual ~Plugin();

    protected:
        //! Copy Constructor
        Plugin(Plugin& other) {}

    // ************************
    // * OVERLOADED OPERATORS *
    // ************************
    public:
        // No functions

    protected:
        //! Plugin Assignment operator
        Plugin& operator=(const Plugin& other) { return *this; }

    // ********************
    // * PLUGIN FUNCTIONS *
    // ********************
    public:
        /** @brief GetHandle
          * @return the handle to this plugin **/
        virtual unsigned int getHandle();
        /* I don't think I need to implement this function because
            it is retarded; yes that's a technical term */
        //FMOD_RESULT F_API FMOD_System_GetPluginHandle(FMOD_SYSTEM *system, FMOD_PLUGINTYPE plugintype, int index, unsigned int *handle);
        /** @brief LoadPlugin
          * @param filename the location of a dll, so or dylib
          * @param priority the priority of this plugin compared to others
          * @return true on success false on failure **/
        virtual bool loadPlugin(std::string filename, unsigned int priority);
        /** @brief registerCodec
          * Use this function instead of loadPlugin when you want to use this class
          * to extend the ability of FMOD to load new file formats
          * @param description is an FMOD_CODEC_DESCRIPTION structure used
          * to setup the codec
          * @param priority the priority of this codec compared to other codecs **/
        virtual bool registerCodec(FMOD_CODEC_DESCRIPTION description, unsigned int priority);
        /** @brief registerDSP
          * use this function instead of load plugin when you want to use this class
          * to extend the DSP by adding your own custom one
          * @param description is an FMOD_DSP_DESCRIPTION structure used
          * to setup the DSP **/
        virtual bool registerDSP(FMOD_DSP_DESCRIPTION description);
        // I don't think this function is needed at all
        //FMOD_System_GetDSPInfoByPlugin(FMODGlobals::pFMODSystem, pluginNandle, &description);
        /** @brief registerOutput
          * use this function instead of load plugin when you want to use this class
          * to extend the ways in which FMOD will output audio
          * @param description is an FMOD_OUTPUT_DESCRIPTION structure used
          * to setup the Output **/
        virtual bool registerOutput(FMOD_OUTPUT_DESCRIPTION description);
        /** @brief UnloadPlugin
          * with this filename **/
        virtual void unloadPlugin();
        /** @brief Get Number of Nested Plugins.
          * A Plugin can have other plugins nested inside of it **/
        virtual int getNumNestedPlugins();
        /** @brief Get Nested Plugin Handle
          * @param filename the name of the file the nested plugin is withing
          * @param index of the nested plugin
          * @return the handle of the nested Plugin **/
        virtual unsigned int getNestedPluginHandle(int index);
        /* NOTE: Types of plugins are
            FMOD_PLUGINTYPE_OUTPUT - The plugin type is an output module.  FMOD mixed audio will play through one of these devices
            FMOD_PLUGINTYPE_CODEC -  The plugin type is a file format codec.  FMOD will use these codecs to load file formats for playback.
            FMOD_PLUGINTYPE_DSP - The plugin type is a DSP unit.  FMOD will use these plugins as part of its DSP network to apply effects
                to output or generate sound in realtime. */
        /** @brief Get Plugin Type
          * @param pluginHandle
          * @return pluginType **/
        virtual FMOD_PLUGINTYPE getPluginType();
        /** @brief getName
          * @return the name of the Plugin **/
        virtual std::string getName();
        /** @brief getVersion
          * @return the version of the plugin**/
        virtual unsigned int getVersion();

    protected:
        // Plugin Handle
        unsigned int handle;
};

#endif // PLUGIN_H
