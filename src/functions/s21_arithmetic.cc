#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::PerformSumAndSubOperations(const S21Matrix &other,
                                           OperationType operation_type) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      CalculateAndAssignSumAndSubValue(other, i, j, operation_type);
    }
  }
}

void S21Matrix::CalculateAndAssignSumAndSubValue(const S21Matrix &other,
                                                 int row_index, int col_index,
                                                 OperationType operation_type) {
  double value = 0;

  if (operation_type == OperationType::kAddition) {
    value = matrix_[row_index][col_index] + other.matrix_[row_index][col_index];
  } else if (operation_type == OperationType::kSubtraction) {
    value = matrix_[row_index][col_index] - other.matrix_[row_index][col_index];
  }

  matrix_[row_index][col_index] = value;
}

}  // namespace s21