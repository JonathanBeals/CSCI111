//We can use this in place of STL's in CS2 and CS3

#include "DynamicArray.hpp"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(int s) : size(s) {
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = 0; //initialize all to 0

	cout << "Constructor called, size = " << size << endl;
}

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = other.data[i]; //initialize all to 0

	cout << "Copy constructor called" << endl;
}


DynamicArray& DynamicArray::operator =(const DynamicArray& other) {
	if (this == &other) return *this; //Self assisgnment check
	delete[] data;
	size = other.size;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = other.data[i]; 

	cout << "Operator = called" << endl;
	return *this;
}

DynamicArray::~DynamicArray() {
	delete[] data;
	size = 0;

	cout << "Destructor automatically called releasing memory" << endl;
}

void DynamicArray::setValue(int idx, int value) {
	if (idx >= 0 && idx < size)
		data[idx] = value;
	cout << "Data at position " << idx << " updated" << endl;
}


int* DynamicArray::getArray()const {
	return data;
}
void DynamicArray::printArray()const {
	cout << "Printing array constents:" << endl;
	for (int i = 0; i < size; i++)
		cout << data[i] << '\t';
	cout << endl << endl;
}


