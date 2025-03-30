#include "matrix.h"
#include <math.h>




bool S21Matrix::EqSize(const S21Matrix& A, const S21Matrix& B) {
    bool result_code = true;
    if (A.cols_ != B.cols_ || A.rows_ != B.rows_) result_code = false;
    return result_code;
}


bool S21Matrix::EqMatrix(const S21Matrix& other){
    if (!EqSize(*this, other)) {
        return false;
    }
    int result_code = true;

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) result_code = false;
        }
    }

    return result_code;
}
    

void S21Matrix::SumMatrix(const S21Matrix& other) {
  
    if (!EqSize(*this, other)) {
        throw std::logic_error("Размеры не равны");
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }

}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!EqSize(*this, other)) {
        throw std::logic_error("Размеры не равны");
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
}


void S21Matrix::MulNumber(const double num) {
    
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] *= num;
      }
    }
}


void S21Matrix::MulMatrix(const S21Matrix& other) {
  
  if (cols_!= other.rows_){
    throw std::logic_error("Количество столбцов не совпадает количеству столбцов");
  }
    
  double temp = 0.0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        temp += matrix_[i][k] * other.matrix_[k][j];
      }
      matrix_[i][j] = temp;
      temp = 0.0;
    }
  }

}

S21Matrix S21Matrix::Transpose() {

    S21Matrix temp(cols_, rows_);

    for (int j = 0; j < rows_; j++) {
      for (int i = 0; i < cols_; i++) {
        temp.matrix_[i][j] = matrix_[j][i];
      }
    }

  return temp;
}


void S21Matrix::SwapLines(int row_1, int row_2, S21Matrix& other) {

  for (int i = 0; i < cols_; i++) {
    std::swap(matrix_[row_1][i], matrix_[row_2][i]);
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::ChangeMatrixRow(int str_to_null, S21Matrix& copy_a, int i) {
  for (int j = str_to_null; j < copy_a.rows_ - 1; j++) {
    if (copy_a.matrix_[j + 1][i] != 0.0) {
      double temp = copy_a.matrix_[j + 1][i] / copy_a.matrix_[i][i];
      for (int k = i; k < copy_a.cols_; k++) {
        copy_a.matrix_[j + 1][k] =
            copy_a.matrix_[j + 1][k] - copy_a.matrix_[i][k] * temp;
      }
    }
  }
}



// double S21Matrix::Determinant() {

//   double det = -1.0;
//   int sign = 1;
//   int str_to_null = 0;
//   int first_not_null_el = -1;
//   S21Matrix copy_a(*this);

//     if (cols_!= rows_){
//         throw std::logic_error("Количество столбцов не совпадает количеству столбцов");
//     }

//   for (int i = 0; i < copy_a.rows_ && det != 0.0; i++) {
//     if (copy_a.matrix_[i][i] == 0.0) {
//       for (int j = i + 1; j < copy_a.rows_; j++) {
//         if (copy_a.matrix_[j][i] != 0.0) first_not_null_el = j;
//       }
//       if (first_not_null_el == -1 || i == copy_a.rows_ - 1)
//         det = 0.0;
//       else {
//         SwapLines(i, first_not_null_el, copy_a);
//         sign = sign * (-1);
//       }
//     }
//     if (det != 0.0) {
//       ChangeMatrixRow(str_to_null, copy_a, i);
//       str_to_null++;
//     }
//   }

//   if (det == -1.0) {
//     det = 1.0;
//     for (int i = 0; i < copy_a.rows_; i++) det = det * copy_a.matrix_[i][i];
//     det = det * sign;
//   } else {
//     det = 0.0;
//   } 

//   return det;
// }

double S21Matrix::Determinant() {
    if (cols_ != rows_) {
        throw std::logic_error("Матрица не квадратная");
    }

    S21Matrix copy_a(*this);  // Копируем матрицу для преобразований
    double det = 1.0;         // Изначально определитель = 1
    int sign = 1;             // Знак определителя (меняется при перестановке строк)
    const double eps = 1e-10; // Погрешность для сравнения с нулём

    for (int i = 0; i < copy_a.rows_; i++) {
        // Поиск ненулевого элемента в текущем столбце (для выбора ведущего элемента)
        int pivot = i;
        while (pivot < copy_a.rows_ && std::fabs(copy_a.matrix_[pivot][i]) < eps) {
            pivot++;
        }

        // Если весь столбец нулевой, определитель = 0
        if (pivot == copy_a.rows_) {
            return 0.0;
        }

        // Если ведущий элемент не на диагонали, меняем строки местами
        if (pivot != i) {
            copy_a.SwapLines(i, pivot, copy_a);
            sign *= -1; // Меняем знак определителя при перестановке строк
        }

        // Зануляем элементы под ведущим
        for (int j = i + 1; j < copy_a.rows_; j++) {
            double factor = copy_a.matrix_[j][i] / copy_a.matrix_[i][i];
            for (int k = i; k < copy_a.cols_; k++) {
                copy_a.matrix_[j][k] -= factor * copy_a.matrix_[i][k];
            }
        }

        // Умножаем определитель на диагональный элемент
        det *= copy_a.matrix_[i][i];
    }

    return det * sign;
}


void S21Matrix::RemoveRowAndCol(S21Matrix &new_matrix, int i, int j) {
  int new_col = 0, new_row = 0;
  for (int row = 0; row < rows_; row++) {
    if (row != i) {
      new_col = 0;
      for (int col = 0; col < cols_; col++) {
        if (col != j) {
          new_matrix.matrix_[new_row][new_col] = matrix_[row][col];
          new_col++;
        }
      }
      new_row++;
    }
  }
}



S21Matrix  S21Matrix::CalcComplements() {

  if (cols_ != rows_) {
        throw std::logic_error("Матрица не квадратная");
    }

    S21Matrix result(rows_, cols_);
    
    if (rows_ == 1) {
        result.matrix_[0][0] = 1.0;
    } else {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                S21Matrix minor(rows_ - 1, cols_ - 1);
                RemoveRowAndCol(minor, i, j);
                double minor_det = minor.Determinant();
                result.matrix_[i][j] = minor_det * std::pow(-1, i + j);
            }
        }
    }
    return result;
}


S21Matrix S21Matrix::InverseMatrix() {
  if (cols_!= rows_){
    throw std::logic_error("Количество столбцов не совпадает количеству столбцов");
  }


  double det = 0.0;
    det = Determinant();

  if (det == 0.0) {
    throw std::logic_error("Ошибка");
  
  }

    S21Matrix temp_matrix_complements = CalcComplements();
    S21Matrix temp_matrix_transpose = temp_matrix_complements.Transpose();

    temp_matrix_transpose.MulNumber(1 / det);
  
  return temp_matrix_transpose;
}
