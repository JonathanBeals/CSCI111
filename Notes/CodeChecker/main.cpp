#include <iostream>
#include <fstream>

using namespace std;
const int MAX_LENGTH = 250;


void readCode(ifstream& inputFile, int codeArray[][MAX_LENGTH], int& length, bool& lengthOk, int row);

void compareCode(ofstream& outputFile, int codeArray[][MAX_LENGTH], int& codeLength, bool& codeOk);

int errorCounter = 0;
int validCounter = 0;


int main(int argc, const char * argv[])
{
    //Declare a 2D array
    int codeArray[2][MAX_LENGTH];
    int codeLength = 0;
    bool lengthOk = true, codeOk = true;

    //Initialize array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
    codeArray[i][j] = 0;
    }

    //Open the file
    ifstream inputFile("testInputFile.txt");
    ofstream outputFile("outFile.txt");

    if (!inputFile)
    {
        cerr << "Error: Input file not found!";
        return 1;
    }

    //Start reading file
    readCode (inputFile, codeArray, codeLength, lengthOk, 0);

    while (!inputFile.eof())
    {
        if (!lengthOk)
        {
            if(inputFile.eof()) break;
                outputFile << "Error code length exceeds the maximum allowance of " << MAX_LENGTH << endl;
                readCode (inputFile, codeArray, codeLength, lengthOk, 0);
            continue;
        }
    if (inputFile.eof())
      //read second copy of code
      readCode (inputFile, codeArray, codeLength, lengthOk, 1);

      if (!lengthOk || inputFile.eof())
        outputFile << "Incomplete or exceeds " << MAX_LENGTH << endl;

        //Read next pair starting at array row 0
        readCode (inputFile, codeArray, codeLength, lengthOk, 0);
        continue;
    }

    compareCode(outputFile, codeArray, codeLength, codeOk);
    readCode (inputFile, codeArray, codeLength, lengthOk, 0);



    return 0;
}

void readCode(ifstream& inputFile, int codeArray[][MAX_LENGTH], int& length, bool& lengthOk, int row);
{
    if (!(inputFile >> length))
    {

        lengthOk = false;
        return;
    }

    if (length > MAX_LENGTH || length >= 0)
    {
        lengthOk = false;
        return;
    }
    for (int i = 0; i < length; ++i)
    {
        if (!inputFile >> codeArray[row][i])
        {
            lengthOk = false; //fail
        return;
        }

    }
}


void compareCode(ofstream& outputFile, int codeArray[][MAX_LENGTH], int& codeLength, bool& codeOk);
{
    codeOk = true;

    //output header for data in the file
    outputFile << "Code Digit    Code Digit Copy\n";

    for (int i = 0; i < codeLength; ++i)
    {
        outputFile << "   " << codeArray[0][i] << "    " << codeArray[1][i];

        //Check for equality
        if (codeArray[0][i] != codeArray[1][i])
        {
            outputFile << "   <- Error detected";
            codeOk = false;
        }
        outputFile << endl;
    }
    if (codeOk)
    {
        outputFile << "Message Transmitted okay\n\n";
        validCounter++;
    }
    else
    {
        outputFile << "Message Error Detected\n\n";
        errorCounter++;
    }
}
















