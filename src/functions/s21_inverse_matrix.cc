#include "../s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::CalculateInverseMatrix(const S21Matrix &matrix,
                                            double det) const {
  S21Matrix result(rows_, cols_);

  for (int row_index = 0; row_index < rows_; ++row_index) {
    for (int col_index = 0; col_index < cols_; ++col_index) {
      result.matrix_[row_index][col_index] =
          (1.0 / det) * matrix.matrix_[row_index][col_index];
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
  //        if (rows_ == cols_ == 1) { //TODO handle this
  //            return GetInverseOfFirstOrderMatrix();
  //        }

  double det = Determinant();
  CheckSingularMatrix(det);

  S21Matrix complementMatrix = CalcComplements();
  S21Matrix transposedComplementMatrix = complementMatrix.Transpose();

  S21Matrix result = CalculateInverseMatrix(transposedComplementMatrix, det);

  return result;
}

S21Matrix S21Matrix::GetInverseOfFirstOrderMatrix() {
  S21Matrix result(1, 1);
  result.matrix_[0][0] = 1 / matrix_[0][0];
  return result;
}
}  // namespace s21