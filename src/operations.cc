#include <math.h>

#include "s21_matrix_oop.h"

int S21Matrix::GetCols() const { return cols_; }

int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 0) {
    throw std::logic_error("Колонок меньше нуля");
  }

  double **temp = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    temp[i] = new double[new_cols];
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < new_cols; j++) {
      if (j < cols_) {
        temp[i][j] = matrix_[i][j];
      } else {
        temp[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = temp;
  cols_ = new_cols;
}

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 0) {
    throw std::logic_error("Строчек меньше нуля");
  }

  double **temp = new double *[new_rows];
  for (int i = 0; i < new_rows; i++) {
    temp[i] = new double[cols_];
  }

  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < rows_) {
        temp[i][j] = matrix_[i][j];
      } else {
        temp[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = temp;
  rows_ = new_rows;
}

bool S21Matrix::EqSize(const S21Matrix &A, const S21Matrix &B) const {
  bool result_code = true;
  if (A.cols_ != B.cols_ || A.rows_ != B.rows_)
    result_code = false;
  return result_code;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (!EqSize(*this, other)) {
    return false;
  }
  int result_code = true;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7)
        result_code = false;
    }
  }

  return result_code;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!EqSize(*this, other)) {
    throw std::logic_error("Размеры не равны");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
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

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::logic_error(
        "Количество столбцов не совпадает c количеством строк");
  }
  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      double temp = 0.0;
      for (int k = 0; k < cols_; k++) {
        temp += matrix_[i][k] * other.matrix_[k][j];
      }
      result.matrix_[i][j] = temp;
    }
  }
  *this = std::move(result);
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

void S21Matrix::SwapLines(int row_1, int row_2) {
  for (int i = 0; i < cols_; i++) {
    std::swap(matrix_[row_1][i], matrix_[row_2][i]);
  }
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::logic_error("Матрица не квадратная");
  }

  S21Matrix copy_a(*this); // Копируем матрицу для преобразований
  double det = 1.0; // Изначально определитель = 1
  int sign = 1; // Знак определителя (меняется при перестановке строк)
  const double eps = 1e-10; // Погрешность для сравнения с нулём

  for (int i = 0; i < copy_a.rows_; i++) {
    // Поиск ненулевого элемента в текущем столбце (для выбора ведущего
    // элемента)
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
      copy_a.SwapLines(i, pivot);
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

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::logic_error(
        "Количество столбцов не совпадает c количеством строк");
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
  if (cols_ != rows_) {
    throw std::logic_error(
        "Количество столбцов не совпадает c количеством строк");
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
