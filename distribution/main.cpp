#include <iostream>
#include "distribution.h"

const double rate = 3;

int main(int argc, char const *argv[]) {
  std::cout << "已知医院平均每小时出生3名婴儿" << '\n';
  double t = 1;

  for (size_t i = 0; i < 10; i++) {
    std::cout << t << "小时内出生" << i << "名婴儿的概率是："
              << 100*f_poisson_distribute(rate, t, i)
              <<'%' << std::endl;
  }

  std::cout << std::endl << "15分钟之内有婴儿出生的概率是"
            << F_exp_distribute(rate, 0.25) << std::endl;
  return 0;
}
