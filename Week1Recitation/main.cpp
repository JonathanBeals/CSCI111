#include <iostream>

using namespace std;

const int secondsInHour = 3600;
const int secondsInMinute = 60;

int main()
{
    int hours;
    int minutes;
    int seconds;

    cout << "Enter the elapsed time in seconds: ";
    cin >> seconds;
    cout << endl;

    cout << "The elapsed time in seconds = " << seconds << endl;

    hours = seconds / secondsInHour;
    seconds %= secondsInHour;
    minutes / secondsInMinute;
    seconds %= secondsInMinute;

    cout << "The equivalent time in hours:minutes:seconds =" << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}


