#include <iostream>
#include <cstdlib>
#include <cctype>

class CipherWheel {
private:
	char* wheel; // Dynamic array for the cipher wheel

	int size; // Number of characters in the wheel

	int position; // Current position of the cipher wheel

	// Converts a character to its 0- based index (A=0, B=1, etc .)
	int charToIndex(char c);

	// Converts a 0- based index back to a character
	char indexToChar(int index);

public:
	// Constructor : Create the cipher wheel dynamically
	CipherWheel(int wheelSize) : size(wheelSize), position(0);

	// Destructor : Free the dynamic memory
	~CipherWheel();

	// Set the starting position of the wheel
	void setPosition(int startPos);

	// Encrypt a single character
	char encryptChar(char c);

	// Decrypt a single character
	char decryptChar(char c);
};

class DynamicArray {
	int* encypt;
	int 
	DynamicArray(int );
};


int menu();

int main() {

	int userChoice = menu();

	switch (userChoice) {
	case 1:
		std::cout << "You have chosen to encrypt a message\n";
		break;
	case 2:
		std::cout << "You have chosen to decrypt a message\n";
		break;
	case 3:
		std::cout << "Program is exiting!";
		break;
	}
	return 0;
}

int menu() {
	int choice;
	while (true) {
		std::cout << "Welcome to the Enigma Wheel cipher\n"
			<< "1. Encrypt a message.\n"
			<< "2. Decrypt a message.\n"
			<< "3. Exit the program.\n"
			<< "Enter choice: " << std::endl;
		std::cin >> choice;
	}
	if (menu >= 1 && menu <= 3) {
		return choice;
	}
	else {
		std::cout << "Invalid choice, try again\n";
	}
}