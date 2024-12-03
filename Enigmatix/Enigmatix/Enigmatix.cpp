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
	DynamicArray(int s);
};


int main() {

	int choice;

	std::cout << "Welcome to the Enigma Wheel cipher\n"
		<< "1. Encrypt a message.\n"
		<< "2. Decrypt a message.\n"
		<< "3. Exit the program. " << std::endl;

	std::cin >> choice;

	switch (choice) {
	case 1:
	case 2:
	case 3:
	}

	

	return 0;
}