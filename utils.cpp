//
// Created by yaroslav on 05.02.19.
//

#include <mutex>
#include "utils.h"
#include <iostream>

using namespace std;


template <typename T>
void swapByLink(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b) {
    swapByLink(*a, *b);
}

void round(double &value) {
    double fraction = value - ((int) value);
    value -= fraction;
    if (fraction > 0.49999999) {
        value++;
    }
}

void round(double *value) {
    round(*value);
}


void multiply(ComplexNumber &number, double factor) {
    number.x = number.x * factor;
    number.y = number.y * factor;
}

void multiply(ComplexNumber *number, double factor) {
    multiply(*number, factor);
}

void transpose(Matrix &source) {
    double **array = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[j][i] = source.matrixValues[i][j];
        }
    }
    free(source.matrixValues);
    source.matrixValues = array;
}

void transpose(Matrix *source) {
    transpose(*source);
}

Matrix::Matrix() {

}

Matrix::Matrix(double **matrixValues) {
    this->matrixValues = matrixValues;
}

void Matrix::printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << this->matrixValues[i][j] << ' ';
        }
        cout << '\n';
    }
}

double **allocateEmptyMatrixArray() {
    double **array;
    array = (double **) malloc(3 * sizeof(double *));
    for (int i = 0; i < 3; i++) {
        array[i] = (double *) malloc(3 * sizeof(double));
    }
    return array;
}

Matrix generateRandomMatrix() {
    double **array = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = (std::rand() % 500) / (float) 10;
        }
    }
    return Matrix(array);
}

ComplexNumber::ComplexNumber(double x, double y) : x(x), y(y) {}
