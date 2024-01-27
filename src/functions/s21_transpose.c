#include "../s21_matrix_oop.h"

S21

int s21_transpose(matrix_t *A, matrix_t *result) {
  int errorCode = handleReturnValueInputMatricesTranspose(A, result);
  if (errorCode & errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;

  int rows = A->rows;
  int columns = A->columns;

  int createResult = s21_create_matrix(columns, rows, result);
  if (createResult) errorCode = errorCode_errorCreatingResultMatrix;

  double **transposedMatrix = result->matrix;

  for (int rowIndex = 0; rowIndex < rows && !errorCode; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      transposedMatrix[columnIndex][rowIndex] =
          A->matrix[rowIndex][columnIndex];
    }
  }
  int returnValue = returnValue_Ok;
  if (errorCode) returnValue = returnValue_IncorrectMatrixError;
  return returnValue;
}