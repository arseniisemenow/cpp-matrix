#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_

#include <utility>

namespace s21 {
class S21Matrix {
 public:
  S21Matrix();
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix();

  void SetRows(int number);

  void SetCols(int number);

  void SetElementInMatrix(int number, int row_index, int col_index);

  [[nodiscard]] int GetRows() const noexcept;

  [[nodiscard]] int GetCols() const noexcept;

  [[nodiscard]] double GetElementInMatrix(int row_index,
                                          int col_index) const noexcept;

  void SumMatrix(const S21Matrix &other);

  void SubMatrix(const S21Matrix &other);

  [[nodiscard]] bool EqMatrix(const S21Matrix &other) const;

  void MulNumber(const double number);
  void MulMatrix(const S21Matrix &other);

  [[nodiscard]] double Determinant() const;

  [[nodiscard]] S21Matrix Transpose() const;

  [[nodiscard]] S21Matrix CalcComplements() const;
  [[nodiscard]] S21Matrix InverseMatrix() const;

  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  S21Matrix operator+(const S21Matrix &other);

  S21Matrix operator-(const S21Matrix &other);

  [[nodiscard]] S21Matrix operator*(const S21Matrix &other);
  [[nodiscard]] S21Matrix operator*(const double number) const;
  friend S21Matrix operator*(const double number, const S21Matrix &matrix);

  [[nodiscard]] bool operator==(const S21Matrix &other) const;
  S21Matrix &operator+=(const S21Matrix &other);

  S21Matrix &operator-=(const S21Matrix &other);

  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double number);

  [[nodiscard]] double operator()(int i, int j) const;
  double &operator()(int i, int j);

  friend std::ostream &operator<<(std::ostream &stream, const S21Matrix &other);

 private:
  int rows_{};
  int cols_{};
  double **matrix_{};

  enum class OperationType {
    kNone = 0,
    kAddition = 1 << 0,
    kSubtraction = 2 << 0,
  };

  void AllocateMemoryForMatrix();

  void CopyMatrixData(const S21Matrix &other) noexcept;

  void DestroyMatrix();

  void ResizeMatrix(int new_rows, int new_cols);

  void PerformSumAndSubOperations(const S21Matrix &other,
                                  OperationType operation_type);

  void CalculateAndAssignSumAndSubValue(const S21Matrix &other, int row_index,
                                        int col_index,
                                        OperationType operation_type);

  void PerformMatrixMulOperation(const double number);
  [[nodiscard]] bool PerformComparison(const S21Matrix &other) const;

  void PerformMatricesMulOperation(const S21Matrix &other);

  int GaussElimination(S21Matrix &temp) const;

  void PerformGaussElimination(S21Matrix &temp, int pivot_index) const;

  void PartialPivotingInGaussElimination(S21Matrix &temp, int pivot_index,
                                         int *p_swap_count) const;

  [[nodiscard]] double GetSignBySwapCount(int swap_count) const;

  void SwapRows(S21Matrix &temp, int row_index_1, int row_index_2) const;

  void FillMinorMatrix(S21Matrix &minor_matrix, int skip_row,
                       int skip_col) const;

  [[nodiscard]] double Minor(int row, int column) const;

  static double GetComplementSign(int i, int j);

  static S21Matrix HandleFirstOrderMatrixCalcComplements();

  [[nodiscard]] S21Matrix CalculateInverseMatrix(const S21Matrix &matrix,
                                                 double det) const;

  [[nodiscard]] S21Matrix GetInverseOfFirstOrderMatrix() const;

  static void CheckEmptyMatrix(const S21Matrix &other);
  void CheckSquareMatrix() const;
  void CheckMultiplicationMatrices(const S21Matrix &other) const;
  void CheckMatricesSizeIdentity(const S21Matrix &other) const;
  void CheckRowsAndColsOverflow(int row_index, int col_index) const;
  void CheckRowsAndColsUnderflow(int row_index, int col_index) const;
  void CheckRowAndColsFlows(int row_index, int col_index) const;
  static void CheckRowAndColsForConstructor(int rows, int cols);

  static void CheckSingularMatrix(double det);

  [[nodiscard]] bool IsFirstOrderMatrix() const;
  [[nodiscard]] static bool IsZero(double value);
};
}  // namespace s21

#endif  // CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_