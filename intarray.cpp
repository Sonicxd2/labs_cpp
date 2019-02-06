//
// Created by yaroslav on 06.02.19.
//

#include "intarray.h"
#include <malloc.h>
#include "utils.h"

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

Array Array::operator+(Array next) {
    Array newArray = Array(size + next.size);
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    for (int j = 0; j < next.size; j++) {
        newArray[size + j] = next[j];
    }
    return newArray;
}
