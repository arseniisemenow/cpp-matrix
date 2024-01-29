#include "../s21_matrix_oop.h"

namespace s21 {
    S21Matrix S21Matrix::CalcComplements() const {
        CheckSquareMatrix();
        CheckEmptyMatrix(*this);

        if (IsFirstOrderMatrix()) {
            return HandleFirstOrderMatrixCalcComplements();
        }
        S21Matrix temp = *this;
        S21Matrix result(rows_, cols_);

        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                double minor_result = temp.Minor(i, j);
                double sign = GetComplementSign(i, j);
                result.matrix_[i][j] = sign * minor_result;
            }
        }

        return result;
    }

    S21Matrix S21Matrix::HandleFirstOrderMatrixCalcComplements() {
        S21Matrix result(1, 1);
        result.matrix_[0][0] = 1;
        return result;
    }

    double S21Matrix::GetComplementSign(int i, int j) {
        double result = 1.0;
        bool is_odd_number = (i + j) % 2 == 1;
        if (is_odd_number) {
            result = -1.0;
        }
        return result;
    }
}  // namespace s21