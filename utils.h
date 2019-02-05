//
// Tasks: 1 6 9 14
// Created by yaroslav on 05.02.19.
//

#ifndef LABS_CPP_UTILS_H
#define LABS_CPP_UTILS_H

class Matrix {
public:
    int** matrixValues;

    Matrix();
    Matrix(int ** matrixValues);

    void printMatrix();
};

struct ComplexNumber {
public:
    double x;
    double y;

    ComplexNumber(double x, double y);
};

void swapByLink(int &a, int &b);

void swapByPointer(int *a, int *b);

void roundByLink(double &value);

void roundByPointer(double *value);

void multiplyByPointer(ComplexNumber *number, double factor);

void multiplyByLink(ComplexNumber &number, double factor);

void transposeByPointer(Matrix *source);

void transposeByLink(Matrix &source);

#endif //LABS_CPP_UTILS_H
