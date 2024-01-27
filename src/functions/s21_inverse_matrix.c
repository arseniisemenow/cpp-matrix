#include "../headers/s21_common.h"

int handleMatrix1x1(matrix_t *A, matrix_t *result) {
  int errorCode = errorCode_noError;
  int size = A->rows;

  if (size == 1) {
    errorCode |= s21_create_matrix(size, size, result);
    result->matrix[0][0] = 1 / A->matrix[0][0];
  }
  return errorCode;
}

int calculateComplementMatrix(matrix_t *A, matrix_t *complementsMatrix) {
  int errorCode = handleReturnValueInputComplementMatrix(A, complementsMatrix);
  if (errorCode) return errorCode;

  int size = A->rows;

  int createResult = s21_create_matrix(size, size, complementsMatrix);
  if (createResult) return errorCode_errorCreatingResultMatrix;

  double **complements = complementsMatrix->matrix;

  int minorErrorCode = errorCode_noError;
  for (int rowIndex = 0; rowIndex < size && !minorErrorCode; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < size && !minorErrorCode;
         ++columnIndex) {
      double minorResult = 0.0;
      minorErrorCode = s21_minor(A, rowIndex, columnIndex, &minorResult);
      if (!minorErrorCode) {
        double sign = getComplementSign(rowIndex, columnIndex);
        complements[rowIndex][columnIndex] = sign * minorResult;
      }
    }
  }

  return minorErrorCode;
}

int calculateInverseMatrix(matrix_t *transposedComplements, double det,
                           matrix_t *result) {
  int size = transposedComplements->rows;
  double **inverseMatrix = result->matrix;

  for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < size; ++columnIndex) {
      inverseMatrix[rowIndex][columnIndex] =
          (1.0 / det) * transposedComplements->matrix[rowIndex][columnIndex];
    }
  }

  return errorCode_noError;
}

int getReturnValue(int errorCode) {
  if (errorCode & errorCode_errorCalculatingDeterminant)
    return returnValue_CalculationError;
  if (errorCode & errorCode_matrixIsSingular)
    return returnValue_CalculationError;
  if (errorCode & returnValue_IncorrectMatrixError)
    return returnValue_IncorrectMatrixError;
  if (errorCode & returnValue_CalculationError)
    return returnValue_CalculationError;
  return returnValue_Ok;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int errorCode = handleReturnValueInputMatrixInversion(A);
  if (errorCode) return returnValue_IncorrectMatrixError;

  int size = A->rows;
  double det = 0;
  int detErrorCode = s21_determinant(A, &det);
  if (detErrorCode) errorCode |= errorCode_errorCalculatingDeterminant;
  if (fabs(det) < S21_EPSILON) errorCode |= errorCode_matrixIsSingular;

  matrix_t complementsMatrix = {0};
  matrix_t transposedComplements = {0};

  if (!errorCode) {
    if (calculateComplementMatrix(A, &complementsMatrix) != errorCode_noError)
      errorCode |= errorCode_errorCalculatingComplementMatrix;
  }
  if (!errorCode) {
    if (s21_transpose(&complementsMatrix, &transposedComplements))
      errorCode |= errorCode_errorTransposing;
  }
  if (!errorCode) {
    if (s21_create_matrix(size, size, result))
      errorCode |= errorCode_errorCreatingResultMatrix;
  }

  if (!errorCode) {
    calculateInverseMatrix(&transposedComplements, det, result);
  }

  s21_remove_matrix(&complementsMatrix);
  s21_remove_matrix(&transposedComplements);

  if (errorCode & errorCode_errorCalculatingComplementMatrix)
    errorCode |= handleMatrix1x1(A, result);
  int returnValue = getReturnValue(errorCode);

  if (errorCode & errorCode_matrixIsSingular)
    returnValue = returnValue_CalculationError;

  return returnValue;
}