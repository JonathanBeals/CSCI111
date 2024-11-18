#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stock {
	char tag[5];
	int cost;
	long volume;

};

const int SIZE = 100;

void selectionSort(double arr[], int size);
void saveToFile(const double arr[], int size, const char* filename);


ifstream inFile("stockData.txt") // open file from instructor

if (!inFile) {
    cerr << "Error with opening the file." << endl;
    return 1;
}

int main() {

    // Selection Sort
    double selectionList[SIZE];
    selectionSort(selectionList, SIZE);
    cout << "Selection Sort Completed " << endl;
    saveToFile(selectionList, SIZE, "Data.txt"); 


	return 0;
}

// Function to perform selection sort
void selectionSort(double arr[], int size, int& comparisons, int& swaps) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

// Function to save the sorted list to a file
void saveToFile(const double arr[], int size, const char* filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << arr[i] << std::endl;
        }
        outFile.close();
    }
    else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}
