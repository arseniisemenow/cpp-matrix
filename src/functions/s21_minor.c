#include "../develop/s21_develop.h"
#include "../headers/s21_common.h"

void fillMinorMatrix(double **minorMatrix, double **originalMatrix, int skipRow,
                     int skipColumn, int minorSize) {
  int rowIndexMinor, columnIndexMinor, rowIndexOrig, columnIndexOrig;

  for (rowIndexMinor = 0, rowIndexOrig = 0; rowIndexMinor < minorSize;
       ++rowIndexMinor, ++rowIndexOrig) {
    if (rowIndexOrig == skipRow) rowIndexOrig++;
    for (columnIndexMinor = 0, columnIndexOrig = 0;
         columnIndexMinor < minorSize; ++columnIndexMinor, ++columnIndexOrig) {
      if (columnIndexOrig == skipColumn) columnIndexOrig++;
      minorMatrix[rowIndexMinor][columnIndexMinor] =
          originalMatrix[rowIndexOrig][columnIndexOrig];
    }
  }
}

int s21_minor(matrix_t *A, int row, int column, double *result) {
  int errorCode = handleReturnValueInputMatrixMinor(A, row, column);
  if (errorCode) return returnValue_IncorrectMatrixError;

  int returnValue = returnValue_Ok;
  int size = A->rows;
  int minorSize = size - 1;
  matrix_t minorMatrixShell = {0};

  int createResult = s21_create_matrix(minorSize, minorSize, &minorMatrixShell);
  if (createResult)
    errorCode = errorCode_errorCreatingResultMatrix;
  else {
    double **minorMatrix = minorMatrixShell.matrix;
    double **originalMatrix = A->matrix;

    fillMinorMatrix(minorMatrix, originalMatrix, row, column, minorSize);
    returnValue = s21_determinant(&minorMatrixShell, result);
    s21_remove_matrix(&minorMatrixShell);
  }

  if (errorCode & errorCode_errorCreatingResultMatrix)
    returnValue = returnValue_IncorrectMatrixError;

  return returnValue;
}