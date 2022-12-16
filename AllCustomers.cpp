#include "AllCustomers.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Global Variables
string fname;
string lname;
int account;
string address;
string cit;
string sta;
int zipC;
int phone;


void AllCustomers::addingRecursive(int num){  // Recursive function to add multiple customers, used in function

	if (num == 0) {  // when customers reach 0, it will cout they were added
		cout << "Customers added!" << endl;
		return;
	}
	else {
		srand(time(0)); // set seed to time(0)
		int random = rand(); // generate random number
		account = random;  // account number will now be this random number

		cout << "\nEnter in first name: ";
		cin >> fname;
		cout << "Enter in last name: ";
		cin >> lname;
		cout << "Enter in Address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Enter in city: ";
		getline(cin, cit);
		cout << "Enter in state abbreviation in uppercase letters (example = NY): ";
		cin >> sta;
		while (sta.size() != 2) {
			cout << "Incorrect input, try again: ";
			cin >> sta;
		}
		cout << "Enter in 5 digit zipcode:";
	while (cout << " " && !(cin >> zipC) || zipC >= 100000 || zipC <= 9999) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}
		cout << "Enter in 7 digit phone number (exclude area code): ";
		while (cout << " " && !(cin >> phone) || phone >= 10000000 || phone <= 999999) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "You have not selected a valid input. Please try again." << endl;
			cout << "Enter in again: ";
		}
		// push back all new customer info to database
		firstName.push_back(fname);
		lastName.push_back(lname);
		accNum.push_back(account);
		addy.push_back(address);
		city.push_back(cit);
		state.push_back(sta);
		zip.push_back(zipC);
		phoneNum.push_back(phone);
		count++;  // count increases for number of customers
		return addingRecursive(num - 1);  // recalls function but subtracts 1 from number of customers
	}
}


AllCustomers::AllCustomers() { // constructor

}


AllCustomers::AllCustomers(string fName, string lName, int account, string address, string cit, string sta, int zipC, int phone) {
	this->firstName[count] = fName;
	this->lastName[count] = lName;
	this->accNum[count] = account;
	this->addy[count] = address;
	this->city[count] = cit;
	this->state[count] = sta;
	this->zip[count] = zipC;
	this->phoneNum[count] = phone;
} // copy consturctor


AllCustomers::~AllCustomers() { // destructor

}


void AllCustomers::loadData() {  // loads in data from customers text
	ifstream fRead;
	
	fRead.open("CustomersIn.txt");

	if (!fRead) {
		cout << "\n Error: Unable to open the file for reading.";  // displays error message if file not read in properly
		exit(0);
	}

	while (!fRead.eof()) {
		fRead >> fname;
		fRead >> lname;
		fRead >> account;
		fRead >> address;
		fRead >> cit;
		fRead >> sta;
		fRead >> zipC;
		fRead >> phone;

		firstName.push_back(fname);
		lastName.push_back(lname);
		accNum.push_back(account);
		addy.push_back(address);
		city.push_back(cit);
		state.push_back(sta);
		zip.push_back(zipC);
		phoneNum.push_back(phone);
		count++;
	}
}


void AllCustomers::writeFile() {			// writes new information put in into output file
	ofstream fWrite;
	fWrite.open("CustomersOut.txt");

	if (!fWrite) {
		cout << "\n Error: Unable to open the file for writing." << endl;		// error message
		exit(0);
	}
	for (int i = 0; i < count; i++) {
		fWrite << firstName[i] << endl;
		fWrite << lastName[i] << endl;
		fWrite << accNum[i] << endl;
		fWrite << addy[i] << endl;
		fWrite << city[i] << endl;
		fWrite << state [i] << endl;
		fWrite << zip[i] << endl;
		fWrite << phoneNum[i] << endl;
	}

	cout << "\nNew data was stored in the file!" << endl;
	fWrite.close();

}


void AllCustomers::showAllData() {  // outputs each customer and their data

	cout << endl;
	cout << setfill(' ') << setw(25);
	cout << "First Name: ";
	cout << setfill(' ') << setw(25);
	cout << "Last name: ";
	cout << setfill(' ') << setw(25);
	cout << "Account number: ";
	cout << setfill(' ') << setw(25);
	cout << "Address: ";
	cout << setfill(' ') << setw(25);
	cout << "City: ";
	cout << setfill(' ') << setw(25);
	cout << "State: ";
	cout << setfill(' ') << setw(25);
	cout << "Zipcode: ";
	cout << setfill(' ') << setw(25);
	cout << "Phone number: ";

	for (int i = 0; i < count; i++) {
		cout << endl;
		cout << setfill(' ') << setw(25);
		cout << firstName[i];
		cout << setfill(' ') << setw(25);
		cout << lastName[i];
		cout << setfill(' ') << setw(25);
		cout << accNum[i];
		cout << setfill(' ') << setw(25);
		cout << addy[i];
		cout << setfill(' ') << setw(25);
		cout << city[i];
		cout << setfill(' ') << setw(25);
		cout << state[i];
		cout << setfill(' ') << setw(25);
		cout << zip[i];
		cout << setfill(' ') << setw(25);
		cout << phoneNum[i];
	}
	cout << endl;
}


