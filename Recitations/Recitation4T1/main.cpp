#include <iostream>

using namespace std;

const int numSalespersons = 5;
const int numWidget = 3;

int main()
{
    int totalSalesperson1 =0,  totalSalesperson2 =0, totalSalesperson3 =0,totalSalesperson4 =0,totalSalesperson5 =0;

    for (int salesPerson = 1; salesPerson <= numSalespersons; ++salesPerson)
    {
        //Outer loop for each
        int totalSalespersonCurrent = 0;

        // Inner loop for widget
        for (int widget =1; widget <= numWidget; ++widget)
        {
            int widgetSales;
            cout << "Enter sales for Salesperson" << salesPerson << ", Widget <<  widget << ": ";
            totalSalespersonCurrent += widgetSales;
        }

        switch (salesPerson)
        {
        case 1:
            totalSalesperson1 = totalSalespersonCurrent;
            break;
        case 2:
            totalSalesperson2 = totalSalespersonCurrent;
            break;
        case 3:
            totalSalesperson3 = totalSalespersonCurrent;
            break;
        case 4:
            totalSalesperson4 = totalSalespersonCurrent;
            break;
        case 5:
            totalSalesperson5 = totalSalespersonCurrent;
            break;
        default:
            break;
        }
    }
    cout << "\nDaily Sales Report:\n";
    cout << "Salesperson 1 total sales: " << totalSalesperson1 << "\n":
    cout << "Salesperson 2 total sales: " << totalSalesperson2 << "\n":
    cout << "Salesperson 3 total sales: " << totalSalesperson3 << "\n":
    cout << "Salesperson 4 total sales: " << totalSalesperson4 << "\n":
    cout << "Salesperson 5 total sales: " << totalSalesperson5 << "\n":





    return 0;
}
