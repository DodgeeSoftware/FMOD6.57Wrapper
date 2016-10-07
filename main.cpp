// C++ Includes
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <limits>
#include <cmath>

// GAMEAUDIO Includes
#include "GameAudio.h"
// GAMECONTENT Includes
#include "AudioManager.h"

// GLOBALS
// AudioSystem
AudioSystem audioSystem;
// AudioManager
AudioManager audioManager;

// UNIT TEST FUNCTIONS
// Sound Test
void soundUnitTest();
// Sound2D Test
void sound2DUnitTest();
// Sound3D Test
void sound3DUnitTest();
// Stream Test
void streamUnitTest();
// Stream2D Test
void stream2DUnitTest();
// Stream3D Test
void stream3DUnitTest();
// Music Test
void musicUnitTest();
// DSPTest
void dspUnitTest();
// ReverbTest
void reverbTest();
// Capture Unit Test
void captureUnitTest();

// UTILITY FUNCTIONS
// Wait for a Keypress
void waitForKeypress();
// Wait until there are NoKeyPresses
void waitForNoKeypress();

// Entry Point
int main(int argc, char* argv[])
{
    // Send a message to the console
    std::cout << "NOTICE: Init AudioSystem" << std::endl;
    std::cout << std::endl;
    // Init AudioSystem
    if (audioSystem.init(1024) == false)
    {
        // Send a message to the console
        std::cout << "ERROR: nitialising AudioSystem Failure" << std::endl;
        // Failure
        return -1;
    }
    // Setup the Doppler Factor, Distance Factor and RollOffScale
    audioSystem.set3DSettings(1.0, 1.0, 1.0f);
    // Set Sound Volume
    audioSystem.setSoundEffectsVolume(1.0f);
    // Set Music Volume
    audioSystem.setMusicVolume(1.0f);
    //audioSystem.mute(); // Works!
    //audioSystem.unmute(); // Works!
    // Send a message to the console
    std::cout << "Initialising AudioSystem Success" << std::endl;

//    // UNIT TESTS
//    // Run Sound Unit Test
//    soundUnitTest();
//    // Run Sound2D Unit Test
//    sound2DUnitTest();
//    // Run Sound3D Unit Test
//    sound3DUnitTest();
//    // Run Stream Unit Test
//    streamUnitTest();
//    // Run Stream2D Unit Test
//    stream2DUnitTest();
//    // Run Stream3D Unit Test
//    stream3DUnitTest();
    // Run Music Unit Test
    musicUnitTest();
//    // DSP Unit test
//    dspUnitTest();
//    // Reverb Test
//    reverbTest();
    // Run Capture Test NOTE: Outside of my spec for a simple GameAudio(FMOD Wrapper)
    captureUnitTest();

    // Shutdown AudioSystem
    audioSystem.shutdown();

    // Send a message to the console
    std::cout << std::endl;
    std::cout << "NOTICE: Shutdown AudioSystem" << std::endl;

    // Success
    return 0;
}

void soundUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING SOUND UNIT TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "Loading Sound...";
    // Try and load a SoundSample
    SoundSample* pSoundSample = audioManager.getSoundSample("media/music/bensound-jazzyfrenchy.ogg");
    // If our SoundSample is invalid
    if (pSoundSample == 0)
    {
        // Send a message to the console
        std::cout << "Failure" << std::endl;
        // Return
        return;
    }
    // Send a message to the console
    std::cout << "Success" << std::endl;
    // Create a Sound
    Sound sound;
    // Set the Sound Sample for the Sound
    sound.setSoundSample(pSoundSample);
    // Set Looping
    sound.setLoop(true);
    // Play the Sound
    sound.play();
    // Send a message to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Main loop
    while(true)
    {
        // Think for the Sound
        sound.think();
        // Update the Sound
        sound.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // When Sound is finished (impossible when looping)
        if (sound.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop the Sound
    sound.stop();
    // Clear the Sound
    sound.clear();
    // Free the Sound
    sound.free();
    // Clear the AudioManager
    audioManager.clear();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    std::cout << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void sound2DUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING SOUND2D UNIT TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "Loading Sound...";
    // Grab a SoundSample
    SoundSample* pSoundSample = audioManager.getSoundSample3D("media/sounds/electronics014.ogg");
    // If our SoundSample is invalid
    if (pSoundSample == 0)
    {
        // Send a message to the console
        std::cout << "Failure" << std::endl;
        // Return
        return;
    }
    // Send a message to the console
    std::cout << "Success" << std::endl;
    // Make a Sound2D
    Sound2D sound2D;
    // Set SoundSample
    sound2D.setSoundSample(pSoundSample);
    // Set Loop
    sound2D.setLoop(true);
    // Set Spacial Position
    sound2D.setPosition(250.0f, 0.0f);
    // Set Min Distance and Max Distance
    sound2D.setMinMaxDistance(0.16f, 10000.0f);
    // Play the Sound2D
    sound2D.play();
    // Set Loop
    sound2D.setLoop(true);
    // Set the Position of the listener
    audioSystem.setListenerPosition(0.0f, 0.0f);
    // unit test variable to control sound movement
    float theta = 0.0f;
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while (true)
    {
        // Interpolate theta
        theta = theta + 0.00005f;
        // Set the Sound's position
        sound2D.setPosition(cos(theta) * 100, 0.0f);
        // Send a message to the console
        std::cout << cos(theta) * 100 << std::endl;
        // Update the Sound2D
        sound2D.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
//        // When Sound2D is finished (impossible when looping)
//        if (sound2D.isPlaying() == false)
//        {
//            // Break from our loop
//            break;
//        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop the Sound2D
    sound2D.stop();
    // Clear the Sound2D
    sound2D.clear();
    // Free the Sound2D
    sound2D.free();
    // Clear the AudioManager
    audioManager.clear();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void sound3DUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING SOUND3D UNIT TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "Loading Sound...";
    // Grab a SoundSample
    SoundSample* pSoundSample = audioManager.getSoundSample3D("media/sounds/electronics014.ogg");
    // If our SoundSample is invalid
    if (pSoundSample == 0)
    {
        // Send a message to the console
        std::cout << "Failure" << std::endl;
        // Return
        return;
    }
    // Send a message to the console
    std::cout << "Success" << std::endl;
    // Make a Sound3D
    Sound3D sound3D;
    // Set the SoundSample
    sound3D.setSoundSample(pSoundSample);
    // Set Looping
    sound3D.setLoop(true);
    // Set Spacial Position
    sound3D.setPosition(100.0f, 0.0f, 0.0f);
    // Set Min Distance and Max Distance
    sound3D.setMinMaxDistance(2.0f, 10000.0f);
    // Play the Sound3D
    sound3D.play();
    // Set the Listener Positoin
    audioSystem.setListenerPosition(0.0f, 0.0f);
    // unit test variable to control sound movement
    float theta = 0.0f;
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while (true)
    {
        // Interpolate theta
        theta = theta + 0.00005f;
        // Set the Sound's position
        sound3D.setPosition(cos(theta) * 100.0f, 0.0f, sin(theta) * 100.0f);
        // Send a message to the console
        std::cout << cos(theta) * 100.0f << ", 0.0f, " << sin(theta) * 100.0f << std::endl;
        // Update the Sound3D
        sound3D.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // When Sound3D is finished (impossible when looping)
        if (sound3D.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Sound3D
    sound3D.stop();
    // Clear Sound3D
    sound3D.clear();
    // Free Sound3D
    sound3D.free();
    // Clear the AudioManager
    audioManager.clear();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void streamUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING STREAM UNIT TEST" << std::endl;
    std::cout << std::endl;
    // Make a Stream
    Stream stream;
    // Load a stream
    if (stream.load("media/music/bensound-littleidea.ogg") == false)
    {
        // Send a message to the console
        std::cout << "ERROR: Unable to open file" << std::endl;
        // Return
        return;
    }
    // Set Looping
    stream.setLoop(true);
    // Play Stream
    stream.play();
    // Set Sound Volume
    audioSystem.setSoundEffectsVolume(1.0f);
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while (true)
    {
        // Update Stream
        stream.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // When Stream is finished (impossible when looping)
        if (stream.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Stream
    stream.stop();
    // Clear Stream
    stream.clear();
    // Free Stream
    stream.free();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    std::cout << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void stream2DUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING STREAM2D UNIT TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "Loading Stream...";
    // Grab a SoundSample
    SoundSample* pSoundSample = audioManager.getSoundSample3D("media/sounds/electronics014.ogg");
    // If our SoundSample is invalid
    if (pSoundSample == 0)
    {
        // Send a message to the console
        std::cout << "Failure" << std::endl;
        // Return
        return;
    }
    // Send a message to the console
    std::cout << "Success" << std::endl;
    // Make a Stream2D
    Stream2D stream2D;
    // Load Audio for our stream
    stream2D.load("media/sounds/electronics014.ogg");
    // Set Loop
    stream2D.setLoop(true);
    // Set Spacial Position
    stream2D.setPosition(250.0f, 0.0f);
    // Set Min Distance and Max Distance
    stream2D.setMinMaxDistance(0.16f, 10000.0f);
    // Play the Stream2D
    stream2D.play();
    // Set Loop
    stream2D.setLoop(true);
    // Set the Position of the listener
    audioSystem.setListenerPosition(0.0f, 0.0f);
    // unit test variable to control sound movement
    float theta = 0.0f;
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while (true)
    {
        // Interpolate theta
        theta = theta + 0.00005f;
        // Set the Sound's position
        stream2D.setPosition(cos(theta) * 100, 0.0f);
        // Send a message to the console
        std::cout << cos(theta) * 100 << std::endl;
        // Update the Sound2D
        stream2D.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
//        // When Stream2D is finished (impossible when looping)
//        if (stream2D.isPlaying() == false)
//        {
//            // Break from our loop
//            break;
//        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop the Stream2D
    stream2D.stop();
    // Clear the Stream2D
    stream2D.clear();
    // Free the Stream2D
    stream2D.free();
    // Clear the AudioManager
    audioManager.clear();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void stream3DUnitTest()
{
    // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING STREAM3D UNIT TEST" << std::endl;
    std::cout << std::endl;
    std::cout << "Loading Sound...";
    // Send a message to the console
    std::cout << "Success" << std::endl;
    // Make a Stream3D
    Stream3D stream3D;
    // Load Audio for the stream
    stream3D.load("media/sounds/electronics014.ogg");
    // Set Looping
    stream3D.setLoop(true);
    // Set Spacial Position
    stream3D.setPosition(100.0f, 0.0f, 0.0f);
    // Set Min Distance and Max Distance
    stream3D.setMinMaxDistance(2.0f, 10000.0f);
    // Play the Stream3D
    stream3D.play();
    // Set the Listener Positoin
    audioSystem.setListenerPosition(0.0f, 0.0f);
    // unit test variable to control sound movement
    float theta = 0.0f;
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while (true)
    {
        // Interpolate theta
        theta = theta + 0.00005f;
        // Set the Sound's position
        stream3D.setPosition(cos(theta) * 100.0f, 0.0f, sin(theta) * 100.0f);
        // Send a message to the console
        std::cout << cos(theta) * 100.0f << ", 0.0f, " << sin(theta) * 100.0f << std::endl;
        // Update the Stream3D
        stream3D.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // When Stream3D is finished (impossible when looping)
        if (stream3D.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Stream3D
    stream3D.stop();
    // Clear Stream3D
    stream3D.clear();
    // Free Stream3D
    stream3D.free();
    // Clear the AudioManager
    audioManager.clear();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void musicUnitTest()
{
     // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING MUSIC UNIT TEST" << std::endl;
    std::cout << std::endl;
    // Make Music
    Music music;
    // Try and Load the Music
    if (music.load("media/music/Level5.mod") == false)
    {
        // Send a message to the console
        std::cout << "ERROR: Failed to load file" << std::endl;
        // Failure
        return;
    }
    // Play the Music
    music.play();
    // Mute the Music
    music.mute();
    // Set the Volume of the Music
    music.setVolume(1.0f);
    // Unmute hte Music
    music.unmute();
    // Set Loop
    music.setLoop(false);
    // Set music Volume
    audioSystem.setMusicVolume(1.0f);
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while(true)
    {
        // Update the music
        music.update(1.0f / 60.0f);
        // When Music is finished (impossible when looping)
        if (music.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Music
    music.stop();
    // Clear Music
    music.clear();
      // Free Music
    music.free();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void dspUnitTest()
{
     // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING DSP UNIT TEST" << std::endl;
    std::cout << std::endl;

    // Some Audio for the demo
    Music music;
    music.load("media/music/bensound-jazzyfrenchy.ogg");
    music.play();
    // Our DSP to add to our audio
    DSP dsp;
    dsp.create(FMOD_DSP_TYPE_ECHO);
    // Add our DSP to our audio
    music.addDSP(0, dsp.getFMODDSP());
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while(true)
    {
        // Update the music
        music.update(1.0f / 60.0f);
        // When Music is finished (impossible when looping)
        if (music.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop music
    music.stop();
    // Clear music
    music.clear();
    // Free Music
    music.free();
    // Release DSP
    dsp.release();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void reverbTest()
{
     // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING REVERB TEST" << std::endl;
    std::cout << std::endl;
    // Make Music
    Music music;
    // Try and Load the Music
    //if (music.load("media/music/Level5.mod") == false)
    if (music.load("media/music/bensound-littleidea.ogg") == false)
    {
        // Send a message to the console
        std::cout << "ERROR: Failed to load file" << std::endl;
        // Failure
        return;
    }
    // Play the Music
    music.play();
    // Mute the Music
    music.mute();
    // Set the Volume of the Music
    music.setVolume(1.0f);
    // Unmute hte Music
    music.unmute();
    // Set Loop
    music.setLoop(false);
    // Set music Volume
    audioSystem.setMusicVolume(1.0f);
    // Set Reverb
    audioSystem.setGlobalReverbProperties(FMOD_PRESET_CONCERTHALL);
//    /*                                      Decay     LateDly    HFDecay    Densty   LoGain    E/L-Mix
//                                                 EarlyDly    HFRef     Diffus   LoFreq     HiCut      WetLvl */
//    #define FMOD_PRESET_OFF              {  1000,    7,  11, 5000, 100, 100, 100, 250, 0,    20,  96, -80.0f }
//    #define FMOD_PRESET_GENERIC          {  1500,    7,  11, 5000,  83, 100, 100, 250, 0, 14500,  96,  -8.0f }
//    #define FMOD_PRESET_PADDEDCELL       {   170,    1,   2, 5000,  10, 100, 100, 250, 0,   160,  84,  -7.8f }
//    #define FMOD_PRESET_ROOM             {   400,    2,   3, 5000,  83, 100, 100, 250, 0,  6050,  88,  -9.4f }
//    #define FMOD_PRESET_BATHROOM         {  1500,    7,  11, 5000,  54, 100,  60, 250, 0,  2900,  83,   0.5f }
//    #define FMOD_PRESET_LIVINGROOM       {   500,    3,   4, 5000,  10, 100, 100, 250, 0,   160,  58, -19.0f }
//    #define FMOD_PRESET_STONEROOM        {  2300,   12,  17, 5000,  64, 100, 100, 250, 0,  7800,  71,  -8.5f }
//    #define FMOD_PRESET_AUDITORIUM       {  4300,   20,  30, 5000,  59, 100, 100, 250, 0,  5850,  64, -11.7f }
//    #define FMOD_PRESET_CONCERTHALL      {  3900,   20,  29, 5000,  70, 100, 100, 250, 0,  5650,  80,  -9.8f }
//    #define FMOD_PRESET_CAVE             {  2900,   15,  22, 5000, 100, 100, 100, 250, 0, 20000,  59, -11.3f }
//    #define FMOD_PRESET_ARENA            {  7200,   20,  30, 5000,  33, 100, 100, 250, 0,  4500,  80,  -9.6f }
//    #define FMOD_PRESET_HANGAR           { 10000,   20,  30, 5000,  23, 100, 100, 250, 0,  3400,  72,  -7.4f }
//    #define FMOD_PRESET_CARPETTEDHALLWAY {   300,    2,  30, 5000,  10, 100, 100, 250, 0,   500,  56, -24.0f }
//    #define FMOD_PRESET_HALLWAY          {  1500,    7,  11, 5000,  59, 100, 100, 250, 0,  7800,  87,  -5.5f }
//    #define FMOD_PRESET_STONECORRIDOR    {   270,   13,  20, 5000,  79, 100, 100, 250, 0,  9000,  86,  -6.0f }
//    #define FMOD_PRESET_ALLEY            {  1500,    7,  11, 5000,  86, 100, 100, 250, 0,  8300,  80,  -9.8f }
//    #define FMOD_PRESET_FOREST           {  1500,  162,  88, 5000,  54,  79, 100, 250, 0,   760,  94, -12.3f }
//    #define FMOD_PRESET_CITY             {  1500,    7,  11, 5000,  67,  50, 100, 250, 0,  4050,  66, -26.0f }
//    #define FMOD_PRESET_MOUNTAINS        {  1500,  300, 100, 5000,  21,  27, 100, 250, 0,  1220,  82, -24.0f }
//    #define FMOD_PRESET_QUARRY           {  1500,   61,  25, 5000,  83, 100, 100, 250, 0,  3400, 100,  -5.0f }
//    #define FMOD_PRESET_PLAIN            {  1500,  179, 100, 5000,  50,  21, 100, 250, 0,  1670,  65, -28.0f }
//    #define FMOD_PRESET_PARKINGLOT       {  1700,    8,  12, 5000, 100, 100, 100, 250, 0, 20000,  56, -19.5f }
//    #define FMOD_PRESET_SEWERPIPE        {  2800,   14,  21, 5000,  14,  80,  60, 250, 0,  3400,  66,   1.2f }
//    #define FMOD_PRESET_UNDERWATER       {  1500,    7,  11, 5000,  10, 100, 100, 250, 0,   500,  92,   7.0f }
    // Send a mesaage to the console
    std::cout << "Press Space to Stop this Unit Test" << std::endl;
    // Psuedo Main Loop
    while(true)
    {
        // Update the music
        music.update(1.0f / 60.0f);
        // When Music is finished (impossible when looping)
        if (music.isPlaying() == false)
        {
            // Break from our loop
            break;
        }
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Music
    music.stop();
    // Clear Music
    music.clear();
      // Free Music
    music.free();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void captureUnitTest()
{
     // Send a message to the console
    std::cout << std::endl;
    std::cout << "PERFORMING CAPTURE UNIT TEST" << std::endl;
    std::cout << std::endl;

    // Recording
    Recording recording;

    std::cout << std::endl;
    std::cout << "NOTE: If there are issue detecting recording devices, its likely another program is running FMOD; alternatively hardware failure." << std::endl;
    std::cout << "Sometimes the recording device takes time to return control back to the OS on shutting down so the device might not necessarily" << std::endl;
    std::cout << "be available" << std::endl;
    std::cout << std::endl;
    std::cout << "Number of Connected Recording Devices: " << audioSystem.getNumberOfConnectedRecordingDevices() << std::endl;
    std::cout << "Number of Connected Recording Drivers: " << audioSystem.getNumberOfDrivers() << std::endl;
    std::cout << std::endl;

    // Create the Recording Device
    if (recording.create(10) == false)
        return;
    std::cout << "Press any key to begin recording..." << std::endl;
    // Wait for keypress
    waitForKeypress();
    // Start Recording
    recording.startRecording();
    std::cout << std::endl;
    std::cout << "Press any key to stop recording..." << std::endl;
    std::cout << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
    // RECORDING MAIN LOOP
    while(true)
    {
        // Update the recording
        recording.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Stop Recording
    recording.stopRecording();
    // Wait for No Keypress
    waitForNoKeypress();
    // Send a message to the console
    std::cout << "Playing recording back" << std::endl;
    std::cout << "Press any key to stop" << std::endl;
    recording.play();
    // PLAYBACK MAIN LOOP
    while(true)
    {
        // Update the recording
        recording.update(1.0f / 60.0f);
        // Think for the AudioSystem
        audioSystem.think();
        // Update the AudioSystem
        audioSystem.update();
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
    // Release the recording
    recording.release();
    // Send a message to the console
    std::cout << "TEST COMPLETE" << std::endl;
    // Wait for no keypress
    waitForNoKeypress();
}

void waitForKeypress()
{
    while(true)
    {
        // If a key was pressed
        if (kbhit() == true)
        {
            // Grab the Keypressed
            char ch = getch();
            // If key was space then break
            if (ch == 32)
                break;
         }
    }
}

void waitForNoKeypress()
{
    while(true)
    {
        // If a key was pressed
        if (kbhit() == false)
        {
            break;
         }
    }
}
