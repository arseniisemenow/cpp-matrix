#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include "headers/s21_structs.h"
#include <iostream>
#include <cmath>


//TODO move all constant away!
#define SUCCESS 1
#define FAILURE 0
#define S21_EPSILON 1e-6

class S21Matrix {
public:
    S21Matrix();

    S21Matrix(int rows, int cols);  // TODO should I use explicit here?
    S21Matrix(const S21Matrix &other);

    S21Matrix(S21Matrix &&other) noexcept;

    ~S21Matrix();

    void SetRows(int number);

    void SetCols(int number);

    void SetElementInMatrix(int number, int rowIndex, int colIndex);

    [[nodiscard]] int GetRows() const noexcept;

    [[nodiscard]] int GetCols() const noexcept;

    [[nodiscard]] double GetElementInMatrix(int rowIndex, int colIndex) const noexcept;

    void SumMatrix(const S21Matrix &other);

    void SubMatrix(const S21Matrix &other);

    [[nodiscard]] bool EqMatrix(const S21Matrix &other) const;
    void MulNumber(const double number);
    void MulMatrix(const S21Matrix& other);

    [[nodiscard]] double Determinant() const;

    S21Matrix Transpose() const;

    S21Matrix CalcComplements() const;

    S21Matrix InverseMatrix();

    S21Matrix &operator=(const S21Matrix &other);

    S21Matrix &operator+(const S21Matrix &other);

    S21Matrix &operator-(const S21Matrix &other);

    S21Matrix operator*(const S21Matrix &other);
    bool operator==(const S21Matrix &other) const;
    S21Matrix &operator+=(const S21Matrix &other);

    S21Matrix &operator-=(const S21Matrix &other);

    S21Matrix &operator*=(const S21Matrix &other);

    S21Matrix &operator+=(const double number);

    double operator()(int i, int j) const;  // WHAT is this for?
    double &operator()(int i, int j);       // WHAT is this for?

    void PrintMatrix();  // TODO const noexcept?

private:
    int rows_{};
    int cols_{};
    double **matrix_{};

    enum class OperationType{
        kNone = 0,
        kAddition = 1 << 0,
        kSubtraction = 2 << 0,
    };


    void AllocateMemoryForMatrix();

    void CopyMatrixData(const S21Matrix &other) noexcept;

    void DestroyMatrix();

    void ResizeMatrix(int newRows, int newCols);

    void PerformSumAndSubOperations(const S21Matrix &other, OperationType operationType);

    void ArithmeticShellForSumAndSub(const S21Matrix &other, OperationType operationType);

    void CalculateAndAssignSumAndSubValue(const S21Matrix& other, int rowIndex,
                                                     int colIndex, OperationType operationType);

    void PerformMatrixMulOperation(const double number);
    [[nodiscard]]bool PerformComparison(const S21Matrix& other) const;

    void PerformMatricesMulOperation(const S21Matrix& other);

    int GaussElimination(S21Matrix & temp) const;

    void PerformGaussElimination(S21Matrix&temp, int pivotIndex) const;

    void partialPivotingInGaussElimination(S21Matrix& temp, int pivotIndex, int *pSwapCount) const;

    [[nodiscard]] double GetSignBySwapCount(int swapCount) const;

    void SwapRows(double **matrix, int rowIndex1, int rowIndex2, int size) const;

    void FillMinorMatrix(double **minorMatrix, double **originalMatrix, int skipRow, int skipColumn, int minorSize) const;

    double Minor(int row, int column) const;

    double GetComplementSign(int i, int j) const;

    S21Matrix HandleFirstGradeMatrix() const;

    double GetComplementSign(int i, int j);

    S21Matrix CalculateInverseMatrix(S21Matrix &transposedComplementMatrix, double det) const;
};

#endif // S21_MATRIX_OOP_H_