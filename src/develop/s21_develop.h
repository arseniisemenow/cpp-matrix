#include <stdio.h>

#include "../s21_matrix_oop.h"

#ifndef S21_MATRIX_DEVELOP_H_
#define S21_MATRIX_DEVELOP_H_

void fillMatrixRandom(matrix_t *matrix);

void printMatrixItself(const matrix_t *matrix);

void printMatrix(const char *matrixName, const matrix_t *matrix);

void printMatrixFile(const matrix_t *matrix);

matrix_t createIdentityMatrix(int size);

int testInverseMatrix(matrix_t *inputMatrix, matrix_t *resultMatrix);

#endif