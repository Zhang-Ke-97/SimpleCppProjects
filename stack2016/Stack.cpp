//
// Class.cpp
// Created by Ke on 09.10.16.

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack():bottom(0){
	size = 100;
	array = new int[100];
	top = 0;
}

Stack::Stack(int size):bottom(0) {
	this->size = size;
	array = new int[size];
	top = 0;
}

Stack::~Stack() {
	
}


bool Stack::isEmpty(){
	if(top == bottom){
		return true;
	}else {
		return false;
	}
}

void Stack::push(int newItem){
	if(top <= size-1){
		array[top] = newItem;
		top++;
	}
}

int Stack::pop(){
	if(isEmpty()){
		return error_code();
	}else{
		top--;
		return array[top];
	}
}

void Stack::clear(){
	top = bottom;
}

int Stack::getTop(){
	return array[top-1];
}

void Stack::output(){
	while(!isEmpty()){
		cout<<' '<<getTop();
		top--;
	}
	cout<<endl;
}

void Stack::transfer(int operand, int base){
	clear();
	while (operand != 0) {
		push( operand%base );
		operand /= base;
	}	
}
