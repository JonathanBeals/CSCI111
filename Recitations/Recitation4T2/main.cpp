#include <iostream>

using namespace std;

int main()
{
    // Outer loop: Controls number of rows
    for (int i =1; i <=10; ++i)
    {
        //inner loops; control the number of asterisks and spaces in each row

        for (int k =10 - i; k > 0; --k)
        {
            cout << " ";
        }
        for (int j =1; j<=i; ++j)
        {
            cout << "* ";
        }

        //move to next line
        cout << endl;
    }

    return 0;
}
