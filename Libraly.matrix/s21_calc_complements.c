#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *ans) {
  if (is_null(A) || is_null(ans)) {
    return MATRIX_ERR;
  } else if (A->columns != A->rows || inf_or_nan(A)) {
    return CALC_ERR;
  }
  s21_create_matrix(A->rows, A->columns, ans);
  matrix_t minor;

  if (A->rows > 1) {
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < ans->rows; i++) {
      for (int j = 0; j < ans->columns; j++) {
        cut_minor_matrix(&minor, *A, i, j);
        s21_determinant(&minor, &ans->matrix[i][j]);
        if ((i + j) & 1) {
          ans->matrix[i][j] *= -1;
        }
      }
    }
    s21_remove_matrix(&minor);
  } else {
    ans->matrix[0][0] = 1.;
  }
  return OK;
}