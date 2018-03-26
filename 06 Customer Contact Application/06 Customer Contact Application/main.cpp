// Name:			Rebecca Deal
// Date:			2/18/18
// Title:			Customer Contact Application
// Description:		A C++ program that uses an array of nested structs to store
//					the addresses for your store’s customers.

#include <iostream>
#include <string>
using namespace std;

// Define structured data
struct Address
{
	string street, city, state;
	int zip;
};
struct Customer
{
	string firstNm, lastNm;
	Address busAddr, homeAddr;
};

// Declare function prototypes
int displayMenu();
Customer getCustomer();
Address getAddress();
void showCustomer(Customer);
void findCust(Customer[], int);

int main()
{
	// Declare array & size
	const int SIZE = 10;
	Customer customers[SIZE];
	
	// Declare & initialize variables
	int choice = 0;
	int numCust = 0;
	
	// Begin while loop for menu option selection
	while (choice <= 4)
	{
		choice = displayMenu();
		if (choice == 1)
		{
			customers[numCust] = getCustomer();
			numCust++;
		}
		else if (choice == 2)
		{
			if (numCust == 0)
			{
				cout << "There are no customers to show. "
				<< "Enter a customer first." << endl << endl;
			}
			else
			{
				for (int i = 0; i < numCust; i++)
				{
					showCustomer(customers[i]);
				}
			}
		}
		else if (choice == 3)
		{
			if (numCust == 0)
			{
				cout << "There are no customers to search. "
				<< "Enter a customer first." << endl << endl;
			}
			else
			{
				findCust(customers, numCust);
			}
		}
		else
		{
			break;
		}
	}
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	cin.ignore();
	string pause;
	getline(cin, pause);
	return 0;
}

// Display option menu
int displayMenu()
{
	int choice;
	cout << "┌─────────────────────────────────────────┐" << endl
	<< "│ Options:								  │" << endl
	<< "├───┬─────────────────────────────────────┤" << endl
	<< "│ 1 │ Enter new customer				  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 2 │ Display all customers				  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 3 │ Display a particular customer		  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 4 │ Exit the program					  │" << endl
	<< "└───┴─────────────────────────────────────┘" << endl << endl
	<< "Enter menu selection: ";
	cin >> choice;
	while ((choice < 1) || (choice > 4))
	{
		cout << "Invalid menu selection. Please try again: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

// Prompt user to input information for a customer
Customer getCustomer()
{
	Customer cust;
	cout << "Enter customer first name: ";
	cin >> cust.firstNm;
	cout << "Enter customer last name: ";
	cin >> cust.lastNm;
	cin.ignore();
	cout << cust.firstNm << "'s business address..." << endl;
	cust.busAddr = getAddress();
	cin.ignore();
	cout << cust.firstNm << "'s home address..." << endl;
	cust.homeAddr = getAddress();
	cout << endl;
	return cust;
}

// Prompt user to input information for an address
Address getAddress()
{
	Address addr;
	cout << "\tEnter street address: ";
	getline(cin, addr.street);
	cout << "\tEnter city: ";
	getline(cin, addr.city);
	cout << "\tEnter state: ";
	getline(cin, addr.state);
	cout << "\tEnter zip code: ";
	cin >> addr.zip;
	return addr;
}

// Display information for a customer
void showCustomer(Customer cust)
{
	cout << "Customer name: " << cust.firstNm << " " << cust.lastNm << endl;
	cout << cust.firstNm << "'s business address:" << endl;
	cout << "\t" << cust.busAddr.street << " " << cust.busAddr.city << ", "
	<< cust.busAddr.state << " " << cust.busAddr.zip << endl;
	cout << cust.firstNm << "'s home address:" << endl;
	cout << "\t" << cust.homeAddr.street << " " << cust.homeAddr.city << ", "
	<< cust.homeAddr.state << " " << cust.homeAddr.zip << endl << endl;
}

// Search for a customer by name & display their information
void findCust(Customer custArr[], int numCust)
{
	string searchFirstNm, searchLastNm;
	int custIndex = 0;
	bool isFound = false;
	if (numCust == 1)
		cout << "There is 1 customer in the list." << endl << endl;
	else
		cout << "There are " << numCust << " customers in the list." << endl << endl;
	cout << "Please enter the first & last names of the customer you would like to look up:" << endl;
	cout << "\tEnter customer first name: ";
	cin >> searchFirstNm;
	cout << "\tEnter customer last name: ";
	cin >> searchLastNm;
	cout << endl;
	for (int i = 0; i < numCust; i++)
	{
		if ((searchFirstNm == custArr[i].firstNm) && (searchLastNm == custArr[i].lastNm))
		{
			custIndex = i;
			isFound = true;
			break;
		}
	}
	if (isFound == true)
	{
		cout << "The customer you entered was found in the list." << endl << endl;
		cout << "Customer name: " << custArr[custIndex].firstNm << " "
		<< custArr[custIndex].lastNm << endl;
		cout << custArr[custIndex].firstNm << "'s business address:" << endl;
		cout << "\t" << custArr[custIndex].busAddr.street << " "
		<< custArr[custIndex].busAddr.city << ", " << custArr[custIndex].busAddr.state
		<< " " << custArr[custIndex].busAddr.zip << endl;
		cout << custArr[custIndex].firstNm << "'s home address:" << endl;
		cout << "\t" << custArr[custIndex].homeAddr.street << " "
		<< custArr[custIndex].homeAddr.city << ", " << custArr[custIndex].homeAddr.state
		<< " " << custArr[custIndex].homeAddr.zip << endl << endl;
	}
	else
	{
		cout << "The customer you entered was not found in the list." << endl << endl;
	}
}
