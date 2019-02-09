//
// Created by yaroslav on 05.02.19.
//
#include <iostream>
#include <functional>
#include <signal.h>
#include "utils.h"
#include <memory>
#include <ctime>

using namespace std;

void assert(bool value) {
    if (!value) {
        throw std::exception();
    }
}

bool swapTest() {
    int a = 1;
    int b = 2;
    swapByLink(a, b);
    assert(a > b);
    swapByPointer(&a, &b);
    return a < b;
}

bool roundTest() {
    double val = 1.2;
    round(val);
    assert((int)val == 1);
    val = 1.6;
    round(val);
    assert((int)val == 2);
    return true;
}

bool complexMultiplyTest() {
    ComplexNumber number = ComplexNumber(10, 0);
    double value = 123;
    multiply(number, value);
    assert(number.x == 123 * 10);
    number.y = 1;
    multiply(&number, 2);
    assert(number.y == 2);
    return true;
}

bool transposeMatrix() {
    Matrix current = generateRandomMatrix();
    Matrix source = Matrix(current);
    current.printMatrix();
    transpose(current);
    current.printMatrix();
    return true;
}

std::function<bool()> tests[] = {swapTest, roundTest, complexMultiplyTest, transposeMatrix};

int main() {
    std::srand(unsigned(std::time(0)));
    int success = 0;
    for (int i = 0; i < sizeof(tests) / sizeof(std::function<bool()>); i++) {
        try {
            bool result = tests[i]();
            if (result) {
                success++;
            } else {
                cout << "Test with number " << i << " was failed!" << endl;
            }
        } catch (std::exception &e) {
            cout << "Catched exception in test number " << i << " with reason " << e.what() << endl;
        }
    }
    cout << "Testing is finished. Amount of tests: " << sizeof(tests) / sizeof(std::function<bool()>)
         << ". Success tests: " << success;
}