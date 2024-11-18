//
//  main.cpp
//  Sorting
//
//  Created by Antoun, Sherine on 10/15/24.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000;  // Define the size of the list

// Function prototypes
void selectionSort(double arr[], int size, int &comparisons, int &swaps);
void insertionSort(double arr[], int size, int &comparisons, int &swaps);
void bubbleSort(double arr[], int size, int &comparisons, int &swaps);
void generateRandomList(double arr[], int size);
void saveToFile(const double arr[], int size, const char* filename);

int main() {
    double list[SIZE];  // List to hold the random doubles
    int comparisons, swaps;

    // Generate the list and run each sort, reporting the results
    generateRandomList(list, SIZE);

    // Selection Sort
    double selectionList[SIZE];
    std::copy(list, list + SIZE, selectionList);
    comparisons = swaps = 0;
    selectionSort(selectionList, SIZE, comparisons, swaps);
    std::cout << "Selection Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << std::endl;
    saveToFile(selectionList, SIZE, "selection.txt");

    // Insertion Sort
    double insertionList[SIZE];
    std::copy(list, list + SIZE, insertionList);
    comparisons = swaps = 0;
    insertionSort(insertionList, SIZE, comparisons, swaps);
    std::cout << "Insertion Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << std::endl;
    saveToFile(insertionList, SIZE, "insertion.txt");

    // Bubble Sort
    double bubbleList[SIZE];
    std::copy(list, list + SIZE, bubbleList);
    comparisons = swaps = 0;
    bubbleSort(bubbleList, SIZE, comparisons, swaps);
    std::cout << "Bubble Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << std::endl;
    saveToFile(bubbleList, SIZE, "bubble.txt");

    return 0;
}

// Function to perform selection sort
void selectionSort(double arr[], int size, int &comparisons, int &swaps) {
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

// Function to perform insertion sort
void insertionSort(double arr[], int size, int &comparisons, int &swaps) {
    for (int i = 1; i < size; ++i) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Function to perform bubble sort
void bubbleSort(double arr[], int size, int &comparisons, int &swaps) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;  // Exit if no swaps were made, indicating the array is sorted
    }
}

// Function to generate a random list of doubles
void generateRandomList(double arr[], int size) {
    std::srand(static_cast<unsigned int>(std::time(0)));  // Seed random number generator
    for (int i = 0; i < size; ++i) {
        arr[i] = (std::rand() % 10000) / 100.0;  // Generate random doubles between 0.0 and 99.99
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
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}
