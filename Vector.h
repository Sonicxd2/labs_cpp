//
// Created by yaroslav on 09.03.19.
//

#ifndef TESTINGPLACE_VECTOR_H
#define TESTINGPLACE_VECTOR_H


class Vector {
public:
    double x;
    double y;
    double z;

    Vector(double x, double y, double z);

    Vector operator+(Vector* other);
};


#endif //TESTINGPLACE_VECTOR_H
