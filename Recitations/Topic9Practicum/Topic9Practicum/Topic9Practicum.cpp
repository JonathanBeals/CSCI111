#include <iostream>
#include <string>

using namespace std;

const int SIZE = 20;

struct Student {
	string studentName;
	int score;
};

//Function prototypes
void insertionSort(double student[], int SIZE, int score);
void bubbleSort(double student[], int SIZE, int score);

int main()
{
    string studentName;
    int studentScore;
    
    cout << "Enter student name: ";
    cin >> studentName;
    cout << "Enter student score: ";
    cin >> studentScore;

    // Insertion Sort
    double insertionList[SIZE];
    copy(list, list + SIZE, insertion list)
    insertionSort(insertionList, SIZE);

    // Bubble Sort
    double bubbleList[SIZE];
    bubbleSort(bubbleList, SIZE);


    //Display to user
     

    return 0;
}

// Function to perform insertion sort
void insertionSort(double arr[], int size, int& comparisons, int& swaps) {
    for (int i = 1; i < size; ++i) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Function to perform bubble sort
void bubbleSort(double arr[], int size, int& comparisons, int& swaps) {
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

