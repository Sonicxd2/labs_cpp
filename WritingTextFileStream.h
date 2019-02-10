//
// Created by yaroslav on 09.02.19.
//

#ifndef DEBUG_WRITINGTEXTFILESTREAM_H
#define DEBUG_WRITINGTEXTFILESTREAM_H


#include <fstream>

class WritingTextFileStream {
private:
    std::ofstream stream;
    bool closed = true;
    std::string* fileName = nullptr;
public:
    WritingTextFileStream();
    WritingTextFileStream(std::string fileName);

    WritingTextFileStream(std::string *fileName);

    void open(std::string fileName);
    bool isClosed();
    void close();
    std::string getFileName();
    void writeString(std::string value);
    void writeInt(int value);
    void writeDouble(double value);
};

class StreamIsClosedException: std::exception {

};

class IllegalStateException: std::exception {

};

#endif //DEBUG_WRITINGTEXTFILESTREAM_H
