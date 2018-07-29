/**
 * This is a single file project to implemente Qin Jiushao argorithm .
 * Compile with commmand line:
 * g++ -o jiushao jiushao.cpp -std=c++14 -O -Wall -W
 * You can use command line parameter to define the degree of polynomial like:
 * ./jiushao 10
 * Otherwise the degree of polynomial can be given over standard input
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#define LENGTH(arr) (int)(sizeof(arr)/sizeof(arr[0]))

void set_coeffs(double* coeff, unsigned int l);
void show_polynm(double* coeff, unsigned int l);

double jiushao(double x, double* coeffs, unsigned int l);
double re_jiushao(unsigned int count, double x, double* coeffs, unsigned int l);

int main(int argc, char const *argv[]){
	unsigned int l = 0u;
	if (argc == 2) {
		l = (unsigned int)atof(argv[1]);
	}else{
		std::cout << "enter degree of polynomial: ";
		std::cin >> l;
	}

	assert(!std::cin.fail());
	double* coeffs = new double[l];
	double x = 0.0;
	std::cout << "x = ";
	std::cin >> x;
	set_coeffs(coeffs, l);
	show_polynm(coeffs,l);
	std::cout << "value is: " << re_jiushao(0, x, coeffs, l) << '\n';

	return 0;
}

void show_polynm(double* coeffs, unsigned int l) {
	for (unsigned int i = 0; i < l; i++) {
		std::cout << ' ' << std::showpos << *(coeffs+i)
		          << "*x^" << std::noshowpos << i;
	}
	std::cout << '\n';
}

void set_coeffs(double* coeffs, unsigned int l) {
	for (unsigned int i = 0; i < l; i++) {
		std::cout << "enter coefficients[" << i << "]: ";
		std::cin >> *(coeffs+i);
	}
}

double re_jiushao(unsigned int count, double x, double* coeffs, unsigned int l) {
	if (count==l-1) {
		return *coeffs;
	} else {
		return *coeffs + x*re_jiushao(count+1, x, coeffs+1, l);
	}
}

double jiushao(double x, double* coeffs, unsigned int l) {
	double result = 0.0;
	for (int i = l-1; i >=0; i--) {
		result = result*x + *(coeffs+i);
	}
	return result;
}
