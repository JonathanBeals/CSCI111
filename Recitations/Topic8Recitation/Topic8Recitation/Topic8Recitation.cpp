#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Open text file for reading
    ifstream textFile("Billing.txt", ios::ate)

        if (!textFile.is_open())
        {

            cerr << "Text file error";


            //Determine the file size
            //textFile.seekg(0, ios::end);
            streampos fileSize = textFile.tellg();
            textFile.seekg(0, ios::beg);

            //Create a string to store the file contents
            string fileContent;

            //Reserve space fo the entire file
            fileContent.reserve(fileSize);

            //Read the file content in one go
            fileContent.assign(istreambuf_iterator<char>(textFile)), 
                istreambuf_iterator<char>());

                //close file
                textFile.close();

                //display
                    cout << "File Content:" << endl;
                cout << "fileContent" << endl;
        }
        else
        
          
        
}
