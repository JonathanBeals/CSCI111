#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function to check if a character is a vowel
bool isVowel(char ch);

//Function to extract the next word from the input stream
void getNextWord(ifstream& inF, char& ch, string& word);

//is punctuation
bool isPunctuation(char ch);

//rotate string
string rotate(string pStr, int len);

//make it pig latin
string pigLatinString(string pStr);


int main(int argc, const char * argv[])
{
    string str;
    char ch;

    ifstream infile;
    ofstream outfile;

    infile.open("Data.txt");
    outfile.open("Out.txt");
    if (!infile)
    {
        cout << "Could not open file, check its presence and try again.\n";
        exit(1);
    }

    //Read one char at a time
    infile.get(ch);
    while (infile)
    {
        while (ch != '\n')
        {
            if (ch == ' ')
            {
                outfile << ch;
                infile.get(ch);
            }
            else
            {
                getNextWord(infile, ch, str);
                outfile << pigLatinString(str);

            }
        }
        outfile << endl;
        infile.get(ch);

    }
    infile.close();
    outfile.close();

        return 0;
}

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
    case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': return true;
    default: return false;
    }
}
bool isPunctuation(char ch)
{
    switch (ch)
    {
    case '.': case '!': case '?': case ',': case ';': case ':': return true;
    default: return false;
    }
}

string rotate(string pStr, int len)
{
    string rStr = pStr.substr(1, len) = pStr[0];
    return rStr;
}

string pigLatinString(string pStr)
{
    string::size_type len = pStr.length();
    bool foundVowel = false;
    bool isPunct = isPunctuation(pStr[len - 1]);
    char puncMark = '\n';

    string::size_type counter;
    if (isPunct)
    {
        puncMark = pStr[len - 1];
        len--;
    }
    if (isVowel(pStr[0]))
    {
       pStr = pStr.substr(0, len) + "-way";
    }
    else
        //append hyphen, rotate until first vowel is found.
    {
        pStr = pStr.substr(0, len) + '-';

        pStr = rotate(pStr, len);

        len = pStr.length
    }
}


    