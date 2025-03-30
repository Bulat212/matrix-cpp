#include "matrix.h"




int main(){
    S21Matrix p;
    S21Matrix p1(3,3);
    
    
    p1.fill();
    
    S21Matrix p2(p1);
    p1.print();
    p2 = p1.InverseMatrix();
    p2.print();
    S21Matrix p3(2,2);
    p3(0, 0) = 0; 
    p3(0, 1) = 2; 
    p3(1, 0) = 8; 
    p3(1, 1) = 3; 
    // S21Matrix p3(std::move(p2));
    std::cout << p3.Determinant();
    return 0;
}