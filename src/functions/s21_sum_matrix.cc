#include "../s21_matrix_oop.h"

namespace s21{
void S21Matrix::SumMatrix(const S21Matrix &other) {
    ArithmeticShellForSumAndSub(other, OperationType::kAddition);
}}