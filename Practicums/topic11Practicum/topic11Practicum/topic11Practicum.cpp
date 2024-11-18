#include <iostream>
#include <string>
#include "Source1.cpp"

struct {
	double 
};

int main() {
	std::string cashRegister;

	double dispenserType candy(100, 0.5);
	double dispenserType chips(100, 0.7);
	double dispenserType gum(100, 0.2);
	double dispenserType cookies(100, 0.6);

	showSelection();

	sellProduct();
}