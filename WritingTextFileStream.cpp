//
// Created by yaroslav on 09.02.19.
//

#include "WritingTextFileStream.h"
#include <iostream>

using namespace std;


WritingTextFileStream::WritingTextFileStream() {

}

WritingTextFileStream::WritingTextFileStream(std::string fileName) {
    open(fileName);
}

void WritingTextFileStream::open(std::string fileName) {
    if (isClosed()) {
        stream.open(fileName);
        this->fileName = &fileName;
        closed = false;
    } else {
        throw IllegalStateException();
    }
}

bool WritingTextFileStream::isClosed() {
    return closed;
}

void WritingTextFileStream::close() {
    if (isClosed()) {
        throw StreamIsClosedException();
    }
    stream.close();
    closed = true;
}

std::string WritingTextFileStream::getFileName() {
    return *fileName;
}

void WritingTextFileStream::writeString(std::string value) {
    if (!isClosed()) {
        stream << value;
    } else {
        throw StreamIsClosedException();
    }
}

void WritingTextFileStream::writeInt(int value) {
    if (!isClosed()) {
        stream << value;
    } else {
        throw StreamIsClosedException();
    }
}

void WritingTextFileStream::writeDouble(double value) {
    if (!isClosed()) {
        stream << value;
    } else {
        throw StreamIsClosedException();
    }
}
