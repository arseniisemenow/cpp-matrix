#include "../headers/s21_common.h"

int performComparison(matrix_t *A, matrix_t *B) {
  int comparisonStatus = SUCCESS;
  int rows = A->rows;
  int columns = A->columns;

  for (int rowIndex = 0; rowIndex < rows && comparisonStatus == SUCCESS;
       ++rowIndex) {
    for (int columnIndex = 0;
         columnIndex < columns && comparisonStatus == SUCCESS; ++columnIndex) {
      double diff = fabs(A->matrix[rowIndex][columnIndex] -
                         B->matrix[rowIndex][columnIndex]);
      if (fabs(diff) > S21_EPSILON) {
        comparisonStatus = FAILURE;
      }
    }
  }
  return comparisonStatus;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int errorCode = handleReturnValueInputMatricesEqualization(A, B);
  if (errorCode) return FAILURE;
  return performComparison(A, B);
}