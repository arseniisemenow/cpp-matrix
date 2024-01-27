#include "../s21_matrix_oop.h"


void S21Matrix::ArithmeticShellForSumAndSub(const S21Matrix& other, OperationType operationType) {
    PerformSumAndSubOperations(other, operationType);
}

void S21Matrix::PerformSumAndSubOperations(const S21Matrix& other, OperationType operationType) {
    for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
        for (int colIndex = 0; colIndex < cols_; ++colIndex) {
            CalculateAndAssignSumAndSubValue(other, rowIndex, colIndex,
                                             operationType);
        }
    }
}

void S21Matrix::CalculateAndAssignSumAndSubValue(const S21Matrix& other, int rowIndex,
                                                 int colIndex, OperationType operationType) {
    double value = 0;

    if (operationType == OperationType::kAddition) {
        value = matrix_[rowIndex][colIndex] + other.matrix_[rowIndex][colIndex];
    } else if (operationType == OperationType::kSubtraction) {
        value = matrix_[rowIndex][colIndex] - other.matrix_[rowIndex][colIndex];
    }

    matrix_[rowIndex][colIndex] = value;
}
