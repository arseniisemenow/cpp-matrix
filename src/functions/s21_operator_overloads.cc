#include <iostream>

#include "../s21_matrix_oop.h"

namespace s21 {
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }

  DestroyMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  AllocateMemoryForMatrix();
  CopyMatrixData(other);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  DestroyMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix temp = *this;
  temp.SumMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix temp = *this;
  temp.SubMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix temp = *this;
  temp.MulMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator*(const double number) const {
  S21Matrix temp = *this;
  temp.MulNumber(number);
  return temp;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return *this;
}

[[nodiscard]] double S21Matrix::operator()(int i, int j) const {
  CheckRowAndColsFlows(i, j);
  return matrix_[i][j];
}

double &S21Matrix::operator()(int i, int j) {
  CheckRowAndColsFlows(i, j);
  return matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

std::ostream &operator<<(std::ostream &stream, const S21Matrix &matrix) {
  for (int i = 0; i < matrix.rows_; ++i) {
    stream << matrix(i, 0);
    for (int j = 1; j < matrix.cols_; ++j) {
      stream << " " << matrix(i, j);
    }
    stream << '\n';
  }
  return stream;
}

S21Matrix operator*(const double number, const S21Matrix &matrix) {
  return matrix * number;
}

}  // namespace s21