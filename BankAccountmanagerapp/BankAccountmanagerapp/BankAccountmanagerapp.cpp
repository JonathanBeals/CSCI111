#include <iostream>
#include <fstream>

struct Account {
	int accountNumber;
	char ownerName[50];
	double balance;

};

bool searchAccount(std::ifstream& inFile, int accNum);
void addAccount(std::ofstream& outFile);

int main() {

	std::ofstream outFile("accounts.dat", std::ios::binary | std::ios::app);
	std::ifstream inFile("accounts.dat", std::ios::binary);

	int choice;

	std::cout << "1. Add account\n2. Search account\n3. Exit\nEnter choice: ";
	std::cin >> choice;

	if (choice == 1) {
		addAccount(outFile);
	}
	else if (choice == 2) {
		int accNum;
		std::cout << "Enter account number: \n";
		std::cin >> accNum;
		searchAccount(inFile, accNum);
	}
	else {
		std::cout << "Thank you for using Account Manager \n\n";
		outFile.close();
		inFile.close();
		return 0;
	}
	



	return 0;
}

bool searchAccount(std::ifstream& inFile, int accNum) {
	Account acc;

	inFile.seekg(0);
	while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
		if (acc.accountNumber == accNum) {
			std::cout << "Account Found: " << acc.ownerName << ", Balance is: " <<
				acc.balance << std::endl;
			return true;
		}
	}
	std::cout << "Account not found!\n";
	return false;
}

void addAccount(std::ofstream& outFile) {
	Account newAcc;

	std::cin.ignore();
	std::cout << "Please enter account holder's name: ";
	std::cin.getline(newAcc.ownerName, 50);
	std::cout << "Please enter the account opening balance: ";
	std::cin >> newAcc.balance;
	std::cout << "Please enter account number: ";
	std::cin >> newAcc.accountNumber;
	outFile.write(reinterpret_cast<char*>(&newAcc), sizeof(Account));
}