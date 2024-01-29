#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::PrintMatrix() const {
  CheckEmptyMatrix(*this);
  for (int i = 0; i <= rows_ - 1; ++i) {
    std::cout << matrix_[i][0];
    for (int j = 1; j <= cols_ - 1; ++j) {
      std::cout << " " << matrix_[i][j];
    }
    std::cout << std::endl;
  }
}
}  // namespace s21