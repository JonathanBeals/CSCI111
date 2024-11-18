#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double TAX_RATE = 0.14;
    const double CLOTHES_PERCENTAGE = 0.10;
    const double SCHOOL_SUPPLIES_PERCENTAGE = 0.01;
    const double SAVING_BONDS_PERCENTAGE = 0.25;
    const double PARENTS_MATCH = 0.50;

    //variables
    double payRatePerHour;
    int hoursWorkedPerWeek;
    int totalWeeks;
    double incomeBeforeTax, incomeAfterTax;
    double closthesExpenses,schoolSuppliesExpenses;
    double savingsBondsExpenses,parentsSavingsBonds;

    cout << "enter pay rate";
    cin >> payRatePerHour;

    cout << "Enter number of hours per week";
    cin >> hoursWorkedPerWeek;

    cout << "enter total weeks worked ";
    cin >> totalWeeks;

    //calculate before tax
    incomeBeforeTax = payRatePerHour * hoursWorkedPerWeek * totalWeeks;

    //after tx
    incomeAfterTax = incomeBeforeTax * (1- TAX_RATE);

    //calculate expenses
    closthesExpenses = incomeAfterTax * CLOTHES_PERCENTAGE;
    schoolSuppliesExpenses = incomeAfterTax * SCHOOL_SUPPLIES_PERCENTAGE;
    savingsBondsExpenses = (incomeAfterTax - closthesExpenses- schoolSuppliesExpenses)
        * SAVING_BONDS_PERCENTAGE;

    parentsSavingsBonds = savingsBondsExpenses * PARENTS_MATCH;

    // output results
    cout << fixed << setprecision(2);
    cout << "\nIncome Before tax: $" << incomeBeforeTax << endl;
    cout << "\nIncome after tax: $ " << incomeAfterTax << endl;
    cout << "Money spent on clothes: $" << closthesExpenses << endl;
    cout << "money spent on school supplies " << schoolSuppliesExpenses << endl;
    cout << "Money spend on savings bonds " << savingsBondsExpenses << endl;
    cout << "Money parents spent on savings bonds $" << parentsSavingsBonds << endl;




    return 0;
}
