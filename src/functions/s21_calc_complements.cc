#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() const {
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

//int s21_calc_complements(matrix_t *A, matrix_t *result) {
//    int errorCode = handleReturnValueInputMatricesCalcComplements(A, result);
//    if (errorCode == errorCode_invalidInputMatrices)
//        return returnValue_IncorrectMatrixError;
//    if (errorCode == errorCode_invalidMatricesDimensions)
//        return returnValue_CalculationError;
//    if (errorCode == errorCode_matrixIsFirstGrade) return handle1x1Matrix(result);
//
//    int size = A->rows;
//
//    int returnValue = s21_create_matrix(size, size, result);
//
//    double **complementsMatrix = result->matrix;
//
//    for (int rowIndex = 0; rowIndex < size && !returnValue; ++rowIndex) {
//        int errorCodeMinor = errorCode_noError;
//        for (int columnIndex = 0; columnIndex < size && !errorCodeMinor;
//             ++columnIndex) {
//            double minorResult = 0.0;
//            errorCodeMinor = s21_minor(A, rowIndex, columnIndex, &minorResult);
//            double sign = getComplementSign(rowIndex, columnIndex);
//            complementsMatrix[rowIndex][columnIndex] = sign * minorResult;
//        }
//    }
//
//    return returnValue;
//}


double S21Matrix::GetComplementSign(int i, int j) {
    return ((i + j) % 2 == 1) ? -1.0 : 1.0;
}