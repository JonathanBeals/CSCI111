#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

//Enumerate
enum mode[ENCRYPT, DECRYPT];
enum CipherType[CAESAR, ATBASH];

//Function prototypes
char caesarCipher(text[], key, mode);
char atBashCipher(text[], mode);
char processMessage(inputFile, cipherTypes[], cipherCount, caesarKey, mode);


//Main function
int main() {
	string inputFile[50], outputFile[50];
	int modeChoice, cipherCount, caesarKey; // not sure if int
	int CipherType[5];

	std::cout << "Enter input file name: ";
	std::cin >> inputFile;
	std::ifstream inputFile(inputFile, std::ios::binary);
	std::cout << "Enter output file name: ";
	std::cin >> outputFile;
	std::ofstream outputFile(outputFile, std::ios::binary);
	std::cout << "Choose mode (1: Encrypt, 2:Decrypt): ";
	std::cin >> modeChoice;
	std::cout << "Enter number of transformations: ";
	std::cin >> cipherCount;

	for (int i = 0; i < cipherCount; i++) {
		std::cout << "Choose transformation i + 1 (1: Caesar, 2: Atbash): ";
		std::cin >> caesarKey;

		if (ciphers[i] = caesarKey)
			std::cout << "Enter caesar cipher key (1-25): "
			
	}

	return 0;
 }


//Functions
char caesarCipher(text[], key, mode) {
	if(isaplha(text[i]))
}

char atBashCipher(text[], mode) {

}

char processMessage(inputFile, cipherTypes[], cipherCount, caesarKey, mode) {

}