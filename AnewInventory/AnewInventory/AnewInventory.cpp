#include <iostream>
#include <fstream>
#include <cstring>

#pragma pack(push, 1) //ensure no padding by OS to struct
struct Product {
	int id;
	char name[50];
	int quantity;
	double price;
		
};
#pragma pack(pop)

void readProducts(std::ifstream& inFile, Product products[], int& n);
void sortProducts(Product products[], int n);
void writeProducts(std::ofstream& outFile, Product products[], int n);



int main() {

	Product products[100];
	int n;
	std::ifstream inFile("inventory_50.dat", std::ios::binary);
	readProducts(inFile, products, n);
	inFile.close();

	sortProducts(products, n);

	std::ofstream outFile("Sorted_Inventory.dat", std::ios::binary);

	writeProducts(outFile, products, n);
	outFile.clear();

	return 0;
}

void sortProducts(Product products[], int n) {
	for (int i = 1; i < n; ++i) {
		Product key = products[i];
		int j = i - 1;
		while (j >= 0 && products[j].price > key.price) {
			products[j + 1] = products[j];
			j = j + 1;
		}
		products[j + 1] = key;
	}
}
void readProducts(std::ifstream& inFile, Product products[], int& n) {
	n = 0;
	while (inFile.read(reinterpret_cast<char*>(&products[n]), sizeof (Product))) {

		//ensure null termination of cstring
		products[n].name[sizeof(products[n].name) - 1] = '\0'; //'1' ' ' '1'o'
		std::cout << "Name was: " << products[n].name << '\t' << "ID was: " << products[n].id << '\n' <<
			" Quantity was: " << products[n].quantity << "Price was: " << products[n].price << '\n' << '\n';
		n++;
	}
}

void writeProducts(std::ofstream& outFile, Product products[], int n) {

	for (int i = 0; i < n; ++i) {
		products[i].name[sizeof(products[i].name) - 1] = '\0';
		outFile.write(reinterpret_cast<char*>(&products[i]), sizeof(Product));

		//debugging
		std::cout << "Name was: " << products[n].name << '\t' << "ID was: " << products[n].id << '\n' <<
			" Quantity was: " << products[n].quantity << "Price was: " << products[n].price << '\n' << '\n';
	}
	return;
}