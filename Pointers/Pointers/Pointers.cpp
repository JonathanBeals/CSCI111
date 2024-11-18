#include <iostream>


void swap(int& X1, int& X2);

int main() {

	/*
	int x = 1, y = 2, z;
	int* p;
	p = &x;
	z = *p;
	p = &y;
	z += *p;

	std::cout << *p << std::endl;
	

	double SalesSpr, SalesSum, SalesAut, SalesWin;
	double* SalesIndex[4] = { &SalesSpr, &SalesSum, &SalesAut, &SalesWin };

	int* ptr = new int;

	delete ptr;		//Deallocate memory
	ptr = nullptr;	//set pointer to null
	*/
}

void Swap(int& X1, int& X2) {
	int temp;
	temp = X1;
	X1 = X2;
	X2 = temp;

	swap(&A, &B);
}