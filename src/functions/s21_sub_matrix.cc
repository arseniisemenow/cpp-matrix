#include "../s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix &other) {
    ArithmeticShellForSumAndSub(other, OperationType::kSubtraction);
}