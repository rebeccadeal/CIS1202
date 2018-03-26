// Name:			Rebecca Deal
// Date:			3/18/18
// Title:			Binary File Update
// Description:		A menu-driven C++ program that updates the binary inventory
//					file, inventory.dat, which is composed of records based on
//					the constructed Product structure.

#include <iostream>
#include <string>
#include <iomanip> // for decimal precision & alignment
#include <fstream> // for file stream object
using namespace std;

// Declare global constants
const int DESC_SIZE = 40; // max number of characters in prodName array

// Define structured data
struct Product
{
	int prodNum;
	char prodName[DESC_SIZE];
	double price;
	int qty;
};

// Declare function prototypes
int showMenu();
void printFile(fstream&);
void displayRecord(fstream&);
void modifyRecord(fstream&);

int main()
{
	// Declare file stream object
	fstream file;
	
	// Declare variable for menu choice
	int menuChoice = 0;
	
	// Open the binary inventory file
	file.open("inventory.dat", ios::in | ios::out | ios::binary);
	
	// Begin main while loop for menu choice
	while (menuChoice != 4)
	{
		menuChoice = showMenu();
		switch (menuChoice)
		{
			case 1:
				printFile(file);
				break;
			case 2:
				displayRecord(file);
				break;
			case 3:
				modifyRecord(file);
				break;
			case 4:
				break;
		}
	}
	
	// Close the file
	file.close();
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	string pause;
	cin.ignore();
	getline(cin, pause);
	return 0;
}

// Display the menu, prompt the user for menu choice, & validate choice
int showMenu()
{
	// Display the menu
	cout << "Options:" << endl
	<< "1. Display product inventory file" << endl
	<< "2. Display a particular product" << endl
	<< "3. Modify a product record" << endl
	<< "4. Exit the program" << endl << endl;
	
	// Prompt the user for their menu choice
	int choice;
	cout << "Enter menu selection: ";
	cin >> choice;
	
	// Validate the user's menu choice
	while ((choice < 1) || (choice > 4))
	{
		cout << "Invalid menu choice. Must be #1-4." << endl
		<< "Please enter menu selection again: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

// Display product inventory file by reading each record into a Product struct
// & then displaying the fields of each struct to the screen
void printFile(fstream &file)
{
	// Declare local variables
	Product prod;
	int recCount = 0;
	
	// Clear the eof flag & seek to the beginning of the file
	file.clear();
	file.seekg(0L, ios::beg);
	
	// Read the first product record
	file.read(reinterpret_cast<char *>(&prod), sizeof(prod));
	
	// Display the contents of each product record in the file
	while (!file.eof())
	{
		cout << "Record #" << recCount << endl
		<< "Product Number: " << prod.prodNum << endl
		<< "Product Name: " << prod.prodName << endl
		<< "Price: $" << fixed << showpoint << setprecision(2) << prod.price << endl
		<< "Quantity: " << prod.qty << endl << endl;
		file.read(reinterpret_cast<char *>(&prod), sizeof(prod));
		recCount++;
	}
}

// Display a particular product by seeking the file for the user-inputted record
// number & then displaying the fields of the corresponding struct to the screen
void displayRecord(fstream &file)
{
	// Declare local variables
	Product prod;
	long recNum;
	
	// Prompt user for the record to display
	cout << "Enter record number of product to be displayed: ";
	cin >> recNum;
	cout << endl;
	
	// Clear the eof flag & seek to the beginning of the file
	file.clear();
	file.seekg(0L, ios::beg);
	
	// Seek to the beginning of the record to be displayed & read it
	file.seekg(recNum * sizeof(prod), ios::beg);
	file.read(reinterpret_cast<char *>(&prod), sizeof(prod));
	
	// Display the contents of the particular product record
	cout << "Record #" << recNum << endl
	<< "Product Number: " << prod.prodNum << endl
	<< "Product Name: " << prod.prodName << endl
	<< "Price: $" << fixed << showpoint << setprecision(2) << prod.price << endl
	<< "Quantity: " << prod.qty << endl << endl;
}

// Modify a product record by seeking the file for the user-inputted record
// number & then writing the new user-inputted field values to the file
void modifyRecord(fstream &file)
{
	// Declare local variables
	Product prod;
	long recNum;
	
	// Prompt user for the record to modify
	cout << "Enter record number of product to be modified: ";
	cin >> recNum;
	cout << endl;
	
	// Clear the eof flag & seek to the beginning of the file
	file.clear();
	file.seekg(0L, ios::beg);
	
	// Seek to the beginning of the record to be modified & read it
	file.seekg(recNum * sizeof(prod), ios::beg);
	file.read(reinterpret_cast<char *>(&prod), sizeof(prod));
	
	// Prompt the user for the new contents of the particular product record
	cout << "Enter the new..." << endl;
	cout << "Product Number: ";
	cin >> prod.prodNum;
	cout << "Product Name: ";
	cin.ignore();
	cin.getline(prod.prodName, DESC_SIZE);
	cout << "Price: $";
	cin >> prod.price;
	cout << "Quantity: ";
	cin >> prod.qty;
	cout << endl;
	
	// Move back to the beginning of the particular product record
	file.seekp(recNum * sizeof(prod), ios::beg);
	
	// Write the new record over the current record
	file.write(reinterpret_cast<char *>(&prod), sizeof(prod));
	
	// Display message that the record was update
	cout << "Record #" << recNum << " was updated successfully." << endl << endl;
}
