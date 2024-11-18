#include <iostream>

using namespace std;

int main()
{
    int num = 0, i = 1, sum =0;


// Task 1
    cout << "Enter a positive integer: ";
    cin >> num;

    while (i <= num)
    {
        sum += i;
        i++;
    }
    cout << "The sum is " << sum << endl;

//task 2

    while (num <= sum % 2)
    {
        sum += i;
        i++;
    }
        cout << "The sum of even numbers from 1 to " << num << " is " << sum;


    return 0;
}
