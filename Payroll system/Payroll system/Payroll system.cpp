#include <iostream>
#include <cstring>
#include <fstream>
// #include "sortemp.hpp"


#pragma pack(push, 1)
struct Employees {
	char name[50];
	int id;
	double hoursWorked;
	double payRate;
};
#pragma pack(pop)

void readEmployees(std::ifstream& inFile, Employees, employees[], int n);
void sortEmployees(Employees employees[], int n);
int calcPay(std::ofstream& outFile, Employees employees[], int n);


int main() {
	Employees employees[50];
	int n;
	std::ifstream inFile("employees.dat", std::ios::binary);
	if (!infile) {
		std::cerr << "Error opening file!";
		return 1;
	}



	return 0;
}

void readEmployees(std::ifstream& inFile, Employees employees[], int& n) {
	n = 0;
	while (inFile.read(reinterpret_cast<char*>(&employees[n]), sizeof(Employees))) {

		//ensure null termination of cstring
		employees[n].name[sizeof(employees[n].name) - 1] = '\0'; //'1' ' ' '1'o'
		std::cout << "Name was: " << employees[n].name << '\t' << "ID was: " << employees[n].id << '\n' <<
			" Quantity was: " << employees[n].quantity << "Price was: " << employees[n].price << '\n' << '\n';
		n++;
	}
}