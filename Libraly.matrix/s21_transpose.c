#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *ans) {
  if (is_null(A) || is_null(ans)) {
    return MATRIX_ERR;
  }
  s21_create_matrix(A->columns, A->rows, ans);
  for (int i = 0; i < ans->rows; i++) {
    for (int j = 0; j < ans->columns; j++) {
      ans->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}
