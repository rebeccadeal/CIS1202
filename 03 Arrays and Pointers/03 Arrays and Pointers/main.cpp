// Name:			Rebecca Deal
// Due Date:		1/28/18
// Title:			Arrays and Pointers
// Description:		A C++ program that uses an array to store, display, sort,
//					and total the income for a friend's 5 rental properties.

#include <iostream>
#include <string>
using namespace std;

// Declare function prototypes
int getMenuItem();
void enterRents(int[], int);
void displayRents(int*, int);
void selectionSort(int[], int);
void displayMemoryLocations(int[], int);

int main()
{
	// Declare arrays & size
	const int SIZE = 5;
	int rents[SIZE];
	
	// Display menu & prompt user for menu choice
	cout << "Sinclair Property Management Company" << endl << endl;
	int choice = getMenuItem();
	while (choice != 5)
	{
		if (choice == 1)
			enterRents(rents, SIZE);
		else if (choice == 2)
			displayRents(rents, SIZE);
		else if (choice == 3)
			selectionSort(rents, SIZE);
		else if (choice == 4)
			displayMemoryLocations(rents, SIZE);
		else
			cout << "Invalid menu choice. Please try again." << endl << endl;
		choice = getMenuItem();
	}
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	cin.ignore();
	string pause;
	getline(cin, pause);
	return 0;
}

// Display option menu
int getMenuItem()
{
	int choice;
	cout << "┌─────────────────────────────────────────┐" << endl
	<< "│ Options:								  │" << endl
	<< "├───┬─────────────────────────────────────┤" << endl
	<< "│ 1 │ Enter rent amounts				  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 2 │ Display rent amounts				  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 3 │ Sort rent amounts from low to high  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 4 │ Display rent array memory locations │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 5 │ Exit the program					  │" << endl
	<< "└───┴─────────────────────────────────────┘" << endl << endl
	<< "Enter menu selection: ";
	cin >> choice;
	cout << endl;
	return choice;
}

// Input rent amounts
void enterRents(int rents[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter rent amount #" << i + 1 << ": ";
		cin >> rents[i];
	}
	cout << endl;
}

// Display rent amounts using pointers
void displayRents(int *rents, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Rental property #" << i + 1 << ": " << *(rents + i) << endl;
	}
	cout << endl;
}

// Sort rent amounts into ascending order
void selectionSort(int rents[], int size)
{
	int minIndex, minValue;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = rents[start];
		for (int index = start + 1; index < size; index++)
		{
			if (rents[index] < minValue)
			{
				minValue = rents[index];
				minIndex = index;
			}
		}
		int temp = rents[minIndex];
		rents[minIndex] = rents[start];
		rents[start] = temp;
	}
}

// Display memory locations of rents
void displayMemoryLocations(int rents[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Memory address of cell " << i << " = " << &rents[i] << endl;
	}
	cout << endl;
}
