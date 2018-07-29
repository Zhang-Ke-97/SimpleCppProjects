#include <iostream>
using namespace std;
#define LENGTH(a) (int)(sizeof(a)/sizeof(a[0]))

int main(int argc, char const *argv[]) {
	int a_i[10] = {1,2,3,4,5,6,7,8,9,10};
	int* a_ptr[10] = {NULL};
	cout << "memory details about a_i[10]:" << endl;
	for(int i=0; i<LENGTH(a_i); i++) {
		a_ptr[i] = &a_i[i];
		cout << "address: " << a_i+i
		     << ", value: " << *(a_i+i) << endl;
	}

	cout << endl << "memory details about a_ptr[10]:" << endl;
	for(int i=0; i<LENGTH(a_ptr); i++) {
		a_ptr[i] = new int[i+1];
		cout << "address: " << a_ptr+i << ", value: " << *(a_ptr+i)
		     << ", size of a_ptr[" << i << "] = " << sizeof(a_ptr[i])
		     << ", size of *(a_ptr[" << i << "]) = " << sizeof(*a_ptr[i])
		     << endl;
	}

	cout << endl;
	for(int i=0; i<LENGTH(a_ptr); i++) {
		cout << "freeing memory at " << a_ptr[i] << endl;
		delete a_ptr[i];
	}


	int** arr = new int*[10];
	cout << endl << "arr is stored at: " << &arr << endl;
	cout << "memory details about arr[10]:" << endl;
	for (size_t i = 0; i < 10; i++) {
		arr[i] = new int[i+1];
		cout << "address: " << arr+i << ", value: " << arr[i] << endl;
	}

	for (size_t i = 0; i < 10; i++) {
		cout << "freeing memory at " << arr[i] << endl;
		delete arr[i];
	}
	cout << endl << "freeing memort at " << arr << endl;
	delete arr;

	return 0;
}
