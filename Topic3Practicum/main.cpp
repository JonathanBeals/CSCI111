#include <iostream>

using namespace std;

double in;

int main()
{
    cout << "Please enter a positive or negative number \n";
    cin >> in;

    if (in > 0)
        cout << "Your number " << in << " is positive";

    else
    cout << "Your number " << in << " is negative";

    return 0;
}
