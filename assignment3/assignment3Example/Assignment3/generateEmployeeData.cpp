//
//  generateEmployeeData.cpp
//  EmpEXample
//
//  Created by Antoun, Sherine on 10/31/24.
//

#include "generateEmployeeData.hpp"
void generateEmployeeData()
{
   std::ofstream file("employee_data.dat", std::ios::binary);

   if (!file) {
       std::cerr << "Error creating file.\n";
       return;
   }

   Employee employees[MAX_EMPLOYEES];
   for (int i = 0; i < MAX_EMPLOYEES; ++i) {
       employees[i].employeeNumber = i + 1;
       std::strcpy(employees[i].firstName, "FirstName");
       std::strcpy(employees[i].lastName, "LastName");
       std::strcpy(employees[i].address, "123 Main St, City");
       std::strcpy(employees[i].phone, "123-456-7890");
       employees[i].hireDate = {1, 1, 2020};

       // Initialize weekly pay data to zero
       for (int j = 0; j < WEEKS_PER_YEAR; ++j) {
           employees[i].weeklyPay[j] = {0.0f, 0.0f, 0.0f, 0.0f};
       }

       file.write(reinterpret_cast<const char*>(&employees[i]), sizeof(Employee));
   }

   std::cout << "Employee data file created successfully.\n";
   file.close();
}

void printEmployeeData() {
    std::ifstream file("employee_data.dat", std::ios::binary);

    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }

    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        std::cout << "Employee Number: " << emp.employeeNumber << '\n'
                  << "First Name: " << emp.firstName << '\n'
                  << "Last Name: " << emp.lastName << '\n'
                  << "Address: " << emp.address << '\n'
                  << "Phone: " << emp.phone << '\n'
                  << "Hire Date: " << emp.hireDate.month << "/"
                  << emp.hireDate.day << "/" << emp.hireDate.year << "\n";

        // Displaying one week's data as a sample
        std::cout << "Sample Weekly Pay Data (Week 1):\n";
        std::cout << "Hours Worked: " << emp.weeklyPay[0].hoursWorked << '\n'
                  << "Hourly Rate: " << emp.weeklyPay[0].hourlyRate << '\n'
                  << "Tax Withheld: " << emp.weeklyPay[0].taxWithheld << '\n'
                  << "Net Pay: " << emp.weeklyPay[0].netPay << '\n';
        std::cout << "-----------------------------\n";
    }

    file.close();
}
