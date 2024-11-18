#include <iostream>

//function proto
void insertAt(int arr[], int& size, int insertItem, int index);

//Function def
void insertAt(int arr[], int& size, int insertItem, int index)
if (index < 0 || index > size) {
	std::cout << "Index out of range" << std::endl;
	return;
	}

for (int i = size; i > index; --i) {

}