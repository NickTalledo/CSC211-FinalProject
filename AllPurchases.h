#pragma once
#ifndef AllPurchases_H
#define AllPurchases_H
#include "AllCustomers.h"
#include <string>
#include <vector>

using namespace std;

class AllPurchases {
public:
	AllPurchases();
	AllPurchases(int accounts, string items, string dates, double amounts);
	~AllPurchases();
	void loadData2();
	void addPurchase();
	void totalSpent();
	void addingRecursive2(int);
	void addMultiplePurchases();
	void writeFile2();

private:
	vector<int> accNum;
	vector<string> item;
	vector<string> date;
	vector<double> amount;
	int count = 0;
};
	

#endif
