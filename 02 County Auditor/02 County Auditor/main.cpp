// Name:			Rebecca Deal
// Due Date:		1/24/18
// Title:			County Auditor Search and Sort
// Description:		A C++ program for the county auditor that uses parallel
//					arrays to input, print, search, find largest amount due,
//					and sort the tax data.

#include <iostream>
#include <string>
#include <iomanip> // for decimal precision & alignment
#include <fstream> // for file stream object
#include <cmath> // for rounding
using namespace std;

// Declare function prototypes
int showMenu();
void loadArrays(string [], double [], int &);
void showArrays(string [], double [], int);
void lookUpTaxes(string [], double [], int);
void sortTaxes(string [], double [], int);
void biggestTaxes(string [], double [], int);

int main()
{
	// Declare arrays & size
	int SIZE = 10;
	string address[SIZE];
	double amtDue[SIZE];
	
	// Declare variables
	int length = -1;
	
	// Load array data from file
	loadArrays(address, amtDue, length);
	
	// Display menu & prompt user for menu choice
	cout << "County Auditor Property Tax Sort and Search" << endl << endl;
	int choice = showMenu();
	while (choice != 5)
	{
		if (choice == 1)
			showArrays(address, amtDue, length);
		else if (choice == 2)
			lookUpTaxes (address, amtDue, length);
		else if (choice == 3)
			sortTaxes(address, amtDue, length);
		else if (choice == 4)
			biggestTaxes(address, amtDue, length);
		else
			cout << "Invalid menu choice. Please try again." << endl << endl;
		choice = showMenu();
	}
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	cin.ignore();
	string pause;
	getline(cin, pause);
	return 0;
}

// Display option menu
int showMenu()
{
	int choice;
	cout << "Options:" << endl
	<< "1. Display property tax data" << endl
	<< "2. Look up taxes for a particular address" << endl
	<< "3. Sort tax amounts into ascending order" << endl
	<< "4. Display property address with the largest amount due" << endl
	<< "5. Exit the program" << endl << endl
	<< "Please enter your menu option selection: ";
	cin >> choice;
	cout << endl;
	return choice;
}

// Load arrays from the input file
void loadArrays(string address[], double amtDue[], int &length)
{
	// Declare input file stream object
	ifstream inFile;
	
	// Open input file stream
	inFile.open("Prog3Input.txt");
	
	// Load data from each line into arrays
	while (!inFile.eof())
	{
		length++;
		string address1, address2;
		inFile >> address1 >> address2;
		address[length] = address1 + " " + address2;
		inFile >> amtDue[length];
	}
	
	// Close input file stream
	inFile.close();
}

// Display property tax data
void showArrays(string address[], double amtDue[], int length)
{
	int w = 15;
	cout << left << setw(w) << "Address" << setw(w) << "Amount Due" << endl;
	for (int i = 0; i < length; i++) {
		cout << setw(w) << address[i] << setw(w) << amtDue[i] << endl;
	}
	cout << endl;
}

// Look up the tax amount for a specific address
void lookUpTaxes(string address[], double amtDue[], int length)
{
	string search;
	int amount = 0;
	cin.ignore();
	cout << "Enter address to look up: ";
	getline(cin, search);
	for (int i = 0; i < length; i++)
	{
		if (address[i] == search)
			amount = amtDue[i];
	}
	cout << "The taxes for " << search << " = " << amount << endl << endl;
}

// Sort tax amounts in ascending order
void sortTaxes(string address[], double amtDue[], int length)
{
	int max, index, tempAmt;
	string tempAddress;
	for (max = length - 1; max > 0; max--)
	{
		for (index = 0; index < max; index++)
		{
			if (amtDue[index] > amtDue[index + 1])
			{
				tempAmt = amtDue[index];
				amtDue[index] = amtDue[index + 1];
				amtDue[index + 1] = tempAmt;
				tempAddress = address[index];
				address[index] = address[index + 1];
				address[index + 1] = tempAddress;
			}
		}
	}
}

// Determine which address paid the largest tax amount
void biggestTaxes(string address[], double amtDue[], int length)
{
	string bigAddress;
	int bigAmt = 0;
	for (int i = 0; i < length; i++)
	{
		if (amtDue[i] > bigAmt)
		{
			bigAddress = address[i];
			bigAmt = amtDue[i];
		}
	}
	cout << "The largest tax amount = " << bigAmt << " at " << bigAddress << endl << endl;
}
