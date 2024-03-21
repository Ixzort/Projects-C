#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *ans) {
  if (is_null(A) || is_null(ans)) {
    return MATRIX_ERR;
  } else if (inf_or_nan(A) || A->rows != A->columns) {
    return CALC_ERR;
  }
  int res = OK;
  double det = 0.;
  s21_determinant(A, &det);

  if (det) {
    det = 1 / det;
    matrix_t complements, transpose;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);

    s21_mult_number(&transpose, det, ans);

    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  } else {
    res = CALC_ERR;
  }

  return res;
}