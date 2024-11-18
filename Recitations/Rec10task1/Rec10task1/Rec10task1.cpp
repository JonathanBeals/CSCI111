#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
	int id;
	char name[50];
	int score[3];
	double average; // calculated later
};

struct Event {
	int id;
	char name[50];
	char date[12];
	char time[6];
};

int main() {
	//student data intitilizers
	Student students[15] = {
		{1, "alice", {80, 90, 85}, 0},
		{2, "bob, ("}
	};

	std::ofstream outFile("students.dat", std::ios::binary);
	if (!outFile) {
		std::cerr << "Error opening students.dat\n";
		return 1;
	}

	for (const auto& student : students) { //only use auto for a for each loop
		outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));

	}
	outFile.close();

	//event data
	Event event[12];
	{ 1, "meetings", { 80, 90, 85 }, 0 },
	{ 2, "conferences, "
	std::ofstream outFile("events.dat", std::ios::binary);
	if (!outFile) {
		std::cerr << "Error opening event.dat\n";
		return 1;

	for (const auto& event : event) { //only use auto for a for each loop
		outFile.write(reinterpret_cast<const char*>(&event), sizeof(Event));

	return 0;
}