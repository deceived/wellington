#ifndef READERS_HPP
#define READERS_HPP

#include <string>

#include <iostream>
#include <fstream>

/***
    RAII implementation reading a file stream.
***/
class InputFileStream
{

public:

    FileStream()
        : stream_( fileName )
    {}

    ~FileStream()
    {
        stream_.close();
    }

    std::string ReadLine()
    {
        std::string line;
        std::getline( stream_, line );
        return line;
    }

    bool Eof()
    {
        return stream_.eof();
    }
 
private:

    std::ifstream   stream_;

};

#endif
