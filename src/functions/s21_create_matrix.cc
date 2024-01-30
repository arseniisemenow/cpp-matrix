#include "../s21_matrix_oop.h"

namespace s21 {

S21Matrix::S21Matrix() = default;

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  CheckRowAndColsForConstructor(rows_, cols_);
  AllocateMemoryForMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMemoryForMatrix();
  CopyMatrixData(other);
}

void S21Matrix::AllocateMemoryForMatrix() {
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}
}  // namespace s21
