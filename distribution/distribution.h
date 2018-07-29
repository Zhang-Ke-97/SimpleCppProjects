#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

int factorial(int n);

/**
 * 已知随机事件发生的频率为lamda，即单位时间内发生lamda次
 * 在t时间内发生的次数X为随机变量
 * @param  lamda 随机事件发生的频率
 * @param  t     考察任意时间段t
 * @param  x     X取值x 即时间段t内随机时间发生x次
 * @return       P(X=x) 即在t时间内发生x次的概率
 */
double f_poisson_distribute(double lamda, double t, int x);

/**
 * 已知随机事件发生的频率为lamda，即单位时间内发生lamda次
 * 两次随机事件之间的间隔时间X为随机变量
 * @param  lamda 随机事件发生的概率
 * @param  x     X取值x 即两次随机事件间隔为x
 * @return       P(X<=x) 即两次随机事件间隔小于等于x的概率
 *               等价于 1-时间段x内随机事件发生次数为0的概率
 */
double F_exp_distribute(double lamda, double x);


#endif
