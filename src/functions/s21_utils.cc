#include <cmath>

#include "../constants.h"
#include "../s21_matrix_oop.h"

namespace s21 {

[[nodiscard]] bool S21Matrix::IsFirstOrderMatrix() const {
  return (rows_ == 1 && cols_ == 1);
}

[[nodiscard]] bool S21Matrix::IsZero(const double value) {
  bool result = false;
  if (std::fabs(value) < constants::kPrecision) {
    result = true;
  }
  return result;
}
}  // namespace s21