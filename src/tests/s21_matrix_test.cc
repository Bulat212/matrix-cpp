#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(MatrixOperatorsTest, OperatorPlus) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix result = m1 + m2;

  EXPECT_DOUBLE_EQ(result(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 12.0);
}

TEST(MatrixOperatorsTest, OperatorMinus) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 5.0;
  m1(0, 1) = 6.0;
  m1(1, 0) = 7.0;
  m1(1, 1) = 8.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  S21Matrix result = m1 - m2;

  EXPECT_DOUBLE_EQ(result(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

TEST(MatrixOperatorsTest, OperatorMultiplyMatrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix result = m1 * m2;

  EXPECT_DOUBLE_EQ(result(0, 0), 19.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 22.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 43.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 50.0);
}

TEST(MatrixOperatorsTest, OperatorMultiplyNumber) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix result = m1 * 2.5;

  EXPECT_DOUBLE_EQ(result(0, 0), 2.5);
  EXPECT_DOUBLE_EQ(result(0, 1), 5.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 7.5);
  EXPECT_DOUBLE_EQ(result(1, 1), 10.0);
}

TEST(MatrixOperatorsTest, OperatorMultiplyAssignNumber) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m1 *= 2.0;

  EXPECT_DOUBLE_EQ(m1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 8.0);
}

TEST(MatrixOperatorsTest, OperatorPlusAssign) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  m1 += m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 12.0);
}

TEST(MatrixOperatorsTest, OperatorMinusAssign) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 5.0;
  m1(0, 1) = 6.0;
  m1(1, 0) = 7.0;
  m1(1, 1) = 8.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  m1 -= m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

TEST(MatrixOperatorsTest, OperatorMultiplyAssignMatrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  m1 *= m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 19.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 22.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 43.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 50.0);
}

TEST(MatrixOperatorsTest, OperatorEqual) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  EXPECT_TRUE(m1 == m2);
}

TEST(MatrixOperatorsTest, OperatorParentheses) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

TEST(MatrixOperatorsTest, OperatorParenthesesConst) {
  const S21Matrix m1(2, 2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 0.0);
}

TEST(MatrixOperatorsTest, OperatorParenthesesOutOfRange) {
  S21Matrix m1(2, 2);

  EXPECT_THROW(m1(-1, 0), std::logic_error);
  EXPECT_THROW(m1(0, -1), std::logic_error);
  EXPECT_THROW(m1(2, 0), std::logic_error);
  EXPECT_THROW(m1(0, 2), std::logic_error);
}

TEST(MatrixOperatorsTest, OperatorMoveAssignment) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2;
  m2 = std::move(m1);

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);

  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
}

TEST(MatrixOperatorsTest, OperatorAssignment) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2;
  m2 = m1;

  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);

  m1(0, 0) = 5.0;
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
}

TEST(MatrixMethodsTest, Transpose) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;

  S21Matrix result = m1.Transpose();

  EXPECT_EQ(result.GetRows(), 3);
  EXPECT_EQ(result.GetCols(), 2);
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 6.0);
}

TEST(MatrixMethodsTest, Determinant) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  double det = m1.Determinant();
  EXPECT_DOUBLE_EQ(det, 0.0);

  S21Matrix m2(2, 2);
  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  det = m2.Determinant();
  EXPECT_DOUBLE_EQ(det, -2.0);
}

TEST(MatrixMethodsTest, CalcComplements) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 0.0;
  m1(1, 1) = 4.0;
  m1(1, 2) = 2.0;
  m1(2, 0) = 5.0;
  m1(2, 1) = 2.0;
  m1(2, 2) = 1.0;

  S21Matrix result = m1.CalcComplements();

  EXPECT_DOUBLE_EQ(result(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(result(0, 2), -20.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -14.0);
  EXPECT_DOUBLE_EQ(result(1, 2), 8.0);
  EXPECT_DOUBLE_EQ(result(2, 0), -8.0);
  EXPECT_DOUBLE_EQ(result(2, 1), -2.0);
  EXPECT_DOUBLE_EQ(result(2, 2), 4.0);
}

TEST(MatrixMethodsTest, InverseMatrix) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 2.0;
  m1(0, 1) = 5.0;
  m1(0, 2) = 7.0;
  m1(1, 0) = 6.0;
  m1(1, 1) = 3.0;
  m1(1, 2) = 4.0;
  m1(2, 0) = 5.0;
  m1(2, 1) = -2.0;
  m1(2, 2) = -3.0;

  S21Matrix result = m1.InverseMatrix();

  EXPECT_NEAR(result(0, 0), 1.0, S21_EPS);
  EXPECT_NEAR(result(0, 1), -1.0, S21_EPS);
  EXPECT_NEAR(result(0, 2), 1.0, S21_EPS);
  EXPECT_NEAR(result(1, 0), -38.0, S21_EPS);
  EXPECT_NEAR(result(1, 1), 41.0, S21_EPS);
  EXPECT_NEAR(result(1, 2), -34.0, S21_EPS);
  EXPECT_NEAR(result(2, 0), 27.0, S21_EPS);
  EXPECT_NEAR(result(2, 1), -29.0, S21_EPS);
  EXPECT_NEAR(result(2, 2), 24.0, S21_EPS);
}

TEST(MatrixMethodsTest, SetRows) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m1.SetRows(3);

  EXPECT_EQ(m1.GetRows(), 3);
  EXPECT_EQ(m1.GetCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(2, 1), 0.0);
}

TEST(MatrixMethodsTest, SetCols) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m1.SetCols(3);

  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 2), 0.0);
}

TEST(MatrixConstructorsTest, MoveConstructorWithoutGetMatrix) {
  S21Matrix source(2, 2);
  source(0, 0) = 1.0;
  source(0, 1) = 2.0;
  source(1, 0) = 3.0;
  source(1, 1) = 4.0;

  S21Matrix moved(std::move(source));

  EXPECT_EQ(moved.GetRows(), 2);
  EXPECT_EQ(moved.GetCols(), 2);
  EXPECT_DOUBLE_EQ(moved(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(moved(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(moved(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(moved(1, 1), 4.0);

  EXPECT_EQ(source.GetRows(), 0);
  EXPECT_EQ(source.GetCols(), 0);

  EXPECT_THROW(source(0, 0), std::logic_error);
}