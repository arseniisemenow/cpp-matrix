#ifndef S21_MATRIX_STRUCTS_H_
#define S21_MATRIX_STRUCTS_H_

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  errorCode_noError = 0,
  errorCode_invalidInputMatrices = 1 << 1,
  errorCode_invalidMatricesDimensions = 1 << 2,
  errorCode_errorCreatingResultMatrix = 1 << 3,
  errorCode_matrixIsNotSquare = 1 << 4,
  errorCode_matrixIsSingular = 1 << 5,
  errorCode_errorCalculatingDeterminant = 1 << 6,
  errorCode_errorCalculatingComplementMatrix = 1 << 7,
  errorCode_errorTransposing = 1 << 8,
  errorCode_matrixIsFirstGrade = 1 << 9,
  errorCode_errorCalculatingMinorMatrix = 1 << 10,
  errorCode_errorCalculatingInverse = 1 << 11,
} errorCode;

typedef enum {
  returnValue_Ok = 0,
  returnValue_IncorrectMatrixError = 1,
  returnValue_CalculationError = 2,
} returnValue;

typedef enum {
  operationType_addition = 0,
  operationType_subtraction = 1,
} operationType;

#endif