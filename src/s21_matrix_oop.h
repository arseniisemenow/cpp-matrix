#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include "headers/s21_structs.h"
#include <iostream>

#define SUCCESS 1
#define FAILURE 0

class S21Matrix {
 public:
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);  // TODO should I use explicit here?
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  void SetRows(int number);
  void SetCols(int number);
  void SetElementInMatrix(int number, int rowIndex, int colIndex);
  [[nodiscard]] int GetRows() const noexcept;
  [[nodiscard]] int GetCols() const noexcept;
  [[nodiscard]] double GetElementInMatrix(int rowIndex, int colIndex) const noexcept;

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void EqMatrix(const S21Matrix& other);  // TODO Should I use const here?
  void MulNumber(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator==(const S21Matrix&& other);
  S21Matrix& operator+(const S21Matrix& other);
  S21Matrix& operator-(const S21Matrix& other);
  S21Matrix& operator*(const S21Matrix& other);
  S21Matrix operator*(double, const S21Matrix&);  // TODO friend?
  S21Matrix operator*(const S21Matrix&, double);  // TODO friend?
  bool operator==(const S21Matrix& other);        // TODO const here?
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator+=(const double number);
  double operator()(int i, int j) const;  // WHAT is this for?
  double& operator()(int i, int j);       // WHAT is this for?

  void PrintMatrix();  // TODO const noexcept?

 private:
  int rows_{};
  int cols_{};
  double** matrix_{};

  void InitNullMatrix() noexcept;
  void AllocateMemoryForMatrix(int rows, int cols) noexcept;
  void CopyMatrixData(const S21Matrix& other) noexcept;
  void DestroyMatrix();
    void ResizeMatrix(int newRows, int newCols);
};

#endif // S21_MATRIX_OOP_H_