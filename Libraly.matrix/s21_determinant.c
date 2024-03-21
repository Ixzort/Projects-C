#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *ans) {
  if (is_null(A) || ans == NULL) {
    return MATRIX_ERR;
  } else if (A->columns != A->rows || inf_or_nan(A)) {
    return CALC_ERR;
  }
  int sign = 1;
  matrix_t B;
  s21_create_matrix(A->rows, A->columns, &B);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B.matrix[i][j] = A->matrix[i][j];
    }
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((i + j < i + i) && (i != j) && B.matrix[i][j] != 0) {
        if (B.matrix[j][j] == 0) {
          double *temp = B.matrix[j];
          B.matrix[j] = B.matrix[j + 1];
          B.matrix[j + 1] = temp;
          sign = -sign;
        }
        double temp = B.matrix[i][j] / B.matrix[j][j];
        for (int k = j; k < A->columns; k++) {
          B.matrix[i][k] -= temp * B.matrix[j][k];
        }
      }
    }
  }
  *ans = 1;
  for (int i = 0; i < B.rows; i++) {
    *ans *= B.matrix[i][i];
  }
  *ans *= sign;
  s21_remove_matrix(&B);
  return OK;
}