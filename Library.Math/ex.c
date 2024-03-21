#include <math.h>
#include <stdio.h>

#include "s21_math.h"
long double s21_factorial(double x);
long double s21_exp(double x);
long double s21_pow_int(double x, int i);
long double s21_sin(double x);

int main() {
  long double x = 0, y = 0;
  scanf("%Lf", &x);
  // scanf("%Lf",&y);
  printf("%Lf math.h = %lf\n", s21_cos(x), cos(x));
}
long double s21_factorial(double x) {
  if (x < 0) {
    return 0;
  } else if (x == 0) {
    return 1;
  } else {
    return x * s21_factorial(x - 1);
  }
}

long double s21_exp(double x) {
  long double total = 1;
  long double step = 1;
  int count = 1;
  while (s21_fabs(step) > s21_EPS) {
    step *= x / count;
    count++;
    total += step;
    if (total > s21_MAX_double) {
      total = s21_INF;
      break;
    }
  }
  return total;
}

long double s21_pow_int(double x, int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;
  else if (n % 2 == 0)
    return s21_pow_int(x * x, n / 2);
  else
    return s21_pow_int(x * x, n / 2) * x;
}

long double s21_pow(double base, double exp) {
  long double total;
  long double copy = base;
  if (exp == (int)exp && exp >= 0) {
    total = s21_pow_int(base, exp);
  } else {
    if (copy < 0) {
      if (exp != ((int)exp && (copy != 1 || copy != -1))) {
        total = s21_NAN;
      } else {
        copy = -copy;
        total = s21_exp(exp * s21_log(copy));
        if (s21_fmod(exp, 2) != 0) {
          total = -total;
        }
      }
    } else {
      total = s21_exp(exp * s21_log(base));
    }
  }
  return total;
}
long double s21_log(double x) {
  int count = 0;
  long double step = 0;
  long double total = 0;
  if (x < 0) {
    total = s21_NAN;

  } else if (x == 0) {
    total = s21_NINF;

  } else {
    for (; x >= e; x /= e, count++) {
      continue;
    }
    for (int i = 0; i < 100; i++) {
      step = total;
      total = step + 2 * (x - s21_exp(step)) / (x + s21_exp(step));
    }
  }
  return total + count;
}
long double s21_sin(double num) {
  long double result = num;
  int status = 1, sign = (-1);
  if (s21_isnan(num) || s21_isinf(num)) {
    status = 0;
  } else {
    num = s21_fmod(num, s21_PI * 2.0);

    if (num > (s21_PI / 2.0) && num <= s21_PI)
      num = (s21_PI - num) * (sign = 1);
    else if (num > s21_PI && num <= ((s21_PI * 3.0) / 2.0))
      num -= s21_PI;
    else if (num > ((s21_PI * 3.0) / 2.0) && num <= (s21_PI * 2.0))
      num = (2.0 * s21_PI) - num;
    else
      sign = 1;

    result = (long double)num;
    long double valueTailor = (long double)num;
    for (int i = 1; s21_fabs(valueTailor / result) > 1e-100; i++)
      result += (valueTailor = ((-valueTailor) * num * num) /
                               ((2.0 * i + 1) * (2.0 * i)));
  }
  return status ? (result * sign) : s21_NAN;
}
long double s21_fabs(double source) { return source; }
long double s21_fmod(double x, double y) {
  long double div = (long double)(x) / y;
  return (double)(div - ((int)div)) * y;
}
// long double s21_cos(double num) {
//   long double result = 1.0;
//   int status = 1, sign = (-1);
//   if (s21_isnan(num) || s21_isinf(num)) {
//     status = 0;
//   } else {
//     num = s21_fmod(num, s21_PI * 2.0);

//     if (num > (s21_PI / 2.0) && num <= s21_PI)
//       num = (s21_PI - num);
//     else if (num > s21_PI && num <= ((s21_PI * 3.0) / 2.0))
//       num -= s21_PI;
//     else if (num > ((s21_PI * 3.0) / 2.0) && num <= (s21_PI * 2.0))
//       num = ((2.0 * s21_PI) - num) * (sign = 1);
//     else
//       sign = 1;

//     long double valueTailor = 1.0;
//     for (int i = 1; s21_fabs(valueTailor / result) > 1e-100; i += 1)
//       result += (valueTailor = ((-valueTailor) * num * num) /
//                                ((2.0 * i - 1) * (2.0 * i)));
//   }
//   return status ? (result * sign) : s21_NAN;
// }
long double s21_cos(double source) { return s21_sin(s21_PI / 2.0 - source); }
