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
		for (int i = 0; i < 26; i++) {
			char A = 0, B = 1, C = 2; // Not correct, rework
			c++;
		}
	}

	// Converts a 0- based index back to a character
	char indexToChar(int index);

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
	c = toupper(c);

	int index = charToIndex(c);
	int newIndex = (index + position) % size;
	char encryptedChar = indexToChar(newIndex);
	position = (position + 1) % size;
	return encryptedChar;
}

char CipherWheel::decryptChar(char c) {
	if (!isalpha(c)) {
		return c;
	}
	c = tolower(c);
	int index = charToIndex(c);
	int newIndex = (index - position) % size;
	char decryptedChar = indexToChar(newIndex);
	position = (position - 1 + size) % size;
	return decryptedChar;

}

int menu();

int main() {

	int userChoice = menu();
	int startingPosition;
	std::string encryptedMessage;

	if (userChoice == 1) {

		//Encrypt the message
		std::cout << "You have chosen to encrypt a message\n"
			<< "Enter a starting position";
		std::cin >> startingPosition;
		std::cout << "Enter message: ";
		std::string message;
		std::cin.ignore();
		std::getline(std::cin, message);
		CipherWheel wheel(26);
		wheel.setPosition(startingPosition);
		std::cout << "Encrypted message: \n";
	}
	else if (userChoice == 2) {
		//Decrypt the message
		std::cout << "You have chosent to decrypt a message\n"
			<< "Enter a starting position";
		std::cin >> startingPosition;
		std::cout << "Enter encrypted message: ";
		std::string encryptedMessage;
		std::cin.ignore();
		std::getline(std::cin, encryptedMessage);
		CipherWheel wheel(26);
		wheel.setPosition(startingPosition);
		std::cout << "Decrypted message: \n";
	}
	else {
		std::cout << "Thanks for using the Enigma Cipher wheel!";
	}
return 0;
}

int menu() {
	int menuChoice;
	while (true) {
		std::cout << "Welcome to the Enigma Wheel cipher\n"
			<< "1. Encrypt a message.\n"
			<< "2. Decrypt a message.\n"
			<< "3. Exit the program.\n"
			<< "Enter choice: ";
		std::cin >> menuChoice;

		if (menuChoice >= 1 && menuChoice <= 3) {
			return menuChoice;
		}
		else {
			std::cout << "Invalid choice, try again\n";
		}
	}
}