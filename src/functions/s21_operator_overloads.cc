#include "../s21_matrix_oop.h"

namespace s21 {
    S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
        if (*this == other) {
            return *this;
        }
        DestroyMatrix();
        rows_ = other.rows_;
        cols_ = other.cols_;
        AllocateMemoryForMatrix();
        CopyMatrixData(other);
        return *this;
    }


    bool S21Matrix::operator==(const S21Matrix &other) const {
        return EqMatrix(other);
    }


    S21Matrix &S21Matrix::operator+(const S21Matrix &other) {
        S21Matrix temp = *this;
        temp.SumMatrix(other);
        return temp;
    }

    S21Matrix &S21Matrix::operator-(const S21Matrix &other) {
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

    double S21Matrix::operator()(int i, int j) const {
        if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
            throw std::invalid_argument("Invalid row or column index");
        }
        return matrix_[i][j];
    }

    double &S21Matrix::operator()(int i, int j) {
        if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
            throw std::invalid_argument("Invalid row or column index");
        }
        return matrix_[i][j];
    }


}