#ifndef COMPANY_H
#define COMPANY_H

#include "Employees.h"

class Company {
private:
	Employee* employees; //dynamic array of employee structs
	int capacity;
	int count;

public:
	//constructor
	Company(int cap);

	//copy const
	Company(const Company& other);

	//Assignment operator
	Company& operator=(const Company& other);

	//Destructor
	~Company();

	//Member functions
	void addEmployee(int id, const char* name, double salary);
	void displayEmployees() const;
	double calculateAverageSalary() const;
};

#endif
