#include "AllPurchases.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int accounts;
string items;
string dates;
double amounts;


void AllPurchases::addingRecursive2(int num) {  // recursive function for adding multiple purchases

	if (num == 0) {
		cout << "Customer purchases added!" << endl;
		return;
	}
	else {
		cout << "Enter in item: ";
		cin >> items;
		cout << "Enter in the date the item was purcahsed (examle = 3/13/2022) : ";
		cin.ignore();
		getline(cin, dates);
		cout << "Enter in amount spent: ";
		while (cout << " " && !(cin >> amounts)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "You have not selected a valid input. Please try again." << endl;
			cout << "Enter in again: ";
		}
		for (int i = 0; i < num; i++) {
			item.push_back(items);
			date.push_back(dates);
			amount[i] = amount[i] + amounts;  // adds money to total spent
		}
		return addingRecursive2(num - 1);
	}
}


AllPurchases::AllPurchases() {  // constructor

}


AllPurchases::AllPurchases(int accounts, string items, string dates, double amounts) {  // copy constructor
	this->accNum[count] = accounts;
	this->item[count] = items;
	this->date[count] = dates;
	this->amount[count] = amounts;
}


AllPurchases::~AllPurchases() { // destructor

}


void AllPurchases::loadData2() {  // loads data in
	ifstream fRead;
	
	fRead.open("PurchasesIn.txt");

	if (!fRead) {
		cout << "\n Error: Unable to open the file for reading.";  // displays error message if file not read in properly
		exit(0);
	}

		while (!fRead.eof()) {
				fRead >> accounts;
				fRead >> items;
				fRead >> dates;
				fRead >> amounts;
				accNum.push_back(accounts);
				item.push_back(items);
				date.push_back(dates);
				amount.push_back(amounts);
				count++;
		}
}


void AllPurchases::addPurchase() {  // adds in purchase for customer

	cout << "\nEnter account's number to search: ";
	while (cout << " " && !(cin >> accounts)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	for (int i = 0; i < count; i++) {
		if (accNum[i] == accounts) {		// compares the number put in, if 0 then the strings are the same
			cout << "Enter in item: ";
			cin >> items;
			cout << "Enter in the date the item was purcahsed (examle = 3/13/2022) : ";
			cin.ignore();
			getline(cin, dates);
			cout << "Enter in amount spent: ";
			while (cout << " " && !(cin >> amounts)) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "You have not selected a valid input. Please try again." << endl;
				cout << "Enter in again: ";
			}
			item.push_back(items);
			date.push_back(dates);
			amount[i] = amount[i] + amounts;  // adds money to total spent
			return;
		}
	}
	cout << "\nCustomer not found." << endl;
}


void AllPurchases::totalSpent() {  // shows how much money was spent
	cout << "\nEnter account's number to search: ";
	while (cout << " " && !(cin >> accounts)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}
	for (int i = 0; i < count; i++) {
		if (accNum[i] == accounts) {
			cout << "Total amount spent is: " << amount[i] << endl;
			return;
		}
	}
	cout << "\nCustomer not found." << endl;
}


void AllPurchases::addMultiplePurchases() {  // adds multiple purchases
	int num;

	cout << "\nEnter account's number to search: ";
	while (cout << " " && !(cin >> accounts)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	cout << "Enter in the number of purchases you wish to enter: ";
	while (cout << " " && !(cin >> num)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	for (int i = 0; i < count; i++) {
		if (accNum[i] == accounts) {
			addingRecursive2(num);
			return;
		}
	}
}


void AllPurchases::writeFile2() {
	ofstream fWrite;
	fWrite.open("PurchasesOut.txt");

	if (!fWrite) {
		cout << "\n Error: Unable to open the file for writing." << endl;		// error message
		exit(0);
	}

	for (int i = 0; i < count; i++) {
		fWrite << accNum[i] << endl;
		fWrite << item[i] << endl;
		fWrite << date[i] << endl;
		fWrite << amount[i] << endl;
	}
	fWrite.close();
}
