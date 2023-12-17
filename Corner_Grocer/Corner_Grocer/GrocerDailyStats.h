#ifndef GrocerDailyStats
#define GrocerDailyStats_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

/* GrocerDailyStats class creation to keep the map data private and allow for added implemetations at a later date ie. save multiple days, more analytics etc */
class GrocerDailyStats {									

public:
	void getStats();
	void exportStats();
	void getUserWord();
	void printItemsWithNumbers();
	void printHistronicList();
	


private:
	map<string, int> dailyTallies;
};

void menuOptions();

#endif
