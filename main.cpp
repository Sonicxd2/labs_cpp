// Tasks 4,6
// Created by yaroslav on 06.02.19.
//

#include <ctime>
#include <iostream>
#include <functional>
#include "utils.h"
#include "matrix.h"
#include "intarray.h"

bool testMatrix() {
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
    res = firstMatrix.operator-(secondMatrix);
    std::cout << "Minus: " << std::endl;
    res.printMatrix();
    free(res.array);
    res = firstMatrix * secondMatrix;
    std::cout << "Multiply: " << std::endl;
    res.printMatrix();
    free(res.array);
    return true;
}

bool testIntArray() {
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
        return false;
    } catch(std::exception e) {
        return true;
    }
}

std::function<bool()> tests[] = {testIntArray, testMatrix};

int main() {
    std::srand(unsigned(std::time(0)));
    int success = 0;
    for (int i = 0; i < sizeof(tests) / sizeof(std::function<bool()>); i++) {
        try {
            bool result = tests[i]();
    *        if (result) {
                success++;
            } else {
                std::cout << "Test with number " << i << " was failed!" << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << "Catched exception in test number " << i << " with reason " << e.what() << std::endl;
        }
    }
    std::cout << "Testing is finished. Amount of tests: " << sizeof(tests) / sizeof(std::function<bool()>)
         << ". Success tests: " << success;
}