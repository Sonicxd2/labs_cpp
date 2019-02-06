// Tasks 4,6
// Created by yaroslav on 06.02.19.
//

#include <ctime>
#include <iostream>
#include "utils.h"
#include "matrix.h"
#include "intarray.h"

void testMatrix() {
    Matrix firstMatrix = generateRandomMatrix();
    Matrix secondMatrix = generateRandomMatrix();
    std::cout << "First matrix: " << std::endl;
    firstMatrix.printMatrix();
    std::cout << "Second matrix: " << std::endl;
    secondMatrix.printMatrix();
    std::cout << "Sum: " << std::endl;
    Matrix res = firstMatrix + secondMatrix;
    res.printMatrix();
    free(res.array);
    res = firstMatrix - secondMatrix;
    std::cout << "Minus: " << std::endl;
    res.printMatrix();
    free(res.array);
    res = firstMatrix * secondMatrix;
    std::cout << "Multiply: " << std::endl;
    res.printMatrix();
    free(res.array);
}

void testIntArray() {
    Array firstArray = Array(10);
    for (int i = 0; i < 10; i++) {
        firstArray[i] = i;
    }
    Array secondArray = Array(10);
    for (int i = 0; i < 10; i++) {
        secondArray[i] = i;
    }
    assert(firstArray == secondArray);
    assert(firstArray[0] == 0);
    assert(firstArray[9] == 9);
    try {
        firstArray[10];
        std::cout << "IndexOutOfBounds not throwed:(";
        exit(-11);
    } catch(std::exception e) {

    }
}

int main() {
    std::srand(unsigned(std::time(0)));
    testMatrix();
    testIntArray();
}