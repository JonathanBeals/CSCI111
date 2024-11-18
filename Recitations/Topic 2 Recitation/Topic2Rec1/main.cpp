#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Enter a number";
    cin >> num;

    if (cin.fail());

    {
        cout << "Invalid input! Please enter an integer" << endl;
        cin.ignore(10000, \n);
    }
    else
    {
        cout << "You entered:"<< num << endl;
    }


    return 0;
}
