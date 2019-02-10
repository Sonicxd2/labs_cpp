//
// Created by yaroslav on 09.02.19.
//
#include <iostream>
#include "WritingTextFileStream.h"

using namespace std;

int main() {
    WritingTextFileStream stream = WritingTextFileStream();
    stream.open("helloWorld!");
    stream.writeInt(123);
    stream.writeString("\nHello!\n");
    stream.writeDouble(123.2);
    stream.close();
}