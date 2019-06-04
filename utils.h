//
// Tasks: 1 6 9 14
// Created by yaroslav on 05.02.19.
//

#ifndef LABS_CPP_UTILS_H
#define LABS_CPP_UTILS_H

class Matrix {
public:
    double** matrixValues;

    Matrix();
    Matrix(double ** matrixValues);

    void printMatrix();
};

struct ComplexNumber {
public:
    double x;
    double y;

    ComplexNumber(double x, double y);
};


template <typename T>
void swapByLink(T &a, T &b);

void swapByPointer(int *a, int *b);

void round(double &value);

void round(double *value);

void multiply(ComplexNumber *number, double factor);

void multiply(ComplexNumber &number, double factor);

void transpose(Matrix *source);

void transpose(Matrix &source);

double **allocateEmptyMatrixArray();

Matrix generateRandomMatrix();

#endif //LABS_CPP_UTILS_H
