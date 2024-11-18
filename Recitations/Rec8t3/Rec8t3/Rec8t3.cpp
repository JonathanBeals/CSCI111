#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//Output text file
	ifstream textFile("Sample.txt");
	if (textFile.is_open())
	{
		//calculate size of file
		//and back to beginning
		textFile.seekg(0, ios::end);
		streampos fileSize = textFile.tellg();
		textFile.seekg(0, ios::beg);

		//define fixed sixed character array
		const int MAX_FILE_SIZE = (int)fileSize + 1; //Adjust this size to file size limit
		char fileContent[MAX_FILE_SIZE];

		//Read file content into array
		textFile.read(fileContent, fileSize);

		//Close file
		textFile.close();

		//add null terminator
		fileContent[fileSize] = "\0";

		cout << "The file contained:\n" << fileContent << endl << endl
		<< " about to break into words, ready?\t Press enter to continue";

		char wait;
		cin.get(wait);

		//Tokenize content
		/*cout << "Token: ";
		for (int i = 0; i < fileSize; i++)
		{
			if (fileContent[i] == ' ' || fileContent[i] == '\n')
			{
				cout << endl << "Token";
			}
			else
			{
				cout << fileContent[i];
			}*/

		char* pch;
		pch = strtok(fileContent, ",.-");
		while (pch != NULL)
		{
			printf("%s\n", pch);
			pch = strtok(NULL, ",,.-");

		}
		cout << endl;
	}
	else {
		cerr "Failed to open txt file" << endl;
		return 1;
	}
	return 0;
}