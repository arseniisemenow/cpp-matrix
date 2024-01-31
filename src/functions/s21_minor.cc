#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::FillMinorMatrix(S21Matrix &minor_matrix, int skip_row,
                                int skip_col) const {
  int row_index_minor = 0;
  int row_index_orig = 0;
  for (; row_index_minor < minor_matrix.rows_;) {
    if (row_index_orig == skip_row) {
      ++row_index_orig;
    }
    int col_index_minor = 0;
    int col_index_orig = 0;
    for (; col_index_minor < minor_matrix.rows_;) {
      if (col_index_orig == skip_col) {
        ++col_index_orig;
      }
      minor_matrix(row_index_minor, col_index_minor) =
          matrix_[row_index_orig][col_index_orig];
      ++col_index_minor;
      ++col_index_orig;
    }
    ++row_index_minor;
    ++row_index_orig;
  }
}

double S21Matrix::Minor(int row, int column) const {
  CheckEmptyMatrix(*this);
  CheckSquareMatrix();
  if (IsFirstOrderMatrix()) {
    return Determinant();
  }

  S21Matrix temp = S21Matrix(rows_ - 1, cols_ - 1);

  FillMinorMatrix(temp, row, column);
  double result = temp.Determinant();

  return result;
}
}  // namespace s21