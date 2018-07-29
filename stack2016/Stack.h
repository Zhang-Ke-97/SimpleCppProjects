//
// Class.h
// Created by Ke on 09.10.16.

#ifndef _Class_h_
#define _Class_h_

class Stack {
public:
	Stack();
	Stack(int);
	virtual ~Stack();
	
	int size;
	int* array;
	int top;
	const int bottom;
	
	bool isEmpty();
	void push(int);
	int pop();
	void clear();
	int getTop();
	void output();
	void transfer(int,int);

};

#endif