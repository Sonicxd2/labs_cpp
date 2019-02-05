//
// Created by yaroslav on 06.02.19.
//

#ifndef DEBUG_MATRIX_H
#define DEBUG_MATRIX_H

#include <cstdlib>

class Matrix {
public:
    double **array;

    explicit Matrix(double **array);

    Matrix operator-(Matrix another);

    Matrix operator+(Matrix another);

    Matrix operator*(double value);

    Matrix operator*(Matrix next);
};

bool operator==(Matrix current, Matrix next);

bool operator!=(Matrix current, Matrix next);

bool operator>(Matrix current, Matrix next);

bool operator<(Matrix current, Matrix next);


double **allocateEmptyMatrixArray();

#endif //DEBUG_MATRIX_H
