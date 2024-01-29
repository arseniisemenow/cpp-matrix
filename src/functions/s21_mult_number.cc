#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::MulNumber(const double number) {
  CheckEmptyMatrix(*this);
  PerformMatrixMulOperation(number);
}

void S21Matrix::PerformMatrixMulOperation(const double number) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= number;
    }
  }
}
}  // namespace s21