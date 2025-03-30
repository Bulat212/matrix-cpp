#include "matrix.h"


S21Matrix S21Matrix::operator+(const S21Matrix& other){
    S21Matrix result(*this);
    result.SumMatrix(other);
    return result;
}


S21Matrix S21Matrix::operator-(const S21Matrix& other){
    S21Matrix result(*this);
    result.SubMatrix(other);
    return result;
}

double& S21Matrix::operator()(int row, int col){
    
    return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const{
    
    return matrix_[row][col];
}


S21Matrix& S21Matrix::operator=(const S21Matrix& other){
    
    S21Matrix temp(other);
    *this=std::move(temp);
    return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other){
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_,other.matrix_);
    return *this;
}

