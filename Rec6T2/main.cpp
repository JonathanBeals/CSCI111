#include <iostream>

using namespace std;

void readSteps(int steps[], int &n);
int calculateTotalSteps(int steps[], int n);
double calculateAverageSteps(int steps[], int n);
int findMax(int steps[], int n);
int findMin(int steps[], int n);

int main()
{
    int steps[100];   //Array to store steps for 100 days
    int n;           //Actual number of days
    int threshold = 10000;

    // Read steps
    readSteps(steps, n);
    //calculate total and average
    int totalSteps = calculateTotalSteps(steps, n);
    double avgSteps = calculateAverageSteps(steps, n);
    int maxDay = findMax(steps, n);
    int minDay = findMin(steps, n);

    //Display results
    cout << "Total steps: " << totalSteps << endl;
    cout << "Average steps per day: " << avgSteps << endl;
    cout << "Most active day: " << maxDay << endl;
    cout << "Least active day: " << minDay << endl;

    //Suggest goal
    if(avgSteps >= threshold)
        cout << "Good on you mate...Do nothin different!\n";
    else
        cout << "We observe you to be in the couch potato catagory get off your seat and walk a bit 2 miles per day\n";

    return 0;
}

void readSteps(int steps[], int &n)
{
    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter step count for each day: ";
    for(int i = 0; i< n; i++)
    {
        cout << "Day " << i+1 << ": ";
        cin >>steps[i];
    }
}

int calculateTotalSteps(int steps[], int n)
{
    int total = 0;
     for(int i = 0; i< n; i++)
    {
        total += steps[i];
    }
    return total;
}

double calculateAverageSteps(int steps[], int n)
{
    int total = calculateTotalSteps(steps, n);
    return static_cast <double> (total) / n;
}

int findMax(int steps[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (steps[i] < steps[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}
int findMin(int steps[], int n)
{

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (steps[i] < steps[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}
