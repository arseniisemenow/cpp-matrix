#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::CheckEmptyMatrix(const S21Matrix &other) {
  if (other.cols_ <= 0 || other.rows_ <= 0 || other.matrix_ == nullptr) {
    throw std::invalid_argument("Matrix is empty");
  }
}

void S21Matrix::CheckSquareMatrix() const {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix is not square");
  }
}

void S21Matrix::CheckMultiplicationMatrices(const S21Matrix &other) const {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Matrix multiplication is not possible, "
        "numbers of rows in first matrix is not the same as "
        "number of second matrix");
  }
}

void S21Matrix::CheckMatricesSizeIdentity(const S21Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Matrices are not identical for the operation");
  }
}

void S21Matrix::CheckRowsAndColsOverflow(int row_index, int col_index) const {
  if (row_index >= rows_ || col_index >= cols_) {
    throw std::out_of_range("The number of rows or columns is overflowed");
  }
}

void S21Matrix::CheckRowsAndColsUnderflow(int row_index, int col_index) const {
  if (row_index < 0 || col_index < 0) {
    throw std::out_of_range("The number of rows or columns is underflowed");
  }
}

void S21Matrix::CheckRowAndColsFlows(int row_index, int col_index) const {
  CheckRowsAndColsUnderflow(row_index, col_index);
  CheckRowsAndColsOverflow(row_index, col_index);
}

void S21Matrix::CheckRowAndColsForConstructor(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument(
        "The number of rows or columns can't be less, then 1");
  }
}

void S21Matrix::CheckSingularMatrix(double det) {
  if (det == 0) {
    throw std::runtime_error("Matrix is singular");
  }
}
}  // namespace s21
