#include "../headers/s21_common.h"

int handle1x1Matrix(matrix_t *result) {
  int createResult = s21_create_matrix(1, 1, result);
  if (createResult) return returnValue_IncorrectMatrixError;
  result->matrix[0][0] = 1;
  return returnValue_Ok;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int errorCode = handleReturnValueInputMatricesCalcComplements(A, result);
  if (errorCode == errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;
  if (errorCode == errorCode_invalidMatricesDimensions)
    return returnValue_CalculationError;
  if (errorCode == errorCode_matrixIsFirstGrade) return handle1x1Matrix(result);

  int size = A->rows;

  int returnValue = s21_create_matrix(size, size, result);

  double **complementsMatrix = result->matrix;

  for (int rowIndex = 0; rowIndex < size && !returnValue; ++rowIndex) {
    int errorCodeMinor = errorCode_noError;
    for (int columnIndex = 0; columnIndex < size && !errorCodeMinor;
         ++columnIndex) {
      double minorResult = 0.0;
      errorCodeMinor = s21_minor(A, rowIndex, columnIndex, &minorResult);
      double sign = getComplementSign(rowIndex, columnIndex);
      complementsMatrix[rowIndex][columnIndex] = sign * minorResult;
    }
  }

  return returnValue;
}
