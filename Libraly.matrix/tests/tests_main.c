#include "tests_main.h"

void run_test(Suite *thesuit) {
  SRunner *therunner = srunner_create(thesuit);
  srunner_run_all(therunner, CK_NORMAL);
  srunner_free(therunner);
  printf("\n");
}

int main() {
  printf("================= TESTING =================\n\n");
  Suite *s_1 = create_matrix();  // Создание тестового кейса create_matrix
  Suite *s_2 = remove_matrix();
  Suite *s_3 = eq_matrix();
  Suite *s_4 = sum_matrix();
  Suite *s_5 = sub_matrix();
  Suite *s_6 = mult_number();
  Suite *s_7 = mult_matrix();
  Suite *s_8 = transpose();
  Suite *s_9 = determinant();
  Suite *s_10 = calc_complements();
  Suite *s_11 = inverse_matrix();

  run_test(s_1);  // Запуск тестов из тестового кейса
  run_test(s_2);
  run_test(s_3);
  run_test(s_4);
  run_test(s_5);
  run_test(s_6);
  run_test(s_7);
  run_test(s_8);
  run_test(s_9);
  run_test(s_10);
  run_test(s_11);

  printf("================= END =================\n");
  return 0;
}