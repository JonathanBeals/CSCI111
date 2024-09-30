#include <iostream>

using namespace std;

int main()
{
    double inputValue = 0.0;
    int valPenny = 0;
    cout << "How much cash you got?\n";
    cin >> inputValue;
    valPenny = inputValue * 100;

    cout << "Number of quarters: " << valPenny / 25 << endl;
    valPenny %= 25;

    cout << "Number of dimes: " << valPenny / 10 << endl;
    valPenny %= 10;

    cout << "Number of nickle: " << valPenny / 5 << endl;
    valPenny %= 5;

    cout << "Number of pennys: " << valPenny << endl;

    return 0;
}
