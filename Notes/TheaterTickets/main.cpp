#include <iostream>
#include <iomanip>  // required for manipulating the output format

using namespace std;

int main(int argc, const char * argv[])
{
    string movieName; // store name input

    double adultTicket = 0.0, childTicket =0.0, percentDonation = 0.0,
            grossAmount = 0.0, amountDonated =0.0, netSalesAmount = 0.0;
    int noOfAdultTickets = 0, noOfChildTickets = 0;


    //Set output to 2 decimals
    cout << fixed << setprecision(2);

    //get some data
    cout << "Please enter the movie name: ";
    getline(cin, movieName);

    //Get price of Adult ticket
    cout << "Please enter the price of an adult ticket: $";
    cin >> adultTicket;

    //Get price of Child ticket
    cout << "Please enter the price of an Child ticket: $";
    cin >> childTicket;

    //Get number of Adult ticket
    cout << "Please enter the number of adult tickets sold: ";
    cin >> noOfAdultTickets;

        //Get number of child ticket
    cout << "Please enter the number of child ticket: ";
    cin >> noOfChildTickets;

    // aDonation Ration
    cout << "Please enter the percentage to be donated (I.E.:10 for 10%): ";
    cin >> percentDonation;

    //Calculate the gross amount
    grossAmount = adultTicket * noOfAdultTickets + childTicket * noOfChildTickets;

    //Donation Value
    amountDonated = grossAmount * percentDonation / 100;

    //Net Sales
    netSalesAmount = grossAmount - amountDonated;

    //Output the results in the specified format
    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

    //Output stuff
    cout <<left<<setw(40)<<"Movie name: " <<movieName<<endl;

    //No of tickets
    cout << left << setw(40) << "Number of Tickets Sold: " << noOfChildTickets + noOfAdultTickets << endl;

    //Gross
    cout << left << setw(30) << "Gross Amount" << right << setw(15) << grossAmount << endl;

    //Donation Percentage
    cout <<left<<setw(30)<<"Percentage of Gross Donated: "<<right<< setw(14)<<percentDonation<< "%" <<endl;

    //Actual $Donated
    cout << left<<setw(30)<< "Amount Donated" <<right<<setw(10)<< " $"<<amountDonated<<endl;

    //Net Sales
    cout<< left << setw(30) << "Net Sales: "<<right<<setw(10)<<" $" <<netSalesAmount<<endl;



    return 0;
}
