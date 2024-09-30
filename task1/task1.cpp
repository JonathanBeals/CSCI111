#include <iostream>

using namespace std;

int iNum;
float avg;

int main()
{
    cout << "Enter your input: " << endl;
    cin >> iNum;

    if (iNum % 2 == 0)
        cout << "Your input: " << iNum << " Is even" << endl;
    else
        cout << "Your input: " << iNum << endl;

    {
        if (iNum % 2 == 0)
            cout << "Your input: " << iNum << endl;
        else
            cout << "Your input: " << iNum << " Is odd" << endl;

    }
    return 0;
}
