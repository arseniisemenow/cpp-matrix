#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::CopyMatrixData(const S21Matrix &other) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other(i, j);
    }
  }
}
}  // namespace s21