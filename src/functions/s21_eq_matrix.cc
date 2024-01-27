#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix&other) const  {
    return PerformComparison(other);
}

bool S21Matrix::PerformComparison(const S21Matrix& other) const {
    bool comparisonStatus = true;

    for (int rowIndex = 0; rowIndex < rows_ && comparisonStatus;
         ++rowIndex) {
        for (int columnIndex = 0;
             columnIndex < cols_ && comparisonStatus; ++columnIndex) {
            double diff = fabs(matrix_[rowIndex][columnIndex] -
                               other.matrix_[rowIndex][columnIndex]);
            if (std::fabs(diff) > S21_EPSILON) {
                comparisonStatus = false;
            }
        }
    }
    return comparisonStatus;
}