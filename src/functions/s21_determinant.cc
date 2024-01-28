#include "../s21_matrix_oop.h"

namespace s21 {
    double S21Matrix::Determinant() const {
        CheckEmptyMatrix(*this);
        CheckSquareMatrix(*this);

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

        return result;
    }

    void S21Matrix::partialPivotingInGaussElimination(S21Matrix &temp, int pivotIndex,
                                                      int *pSwapCount) const {
        for (int rowIndex = pivotIndex + 1; rowIndex < temp.rows_; rowIndex++) {
            if (std::fabs(temp.matrix_[pivotIndex][pivotIndex]) <
                std::fabs(temp.matrix_[rowIndex][pivotIndex])) {
                (*pSwapCount)++;
                SwapRows(temp.matrix_, pivotIndex, rowIndex, temp.rows_);
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


    void S21Matrix::SwapRows(double **matrix, int rowIndex1, int rowIndex2, int size) const {
        if (rowIndex1 == rowIndex2 || rowIndex1 < 0 || rowIndex2 < 0 ||
            rowIndex1 >= size || rowIndex2 >= size) {
            throw std::invalid_argument("Swap rows is not possible");
        }
        for (int columnIndex = 0; columnIndex < size; columnIndex++) {
            double tempValue = matrix[rowIndex1][columnIndex];
            matrix[rowIndex1][columnIndex] = matrix[rowIndex2][columnIndex];
            matrix[rowIndex2][columnIndex] = tempValue;
        }
    }

    double S21Matrix::GetSignBySwapCount(int swapCount) const { return swapCount % 2 == 1 ? -1.0 : 1.0; }
}