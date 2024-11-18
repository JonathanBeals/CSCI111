// Made by Jonathan Beals
// CSCI 111
// Professor Sherine Antoun
// 10/20/2024

// This program is meant to open a file named task1.txt, read all the data,
// calculate the average grade for the student, and display the students scores,
// as well as the class average, and just for fun the class grade as a whole.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Set the max number of students
const int MAX_STUDENTS = 50;
const int NUM_SCORES = 5;

void readAndStoreData(string name[], int scores[][NUM_SCORES], int& count);
void calculateAverageAndGrade(const string name[], const int scores[][NUM_SCORES], double averages[], char grades[], int count);
double calculateClassAverage(const double averages[], int count);
char calculateClassGrade(double classAverage);
void outputResults(const string name[], const double averages[], const char grades[], int studentCount, double classAverage, char classGrade);

int main() {
    string name[MAX_STUDENTS];
    int scores[MAX_STUDENTS][NUM_SCORES];
    double averages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];
    int studentCount = 0;

    readAndStoreData(name, scores, studentCount);
    calculateAverageAndGrade(name, scores, averages, grades, studentCount);

    // Calculate class average and grade
    double classAverage = calculateClassAverage(averages, studentCount);
    char classGrade = calculateClassGrade(classAverage);

    // Output results
    outputResults(name, averages, grades, studentCount, classAverage, classGrade);

    return 0;
}

// Function to read and store data from the file
void readAndStoreData(string name[], int scores[][NUM_SCORES], int& count) {
    ifstream inFile("task1.txt");

    if (!inFile) {
        cerr << "Error opening the file." << endl;
        exit(1);
    }

    while (count < MAX_STUDENTS) {
        inFile >> name[count];
        if (inFile.fail()) break;

        // Read scores for the current student
        for (int j = 0; j < NUM_SCORES; j++) {
            inFile >> scores[count][j];
            if (inFile.fail()) break;
        }

        // Check if all scores were read successfully
        if (inFile.fail()) break;

        count++;
    }

    inFile.close();
}

// Function to calculate avg score and assign grade
void calculateAverageAndGrade(const string name[], const int scores[][NUM_SCORES], double averages[], char grades[], int count) {
    for (int i = 0; i < count; i++) {
        int totalScore = 0;

        // Calculate the total score for the current student
        for (int j = 0; j < NUM_SCORES; j++) {
            totalScore += scores[i][j];
        }

        // Calculate the average score
        averages[i] = static_cast<double>(totalScore) / NUM_SCORES;

        // Assign grades based on the average score
        if (averages[i] >= 90) {
            grades[i] = 'A';
        }
        else if (averages[i] >= 80) {
            grades[i] = 'B';
        }
        else if (averages[i] >= 70) {
            grades[i] = 'C';
        }
        else if (averages[i] >= 60) {
            grades[i] = 'D';
        }
        else {
            grades[i] = 'F';
        }
    }
}

// Function to calculate class average
double calculateClassAverage(const double averages[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += averages[i];
    }
    return total / count;
}

// Function to calculate class grade
char calculateClassGrade(double classAverage) {
    if (classAverage >= 90) {
        return 'A';
    }
    else if (classAverage >= 80) {
        return 'B';
    }
    else if (classAverage >= 70) {
        return 'C';
    }
    else if (classAverage >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

// Function to output results
void outputResults(const string name[], const double averages[], const char grades[], int studentCount, double classAverage, char classGrade) {
    cout << fixed << setprecision(2);
    cout << "\nStudent  |  Average Score | Grade\n";
    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(15) << name[i] << setw(14) << averages[i] << setw(12) << grades[i] << endl;
    }

    cout << "\nClass Average: " << classAverage << endl;
    cout << "Class Grade: " << classGrade << endl;
}