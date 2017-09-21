#include "Plugin.h"

Plugin::Plugin()
{
    // Handle
    this->handle = 0;
}

Plugin::~Plugin()
{
//    if (this->handle != 0)
//    {
//        // Unload Plugin
//        FMOD_System_UnloadPlugin(FMODGlobals::pFMODSystem, this->handle);
//    }
//    this->handle = 0;
}

Plugin::Plugin(Plugin& other)
{

}

Plugin& Plugin::operator=(const Plugin& other)
{
    return *this;
}

unsigned int Plugin::getHandle()
{
    // return handle
    return this->handle;
}

bool Plugin::loadPlugin(std::string filename, unsigned int priority)
{
    // Load Plugin
    FMOD_System_LoadPlugin(FMODGlobals::pFMODSystem, filename.c_str(), &(this->handle), priority);
}

bool Plugin::registerDSP(FMOD_DSP_DESCRIPTION description)
{
    // Register DSP
    FMOD_System_RegisterDSP(FMODGlobals::pFMODSystem, &description, &(this->handle));
}

bool Plugin::registerOutput(FMOD_OUTPUT_DESCRIPTION description)
{
    // Register Output
    FMOD_System_RegisterOutput(FMODGlobals::pFMODSystem, &description, &(this->handle));
}

bool Plugin::registerCodec(FMOD_CODEC_DESCRIPTION description, unsigned int priority)
{
    // Register Codec
    FMOD_System_RegisterCodec(FMODGlobals::pFMODSystem, &description, &(this->handle), priority);
}

void Plugin::unloadPlugin()
{
    // Unload Plugin
    FMOD_System_UnloadPlugin(FMODGlobals::pFMODSystem, this->handle);
    // Clear handle
    this->handle = 0;
}

int Plugin::getNumNestedPlugins()
{
    // Grab number of nested Plugins
    int numberOfNestedPlugins = 0;
    FMOD_System_GetNumNestedPlugins(FMODGlobals::pFMODSystem, this->handle, &numberOfNestedPlugins);
    // return numberOfNestedPlugins
    return numberOfNestedPlugins;
}

unsigned int Plugin::getNestedPluginHandle(int index)
{
    // Grab nested handle
    unsigned int nestedHandle = 0;
    FMOD_System_GetNestedPlugin(FMODGlobals::pFMODSystem, this->handle, index, &nestedHandle);
    // return nestedHandle
    return nestedHandle;
}

FMOD_PLUGINTYPE Plugin::getPluginType()
{
    // Grab plugin Info
    FMOD_PLUGINTYPE pluginType;
    char name[255];
    unsigned int version = 0;
    FMOD_System_GetPluginInfo(FMODGlobals::pFMODSystem, this->handle, &pluginType, name, 255, &version);
    // return pluginType
    return pluginType;
}

std::string Plugin::getName()
{
    // Grab plugin Info
    FMOD_PLUGINTYPE pluginType;
    char name[255];
    unsigned int version = 0;
    FMOD_System_GetPluginInfo(FMODGlobals::pFMODSystem, this->handle, &pluginType, name, 255, &version);
    // return std::string(name)
    return std::string(name);
}

unsigned int Plugin::getVersion()
{
    // Grab plugin Info
    FMOD_PLUGINTYPE pluginType;
    char name[255];
    unsigned int version = 0;
    FMOD_System_GetPluginInfo(FMODGlobals::pFMODSystem, this->handle, &pluginType, name, 255, &version);
    // return version
    return version;
}
