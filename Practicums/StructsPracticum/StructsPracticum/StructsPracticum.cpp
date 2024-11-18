//
//  sales.cpp
//  Sales
//
//  Created by Antoun, Sherine on 10/9/24.
//
//Instructions:
//initialize: Add the loop logic to read salesperson IDs into the array salesPersons.
//processSalesData: Complete the loop to process each sale, identify the salesperson, and update the quarterly sales.
//calculateTotalSales: Fully implement this function to sum up quarterly sales into the totalSales for each salesperson.
//calculateQuarterlyTotals: Partially implemented, complete the missing logic if needed.
//printReport: Implement the loop to output the sales data, quarterly totals, and other necessary parts of the report.
//maxSaleByPerson: Implement the logic to find and return the index of the salesperson with the maximum sales.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Struct to hold salesperson data
struct SalesPerson {
    int id;
    double quarterlySales[4] = { 0.0 }; // Quarterly sales initialized to 0
    double totalSales = 0.0;          // Total annual sales initialized to 0
};

// Function declarations
void initialize(SalesPerson salesPersons[], int size, const char* idFileName);
void processSalesData(SalesPerson salesPersons[], int size, double quarterlyTotal[], const char* salesFileName);
void calculateTotalSales(SalesPerson salesPersons[], int size); // Function prototype only
void calculateQuarterlyTotals(SalesPerson salesPersons[], int size, double quarterlyTotal[]);
void printReport(const SalesPerson salesPersons[], int size, const double quarterlyTotal[], const char* outputFileName);
int maxSaleByPerson(const SalesPerson salesPersons[], int size);
int maxSaleByQuarter(const double quarterlyTotal[]);

int main(int argc, const char* argv[]) {
    // Check if correct number of arguments is provided
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <Salesperson ID File> <Sales Data File> <Output Report File>" << endl;
        return 1;
    }

    const char* idFileName = argv[1];
    const char* salesFileName = argv[2];
    const char* outputFileName = argv[3];

    const int size = 6;
    SalesPerson salesPersons[size];
    double quarterlyTotal[4] = { 0.0 }; // Array to hold total sales per quarter

    // Initialize salespersons data from ID file
    initialize(salesPersons, size, idFileName);

    // Process sales data and update salesPersons and quarterlyTotal
    processSalesData(salesPersons, size, quarterlyTotal, salesFileName);

    // Calculate total sales by salesperson
    calculateTotalSales(salesPersons, size); // Please complete this function

    double totalSales = 0.0;{
    for (int i = 0; i < salesPersons[i]; i++)
        {
            totalSales += salesPersons[i].quarterlySales;
        }
        return totalSales;
    }


    // Calculate total sales by quarter
    calculateQuarterlyTotals(salesPersons, size, quarterlyTotal); // Please complete missing parts

    // Print the annual sales report
    printReport(salesPersons, size, quarterlyTotal, outputFileName);

    return 0;
}

// Function to initialize the salespersons array with IDs from file
void initialize(SalesPerson salesPersons[], int size, const char* idFileName) {
    ifstream inFile(idFileName);
    if (!inFile) {
        cerr << "Error opening ID file." << endl;
        exit(1);
    }
    // You need to complete the loop to read IDs into salesPersons array
    for (int i = 0; i < size; i++) {
        // ...
        inFile >> salesPersons[i].id;
    }
    inFile.close();
}

// Function to process sales data and update quarterly sales
void processSalesData(SalesPerson salesPersons[], int size, double quarterlyTotal[], const char* salesFileName) {
    ifstream inFile(salesFileName);
    if (!inFile) {
        cerr << "Error opening Sales Data file." << endl;
        exit(1);
    }
    int id, month;
    double saleAmount;
    // Complete the loop to read and process sales data
    while (inFile >> id >> month >> saleAmount) {
        for (int i = 0; i < size; i++) {
            if (salesPersons[i].id == id) {
                //determine quarter based on month
                int quarter = (month - 1) / 3;
                    salesPersons[i].quarterlySales[quarter] += saleAmount;
                break;
            }

        }
    }
    inFile.close();
}

// Function to calculate the total sales for each salesperson
// You need to fully implement this function
void calculateTotalSales(SalesPerson salesPersons[], int size) {
    // fixed
    for (int q = 0; q < 4; q++) {
        for (int i = 0; i < size; i++) {
            quarterlyTotal[q] += salesPersons[i].quarterlySales[q];
        }
    }
    // Placeholder for loop logic to compute total sales per salesperson
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            quarterlyTotal[q] += salesPersons[i].quarterlySales[j];
        }
    }
}

// Function to calculate the total sales for each quarter
void calculateQuarterlyTotals(SalesPerson salesPersons[], int size, double quarterlyTotal[]) {
    // Loop partially completed - fill in missing logic
    //good to go!
    for (int q = 0; q < 4; q++) {
        for (int i = 0; i < size; i++) {
            quarterlyTotal[q] += salesPersons[i].quarterlySales[q]; // You should adjust as needed
        }
    }
}

// Function to print the sales report to an output file
void printReport(const SalesPerson salesPersons[], int size, const double quarterlyTotal[], const char* outputFileName) {
    ofstream outFile(outputFileName);
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        exit(1);
    }
    outFile << "----------- Annual Sales Report -------------" << endl;
    outFile << "ID       QT1       QT2       QT3       QT4       Total" << endl;
    outFile << "---------------------------------------------------------" << endl;

    // Please implement loop to output data for each salesperson
    // and calculate and output the grand total for each quarter.

    outFile.close();
}

// Function to find the salesperson with the maximum sales
// You need to fully implement this function
int maxSaleByPerson(const SalesPerson salesPersons[], int size) {
    int maxIdx = 0;
    // Logic to determine the maximum salesperson needs to be added by yourself
    return maxIdx;
}

// Function to find the quarter with the maximum sales
// Partially implemented, please complete the logic
int maxSaleByQuarter(const double quarterlyTotal[]) {
    int maxIdx = 0;
    for (int i = 1; i < 4; i++) {
        if (quarterlyTotal[i] > quarterlyTotal[maxIdx]) {
            maxIdx = i;
        }
    }
    cout << "The most profitable quarter sales were:$" << quarterlySalesTotal[maxIdx] << endl;
    return maxIdx;
}
