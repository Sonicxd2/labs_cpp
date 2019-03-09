//
// Created by yaroslav on 06.02.19.
//

#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <iostream>

/**
 * throw assertexception
 */
void assert(bool value);

class assertexception : public std::exception {
    virtual const char *what() const throw() {
        return "Assertion exception.";
    };
};

#endif //DEBUG_UTILS_H
