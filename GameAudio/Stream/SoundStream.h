//#ifndef SOUNDSTREAM_H
//#define SOUNDSTREAM_H
//
//#include <iostream>
//#include <fmod.h>
////extern "C"
////{
////    #include <lua.h>
////    #include <lualib.h>
////    #include <lauxlib.h>
////}
////#include <luabind/luabind.hpp>
//
// /** The Stream class is a wrapper around an FSOUND_STREAM object.
//    This class is used because the FSOUND_STREAM object is actually a predeclaration and using is
//    as anything other than a pointer will create compile errors. So it becomes impossible to bind
//    the FSOUND_STREAM to any scripting language because the object isn't defined **/
//class SoundStream
//{
//    public:
//        //! Default Constructor
//        SoundStream()
//        {
//           this->pFMODSoundStream = 0;
//           this->filename.clear();
//        }
//        //! Destructor
//        virtual ~SoundStream()
//        {
//            // Release the SoundStream if that hasn't happened already
//            //if (this->pFMODSoundStream != 0)
//                //FSOUND_Stream_Close(this->pFMODSoundStream);
//            // Reset the pointer to the SoundStream
//            this->pFMODSoundStream = 0;
//            // Clear the filename
//            this->filename.clear();
//        }
//
//    // STREAM FUNCTIONS
//    public:
//        /* TODO: EXCLUDED STREAM FUNCTIONS
//            FSOUND_Stream_AddSyncPoint - requires callbacks
//            FSOUND_Stream_Close - handled by the content manager
//            FSOUND_Stream_Create - requires callbacks and not neccessary to our purpose
//            FSOUND_Stream_CreateDSP - requires callbacks (DSP Only supported WIN32)
//            FSOUND_Stream_DeleteSyncPoint - function related to callbacks
//            FSOUND_Stream_FindTagField - exlcuded for now not sure what it does
//            FSOUND_Stream_GetNumSyncPoints - requires callbacks
//            FSOUND_Stream_GetNumTagFields - exlcuded for now not sure what it does
//            FSOUND_Stream_GetSyncPoint - requires callbacks
//            FSOUND_Stream_GetSyncPointInfo - requires callbacks
//            FSOUND_Stream_GetTagField - exlcuded for now not sure what it does
//            FSOUND_Stream_Net_GetBufferProperties - excluded for now complex return types
//            FSOUND_Stream_Net_GetLastServerStatus - excluded no net support yet
//            FSOUND_Stream_Net_GetStatus - excluded no net support yet
//            FSOUND_Stream_Net_SetBufferProperties - excluded no net support yet
//            FSOUND_Stream_Net_SetMetadataCallback - excluded no net support yet
//            FSOUND_Stream_Net_SetProxy - excluded no net support yet
//            FSOUND_Stream_Open - handled by the content manager
//            FSOUND_Stream_SetBufferSize - Doesn't seem applicable
//            FSOUND_Stream_SetEndCallback - requires callbacks
//            FSOUND_Stream_SetLoopPoints - Excluding doesn't seem to apply
//            FSOUND_Stream_SetSyncCallback - requires callbacks*/
//        //! Get the Stream Length in Bytes
//        int getLength() { return FSOUND_Stream_GetLength(this->pFMODSoundStream); }
//        //! Get the Stream Length in Miliseconds
//        int getLengthMs() { return FSOUND_Stream_GetLengthMs(this->pFMODSoundStream); }
//        //! Get Mode Stream Mode
//        unsigned int getMode() { return FSOUND_Stream_GetMode(this->pFMODSoundStream); }
//        //! Get the number of substreams
//        int getSubStreamCount() { return FSOUND_Stream_GetNumSubStreams(this->pFMODSoundStream); }
//        //! Get the OpenState
//        /**  0 = stream is opened and ready.
//            -1 = stream handle passed in is invalid.
//            -2 = stream is still opening or performing a SetSubStream command.
//            -3 = stream failed to open. (file not found, out of memory or other error).
//            -4 = connecting to remote host (internet streams only)
//            -5 = stream is buffering data (internet streams only) **/
//        int getOpenState() { return FSOUND_Stream_GetOpenState(this->pFMODSoundStream); }
//        //! Get Position
//        /** Returns the current FILE position of the stream of the stream in BYTES **/
//        unsigned int getPosition() { return FSOUND_Stream_GetPosition(this->pFMODSoundStream); }
//        // TODO: This function should really return a SoundSample Object for the benefit of scripting
//        //! Get the sample for the stream
//        FSOUND_SAMPLE* getSample() { return FSOUND_Stream_GetSample(this->pFMODSoundStream); }
//        //! Get Time
//        /** Returns the current time offset in stream in milliseconds. **/
//        int getTime() { return FSOUND_Stream_GetTime(this->pFMODSoundStream); }
//        //! Set the streams loop count
//        /** if this is not called or parameter is < 0 then the stream loops forever **/
//        void setLoopCount(int count)
//        {
//            FSOUND_Stream_SetLoopCount(this->pFMODSoundStream, count);
//        }
//        //! Set loop (turn looping on)
//        void setLoop(bool state)
//        {
//            if (state == true)
//            {
//                int mode = FSOUND_Stream_GetMode(this->pFMODSoundStream);
//                bool isLooping = mode & 2;
//                if (isLooping == true)
//                    return;
//                mode = mode xor FSOUND_LOOP_NORMAL;
//                FSOUND_Stream_SetMode(this->pFMODSoundStream, mode);
//                std::cout << "Loop mode for stream set to true. Value is: " << (FSOUND_Stream_GetMode(this->pFMODSoundStream) & 2) << std::endl;
//            }
//            else
//            {
//                int mode = FSOUND_Stream_GetMode(this->pFMODSoundStream);
//                bool isLooping = mode & 2;
//                if (isLooping == false)
//                    return;
//                mode = mode xor FSOUND_LOOP_NORMAL;
//                FSOUND_Stream_SetMode(this->pFMODSoundStream, mode);
//                std::cout << "Loop mode for stream set to false. Value is: " << (FSOUND_Stream_GetMode(this->pFMODSoundStream) & 2) << std::endl;
//            }
//        }
//        //! Set the streams modes
//        void setMode(unsigned int mode) { FSOUND_Stream_SetMode(this->pFMODSoundStream, mode); }
//        //! Set the stream position in Bytes
//        void setPosition(unsigned int position) { FSOUND_Stream_SetPosition(this->pFMODSoundStream, position); }
//        //! Seek to a substream inside an FSB bank file
//        void setSubStream(int index) { FSOUND_Stream_SetSubStream(this->pFMODSoundStream, index); }
//        //! Describe the playback order for the list of substreams (FSB bank file)
//        void setSubStreamSentence(const int* sentenceList, int numItems) { FSOUND_Stream_SetSubStreamSentence(this->pFMODSoundStream, sentenceList, numItems); }
//        //! Set Stream Time in miliseconds (seeking)
//        void setTime(int ms) { FSOUND_Stream_SetTime(this->pFMODSoundStream, ms); }
//
//    // FMOD SOUNDSTREAM FUNCTIONS
//    public:
//        //! Get the SoundStream
//        FSOUND_STREAM* getFMODSoundStream() { return this->pFMODSoundStream; }
//        //! Set the SoundStream
//        void setFMODSoundStream(FSOUND_STREAM* pFMODSoundStream)
//        {
//            this->pFMODSoundStream = pFMODSoundStream;
//        }
//
//    protected:
//        //! A pointer to the FSOUND_STREAM
//        FSOUND_STREAM* pFMODSoundStream;
//
//    // FILENAME FUNCTIONS
//    public:
//        //! Get filename
//        const char* getFilename() { return this->filename.c_str(); }
//        //! Set filename
//        void setFilename(const char* filename) { this->filename = filename; }
//
//    protected:
//        //! Sound filename
//        std::string filename;
//
////    public:
////        //! Bind this class to a lua state
////        static void bindToLua(lua_State* pLuaState);
//};
//
//#endif // SOUNDSTREAM_H
