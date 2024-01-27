#include "../s21_matrix_oop.h"

void S21Matrix::FillMinorMatrix(double **minorMatrix, int skipRow, int skipColumn, int minorSize) const {
    int rowIndexMinor, columnIndexMinor, rowIndexOrig, columnIndexOrig;

    for (rowIndexMinor = 0, rowIndexOrig = 0; rowIndexMinor < minorSize;
         ++rowIndexMinor, ++rowIndexOrig) {
        if (rowIndexOrig == skipRow) {
            rowIndexOrig++;
        }
        for (columnIndexMinor = 0, columnIndexOrig = 0;
             columnIndexMinor < minorSize; ++columnIndexMinor, ++columnIndexOrig) {
            if (columnIndexOrig == skipColumn) {
                columnIndexOrig++;
            }
            minorMatrix[rowIndexMinor][columnIndexMinor] =
                    matrix_[rowIndexOrig][columnIndexOrig];
        }
    }
}

double S21Matrix::Minor(int row, int column) const {
    //TODO throw errors
    S21Matrix temp = S21Matrix(rows_ - 1, cols_ - 1);

    FillMinorMatrix(temp.matrix_, row, column, rows_ - 1);
    double result = temp.Determinant();

    return result;
}