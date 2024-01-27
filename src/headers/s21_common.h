#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix_oop.h"

#ifndef S21_MATRIX_COMMON_H_
#define S21_MATRIX_COMMON_H_

#define S21_EPSILON 1e-7

int handleReturnValueInputMatricesEqualization(matrix_t *A, matrix_t *B);

int handleReturnValueInputMatricesSumAndSub(matrix_t *A, matrix_t *B,
                                            matrix_t *result);

int handleReturnValueInputMatricesMultiplyMatrices(matrix_t *A, matrix_t *B,
                                                   matrix_t *result);

int handleReturnValueInputMatricesMultiplyMatrix(matrix_t *A, matrix_t *result);

int handleReturnValueInputMatricesCalcComplements(matrix_t *A,
                                                  matrix_t *result);

int handleReturnValueInputCreateMatrix(int rows, int columns, matrix_t *result);

int handleReturnValueInputMatrixDeterminant(matrix_t *A);

int handleReturnValueInputComplementMatrix(matrix_t *A,
                                           matrix_t *complementsMatrix);

int handleReturnValueInputMatricesTranspose(matrix_t *A, matrix_t *result);

int handleReturnValueInputMatrixInversion(matrix_t *A);

int handleReturnValueInputMatrixMinor(matrix_t *A, int row, int column);

void performSumAndSubOperations(matrix_t *A, matrix_t *B, matrix_t *result,
                                int errorCode, operationType operationType);

int arithmeticShellForSumAndSub(matrix_t *A, matrix_t *B, matrix_t *result,
                                operationType operationType);

void copyMatrixItself(double **destination, const double **source, int rows,
                      int columns);

double getComplementSign(int rowIndex, int columnIndex);

void swapRows(double **matrix, int rowIndex1, int rowIndex2, int size);

void swapColumns(double **matrix, int columnIndex1, int columnIndex2, int size);

#endif