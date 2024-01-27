#include "s21_develop.h"

#include "../headers/s21_common.h"

void fillMatrixRandom(matrix_t *matrix) {
  if (!matrix || !matrix->matrix) {
    return;
  }

  srand(time(NULL));

  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      double value = (double)rand() / RAND_MAX;
      matrix->matrix[i][j] = (int)(value * 10);
    }
  }
}

int testInverseMatrix(matrix_t *inputMatrix, matrix_t *resultMatrix) {
  int size = inputMatrix->rows;
  matrix_t expectedIdentityMatrix = createIdentityMatrix(size);
  matrix_t resultIdentityMatrix = {0};
  s21_mult_matrix(inputMatrix, resultMatrix, &resultIdentityMatrix);
  return s21_eq_matrix(&expectedIdentityMatrix, &resultIdentityMatrix);
}

void printBottomLine(int stringLength) {
  putchar('<');
  while ((stringLength--) - 4 > 0) putchar('=');
  putchar('>');
  putchar('\n');
}

int printTopLine(const char *matrixName) {
  return printf("\n<===== %s ======>\n", matrixName);
}

void printMatrixItself(const matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      printf("% .8f\t", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}

void printMatrixFile(const matrix_t *matrix) {
  FILE *filePtr = fopen("../test.txt", "w");
  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      fprintf(filePtr, "%.8f\t", matrix->matrix[i][j]);
    }
    fprintf(filePtr, "\n");
  }
  fclose(filePtr);
}

void printMatrix(const char *matrixName, const matrix_t *matrix) {
  if (!matrix || !matrix->matrix) {
    fprintf(stderr, "\n<xxxxxxxxxxxx>\nInvalid matrix\n<xxxxxxxxxxxx>\n");
    return;
  }
  int stringLength = printTopLine(matrixName);
  printMatrixItself(matrix);
  printBottomLine(stringLength);
}

void writeFile(const matrix_t *matrix) {
  if (!matrix || !matrix->matrix) {
    fprintf(stderr, "\n<xxxxxxxxxxxx>\nInvalid matrix\n<xxxxxxxxxxxx>\n");
    return;
  }
  printMatrixFile(matrix);
}

matrix_t createIdentityMatrix(int size) {
  matrix_t matrix = {0};
  s21_create_matrix(size, size, &matrix);
  for (int i = 0; i < size; ++i) {
    matrix.matrix[i][i] = 1;
  }
  return matrix;
}
