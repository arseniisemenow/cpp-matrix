#include "../headers/s21_common.h"

void performMatricesMulOperation(matrix_t *A, matrix_t *B, matrix_t *result,
                                 int errorCode) {
  int rowsA = A->rows;
  int columnsA = A->columns;
  int columnsB = B->columns;

  for (int rowIndex = 0; rowIndex < rowsA && !errorCode; ++rowIndex) {
    for (int columnsBIndex = 0; columnsBIndex < columnsB; ++columnsBIndex) {
      (*result).matrix[rowIndex][columnsBIndex] = 0;
      for (int columnsAIndex = 0; columnsAIndex < columnsA; ++columnsAIndex) {
        (*result).matrix[rowIndex][columnsBIndex] +=
            A->matrix[rowIndex][columnsAIndex] *
            B->matrix[columnsAIndex][columnsBIndex];
      }
    }
  }
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = handleReturnValueInputMatricesMultiplyMatrices(A, B, result);
  if (errorCode & errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;
  if (errorCode & errorCode_invalidMatricesDimensions)
    return returnValue_CalculationError;

  int rowsA = A->rows;
  int columnsB = B->columns;

  int createResult = s21_create_matrix(rowsA, columnsB, result);
  if (createResult) errorCode = errorCode_errorCreatingResultMatrix;

  performMatricesMulOperation(A, B, result, errorCode);

  return errorCode;
}