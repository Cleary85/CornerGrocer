#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<iomanip>
#include"GrocerDailyStats.h"
using namespace std;

/* Function to import daily statistics from .txt file and store them in a map object for exporting and reporting */
void GrocerDailyStats::getStats() {
	ifstream inFS;
	string grocerItem;
	
	// opens and while loops through the .txt file checking if the item already exists to plus up them item or create a new item/entry at one
	inFS.open("CS210_Project_Three_Input_File.txt");
	while (!inFS.fail()) {
		inFS >> grocerItem;
		if (!dailyTallies.count(grocerItem)) {
			dailyTallies.emplace(grocerItem, 1);
		}
		else {
			dailyTallies[grocerItem] += 1;
		}
	}
	inFS.close();
}

/* Function to export daily statistics into frequency.dat file for future analytics */
void GrocerDailyStats::exportStats(){
	ofstream ouFS;

	ouFS.open("frequency.dat");
	// for loop to transcribe each key-pair into a .dat on the same line
	for (auto it = dailyTallies.begin(); it != dailyTallies.end(); ++it) {
		ouFS << it->first << " " << it->second << endl;
	}
	ouFS.close();
}

/* Function to prompt for an item string from user and search map object for existance and if so report number of items sold */
void GrocerDailyStats::getUserWord() {
	string userInput;

	cout << "Please enter the item name you wish to view." << endl;
	cin >> userInput;
	// if/else to check it the user input is in the map and either respond that it is not or misspelled or print how many were sold
	if (!dailyTallies.count(userInput)) {
		cout << "Item is was not sold today. Check spelling and capitalization and try again if a count was expected" << endl;
	}
	else {
		cout << "There were " << dailyTallies[userInput] << " " << userInput << " sold today." << endl;
	}
};

/* Function to print to output a running total of items sold with sell counter */
void GrocerDailyStats::printItemsWithNumbers() {
	cout << "Items sold today" << endl;
	cout << "Items    ";
	cout << "  Count" << endl;
	// for loop to iterate through every entry of the map and print the key and its pair
	for (auto it = dailyTallies.begin(); it != dailyTallies.end(); ++it) {
		cout << setw(12) << left << it->first;
		cout << setw(4) << right << it->second << endl;
	}
};

/* Function to print a histronic view of items sold */
void GrocerDailyStats::printHistronicList() {
	cout << "Items sold today!" << endl;
	cout << "Items    ";
	cout << "   Count" << endl;
	// for loop to look at each key and excute a for loop to get the number of histronic chars and outout it all on one line
	for (auto it = dailyTallies.begin(); it != dailyTallies.end(); ++it) {
		string histronicCount = "";
		char histronicChar = '|';
		int itemCount = it->second;

		for (int i = 0; i < itemCount; i++) {
			histronicCount += histronicChar;
		}
		cout << setw(12) << left << it->first;
		cout << left << histronicCount << endl;
	}
};

/* Prints available menu options and prompts for user selection */
void menuOptions() {
	cout << "Please select an option from the following:" << endl;
	cout << "1. Enter a item name to check if item was sold and if so how many:" << endl;
	cout << "2. Print to screen the Item names with the number count of how many were sold today:" << endl;
	cout << "3. Print to screen a histronics table with '|' marks to denote number of items:" << endl;
	cout << "4. Exit the program:" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
}






