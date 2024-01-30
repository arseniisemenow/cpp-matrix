#include "../s21_matrix_oop.h"

namespace s21 {
S21Matrix S21Matrix::Transpose() const {
  S21Matrix transpose_result(cols_, rows_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      transpose_result(j, i) = matrix_[i][j];
    }
  }
  return transpose_result;
}
}  // namespace s21