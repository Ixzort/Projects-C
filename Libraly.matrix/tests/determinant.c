#include "tests_main.h"

START_TEST(determinant_part_1) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  //  A.matrix = {{1,2,3},{4,5,6},{7,8,9}};
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_part_2) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  //  A.matrix = {{1,2,3},{4,5,6},{7,8,9}};
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_eq(result, 36);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_part_3) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 2, &A);

  ck_assert_int_eq(s21_determinant(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_part_4) {
  matrix_t A;
  s21_create_matrix(3, 2, &A);

  ck_assert_int_eq(s21_determinant(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant() {
  Suite *s = suite_create("determinant");
  TCase *tc_create = tcase_create("determinant");
  tcase_add_test(tc_create, determinant_part_1);
  tcase_add_test(tc_create, determinant_part_2);
  tcase_add_test(tc_create, determinant_part_3);
  tcase_add_test(tc_create, determinant_part_4);
  suite_add_tcase(s, tc_create);
  return s;
}