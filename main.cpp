//
// Created by yaroslav on 05.02.19.
//
#include <iostream>
#include "utils.h"

using namespace std;

void testRoundByLink(double a) {
    roundByLink(a);
    cout << a << endl;
}

void testRoundByPointer(double b) {
    roundByPointer(&b);
    cout << b << endl;
}

void testMatrix(int **sampled) {
    Matrix *matrix = new Matrix(sampled);
    matrix->matrixValues = sampled;
    matrix->printMatrix();
    transposeByPointer(matrix);
    matrix->printMatrix();
}

int main() {
    int a = 120;
    int b = 34;
    swapByLink(a, b);
    cout << a << " " << b << '\n';
    swapByPointer(&a, &b);
    cout << a << '\n';
    testRoundByLink(123.45);
    testRoundByPointer(123.5);

    int ** array;
    array = (int**) malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        array[i] = (int*) malloc(sizeof(int));
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = ++cnt;
        }
    }
    testMatrix(array);

    ComplexNumber number = ComplexNumber(1.0, 0.0);
    multiplyByLink(number, 123);
    cout << number.x << " " << number.y;
}