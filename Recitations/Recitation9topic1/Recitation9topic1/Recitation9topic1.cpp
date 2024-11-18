#include <iostream>
#include <string>

//define struct
struct Student {
	std::string name;
	int id;
	float score;
};

//function prototype
void selectionSort(Student arr[], int n);

int main() {
	const int size = 5;
	Student students[size] = {
		{"Alice, 1001, 85.5},"},
		{"Bob", 1002, 72.0 },
	{ "Charlie", 1003, 90.2 },
	{ "Diana", 1004, 88.8 },
	};


	std::cout << "OG list: " << std::endl;
	for (int i = 0; i < size: ++i) {
		std::cout << students[i].name << " " << students[i].id << " " << students[i].score << std::endl;
	}
	return 0;
}

void selectionSort(Student arr[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j].score < arr[minIndex].score)
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}