void AllCustomers::getCustomerData() {		// gets data for a specific customer
	
	cout << "\nEnter account's number to search: ";
	while (cout << " " && !(cin >> account)) {  // no string allowed
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
	}
	
	for (int i = 0; i < count; i++) {
		if (accNum[i] == account) {
			cout << "\nFirst name: " << firstName[i] << "\nLast name: " << lastName[i] << "\nAccount number: " << accNum[i]
				<< "\nAddress: " << addy[i] << "\nCity: " << city[i] << "\nState: "
				<< state[i] << "\nZipcode: " << zip[i] << "\nPhone number: " << phoneNum[i] << endl;
			return;
			//outputs all account info
		}

	}
	cout<< "\nCustomer data not found." << endl;
}


void AllCustomers::updateCustomer() {  //updates customer information

	cout << "\nEnter in account's number to search: ";
	while (cout << " " && !(cin >> account)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
	}

	for (int i = 0; i < count; i++) {
		if (accNum[i] == account) {
			cout << "\nEnter in first name: ";
			cin >> fname;
			cout << "Enter in last name: ";
			cin >> lname;
			cout << "Enter in Address: ";
			cin.ignore();
			getline(cin, address);
			cout << "Enter in city: ";
			getline(cin, cit);
			cout << "Enter in state abbreviation in uppercase letters (example = NY): ";
			cin >> sta;
			while (sta.size() != 2) {
				cout << "Incorrect input, try again: ";
				cin >> sta;
			}
			cout << "Enter in 5 digit zipcode:";
			while (cout << " " && !(cin >> zipC) || zipC >= 100000 || zipC <= 9999) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "You have not selected a valid input. Please try again." << endl;
				cout << "Enter in again: ";
			}

			cout << "Enter in 7 digit phone number (exclude area code): ";
			while (cout << " " && !(cin >> phone) || phone >= 10000000 || phone <= 999999) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "You have not selected a valid input. Please try again." << endl;
				cout << "Enter in again: ";
			}
			firstName[i] = fname;
			lastName[i] = lname;
			addy[i] = address;
			city[i] = cit;
			state[i] = sta;
			zip[i] = zipC;
			phoneNum[i] = phone;
			return;
		}
	}
	cout << "\nCustomer data not found." << endl;  //Error message if customer not found
}


void AllCustomers::addCustomer() {

	srand(time(0)); // set seed to time(0)
	int random = rand(); // generate random number
	account = random;

	cout << "\nEnter in first name: ";
	cin >> fname;
	cout << "Enter in last name: ";
	cin >> lname;
	cout << "Enter in Address: ";
	cin.ignore();
	getline(cin, address);
	cout << "Enter in city: ";
	getline(cin, cit);
	cout << "Enter in state abbreviation in uppercase letters (example = NY): ";
	cin >> sta;
	while (sta.size() != 2) {
		cout << "Incorrect input, try again: ";
		cin >> sta;
	}
	cout << "Enter in 5 digit zipcode:";
	while (cout << " " && !(cin >> zipC) || zipC >= 100000 || zipC <= 9999 ) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	cout << "Enter in 7 digit phone number (exclude area code): ";
	while (cout << " " && !(cin >> phone) || phone >= 10000000 || phone <= 999999) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	cout << "Customer added!" << endl;

	firstName.push_back(fname);
	lastName.push_back(lname);
	accNum.push_back(account);
	addy.push_back(address);
	city.push_back(cit);
	state.push_back(sta);
	zip.push_back(zipC);
	phoneNum.push_back(phone);
	count++;
}


void AllCustomers::addMultipleCustomers() {
	int num; // number of customers being added
	cout << "Enter in the number of customers you would like to enter: ";
	while (cout << " " && !(cin >> num) || num <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}
	addingRecursive(num); // calls recursive function

}


void AllCustomers::deleteCustomer() {

	cout << "\nEnter account's number to search for deletion: ";
	while (cout << " " && !(cin >> account)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}

	for (int i = 0; i < count; i++) {
		if (accNum[i] == account) {
			firstName.erase(firstName.begin() + i);
			lastName.erase(lastName.begin() + i);
			accNum.erase(accNum.begin() + i);
			addy.erase(addy.begin() + i);
			city.erase(city.begin() + i);
			state.erase(state.begin() + i);
			zip.erase(zip.begin() + i);
			phoneNum.erase(phoneNum.begin() + i);
			// erase from when the vector begins + i
			count--;  // subtracts a customer

			cout << "\nAccount information was deleted!" << endl;
			return;
		}
	}
	cout << "\nCustomer not found." << endl;
}


void AllCustomers::sortCustomers() {
	int num;
	cout << "Enter in the number 1 for ascending order or the number 2 for descending order: ";
	while (cout << " " && !(cin >> num) || num <= 0 || num >= 3) { // only allows for answers 1 and 2
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have not selected a valid input. Please try again." << endl;
		cout << "Enter in again: ";
	}
	if (num == 1) { // sorts ascending
		cout << "\nYou have chosen ascending order. " << endl;
		sort(lastName.begin(), lastName.end());
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << "Account holder: " << lastName[i] << endl;
		}
		cout << endl;
	}
	else { // sorts descending
		cout << "\nYou have chosen descending order. " << endl;
		sort(lastName.begin(), lastName.end(), greater<string>());
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << "Account holder: " << lastName[i] << endl;
		}
		cout << endl;
	}
}
