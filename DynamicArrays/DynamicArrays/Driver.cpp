#include <iostream>
#include "DynamicArray.hpp"

using namespace std;

int main() {

	DynamicArray arrDemo(15);
	for (int i = 0; i < 15; i++)
		arrDemo.setvalue(i, 78 * i % 31);

	cout << "Array1:\n";
	arrDemo.printArray();

	DynamicArray arrDemo2 = arrDemo;
	cout << "Array2 copied from array 1:\n";
	arrDemo2.printArray();

	DynamicArray arrDemo3(5);
	arrDemo3 = arrDemo;
	cout << "Array3 assigned from array 1:\n";
	arrDemo3.printArray(); // might be arrDemo2 or 3 not sure

	return 0;//Destructor will be called
}