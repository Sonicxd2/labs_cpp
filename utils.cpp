//
// Created by yaroslav on 05.02.19.
//

#include <mutex>
#include "utils.h"
#include <iostream>

using namespace std;

void swapByLink(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b) {
    swapByLink(*a, *b);
}

void roundByLink(double &value) {
    double fraction = value - ((int) value);
    value -= fraction;
    if (fraction > 0.49999999) {
        value++;
    }
}

void roundByPointer(double *value) {
    roundByLink(*value);
}


void multiplyByLink(ComplexNumber &number, double factor) {
    number.x = number.x * factor;
    number.y = number.y * factor;
}

void multiplyByPointer(ComplexNumber *number, double factor) {
    multiplyByLink(*number, factor);
}

void transposeByLink(Matrix &source) {
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            swapByLink(source.matrixValues[i][j], source.matrixValues[j][i]);
        }
    }
}

void transposeByPointer(Matrix *source) {
    transposeByLink(*source);
}

Matrix::Matrix() {

}

Matrix::Matrix(int **matrixValues) {
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

ComplexNumber::ComplexNumber(double x, double y) : x(x), y(y) {}
