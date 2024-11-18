#include <iostream>

using namespace std;

class Cinema {
private:
	int** seats;
	int rows;
	int cols;

public:
	//Constructors allocating 2d arrays and int to 0
	Cinema(int r = 5, int c = 10) : rows(r), cols(c) {
		seats = new int* [rows];
		for (int i = 0; i < rows; ++i) {
			seats[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				seats[i][j] = 0;
			}
		}
	}
	//destructor
	~Cinema() {
		for (int i = 0; i < rows; i++) {
			delete[] seats[i];
		}
		delete[] seats;
	}

	//Reserve seat
	void reserveSeat(int row, int cols) {
		if (row >= 0 && row < rows && col >= 0 && col < cols) {
			if (seats[row][cols] == 0) {
				seats[row][cols] = 1;
				cout << "seat at (" << row < ", " col << ") reserved successfully \n";

			}
		}
		else {
			cout << "Invalid seat postition.\n";
		}
	}

	void displaySeating() {
		cout << "Cinema Seating arrangment:\n";
		for (int i = 0 i < rows; i++) {

		}
	}

};