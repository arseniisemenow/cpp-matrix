#include "../s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::CalculateInverseMatrix(const S21Matrix &matrix,
                                            double det) const {
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      double inverse_term = 1.0 / det;
      double number = matrix.matrix_[i][j];
      result.matrix_[i][j] = inverse_term * number;
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  CheckEmptyMatrix(*this);
  CheckSquareMatrix();
  if (IsFirstOrderMatrix()) {
    return GetInverseOfFirstOrderMatrix();
  }

  double det = Determinant();
  CheckSingularMatrix(det);

  S21Matrix complement_matrix = CalcComplements();
  S21Matrix transposed_complement_matrix = complement_matrix.Transpose();

  S21Matrix result = CalculateInverseMatrix(transposed_complement_matrix, det);

  return result;
}

S21Matrix S21Matrix::GetInverseOfFirstOrderMatrix() {
  S21Matrix result(1, 1);
  result.matrix_[0][0] = 1 / matrix_[0][0];
  return result;
}
}  // namespace s21