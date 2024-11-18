#include <iostream>

using namespace std;

const int secondsInHour = 3600;
const int secondsInMinute = 60;

int main()
{
    double originalPrice;
    double markedUpPercentage;
    double salesTaxRate;
    double sellingPrice;
    double salesTax;
    double finalPrice;

    cout << "Enter the original price of the item: ";
    cin >> originalPrice;
    cout << endl;

    cout << "Enter the marked up percentage: ";
    cin >> markedUpPercentage;
    cout << endl;

    cout << "Enter the sales tax rate: ";
    cin >> salesTaxRate;
    cout << endl;

    sellingPrice = originalPrice + (originalPrice * markedUpPercentage / 100);
    salesTax = sellingPrice * salesTaxRate / 100;
    finalPrrice = sellingPrice + salesTax;

    cout << "The original price = $" << originalPrice << endl;
    cout << "The price is marked up by $" << markedUpPercentage << endl;
    cout << "The selling price = $" << originalPrice << endl;




    return 0;
}


