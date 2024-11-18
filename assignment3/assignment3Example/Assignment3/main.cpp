//
//  main.cpp
//  EmpEXample
//
//  Created by Antoun, Sherine on 10/31/24.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "generateEmployeeData.hpp"

void updateEmployeeData(int empNumber);


int main()
{
    generateEmployeeData();
    
    int choice = 4;
    std::cout << "1. Generate Employee Data\n";
    std::cout << "5. Update Employee Data\n";
    std::cout << "3. Print Employee Data\n";
    std::cout << "4. Exit Employee Management\n";
    
    std::cout << "Enter choice: ";
    std::cin >> choice;
    while (choice >0 && choice <5)
    {
        if (choice == 1)
        {
            generateEmployeeData();
        }
        else if (choice == 3)
        {
            printEmployeeData();
        }
        
        else if (choice == 4)
        {
            std::cout << "Terminating...\n";
            return 0;
        }
        std::cout << "Enter choice: ";
        std::cin >> choice;
    }
    
    int empNumber;
    std::cout << "Enter employee number to update (1 - " << MAX_EMPLOYEES << "): ";
    std::cin >> empNumber;
    
    if (empNumber < 1 || empNumber > MAX_EMPLOYEES)
    {
        std::cerr << "Invalid employee number.\n";
        return 1;
    }
    
    updateEmployeeData(empNumber);
    printEmployeeData();
    return 0;
}


void updateEmployeeData(int empNumber)
{
    std::fstream file("employee_data.dat", std::ios::in | std::ios::out | std::ios::binary);
    
    if (!file)
    {
        std::cerr << "Error opening file for updating.\n";
        return;
    }
    
    Employee emp;
    int recordSize = sizeof(Employee);
    int position = (empNumber - 1) * recordSize; // Calculate position in the file for random access
    
    // Move to the specified employee record for reading
    file.seekg(position);
    file.read(reinterpret_cast<char*>(&emp), recordSize);
    
    if (file.gcount() == 0)
    {
        std::cerr << "Employee not found.\n";
        return;
    }
    
    // Prompt user for current week data
    int week;
    std::cout << "Enter current week number (1 - " << WEEKS_PER_YEAR << "): ";
    std::cin >> week;
    
    if (week < 1 || week > WEEKS_PER_YEAR)
    {
        std::cerr << "Invalid week number.\n";
        return;
    }
    
    // Fill in pay data
    PaySlip &currentPay = emp.weeklyPay[week - 1];
    std::cout << "Enter hours worked: ";
    std::cin >> currentPay.hoursWorked;
    std::cout << "Enter hourly rate: ";
    std::cin >> currentPay.hourlyRate;
    
    currentPay.taxWithheld = 0.16f * (currentPay.hoursWorked * currentPay.hourlyRate);
    currentPay.netPay = (currentPay.hoursWorked * currentPay.hourlyRate) - currentPay.taxWithheld;
    
    // Move the write pointer back to the start of the employee record
    file.seekp(position);
    file.write(reinterpret_cast<const char*>(&emp), recordSize);
    
    if (file)
    {
        std::cout << "Employee data updated successfully.\n";
    }
    else
    {
        std::cerr << "Error writing to file.\n";
    }
    file.close();
}
