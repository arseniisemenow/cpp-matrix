#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::MulMatrix(const S21Matrix &other) {
  CheckMultiplicationMatrices(other);
  PerformMatricesMulOperation(other);
}

void S21Matrix::PerformMatricesMulOperation(const S21Matrix &other) {
  S21Matrix temp = S21Matrix(rows_, other.cols_);

  for (int row_index = 0; row_index < rows_; ++row_index) {
    for (int other_col_index = 0; other_col_index < other.cols_;
         ++other_col_index) {
      temp.matrix_[row_index][other_col_index] = 0;
      for (int col_index = 0; col_index < cols_; ++col_index) {
        double first_number = matrix_[row_index][col_index];
        double second_number = other.matrix_[col_index][other_col_index];

        temp.matrix_[row_index][other_col_index] +=
            first_number * second_number;
      }
    }
  }
  *this = temp;
}
}  // namespace s21