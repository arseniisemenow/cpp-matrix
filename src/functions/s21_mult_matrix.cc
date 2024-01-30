#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::MulMatrix(const S21Matrix &other) {
  CheckMultiplicationMatrices(other);
  PerformMatricesMulOperation(other);
}

void S21Matrix::PerformMatricesMulOperation(const S21Matrix &other) {
  S21Matrix temp = S21Matrix(rows_, other.cols_);
  int row_index = 0;
  for (; row_index < rows_;) {
    int other_col_index = 0;
    for (; other_col_index < other.cols_;) {
      temp(row_index, other_col_index) = 0;
      int col_index = 0;
      for (; col_index < cols_;) {
        double first_number = matrix_[row_index][col_index];
        double second_number = other(col_index, other_col_index);
        double result_number = first_number * second_number;

        temp(row_index, other_col_index) += result_number;
        ++col_index;
      }
      ++other_col_index;
    }
    ++row_index;
  }
  *this = temp;
  std::cerr << "matrix: " << temp;
}
}  // namespace s21