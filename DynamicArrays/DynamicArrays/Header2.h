#ifndef DynamicArray_HPP
#define DynamicArray_HPP

#include <stdio.h>

class DynamicArray {
private:
	int* data;
	int size;

public:
	//constructor with parameter
	DynamicArray(int s);

	//copy constructor
	DynamicArray(const DynamicArray& other);

	//overloaded assignment operator
	DynamicArray& operator =(const DynamicArray& other);

	//Destructor to release memory
	~DynamicArray();

	void setValue(int idx, int value);

	//member function to get a pointer to the array

	int* getArray()const;

	//print function
	void printArray()const;

};

#endif
