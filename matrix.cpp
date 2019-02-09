/
// Created by yaroslav on 06.02.19.
//

#include "matrix.h"
#include "unsupportedoperationexception.h";


Matrix::Matrix(double **array) : array(array) {}

Matrix Matrix::operator-(Matrix next) {
    double **matrix = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = array[i][j] - next.array[i][j];
        }
    }
    return Matrix(matrix);
};

Matrix Matrix::operator+(Matrix next) {
    double **matrix = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = array[i][j] + next.array[i][j];
        }
    }
    return Matrix(matrix);
};

Matrix Matrix::operator*(double value) {
    double **matrix = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = array[i][j] * value;
        }
    }
    return Matrix(matrix);
}

Matrix Matrix::operator*(Matrix next) {
    double **matrix = allocateEmptyMatrixArray();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                matrix[i][j] += array[i][k] * next.array[i][k];
            }
        }
    }
    return Matrix(matrix);
}

bool operator==(Matrix current, Matrix next) {
    bool equals = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            equals &= current.array[i][j] == next.array[i][j];
        }
    }
    return equals;
}

bool operator!=(Matrix current, Matrix next) {
    return !operator==(current, next);
}

//Operations > < is not supported to matrixs. >_<
bool operator>(Matrix current, Matrix next) {
    throw unsupportedoperationexception();
}

bool operator<(Matrix current, Matrix next) {
    throw unsupportedoperationexception();
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

void Matrix::printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
