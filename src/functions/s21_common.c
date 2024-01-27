#include "../headers/s21_common.h"

int checkMatrixExistence(matrix_t *matrix) {
  if (!matrix || !matrix->matrix) return errorCode_invalidInputMatrices;
  return errorCode_noError;
}
int checkMatricesExistence(matrix_t *matrix1, matrix_t *matrix2) {
  return checkMatrixExistence(matrix1) || checkMatrixExistence(matrix2);
}

int handleReturnValueInputMatricesEqualization(matrix_t *A, matrix_t *B) {
  if (checkMatricesExistence(A, B)) return errorCode_invalidInputMatrices;
  if (A->rows != B->rows || A->columns != B->columns)
    return errorCode_invalidMatricesDimensions;
  return errorCode_noError;
}

int handleReturnValueInputMatricesSumAndSub(matrix_t *A, matrix_t *B,
                                            matrix_t *result) {
  if (checkMatricesExistence(A, B) || !result)
    return errorCode_invalidInputMatrices;
  if (A->rows != B->rows || A->columns != B->columns)
    return errorCode_invalidMatricesDimensions;
  return errorCode_noError;
}

int handleReturnValueInputMatricesMultiplyMatrices(matrix_t *A, matrix_t *B,
                                                   matrix_t *result) {
  if (!result || checkMatricesExistence(A, B))
    return errorCode_invalidInputMatrices;
  if (A->columns != B->rows) return errorCode_invalidMatricesDimensions;
  return errorCode_noError;
}

int handleReturnValueInputMatricesMultiplyMatrix(matrix_t *A,
                                                 matrix_t *result) {
  if (!A || !result || !A->matrix) return errorCode_invalidInputMatrices;
  return errorCode_noError;
}

int handleReturnValueInputMatricesCalcComplements(matrix_t *A,
                                                  matrix_t *result) {
  if (checkMatrixExistence(A) || !result) return errorCode_invalidInputMatrices;
  if (A->rows != A->columns) return errorCode_invalidMatricesDimensions;
  if (A->rows == 1) return errorCode_matrixIsFirstGrade;
  return errorCode_noError;
}

int handleReturnValueInputCreateMatrix(int rows, int columns,
                                       matrix_t *result) {
  if (rows <= 0 || columns <= 0 || !result)
    return returnValue_IncorrectMatrixError;
  return returnValue_Ok;
}

int handleReturnValueInputMatrixDeterminant(matrix_t *A) {
  if (checkMatrixExistence(A)) return errorCode_invalidInputMatrices;
  if (A->rows != A->columns) return errorCode_matrixIsNotSquare;
  return errorCode_noError;
}

int handleReturnValueInputMatrixInversion(matrix_t *A) {
  if (checkMatrixExistence(A)) return errorCode_invalidInputMatrices;
  return errorCode_noError;
}

int handleReturnValueInputComplementMatrix(matrix_t *A,
                                           matrix_t *complementsMatrix) {
  if (!A || !complementsMatrix) return errorCode_invalidInputMatrices;
  if (A->rows != A->columns) return errorCode_errorCalculatingComplementMatrix;
  return errorCode_noError;
}

int handleReturnValueInputMatrixMinor(matrix_t *A, int row, int column) {
  if (checkMatrixExistence(A) || row < 0 || column < 0 || row >= A->rows ||
      column >= A->columns || (A->rows - 1 <= 0))
    return errorCode_invalidInputMatrices;
  return errorCode_noError;
}

int handleReturnValueInputMatricesTranspose(matrix_t *A, matrix_t *result) {
  if (checkMatrixExistence(A) || !result) return errorCode_invalidInputMatrices;
  return errorCode_noError;
}

void calculateAndAssignSumAndSubValue(matrix_t *A, matrix_t *B,
                                      matrix_t *result, int rowIndex,
                                      int columnIndex,
                                      operationType operationType) {
  double value = 0;

  if (operationType == operationType_addition)
    value = A->matrix[rowIndex][columnIndex] + B->matrix[rowIndex][columnIndex];
  else if (operationType == operationType_subtraction)
    value = A->matrix[rowIndex][columnIndex] - B->matrix[rowIndex][columnIndex];

  (*result).matrix[rowIndex][columnIndex] = value;
}

void performSumAndSubOperations(matrix_t *A, matrix_t *B, matrix_t *result,
                                int errorCode, operationType operationType) {
  int rows = A->rows;
  int columns = A->columns;

  for (int rowIndex = 0; rowIndex < rows && !errorCode; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      calculateAndAssignSumAndSubValue(A, B, result, rowIndex, columnIndex,
                                       operationType);
    }
  }
}

int arithmeticShellForSumAndSub(matrix_t *A, matrix_t *B, matrix_t *result,
                                operationType operationType) {
  int errorCode = handleReturnValueInputMatricesSumAndSub(A, B, result);
  if (errorCode & errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;
  if (errorCode & errorCode_invalidMatricesDimensions)
    return returnValue_CalculationError;

  int rows = A->rows;
  int columns = A->columns;

  int createResult = s21_create_matrix(rows, columns, result);
  if (createResult) errorCode = errorCode_errorCreatingResultMatrix;
  performSumAndSubOperations(A, B, result, errorCode, operationType);

  int returnValue = returnValue_Ok;
  if (errorCode) returnValue = returnValue_IncorrectMatrixError;
  return returnValue;
}

void copyMatrixItself(double **destination, const double **source, int rows,
                      int columns) {
  for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columns; ++columnIndex) {
      destination[rowIndex][columnIndex] = source[rowIndex][columnIndex];
    }
  }

}

double getComplementSign(int i, int j) {
  return ((i + j) % 2 == 1) ? -1.0 : 1.0;
}

void swapRows(double **matrix, int rowIndex1, int rowIndex2, int size) {
  if (rowIndex1 == rowIndex2 || rowIndex1 < 0 || rowIndex2 < 0 ||
      rowIndex1 >= size || rowIndex2 >= size)
    return;
  for (int columnIndex = 0; columnIndex < size; columnIndex++) {
    double tempValue = matrix[rowIndex1][columnIndex];
    matrix[rowIndex1][columnIndex] = matrix[rowIndex2][columnIndex];
    matrix[rowIndex2][columnIndex] = tempValue;
  }
}

void swapColumns(double **matrix, int columnIndex1, int columnIndex2,
                 int size) {
  if (columnIndex1 == columnIndex2 || columnIndex1 < 0 || columnIndex2 < 0 ||
      columnIndex1 >= size || columnIndex2 >= size)
    return;

  for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
    double tempValue = matrix[rowIndex][columnIndex1];
    matrix[rowIndex][columnIndex1] = matrix[rowIndex][columnIndex2];
    matrix[rowIndex][columnIndex2] = tempValue;
  }
}