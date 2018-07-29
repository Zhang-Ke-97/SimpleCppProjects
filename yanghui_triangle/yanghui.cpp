#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "yanghui.h"
using namespace std;


void allocate_mem(unsigned long** &triangle, int SIZE) {
	/* To make the programm safer and cleaner, dangling pointer are not wished.
	 * If triangle point to somewhere before allocation, programm should throw a WARNING.
	 * Same thing in the overloaded function allocate_mem(unsigned long**, int)
	 */
	if (triangle!=NULL) {
		cout << "!!! WARNING: dangling pointer OR memory leak !!!" << endl;
	}
	triangle = new unsigned long*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		triangle[i] = new unsigned long[i+1];
	}
}

void allocate_mem(unsigned long*** triangle, int SIZE) {
	if (*triangle!=NULL) {
		cout << "!!! WARNING: dangling pointer OR memory leak !!!" << endl;
	}

	*triangle = new unsigned long*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		(*triangle)[i] = new unsigned long[i+1];
	}
}


void set_two_sides(unsigned long** triangle, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		*(triangle[i]) = 1lu;
		*(triangle[i] + i) = 1lu;
	}
}

void set_value(unsigned long** triangle, int SIZE) {
	set_two_sides(triangle, SIZE);
	for (int i = 2; i < SIZE; i++) {
		for (int j = 1; j < i; j++) {
			*(triangle[i]+j ) = *(triangle[i-1]+j-1) + *(triangle[i-1]+j);
		}
	}
}

void cal_part(unsigned long** triangle, int SIZE, int i, int j){
	if (i > SIZE -1 || j > SIZE -1 ) {
		cout << "invalid argument! Programm terminated at cal_rest()." << endl;
	}
	if (triangle[i][j] == 1lu) {
		return;
	}else{
		cal_part(triangle, SIZE, i-1, j-1);
		cal_part(triangle, SIZE, i-1, j);
		triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
	}
}

void build(unsigned long** &triangle, int SIZE) {
	allocate_mem(triangle, SIZE);
	set_value(triangle, SIZE);
}

void build(unsigned long*** triangle, int SIZE) {
	allocate_mem(triangle, SIZE);
	set_value(*triangle, SIZE);
}

void show(unsigned long** triangle, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << setw(6) << *(triangle[i]+j) << ' ';
		}
		cout << endl;
	}
}

void destroy(unsigned long** &triangle, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (triangle[i]!= NULL) {
			delete triangle[i];
			triangle[i] = NULL;
		}
	}
	if (triangle!=NULL) {
		delete triangle;
		triangle = NULL;
	}
	cout << "all memory in heap freed" << endl;
}

void destroy(unsigned long*** triangle, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if ((*triangle)[i]!= NULL) {
			delete (*triangle)[i];
			*(triangle)[i] = NULL;
		}
	}
	if (*triangle!=NULL) {
		delete *triangle;
		*triangle = NULL;
	}
	cout << "all memory in heap freed" << endl;
}
