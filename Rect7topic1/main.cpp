#include <iostream>
#include <fstream>
#include <cstring>

//function prototypes
int readFile(char filename[], char lines[][100], int maxLines);
int countWords(char line[]);
void findLongestWord(char line[][100], char longestWord[]);
void printReverse(char lines[][100], int lineCount)


using namespace std;

int main(int argc, char* argv[]) {
if (argc != 2) {
std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
return 1;
}
char lines[100][100]; // 2D array to store up to 100 lines, each up to 100 chars
int lineCount = readFile(argv[1], lines, 100);
if (lineCount == -1) {
std::cout << "Error opening file." << std::endl;
return 1;
}
for (int i = 0; i < lineCount; ++i) {
int wordCount = countWords(lines[i]);
char longestWord[100];
findLongestWord(lines[i], longestWord);
std::cout << "Line " << (i + 1) << ": " << lines[i] << std::endl;
std::cout << "Word count: " << wordCount << std::endl;
std::cout << "Longest word: " << longestWord << std::endl;
}
std::cout << "\nLines in reverse order:\n";
printReverse(lines, lineCount);
return 0;
}
//Function to read lines from a file into a 2d array
int readFile(char filename[], char lines[][100], int maxLines)
{
    std::ifstream file(filename);

    //Check if file could not be opened
    if (!file)
    {
        return -1; // return error code
    }
    int count = 0;
    while (file.getline(lines[count], 100) && count < maxLines)
    {
        ++count;
    }

    file.close();
    return count; // Return number of lines read
}
int countWords(char line[])
{
    int wordCount = 0;
    bool inWord = false;

    //iterate through each character
    for (int i = 0; line [i] !'\0'; I++)
    {
        if (line[i] != ' ' && !inWord)
        {
            inWord = true; //We are entering a word
            ++wordCount;
        }
        else if (line[i] == ' ')
        {
            inWord = false; // We are outside a word
        }
    }
    return wordCount; // Return the total word count
}

//Function to find longest word in a line
void findLongestWord(char line[][100], char longestWord[])
{
    int maxLength = 0;
    int currentLength =0;
    int startIndex = 0;
    int longestStartIndex =0;

    //Iterate trhough each character
    for (int i =0; line [i] != '\0'; ++i)
    {
        if (line [i] != ' ')
        {
            if (currentLength == 0)
            {
                startIndex = i;
            }
            ++currentLength;
            else
            {
                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    longestStartIndex = startIndec;
                }
                currentLength = 0;
            }
        }
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            longestStartIndex = startIndex
        }

        //Copy longestWord into the longestWord array
        for (int i = 0; i < maxLength; ++i)
        {
            longestWord[i] = line[longestStartIndex + i];
        }
        longestWord[maxLength] = '\0'; //Add null terminator at the end
    }
}


//function to print all lines in reverse order
void printReverse(char lines[][100], int lineCount)
{
    for (int i = lineCount -1; i >=0; --i)
    {
        std::cout << lines[i] << std::endl;
    }
}
