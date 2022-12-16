#include "AllCustomers.h"
#include "AllPurchases.h"
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

int loadMenu() {		// loads menu up
	int choice;

	cout << endl;
	cout << "Welcome to the NickMart clothes department store!" << endl;
	cout << setfill('*') << setw(50);
	cout << " " << endl;
	cout << " 1. Print all personal data of all customers" << endl;
	cout << " 2. Show a specific Customers' data" << endl;
	cout << " 3. Sort all customers in ascending or descending order" << endl;
	cout << " 4. Add a new customer" << endl;
	cout << " 5. Add multiple customers" << endl;
	cout << " 6. Update a customers' information" << endl;
	cout << " 7. Delete a customers' information" << endl;
	cout << " 8. Add a new customers' purchase" << endl;
	cout << " 9. Add multiple new customers' purchases" << endl;
	cout << " 10. Print out the total spent for a customers' purchases" << endl;
	cout << " 11. Store all information into file" << endl;
	cout << " 12. Quit" << endl;

	while (cout << "Choose your option: " && !(cin >> choice) || choice > 12 || choice < 1) {		// allows user to put a string and try again
		cin.clear();		//clear bad input
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');		//discard input
		cout << "You have not selected a valid input. Please try again." << endl;
	}
	return choice;		// returns user choice
}


int main() {
	
	vector<AllCustomers>data(100);
	vector<AllPurchases>data2(100);
	data[0].loadData();
	data2[0].loadData2();
	
	// switch statement for menu choices
	do {
		switch (loadMenu()) {
		case 1:
			data[0].showAllData();
			break;
		case 2:
			data[0].getCustomerData();
			break;
		case 3:
			data[0].sortCustomers();
			break;
		case 4:
			data[0].addCustomer();
			break;
		case 5:
			data[0].addMultipleCustomers();
			break;
		case 6:
			data[0].updateCustomer();
			break;
		case 7:
			data[0].deleteCustomer();
			break;
		case 8:
			data2[0].addPurchase();
			break;
		case 9:
			data2[0].addMultiplePurchases();
			break;
		case 10:
			data2[0].totalSpent();
			break;
		case 11:
			data[0].writeFile();
			data2[0].writeFile2();
			break;
		case 12:
			exit(0);
			break;
		default:
			cout << "You have not selected a valid input. Please try again. " << endl;
		}
	} while (1);

return 0;
}
