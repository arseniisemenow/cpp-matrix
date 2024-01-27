#include "../headers/s21_common.h"

void S21Matrix::SubMatrix(const S21Matrix &other) {
    ArithmeticShellForSumAndSub(other, OperationType::kSubtraction);
}