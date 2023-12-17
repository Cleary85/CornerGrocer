#include <iostream>
#include <string>
#include "GrocerDailyStats.h"
using namespace std;

int main() {
	bool endProgram = false;
	int userMenuChoice;
	GrocerDailyStats dailyReport;

	// read and write functions operated before user input to ensure .dat creation incase of crash
	dailyReport.getStats();
	dailyReport.exportStats();

	cout << "Welcome to Corner Grocer Daily Statistics Compliler!!!" << endl;

	// while loop using a bool value and switch int input from user to keep things simple and minimizing unintended interactions from user
	while (endProgram != true) {
		menuOptions();					// shows menu options
		cin >> userMenuChoice;


		switch (userMenuChoice) {
		case 1: {
			dailyReport.getUserWord();	// word search from user against imported list
			break;
		}
		case 2: {
			dailyReport.printItemsWithNumbers();	// line by line output of entire list with counts
			break;
		}
		case 3: {
			dailyReport.printHistronicList();		// line by line ouput of entire list with a number of symbols vice actual numbers
			break;
		}
		case 4:
		{
			endProgram = true;			// change bool from false to true terminating while loop and ending program
			cout << "Thank you for using Corner Grocer Statistics Compliler!!!" << endl;
			break;
		}
		default: {						// default to catch any user input that is not defined as an option
			cout << "That input was not recognized!" << endl;
		}

		}
	}

	return 0;
}