#include "../headers/s21_common.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return arithmeticShellForSumAndSub(A, B, result, operationType_subtraction);
}