#include "../s21_matrix_oop.h"

namespace s21{
S21Matrix S21Matrix::CalcComplements() const {
    //TODO handle errors
    if (rows_ == cols_ == 1){
        return HandleFirstGradeMatrix();
    }
    S21Matrix temp = *this;
    S21Matrix result(rows_, cols_);

    for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < rows_; ++columnIndex) {
            double minorResult = 0.0;
            temp.Minor(rowIndex, columnIndex);
            double sign = GetComplementSign(rowIndex, columnIndex);
            result.matrix_[rowIndex][columnIndex] = sign * minorResult;
        }
    }

    return result;
}

S21Matrix S21Matrix::HandleFirstGradeMatrix() const {
    S21Matrix result(1, 1);
    result.matrix_[0][0] = 1;
    return result;
}
double S21Matrix::GetComplementSign(int i, int j )const {
    return ((i + j) % 2 == 1) ? -1.0 : 1.0;
}}