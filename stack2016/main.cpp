#include <iostream>
#include "Stack.h"
#include <math.h>
using namespace std;

//Test_十进制转n进制
void playAGame(){
	Stack result(100); 
	int operand = 0,base = 2;
	
	cout<<"Press 0 to stop.Press any other keys to continue. "<<endl;
	char stop = getchar(); 
	while(stop != '0'){
		cout<<"operand = "; cin>>operand;
		cout<<"base = "; cin>>base;
		
		result.transfer(operand,base);
		result.output();
		
		cout<<"Press 0 to stop.Press any other keys to continue. "<<endl;
		stop = getchar();
	}
	
}

int main(int argc, char *argv[]) {
	playAGame();
}
