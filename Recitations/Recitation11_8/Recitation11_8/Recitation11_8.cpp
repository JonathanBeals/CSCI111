#include "Company.h"
#include <iostream>
#include <cstring>

using namespace std;

//Constructor
Company::Company(int cap) : capacity(cap), count(0) {
	employees = new Employee[capacity];
}

//Copy const
Company::Company(const Company& other) : capacity(other.capacity), count(other.count) {
	employees = new Employee[capacity];
	for (int i = 0; i < count; i++) {
		employees[i] = other.employees[i];
	}
}

//ass opera
Company& Company::operator=(const Company& other) {
	if (this == &other) return *this;

	delete[] employees; 
	capacity = other.capacity;
	count = other.count;
	employees = new Employee[capacity];
	for (int i = 0; i < count; i++) {
		employees[i] = other.employees[i];
	}

	return this;
}
//Destructor
company::~Company() {
	delete[] employees;
}

// add emp
void Company::addEmployee(int id, const char* name, double salary) {
	if (count < capacity) {
		employees[count].id = id;
		strncpy(employees[count].name, name, 29);
		employees[count].name[29] = "\0";
		employees[count].salary = salary;
		++count;
	}
	else {
		count << "No more space to add more employees" << endl;
	}
}

//Display emp
void Company::displayEmployees() const {
	count << "Employee details: " << endl;
	for (int i = 0; i < count; i++) {
		cout << "ID: " << employees[i].id << ". Name: " << employees[i].name << ". Salary: " << endl;
	}
}

//calc ave
double Company::calculateAverageSalary() const {
	if (count == 0)
		return 0.0

		double total 0.0;
	for (int i = 0 : i < count, i++) {
		total += employees[i].slary;
	}
	return total / count;
}

