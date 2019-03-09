//
// Created by yaroslav on 09.03.19.
//

#include "Vector.h"

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector Vector::operator+(Vector* other) {
    return Vector(this->x + other->x, this->y + other->y, this->z + other->z);
}

