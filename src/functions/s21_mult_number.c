#include "../headers/s21_common.h"

void performMatrixMulOperation(matrix_t *A, double number, matrix_t *result,
                               int errorCode) {
  int rows = A->rows;
  int columns = A->columns;

  for (int rowIndex = 0; rowIndex < rows && !errorCode; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      (*result).matrix[rowIndex][columnIndex] =
          A->matrix[rowIndex][columnIndex] * number;
    }
  }
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int errorCode = handleReturnValueInputMatricesMultiplyMatrix(A, result);
  if (errorCode & errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;

  int rows = A->rows;
  int columns = A->columns;

  int createResult = s21_create_matrix(rows, columns, result);
  if (createResult) errorCode = errorCode_errorCreatingResultMatrix;

  performMatrixMulOperation(A, number, result, errorCode);

  return 0;
}