#include <cmath>

#include "../constants.h"
#include "../s21_matrix_oop.h"

namespace s21 {
bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  return PerformComparison(other);
}

bool S21Matrix::PerformComparison(const S21Matrix &other) const {
  bool comparison_status = true;

  for (int i = 0; i < rows_ && comparison_status; ++i) {
    for (int j = 0; j < cols_ && comparison_status; ++j) {
      double diff = std::fabs(matrix_[i][j] - other.matrix_[i][j]);
      if (diff > constants::kPrecision) {
        comparison_status = false;
      }
    }
  }
  return comparison_status;
}
}  // namespace s21