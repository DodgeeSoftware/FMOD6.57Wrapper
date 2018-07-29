# FMODStudio1.09.04 Wrapper

This is a very neat tidy wrapper around FMOD6.75 (aka FMODDudio1.09.04)

This doesn't reprodue the C++ Wrapper that comes out of the box with FMOD. Rather
it makes a neat tidy interface so you don't have to care about how FMOD works.

I made this because its elegant and helps me rapidly create content.

The Folder FMOD Studio Wrapper contains the binaries.

The Folder GameContent contains the Audio Manager which loads Sound Samples,
Sound Sample2Ds and Sound Sample3Ds. The 2d and 3d loading functions are required for positional audio.

The neat functional logic of this wrapper is in the GameAudio folder. I have created easy containers around
many of the objects used by FMOD. For instance, you create a sound system call init and shutdown on that.
Then say to stream audio you can create a Stream object then call the load method to load an audio source
then call the play method to get it to play.

You can check out the main.cpp file here where I do pretty much everything this wrapper can do.

I left recording out. The wrapper supports it yes, but it wasn't appropriate for a demo

