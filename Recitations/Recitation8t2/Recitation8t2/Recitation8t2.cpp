#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile("positions.txt");

    outputFile << "Hello, World!" << endl;

    streampos putPos = outputFile.tellp();

    outputFile << "This is additional data" << endl;

    streampos newPos = outputFile.tellp();

    cout << "Current put position: " << putPos << endl;
    cout << "New put position: " << NewPos << endl;

    outputFile.close;
}

