#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>

#define S21_EPS 1e-7

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } S21MatrixResultCode;


class S21Matrix {
private:
    // attributes
    int rows_, cols_;                                          // rows and columns attributes
    double **matrix_;   
    bool EqSize(const S21Matrix& A, const S21Matrix& B);      
                                          // pointer to the memory where the matrix will be allocated

    void CopyMatrix(const S21Matrix& other);
    void SwapLines(int row_1, int row_2, S21Matrix& other);
    void ChangeMatrixRow(int str_to_null, S21Matrix& copy_a, int i);
    void RemoveRowAndCol(S21Matrix& new_matrix, int i, int j);


public:
    S21Matrix();                                                // default constructor
    S21Matrix(int rows, int cols);                              // parameterized constructor
    S21Matrix(const S21Matrix& other);                              // copy cnstructor
    S21Matrix(S21Matrix&& other);                                   // move cnstructor
    ~S21Matrix();                                               // destructor

    S21Matrix& operator=(S21Matrix&& other);
    // some operators overloads

    S21Matrix& operator=(const S21Matrix& other);                   // assignment operator overload
    double& operator()(int row, int col);                          // index operator overload
    double operator()(int row, int col) const;
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    S21Matrix operator*(const double number);

    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double number);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    bool operator==(const S21Matrix& other);


    bool EqMatrix(const S21Matrix& other);
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();
    
    void print();
    void fill();
    int GetCols()const;
    int GetRows()const;
    void SetCols(int new_cols);
    void SetRows(int new_rows);
};

#endif
