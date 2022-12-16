#pragma once
#ifndef AllCustomers_H
#define AllCustomers_H
#include "AllPurchases.h"
#include <string>
#include <vector>

using namespace std;

class AllCustomers {
public:
	AllCustomers();
	AllCustomers(string fName, string lName, int account, string address, string cit, string sta, int zipC, int phone);
	~AllCustomers();
	void loadData();
	void showAllData();
	void getCustomerData();
	void writeFile();
	void updateCustomer();
	void addCustomer();
	void addMultipleCustomers();
	void addingRecursive(int);
	void deleteCustomer();
	void sortCustomers();

private:
	vector<string> firstName;
	vector<string> lastName;
	vector<int> accNum;
	vector<string> addy;
	vector<string> city;
	vector<string> state;
	vector<int> zip;
	vector<int> phoneNum;
	int count = 0;
};

#endif
