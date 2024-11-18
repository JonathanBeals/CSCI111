#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
	int id;
	char name[30];
	double salary;

	employee() : id(0), salary(0.0) {
		name[0] = "\0"; // initialize
	}
};
#endif

