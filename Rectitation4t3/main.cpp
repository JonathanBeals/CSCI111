#include <iostream>

using namespace std;

int main()
{
    //Variable to store numbers
    int previous = 0;
    int current = 1;
    int next;

    int sentinal;

    // Prompt user to enter sentinal value
    cout << "Enter sentinal value to stop calculating";
    cin >> sentinal;

    while (current <= sentinal)
    {
        //Algorithm
        next = previous + current;

        //output fibonacci number
        cout << current << " ";

        //Update variables for the next iteration
        previous = current;
        current = next;
    }

    //Display end of program
    cout << "\nEnd of program" << endl;


    return 0;
}
