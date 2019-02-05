//
// Created by yaroslav on 06.02.19.
//

#include "intarray.h"
#include <malloc.h>
#include <assert.h>

Array::Array(int size) : size(size) {
    this->array = (int *) (malloc(size * sizeof(int)));
}


int &Array::operator[](int id) {
    assert(id < size);
    assert(id > -1);
    return array[id];
}

bool Array::operator==(Array next) {
    return size == next.size;
}

bool Array::operator>(Array next) {
    return size > next.size;
}

bool Array::operator<(Array next) {
    return size < next.size;
}

bool Array::operator!=(Array next) {
    return size != next.size;
}
