#include <iostream>

using namespace std;


//Struct for fractions
struct Fraction {
	int num;
	int denom;
};

//Function for finding greatest common denominator (adding and subtracting)
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

//Function for finding least common multiples (multiplication and division)
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

Fraction simplify(Fraction f) {
	int comDiv = gcd(f.num, f.denom);
	f.num /= comDiv;
	f.denom /= comDiv;
	return f;
}

//Function for printing
void printResult(Fraction f) {
	cout << f.num << "/" << f.denom << endl;
}

//Function to add fractions
Fraction addition(Fraction f1, Fraction f2) {
	Fraction result;
	int lcd = lcm(f1.denom, f2.denom);
	result.num = f1.num * (lcd / f1.denom) + f2.num * (lcd / f2.denom);
	result.denom = lcd;
	return simplify(result);
}

//Function to subtract fractions
Fraction subtraction(Fraction f1, Fraction f2) {
	Fraction result;
	int lcd = lcm(f1.denom, f2.denom);
	result.num = f1.num * (lcd / f1.denom) - f2.num * (lcd / f2.denom);
	result.denom = lcd;
	return simplify(result);
}

//Function to multiply fractions
Fraction multiplication(Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.num;
	result.denom = f1.denom * f2.denom;
	return simplify(result);
}

//Function to divide fractions
Fraction division(Fraction f1, Fraction f2) {
	if (f2.num == 0) {
		cout << "Error, cannot devide by 0" << endl;
		return { 0, 1 };
	}
	Fraction result;
	result.num = f1.num * f2.denom;
	result.denom = f1.denom * f2.num;
	return simplify(result);
}

int main() {
	Fraction frac1, frac2, result;
	int menu;
	
	//Prompt user to select operation
	for (int i = 0; i < 100; i++) {
		cout << "Enter a number to choose an operation:\n" <<
			"1. addition\n" <<
			"2. subtraction\n" <<
			"3. multiplication\n" <<
			"4. division\n" <<
			"5. to exit\n" << endl;
		cin >> menu;

		if (menu == 5) {
			cout << "Thanks for using my fraction calculator!" << endl;
			break;
		}
		if (menu < 1 || menu > 5) {
			cout << "Invalid menu choice, try again" << endl;
			continue;
		}
		//Input numerator and denominator for frac 1 and frac2
		cout << "Please enter Fraction 1's numerator:\n ";
		cin >> frac1.num;
		cout << "\nPlease enter Fraction 1's denominator: \n";
		cin >> frac1.denom;
		cout << "\nPlease enter Fraction 2's numerator:\n ";
		cin >> frac2.num;
		cout << "\nPlease enter Fraction 2's denominator: \n";
		cin >> frac2.denom;

		//Check if denom is undefined

		if (frac1.denom == 0) {
			cout << "Denominator is undefined." << endl;
			continue;
		}

		if (frac2.denom == 0) {
			cout << "Denominator is undefined." << endl;
			continue;
		}

		//Use switch to handle menu options and user input 


		switch (menu) {
		case 1:
			result = addition(frac1, frac2);
			break;
		case 2:
			result = subtraction(frac1, frac2);
			break;
		case 3:
			result = multiplication(frac1, frac2);
			break;
		case 4:
			result = division(frac1, frac2);
			break;

		default:
			cout << "Invalid input" << endl;
			return 1;
		}

		//Call function to print results
		printResult(result);

	}

	return 0;
}