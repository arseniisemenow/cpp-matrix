#include "../headers/s21_common.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return arithmeticShellForSumAndSub(A, B, result, operationType_addition);
}