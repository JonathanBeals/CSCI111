//Program made by Jonathan Beals
//Professor Sherine Antoun
//CSCI 111
//November 2nd 2024

//This program is intended to open a mp3 file, seek and put the header at the last 128 byte location 
//where the comments are located. Overwrite and display the new comment. It will also let the 
//user choose to make changes to another .mp3 file of their choosing!

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "mp3.h"

//function prototypes
bool readFile(const std::string& filename);
bool checkFile(const std::string& filename);
void writeComment(const std::string& filename);
void printComment(const MP3& mp3);




int main() {
	std::string filename;
	int choice = 0;

	//using a do while loop to stay in the menu until the user decides to exit 
	do {

		//prompt user for filename
		std::cout << "Please enter an filename (Must include .mp3 file extension): ";
		std::cin >> filename;


		//check if the filename is correct with an mp3 extension
		if (!checkFile(filename)) {
			std::cerr << "Invalid file type/name: ";
			continue;
		}

		//attempt to read the file
		if (!readFile(filename)) {
			std::cerr << "Error opening the file to read, check spelling and try again";
			continue;
		}

		//add the menu option for asking to make a new comment on a new file
		std::cout << "\n--------------------------------------\n";
		std::cout << "Would you like to comment on this mp3?\n";
		std::cout << "--------------------------------------\n";
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		std::cin >> choice;

		//handling the user exiting the program
		if (choice == 1) {
		writeComment(filename);
		}
		else if (choice == 2) {
		std::cout << "\nNo comment added\n";
		}
		else
			std::cout << "Invalid input, try again!";

		readFile(filename);

		//set choice to zero for choosing another file
		choice = 0;

		std::cout << "\n-----------------------------------\n";
		std::cout << "Would you like to edit another file?\n";
		std::cout << "------------------------------------\n\n";
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		std::cin >> choice;
	}
	while (choice == 1);
	std::cout << "\n**************************************";
	std::cout << "\n* Exiting the program, See ya later! *";
	std::cout << "\n**************************************\n\n";
	return 0;
	
}

//FUNCTIONS

//open mp3 file
bool readFile(const std::string& filename) {

	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	if (!file) {
		std::cerr << "\nError reading file! Check your spelling\n";
			return false;
	}
	//move the pointer to the last 128 bytes of the .mp3 file
	MP3 tag;
	int position = 128;
	file.seekg(-position, std::ios::end);
	file.read(reinterpret_cast<char*>(&tag), sizeof(MP3));

	//error handling if id3v1 tag is not found
	if (std::string(tag.header, 3) != "TAG") {
		std::cerr << "id3v1 tag not found\n";
		return false;
	}

	printComment(tag);
	file.close();
	return true;
}

//function to check the file for mp3 extension
bool checkFile(const std::string& filename) {
	return filename.size() > 4 && filename.substr(filename.size() - 4) == ".mp3";
}

//function to print the mp3 information
void printComment(const MP3& mp3) {
	std::cout << "---------------------------------------------\n";
	std::cout << std::left << std::setw(15) << "Song Title: " << std::string(mp3.songTitle, 30) << "\n";
	std::cout << std::left << std::setw(15) << "Artist: " << std::string(mp3.artist, 30) << "\n";
	std::cout << std::left << std::setw(15) << "Album: " << std::string(mp3.album, 30) << "\n";
	std::cout << std::left << std::setw(15) << "Year: " << std::string(mp3.year, 4) << "\n";
	std::cout << std::left << std::setw(15) << "Comment: " << std::string(mp3.comment, 28) << "\n";
	std::cout << std::left << std::setw(15) << "Track: " << static_cast<int>(mp3.trackNumber[0]) << "\n";
	std::cout << std::left << std::setw(15) << "Genre: " << genre[static_cast<unsigned char>(mp3.genre)] << "\n";
}

//function to write the comment
void writeComment(const std::string& filename) {
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

	if (!file) {
		std::cerr << "Error opening the file to write\n";
		return;
	}

	//move to the last 128 bytes of the .mp3 file
	MP3 tag;
	int position = 128;
	file.seekg(-position, std::ios::end);
	file.read(reinterpret_cast<char*>(&tag), sizeof(MP3));
	//error handling if id3v1 tag is not found
	if (std::string(tag.header, 3) != "TAG") {
		std::cerr << "id3v1 tag not found!\n";
		return;
	}
	//enter new comment
	std::cout << "Enter a new comment. 28 character max: \n";
	std::cin.ignore();
	std::cin.getline(tag.comment, 28);

	//padding with null terminator
	memset(tag.comment + std::strlen(tag.comment), 0, 28 - std::strlen(tag.comment));

	file.seekp(-position, std::ios::end);
	file.write(reinterpret_cast<const char*>(&tag), sizeof(MP3));

	if (file) {
		std::cout << "\n-----------------------------------\n";

		std::cout << "Comment updated for: \n" << filename << "\n";
	}
	else {
		std::cerr << "Error writing to file\n";
	}
	file.close();
}


