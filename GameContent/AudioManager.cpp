#include "AudioManager.h"

SoundSample* AudioManager::getSoundSample(std::string filename)
{
    return this->getSoundSample(filename, true);
}

SoundSample* AudioManager::getSoundSample(std::string filename, bool addToMap)
{
    // Validate Filename
    if (filename.size() == 0)
        return 0;
    // uppercase the filename
    filename = this->toUpperCase(filename);
    // Send a message to the console
    std::cout << "SoundSample* AudioManager::getSoundSample(std::string filename, bool addToMap)" << std::endl;
    // Try and find existing SoundSample
    std::map<std::string, SoundSample*>::iterator i = this->soundSampleMap.find(filename);
    if (i != this->soundSampleMap.end())
    {
        //// Send a message to the console
        //std::cout << filename.c_str() << " already loaded. Function Successful" << std::endl;
        return i->second;
    }
    // A variable to track the result of FMOD function calls
    FMOD_RESULT result;
    // Make a pointer to an FMODSound
    FMOD_SOUND* pFMODSound = 0;
    // Create an FMODSound
    result = FMOD_System_CreateSound(FMODGlobals::pFMODSystem, filename.c_str(), FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &pFMODSound);
    // If there were any problems
    if (result != FMOD_OK)
    {
        // Send a message to the console
        std::cout << "ERROR: Could not sound sample: " << filename.c_str() << std::endl;
        std::cout << "FMOD error! (" << FMOD_ErrorString(result) << ") " << std::endl;
        // sound effect was not loaded
        return 0;
    }
    // Send a message to the console
    std::cout << "SoundSample: " << filename << " Loaded." << std::endl;
    SoundSample* pSoundSample = new SoundSample();
    pSoundSample->setFilename(filename.c_str());
    pSoundSample->setFMODSound(pFMODSound);
    if (addToMap == true)
    {
        this->soundSampleMap[filename] = pSoundSample;
        // Send a message to the console
        std::cout << "SoundSample added to sound sample map under the key: " << filename.c_str() << " " << filename << std::endl;
    }
    // sound effect was successfully loaded
    return pSoundSample;
}

SoundSample* AudioManager::getSoundSample3D(std::string filename)
{
    return this->getSoundSample3D(filename, true);
}

SoundSample* AudioManager::getSoundSample3D(std::string filename, bool addToMap)
{
    // Validate Filename
    if (filename.size() == 0)
        return 0;
    // uppercase the filename
    filename = this->toUpperCase(filename);
    // Try and find existing SoundSample
    std::map<std::string, SoundSample*>::iterator i = this->soundSample3DMap.find(filename);
    if (i != this->soundSample3DMap.end())
    {
        //// Send a message to the console
        //std::cout << filename.c_str() << " already loaded. Function Successful" << std::endl;
        return i->second;
    }
    // A variable to track the result of FMOD function calls
    FMOD_RESULT result;
    // Make a pointer to an FMODSound
    FMOD_SOUND* pFMODSound = 0;
    // Create an FMODSound
    result = FMOD_System_CreateSound(FMODGlobals::pFMODSystem, filename.c_str(), FMOD_LOOP_NORMAL | FMOD_3D, 0, &pFMODSound);
    //// handle any problems loading this file
    if (result != FMOD_OK)
    {
        // Send a message to the console
        std::cout << "ERROR: Could not sound sample: " << filename.c_str() << std::endl;
        std::cout << "FMOD error! (" << FMOD_ErrorString(result) << ") " << std::endl;
        // sound effect was not loaded
        return 0;
    }
    // Send a message to the console
    std::cout << "SoundSample: " << filename << " Loaded." << std::endl;
    SoundSample* pSoundSample = new SoundSample();
    pSoundSample->setFilename(filename.c_str());
    pSoundSample->setFMODSound(pFMODSound);
    if (addToMap == true)
    {
        this->soundSample3DMap[filename] = pSoundSample;
        // Send a message to the console
        std::cout << "SoundSample3D added to sound sample map under the key: " << filename.c_str() << " " << filename << std::endl;
    }
    // sound effect was successfully loaded
    return pSoundSample;
}

void AudioManager::clear()
{
    // Release Sound Samples
    for (std::map<std::string, SoundSample*>::iterator i = this->soundSampleMap.begin(); i != this->soundSampleMap.end(); i++)
    {
        SoundSample* pSoundSample = i->second;
        FMOD_Sound_Release(pSoundSample->getFMODSound());
        delete pSoundSample;
    }
    // Clear sound Sample Map
    this->soundSampleMap.clear();
    // Clear 3D Sound Samples
    for (std::map<std::string, SoundSample*>::iterator i = this->soundSample3DMap.begin(); i != this->soundSample3DMap.end(); i++)
    {
        SoundSample* pSoundSample = i->second;
        FMOD_Sound_Release(pSoundSample->getFMODSound());
        delete pSoundSample;
    }
    // Clear sound Sample Map
    this->soundSample3DMap.clear();
}

//void AudioManager::bindToLua(lua_State* pLuaState)
//{
//    // TODO: More bindings
//    // Bind functions to lua state
//    luabind::module(pLuaState)
//    [
//        luabind::class_<AudioManager>("AudioManager")
//        .def(luabind::constructor<>())
//        .def("getVersion", (std::string (AudioManager::*)()) &AudioManager::getVersion)
//        .def("getSoundSample", (SoundSample*(AudioManager::*)(std::string)) &AudioManager::getSoundSample)
//        .def("getSoundSample", (SoundSample*(AudioManager::*)(std::string, bool)) &AudioManager::getSoundSample)
//        .def("getSoundSample3D", (SoundSample*(AudioManager::*)(std::string)) &AudioManager::getSoundSample3D)
//        .def("getSoundSample3D", (SoundSample*(AudioManager::*)(std::string, bool)) &AudioManager::getSoundSample3D)
//        .def("clear", (void(AudioManager::*)()) &AudioManager::clear)
//    ];
//}
