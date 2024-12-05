#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

class CipherWheel {
private:
	char* wheel; // Dynamic array for the cipher wheel

	int size; // Number of characters in the wheel

	int position; // Current position of the cipher wheel

	// Converts a character to its 0- based index (A=0, B=1, etc .)
	int charToIndex(char c) {
		if (isalpha(c)) {
			return toupper(c) - 'A';
		}
		else {
			return -1;
		}
	}

	// Converts a 0- based index back to a character
	char indexToChar(int index) {
		if (index >= 0 && index < 26) {
			return 'A' + index;
		}
		else {
			return '?';
		}
	}

public:
	// Constructor : Create the cipher wheel dynamically
	CipherWheel(int wheelSize) : size(wheelSize), position(0) {
		wheel = new char[size];

		for (int i = 0; i < size; i++) {
			wheel[i] = 'A' + (i % 26);
		}
	}

	// Destructor : Free the dynamic memory
	~CipherWheel() {
		delete[] wheel;
	}

	// Set the starting position of the wheel
	void setPosition(int startPos);

	// Encrypt a single character
	char encryptChar(char c);

	// Decrypt a single character
	char decryptChar(char c);
};

void CipherWheel::setPosition(int startPos) {
	position = startPos % size;
}

char CipherWheel::encryptChar(char c) {
	if (!isalpha(c)) {
		return c;
	}
	bool isLower = islower(c);
	c = toupper(c);

	int index = charToIndex(c);
	int newIndex = (index + position) % size;
	char encryptedChar = indexToChar(newIndex);
	position = (position + 1) % size;
	return isLower ? tolower(encryptedChar) : encryptedChar;
}

char CipherWheel::decryptChar(char c) {
	if (!isalpha(c)) {
		return c;
	}
	bool isLower = islower(c);
	c = toupper(c);

	int index = charToIndex(c);
	int newIndex = (index - position + size) % size;
	char decryptedChar = indexToChar(newIndex);
	position = (position + 1) % size;
	return isLower ? tolower(decryptedChar) : decryptedChar;;

	
}

int menu() {
	int menuChoice;
	while (true) {
		std::cout 
			<< "----------------------------------\n"
			<< "Welcome to the Enigma Wheel cipher\n"
			<< "1. Encrypt a message.\n"
			<< "2. Decrypt a message.\n"
			<< "3. Exit the program.\n"
			<< "----------------------------------\n"
			<< "Enter choice: ";
		std::cin >> menuChoice;

		if (menuChoice >= 1 && menuChoice <= 3) {
			return menuChoice;
		}
		else {
			std::cout << "Invalid choice, try again\n" 
				<< "----------------------------------\n";
		}
	}
}

int main() {

	while (true) {
		int userChoice = menu();
		//Exit program
		if (userChoice == 3) {
			std::cout << "Thanks for using the Enigma Cipher wheel!" << std::endl;
			break;
		}
		int startingPosition;
		std::string message;

		if (userChoice == 1) {

			//Encrypt the message
			std::cout << "You have chosen to encrypt a message\n"
				<< "----------------------------------\n"
				<< "Enter a starting position: ";
			std::cin >> startingPosition;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (startingPosition < 1 || startingPosition > 26) {
				std::cout << "Invalid position. Please enter a value between 1 and 26\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cout << "----------------------------------\n" 
				<< "Enter message: ";
			
			std::getline(std::cin, message);

			CipherWheel wheel(26);
			wheel.setPosition(startingPosition - 1);

			std::cout << "Encrypted message: ";
			for (char c : message) {
				std::cout << wheel.encryptChar(c);
			}
			std::cout << std::endl;
		}
		else if (userChoice == 2) {

			//Decrypt the message
			std::cout << "You have chosen to decrypt a message\n"
				<< "Enter the starting position: ";
			std::cin >> startingPosition;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (startingPosition < 1 || startingPosition > 26) {
				std::cout << "Invalid position. Please enter a value between 1 and 26\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			

			std::cout << "Enter message: ";
			std::getline(std::cin, message);

			CipherWheel wheel(26);
			wheel.setPosition(startingPosition - 1);

			std::cout << "Decrypted message: ";
			for (char c : message) {
				std::cout << wheel.decryptChar(c);
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
