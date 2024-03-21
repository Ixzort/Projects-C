#include "s21_math.h"

long double s21_factorial(double x) {
  if (x < 0) {
    return 0;
  } else if (x == 0) {
    return 1;
  } else {
    return x * s21_factorial(x - 1);
  }
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

long double s21_fabs(double source) {
  return (source > 0) ? source : (-source);
}

long int s21_abs(int source) { return (source > 0) ? source : (-source); }

//int8_t s21_is_zero(double source) { return s21_fabs(source) < s21_EPS; }

long double s21_cos(double source) { return s21_sin(s21_PI / 2.0 - source); }

long double s21_tan(double source) { return s21_sin(source) / s21_cos(source); }

long double s21_ceil(double source) {
  int floored = source;
  if (source - floored && source > 0.) return (long double)(floored + 1);
  return (long double)floored;
}

long double s21_floor(double source) {
  int floored = source;
  if (source - floored && source < 0.) return (long double)(floored - 1);
  return (long double)floored;
}

long double s21_fmod(double x, double y) {
  long double div = (long double)(x) / y;
  return (double)(div - ((int)div)) * y;
}

long double s21_acos(double source) {
  double result = (s21_PI / 2) - s21_asin(source);
  return result;
}
long double s21_asin(double x) {
  double asin = x, temp = x;
  int n = 1;
  if (x > 1 || x < -1) return s21_NAN;
  if (x == 1) {
    asin = s21_PI / 2;
  } else if (x == -1) {
    asin = -s21_PI / 2;
  } else {
    while (!(temp >= -s21_EPS && temp <= s21_EPS)) {
      temp = ((temp) * (x * x) * (2 * n - 1) * (2 * n - 1)) /
             ((2 * n + 1) * (2 * n));
      asin += temp;
      n++;
    }
  }
  return asin;
}
long double s21_sqrt(double x) {
  if (S21_IS_NAN(x) || x == s21_NINF || x < 0) return s21_NAN;
  if (x == s21_INF || x == 0) return (long double)x;
  return s21_pow(x, 0.5);
}
long double s21_atan(double x) {
  int flag = 0;
  long double result = 0;
  if (x < 0) {
    x = x * -1;
    flag = 1;
  }
  if (x == 0.0) {
    result = 0.0;
  } else if (x == 1.0 || x == -1.0) {
    result = (x == 1.0) ? s21_PI / 4.0 : s21_PI / 4.0 * (-1);
    //
  } else {
    int k = s21_fabs(x) > 1 ? -1 : 1;
    for (int i = 0; i < s21_EPS; i++) {
      result +=
          (s21_pow(-1, i) * s21_pow(x, (1 * k + 2 * k * i))) / (1 + 2 * i);
    }
    result = (k == -1.0) ? (s21_PI * s21_fabs(x) / (2 * x) - result) : result;
  }
  if (flag == 1) {
    result = result * -1;
  }
  return result;
}
// long double s21_atan(double x) {
//     return (s21_asin(x) / s21_acos(x));
// }
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
    long double temp = (long double)num;
    for (int i = 1; s21_fabs(temp / result) > 1e-100; i += 1)
      result += (temp = ((-temp) * num * num) / ((2.0 * i + 1) * (2.0 * i)));
  }
  return status ? (result * sign) : s21_NAN;
}

double s21_fmax(double x, double y) {
  if (x > y) {
    return x;
  }
  return y;
}
