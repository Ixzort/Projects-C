#include "tests_main.h"

START_TEST(create_matrix_part_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_part_2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 3, &A), 1);
}
END_TEST

START_TEST(create_matrix_part_3) {
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), 1);
}
END_TEST

START_TEST(create_matrix_part_4) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(5, 7, &A), 0);
  ck_assert_int_eq(A.rows, 5);
  ck_assert_int_eq(A.columns, 7);
  s21_remove_matrix(&A);
}
END_TEST

Suite *create_matrix() {
  Suite *s = suite_create("create_matrix");
  TCase *tc_create = tcase_create("create_matrix");
  tcase_add_test(tc_create, create_matrix_part_1);
  tcase_add_test(tc_create, create_matrix_part_2);
  tcase_add_test(tc_create, create_matrix_part_3);
  tcase_add_test(tc_create, create_matrix_part_4);
  suite_add_tcase(s, tc_create);
  return s;
}