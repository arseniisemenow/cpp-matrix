#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <iostream>
#include <cmath>
#include <utility>


//TODO move all constant away!
#define SUCCESS 1
#define FAILURE 0
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

        void PrintMatrix() const noexcept;

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

        void FillMinorMatrix(double **minorMatrix, int skipRow, int skipColumn, int minorSize) const;

        double Minor(int row, int column) const;

        double GetComplementSign(int i, int j) const;

        S21Matrix HandleFirstGradeMatrix() const;

        S21Matrix CalculateInverseMatrix(S21Matrix &transposedComplementMatrix, double det) const;

        S21Matrix GetInverseOfFirstOrderMatrix();

        void CheckEmptyMatrix(const S21Matrix& other) const{
            if (other.cols_ <= 0 || other.rows_ <= 0 || other.matrix_ == nullptr) {
                throw std::invalid_argument("Matrix is empty");
            }
        }
        void CheckSquareMatrix(const S21Matrix& other) const{
            if (cols_ != rows_) {
                throw std::invalid_argument("Matrix is not square");
            }
        }
        void CheckMultiplicationMatrices(const S21Matrix& other) const {
            if (cols_ != other.rows_){
                throw std::invalid_argument("Matrix multiplication is not possible, "
                                            "numbers of rows in first matrix is not the same as "
                                            "number of second matrix");
            }
        }

        void CheckMatricesSizeIdentity(const S21Matrix& other) const{
            if (rows_ != other.rows_ || cols_ != other.cols_){
                throw std::invalid_argument("Matrices are not identical for the operation");
            }
        }
        void CheckRowsAndColsOverflow(int rowIndex, int colIndex) const{
            if (rowIndex >= rows_ || colIndex >= cols_) {
                throw std::out_of_range("The number of rows or columns is overflowed");
            }
        }
        void CheckRowsAndColsUnderflow(int rowIndex, int colIndex) const{
            if (rowIndex < 0 || colIndex < 0) {
                throw std::out_of_range("The number of rows or columns is underflowed");
            }
        }

        void CheckRowAndCols(int rowIndex, int colIndex) const{
            CheckRowsAndColsUnderflow(rowIndex, colIndex);
            CheckRowsAndColsOverflow(rowIndex, colIndex);
        }
    };
}


#endif // S21_MATRIX_OOP_H_