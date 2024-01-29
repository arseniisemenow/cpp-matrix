#include "../s21_matrix_oop.h"

namespace s21 {
double S21Matrix::Determinant() const {
  CheckEmptyMatrix(*this);
  CheckSquareMatrix();

  S21Matrix temp = *this;
  double result = 0;

  int swapCount = GaussElimination(temp);

  double tempResult = 1;

  for (int pivotIndex = 0; pivotIndex < rows_; pivotIndex++) {
    tempResult *= temp.matrix_[pivotIndex][pivotIndex];
  }

  double sign = GetSignBySwapCount(swapCount);

  if (!std::isnan(tempResult)) {
    result = sign * tempResult;
  }
  if (IsZero(tempResult)) {
    result = 0;
  }

  return result;
}

void S21Matrix::partialPivotingInGaussElimination(S21Matrix &temp,
                                                  int pivotIndex,
                                                  int *pSwapCount) const {
  for (int rowIndex = pivotIndex + 1; rowIndex < temp.rows_; rowIndex++) {
    if (std::fabs(temp.matrix_[pivotIndex][pivotIndex]) <
        std::fabs(temp.matrix_[rowIndex][pivotIndex])) {
      (*pSwapCount)++;
      SwapRows(temp, pivotIndex, rowIndex);
    }
  }
}

void S21Matrix::PerformGaussElimination(S21Matrix &temp, int pivotIndex) const {
  for (int rowIndex = pivotIndex + 1; rowIndex < rows_; rowIndex++) {
    double term = temp.matrix_[rowIndex][pivotIndex] /
                  temp.matrix_[pivotIndex][pivotIndex];
    for (int colIndex = 0; colIndex < rows_; colIndex++) {
      temp.matrix_[rowIndex][colIndex] -=
          term * temp.matrix_[pivotIndex][colIndex];
    }
  }
}

int S21Matrix::GaussElimination(S21Matrix &temp) const {
  int swapCount = 0;
  for (int pivotIndex = 0; pivotIndex < temp.rows_ - 1; pivotIndex++) {
    partialPivotingInGaussElimination(temp, pivotIndex, &swapCount);
    PerformGaussElimination(temp, pivotIndex);
  }
  return swapCount;
}

void S21Matrix::SwapRows(S21Matrix &temp, int rowIndex1, int rowIndex2) const {
  if (rowIndex1 == rowIndex2 || rowIndex1 < 0 || rowIndex2 < 0 ||
      rowIndex1 >= temp.rows_ || rowIndex2 >= temp.rows_) {
    throw std::invalid_argument("Swap rows is not possible");
  }
  for (int columnIndex = 0; columnIndex < temp.rows_; columnIndex++) {
    double tempValue = temp.matrix_[rowIndex1][columnIndex];
    temp.matrix_[rowIndex1][columnIndex] = temp.matrix_[rowIndex2][columnIndex];
    temp.matrix_[rowIndex2][columnIndex] = tempValue;
  }
}

double S21Matrix::GetSignBySwapCount(int swapCount) const {
  return swapCount % 2 == 1 ? -1.0 : 1.0;
}
}  // namespace s21