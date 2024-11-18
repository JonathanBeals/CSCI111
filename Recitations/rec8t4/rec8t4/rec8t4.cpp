#include <iostream>

using namespace std;

enum day {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};


//Function to convert day to text value
string dayToString(Day, day) {
	switch (day) {
	case Monday: return "Monday";
	case Tuesday: return "Tuesday";
	case Wednesday: return "Wednesday";
	case Thursday: return "Monday";
	case Friday: return "Friday";
	case Saturday: return "Sat";
	case Sunday: return "Sun";
	default: return "Invalid Day"
	}
}

int main()
{
	Day today = Monday;

	cout << "Today is: " << dayToString(today) << endl;

	today = static_cast<Day>((static_cast<int>(today) + 1) % 7);

	cout << "Tomorrow will be: " << dayToString(today) << endl;

	return 0;
}
