//
// Created by yaroslav on 06.02.19.
//

#include "utils.h"

void assert(bool value) {
    if (!value) throw assertexception();
}