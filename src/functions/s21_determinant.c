#include "../develop/s21_develop.h"
#include "../headers/s21_common.h"

void partialPivotingInGaussElimination(matrix_t *matrix, int pivotIndex,
                                       int *pSwapCount) {
  int size = matrix->rows;
  double **matrixItself = matrix->matrix;
  for (int rowIndex = pivotIndex + 1; rowIndex < size; rowIndex++) {
    if (fabs(matrixItself[pivotIndex][pivotIndex]) <
        fabs(matrixItself[rowIndex][pivotIndex])) {
      (*pSwapCount)++;
      swapRows(matrixItself, pivotIndex, rowIndex, size);
    }
  }
}
void performGaussElimination(matrix_t *matrix, int pivotIndex) {
  int size = matrix->rows;
  double **matrixItself = matrix->matrix;

  for (int rowIndex = pivotIndex + 1; rowIndex < size; rowIndex++) {
    double term = matrixItself[rowIndex][pivotIndex] /
                  matrixItself[pivotIndex][pivotIndex];
    for (int columnIndex = 0; columnIndex < size; columnIndex++) {
      matrixItself[rowIndex][columnIndex] -=
          term * matrixItself[pivotIndex][columnIndex];
    }
  }
}

int gaussElimination(matrix_t *matrix) {
  int size = matrix->rows;
  int swapCount = 0;
  for (int pivotIndex = 0; pivotIndex < size - 1; pivotIndex++) {
    partialPivotingInGaussElimination(matrix, pivotIndex, &swapCount);
    performGaussElimination(matrix, pivotIndex);
  }
  return swapCount;
}

void initResult(double *result) { *result = 0; }

double getSign(int swapCount) { return swapCount % 2 == 1 ? -1.0 : 1.0; }

int s21_determinant(matrix_t *A, double *result) {
  initResult(result);
  int errorCode = handleReturnValueInputMatrixDeterminant(A);
  if (errorCode == errorCode_invalidInputMatrices)
    return returnValue_IncorrectMatrixError;
  if (errorCode == errorCode_matrixIsNotSquare)
    return returnValue_CalculationError;

  int size = A->rows;

  matrix_t tempMatrix = {0};
  s21_create_matrix(size, size, &tempMatrix);
  double **tempMatrixItself = tempMatrix.matrix;

  copyMatrixItself(tempMatrixItself, (const double **)A->matrix, size, size);

  int swapCount = gaussElimination(&tempMatrix);

  double tempResult = 1;

  for (int pivotIndex = 0; pivotIndex < size; pivotIndex++) {
    tempResult *= tempMatrixItself[pivotIndex][pivotIndex];
  }

  double sign = getSign(swapCount);

  if (!isnan(tempResult)) *result = sign * tempResult;

  s21_remove_matrix(&tempMatrix);

  int returnValue = returnValue_Ok;
  if (errorCode & errorCode_errorCreatingResultMatrix)
    returnValue = returnValue_IncorrectMatrixError;
  return returnValue;
}
