#include <iostream>

using namespace std;

int main()
{
    int numSharesSold;
    double purchasePricePerShare, sellingPricePerShare;
    double amountInvested, totalServiceCharges, amountGainedOrLost, amountReceived;

    cout << "Enter number of shares sold: ";
    cin >> numSharesSold;

    cout << "Enter the purchase price per share: $ ";
    cin >> purchasePricePerShare;

    cout << "Enter selling price per share: $ ";
    cin >> sellingPricePerShare;

    amountInvested = numSharesSold * purchasePricePerShare;

    totalServiceCharges = 0.015 * (amountInvested + numSharesSold * sellingPricePerShare);

    amountReceived = numSharesSold * sellingPricePerShare - totalServiceCharges;

    amountGainedOrLost = amountReceived - amountInvested;

    cout << "Amount invested: $" << amountInvested << endl;
    cout << "Total service charges: $" << totalServiceCharges << endl;
    cout << "Amount gained or lost: $" << amountGainedOrLost << endl;
    cout << "Amount Received after selling the stock $" << amountReceived << endl;

    return 0;
}
