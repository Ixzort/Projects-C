#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#define s21_PI 3.14159265358979324
#define s21_NPI -3.14159265358979324
#define s21_EPS 1e-17
#define s21_ln10 2.30258509299404590109
#define s21_INF 1.0 / 0.0
#define s21_NINF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_N_NAN -0.0 / 0.0
#define s21_MAX_double 1.7976931348623157e308
#define s21_isnan(x) __builtin_isnan(x)
#define e 2.7182818284
#define S21_IS_NAN(x) (x != x)
#define s21_isinf(x) __builtin_isinf(x)
#define S21_M_2_PI 0.63661977236758134308
#define S21_M_PI_2 1.57079632679489661923

int8_t s21_is_zero(double source);
long int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_log(double x);
double s21_fmax(double x, double y);

#endif  // SRC_S21_MATH_H_
