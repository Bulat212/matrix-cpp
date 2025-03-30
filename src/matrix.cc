#include "matrix.h"


void S21Matrix::fill(){
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j]=rand()%10;
        }
    }
}


void S21Matrix::print(){
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            std::cout << matrix_[i][j] << " ";
        }
        std::cout<< std::endl;
    } 
}

S21Matrix::S21Matrix():rows_(0), cols_(0), matrix_(nullptr){}

S21Matrix::S21Matrix(int rows, int cols):rows_(rows),cols_(cols){
    matrix_=new double*[rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i]=new double[cols_];
    }
}

S21Matrix::S21Matrix(const S21Matrix& other):S21Matrix::S21Matrix(other.rows_, other.cols_){
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j]=other.matrix_[i][j];
        }
    } 
}     


S21Matrix::S21Matrix(S21Matrix&& other):rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_){
    other.rows_=0;
    other.cols_=0;
    other.matrix_=nullptr;
}     


S21Matrix::~S21Matrix(){
    for (int i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    
}                                         
