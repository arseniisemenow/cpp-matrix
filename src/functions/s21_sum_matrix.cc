#include "../headers/s21_common.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
    ArithmeticShellForSumAndSub(other, OperationType::kAddition);
}