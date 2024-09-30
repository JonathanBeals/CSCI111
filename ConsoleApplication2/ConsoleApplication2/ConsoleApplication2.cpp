#include <iostream>
#include <iomanip>
#include <fstream>

// CableBilling.cpp
// Calculate various customer accounts
// Created by Jonathan Beals
// September 17th 2024

using namespace std;

int main()
{
    // Assign values

    int bService, pChannels, numConnection;
    char accountType;
    double billingAmount = 0.00;
    double bBillingAmount = 0.00;

    const double billProcessingfee = 4.50, basicServiceFee = 20.50, premiumChannels = 7.50;
    const double bBillprocessingFee = 15.00, bBasicServiceFee = 75.00, bPremiumChannels = 50.00, bServiceConnections = 75.00;

    string residentialAccount, businessAccount;

    // Create txt file
    ofstream file("Bill.txt");

    // Get customer information
    cout << "Please enter account type \n";
    cout << "R for residential, B for business \n";
    cin >> accountType;

    if (accountType == 'R' || accountType == 'r')
    {
        cout << "\n---------------------------------------\n";
        cout << "Please enter your Residential account #: ";
        cin >> residentialAccount;
        cout << "Enter the number of premium channels you are subscribed to: \n";
        cin >> pChannels;

        // Outputting service costs
        cout << "\n---------------------------------------\n";
        cout << "Bill processing fee: " << setw(7) << fixed << setprecision(2) << "$" << billProcessingfee << "\nBasic Service fee: " << setw(9) << fixed << setprecision(2) << "$" << basicServiceFee << "\nPremium channels: " << setw(6) << fixed << setprecision(2) << pChannels << " @ $" << premiumChannels << endl;
        cout << "\n-------------------------------------\n";

        // Calculate Residential Billing
        billingAmount = billProcessingfee + basicServiceFee + (premiumChannels * pChannels);

        // Output total amount of cable bill for residential account
        cout << "Your total bill is: " << setw(8) << fixed << setprecision(2) << "$" << billingAmount << endl;

        // Write to txt file
        file << "Account number: #" << residentialAccount << "\n---------------------------------------\n"
            "\nBill processing fee: "
            << setw(13) << fixed << setprecision(2) << "$" << billProcessingfee << "\nBasic Service fee: " << setw(15) << fixed << setprecision(2) << "$" << basicServiceFee << "\nPremium channels: " << setw(12) << fixed << setprecision(2) << pChannels << " @ $" << premiumChannels << "\n---------------------------------------\n"
            "\nYour total bill is: "
            << setw(14) << fixed << setprecision(2) << "$" << billingAmount << endl;
    }

    // Get business customers info
    else if (accountType == 'B' || accountType == 'b')
    {
        cout << "\n---------------------------------------\n";
        cout << "Please enter your Business account # ";
        cin >> businessAccount;
        cout << "Enter the number of premium channels you are subscribed to: ";
        cin >> pChannels;
        cout << "Enter the total number of connections: ";
        cin >> numConnection;
        cout << "\n----------------------------------------\n";

        // Calculate business billing
        cout << "\n----------------------------------------\n";
        bBillingAmount = bBillprocessingFee + bBasicServiceFee + (bPremiumChannels * pChannels) + (bServiceConnections * numConnection);

        // Outputting service costs
        cout << "Bill processing fee: " << setw(7) << fixed << setprecision(2) << "$" << bBillprocessingFee << "\nBasic Service fee: " << setw(9) << fixed << setprecision(2) << "$" << bBasicServiceFee << "\nPremium channels: " << setw(6) << fixed << setprecision(2) << pChannels << " @ $" << bPremiumChannels << "\nService Connections: " << setw(3) << fixed << setprecision(2) << numConnection << " @ $" << bServiceConnections << "\n----------------------------------------\n";

        // Output total amount of cable bill for business account
        cout << "\nYour total bill is: " << setw(7) << fixed << setprecision(2) << "$" << bBillingAmount << endl;

        // Write to txt file
        file << "Account Number: #" << businessAccount << "\n-----------------------------------------\n"
            << "\nBill processing fee: " << setw(13) << fixed << setprecision(2) << "$" << bBillprocessingFee << "\nBasic Service fee: " << setw(15) << fixed << setprecision(2) << "$" << bBasicServiceFee << "\nPremium channels: " << setw(12) << fixed << setprecision(2) << pChannels << " @ $" << bPremiumChannels << "\nService Connections: " << setw(9) << fixed << setprecision(2) << numConnection << " @ $" << bServiceConnections << "\n----------------------------------------\n"
            << "\nYour total bill is: " << setw(13) << fixed << setprecision(2) << "$" << bBillingAmount << endl;
    }

    // Handle the monkey's error
    else
    {
        cout << "Please enter a valid choice" << endl;
    }

    // Close the txt file
    file.close();

    return 0;
}
