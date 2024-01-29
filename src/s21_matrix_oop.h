#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <iostream>
#include <cmath>
#include <utility>


//TODO move all constant away!
#define S21_EPSILON 1e-6
namespace s21{
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

        [[nodiscard]] S21Matrix Transpose() const;

        [[nodiscard]] S21Matrix CalcComplements() const;

        S21Matrix InverseMatrix();

        S21Matrix &operator=(const S21Matrix &other);
        S21Matrix &operator=(S21Matrix && other) noexcept;


        S21Matrix operator+(const S21Matrix &other);

        S21Matrix operator-(const S21Matrix &other);

        [[nodiscard]]S21Matrix operator*(const S21Matrix &other);
        [[nodiscard]]S21Matrix operator*(const double number) const;

        [[nodiscard]]bool operator==(const S21Matrix &other) const;
        S21Matrix &operator+=(const S21Matrix &other);

        S21Matrix &operator-=(const S21Matrix &other);

        S21Matrix &operator*=(const S21Matrix &other);
        S21Matrix &operator*=(const double number);

        [[nodiscard]]double operator()(int i, int j) const;
        double &operator()(int i, int j);

        void PrintMatrix() const;

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

        void CalculateAndAssignSumAndSubValue(const S21Matrix& other, int rowIndex,
                                              int colIndex, OperationType operationType);

        void PerformMatrixMulOperation(const double number);
        [[nodiscard]]bool PerformComparison(const S21Matrix& other) const;

        void PerformMatricesMulOperation(const S21Matrix& other);

        int GaussElimination(S21Matrix & temp) const;

        void PerformGaussElimination(S21Matrix&temp, int pivotIndex) const;

        void partialPivotingInGaussElimination(S21Matrix& temp, int pivotIndex, int *pSwapCount) const;

        [[nodiscard]] double GetSignBySwapCount(int swapCount) const;

        void SwapRows(S21Matrix &temp, int rowIndex1, int rowIndex2) const;

        void FillMinorMatrix(double **minorMatrix, int skipRow, int skipColumn, int minorSize) const;

        [[nodiscard]] double Minor(int row, int column) const;

        static double GetComplementSign(int i, int j) ;

        static S21Matrix HandleFirstOrderMatrixCalcComplements() ;

        [[nodiscard]] S21Matrix CalculateInverseMatrix(const S21Matrix &transposedComplementMatrix, double det) const;

        S21Matrix GetInverseOfFirstOrderMatrix();

        static void CheckEmptyMatrix(const S21Matrix& other);
        void CheckSquareMatrix() const;
        void CheckMultiplicationMatrices(const S21Matrix& other) const;
        void CheckMatricesSizeIdentity(const S21Matrix& other) const;
        void CheckRowsAndColsOverflow(int rowIndex, int colIndex) const;
        void CheckRowsAndColsUnderflow(int rowIndex, int colIndex) const;
        void CheckRowAndColsFlows(int rowIndex, int colIndex) const;
        static void CheckRowAndColsForConstructor(int rows, int cols);

        static void CheckSingularMatrix(double det);

        [[nodiscard]] bool IsFirstOrderMatrix() const;
        [[nodiscard]] static bool IsZero(double value);
    };
}


#endif // S21_MATRIX_OOP_H_