#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::MulNumber(const double number) {
  CheckEmptyMatrix(*this);
  PerformMatrixMulOperation(number);
}

void S21Matrix::PerformMatrixMulOperation(const double number) {
  for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
    for (int colIndex = 0; colIndex < cols_; ++colIndex) {
      matrix_[rowIndex][colIndex] *= number;
    }
  }
}
}  // namespace s21