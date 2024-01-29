#include "../s21_matrix_oop.h"

namespace s21 {
S21Matrix S21Matrix::CalculateInverseMatrix(
    const S21Matrix &transposedComplementMatrix, double det) const {
  S21Matrix result(rows_, cols_);

  for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < cols_; ++columnIndex) {
      result.matrix_[rowIndex][columnIndex] =
          (1.0 / det) *
          transposedComplementMatrix.matrix_[rowIndex][columnIndex];
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