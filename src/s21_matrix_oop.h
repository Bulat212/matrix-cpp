#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>

#define S21_EPS 1e-7

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } S21MatrixResultCode;

class S21Matrix {
private:
  int rows_, cols_;
  double **matrix_;
  bool EqSize(const S21Matrix &A, const S21Matrix &B) const;

  void SwapLines(int row_1, int row_2);
  void RemoveRowAndCol(S21Matrix &new_matrix, int i, int j);

public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  S21Matrix &operator=(S21Matrix &&other);

  S21Matrix &operator=(const S21Matrix &other);
  double &operator()(int row, int col);
  double operator()(int row, int col) const;
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double number);

  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double number);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  bool operator==(const S21Matrix &other) const;

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int GetCols() const;
  int GetRows() const;
  void SetCols(int new_cols);
  void SetRows(int new_rows);
};

#endif
