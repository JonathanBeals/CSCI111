
#include <iostream>

using namespace std;

void readTemperatures(int temps[], int &n);
double calculateAverage(int temps[], int n);
void adjustTemperature(double avgTemp, double setPoint);


int main()
{
    int temps[100];   //Array to store temp.
    int n;           //Actual number of rooms
    double setPoint = 22.0;   //Desired target

    //read temp
    readTemperatures(temps, n);

    //work out average temp
    double avg = calculateAverage(temps, n);

    //display average
    cout << "The average temperature is: " << avg << " centigrade" << endl;

    //Adjustment
    adjustTemperature(avg, setPoint);

    return 0;
}
//Function to read temperature
void readTemperatures(int temps[], int &n)
{
    cout << "Enter the number of rooms: ";
    cin >> n;
    cout << "Enter temperature for each room please: \n";
    for (int i = 0; i< n; i++)
    {
        cout << "Room " << i+1;
        cin >> temps[i];
    }
}
//Calculate average
double calculateAverage(int temps[], int n)
{
    int sum;
    for (int i = 0; i< n; i++)
    sum += temps[i];
    return static_cast <double> (sum) / n;
}

//suggest adjustment based on avg
void adjustTemperature(double avgTemp, double setPoint)
{
    if(avgTemp>setPoint)
    cout << "Cooling Needed, lower the temp by " << (avgTemp - setPoint) << "C" << endl;

    else if(avgTemp < setPoint)
        cout << "Heating Needed, raise the temp by " << (avgTemp - setPoint) << "C" << endl;
    else
        cout << "Temperature is ideal, have a cup of tea!\n";
}


