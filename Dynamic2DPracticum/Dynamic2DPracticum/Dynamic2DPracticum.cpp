#include <iostream>

using namespace std;

int main() {

	int rows = 3;
	int cols = 4;
	int** grades = new int* [rows]; //allocate rows

	for (int i = 0; i < rows; i++) {
		grades[i] = new int[cols]; //allocate columns
	}

	//assign and display an example value
	grades[0][0] = 75;
	cout << "Grade at (0,0): " << grades[0][0] << endl;

	cout << "Please enter values for grades:";
	cin >> grades[0][0];

	cout << grades[0][0] << endl;

	//deallocate memory
	for (int i = 0; i < rows; i++) {
		delete[] grades[i];
	}
	delete[] grades;

	return 0;
}