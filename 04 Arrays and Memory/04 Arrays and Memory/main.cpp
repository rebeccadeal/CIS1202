// Name:			Rebecca Deal
// Date:			2/7/18
// Title:			Arrays and Memory
// Description:		A C++ program that uses an array (accessed with pointers
//					rather than subscripts) to store, display, sort, and total
//					the income for a friend's 7 rental properties.

#include <iostream>
#include <string>
using namespace std;

// Declare function prototypes
int getMenuItem();
void enterRents(int*, int); // menu option #1
void displayRents(int*, int); // menu option #2
void selectionSort(int*, int); // menu option #3
int totalRents(int*, int); // menu option #4
void displayMemoryLocations(int*, int); // menu option #5

int main()
{
	// Declare arrays & size
	const int SIZE = 7;
	int rents[SIZE];
	
	// Display menu & prompt user for menu choice
	cout << "Sinclair Property Management Company" << endl << endl;
	int choice = getMenuItem();
	while (choice != 6)
	{
		if (choice == 1)
			enterRents(rents, SIZE);
		else if (choice == 2)
			displayRents(rents, SIZE);
		else if (choice == 3)
			selectionSort(rents, SIZE);
		else if (choice == 4)
			cout << "Total rents = $" << totalRents(rents, SIZE) << endl << endl;
		else if (choice == 5)
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
	<< "│ 4 │ Total rent amounts				  │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 5 │ Display rent array memory locations │" << endl
	<< "├───┼─────────────────────────────────────┤" << endl
	<< "│ 6 │ Exit the program					  │" << endl
	<< "└───┴─────────────────────────────────────┘" << endl << endl
	<< "Enter menu selection: ";
	cin >> choice;
	cout << endl;
	return choice;
}

// Input rent amounts
void enterRents(int *rents, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter rent amount #" << i + 1 << ": ";
		cin >> *(rents + i);
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
void selectionSort(int *rents, int size)
{
	int minIndex, minValue;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = *(rents + start);
		for (int index = start + 1; index < size; index++)
		{
			if (*(rents + index) < minValue)
			{
				minValue = *(rents + index);
				minIndex = index;
			}
		}
		int temp = *(rents + minIndex);
		*(rents + minIndex) = *(rents + start);
		*(rents + start) = temp;
	}
}

// Total rent amounts using pointers
int totalRents(int *rents, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(rents + i);
	}
	return sum;
}

// Display memory locations of rents
void displayMemoryLocations(int *rents, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Memory address of cell " << i << " = " << (rents + i) << endl;
	}
	cout << endl;
}
