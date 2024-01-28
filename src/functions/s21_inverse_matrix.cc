#include "../s21_matrix_oop.h"

namespace s21 {
    S21Matrix S21Matrix::CalculateInverseMatrix(S21Matrix &transposedComplementMatrix, double det) const {
        //TODO handle errors
        S21Matrix result(rows_, cols_);

        for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
            for (int columnIndex = 0; columnIndex < cols_; ++columnIndex) {
                result.matrix_[rowIndex][columnIndex] =
                        (1.0 / det) * transposedComplementMatrix.matrix_[rowIndex][columnIndex];
            }
        }

        return result;
    }

    S21Matrix S21Matrix::InverseMatrix() {
        CheckEmptyMatrix(*this);
        CheckSquareMatrix(*this);
        if (rows_ == cols_ == 1) {
            return GetInverseOfFirstOrderMatrix();
        }

        double det = Determinant();

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
}