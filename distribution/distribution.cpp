#include <cmath>
#include "distribution.h"

double f_poisson_distribute(double lamda, double t, int x) {
  return pow(lamda*t, x)*exp(-lamda*t)/factorial(x);
}

int factorial(int n) {
  if (n==0) {
    return 1;
  } else {
    return n*factorial(n-1);
  }
}

double F_exp_distribute(double lamda, double x) {
  return 1-f_poisson_distribute(lamda, x, 0);
}
