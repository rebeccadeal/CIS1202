// Name:			Rebecca Deal
// Date:			2/11/18
// Title:			C-strings
// Description:		A C++ program that uses C-strings instead of the C++ string
//					class to extract the length, location of ‘w’, year, customer
//					number, and order number from a workorder.

#include <iostream>
#include <cstring> // for working with C-strings
#include <cstdlib> // for C-string/numeric conversion
using namespace std;

// Declare function prototypes
int findW(char[], int);
long getCustNum(char[], int);
int getYear(char[], int);
long getOrderNum(char[], int, int);

int main()
{
	// Declare variables
	const int SIZE = 20;
	char workOrder[SIZE];
	int strLength, wPointer, year;
	long custNumber, workOrderNumber;
	
	// Display instructions & prompt user for the work order
	cout << "Program Instructions:" << endl << endl;
	cout << "You will enter a three part work order code in the following format: "
	<< endl << "CustomerNumber + 'w' + Year + OrderNumber" << endl << endl;
	cout << "The first 5-6 digits contain the customer number "
	<< "(digits before the 'w')." << endl;
	cout << "The 2 digits following the 'w' represent the year." << endl;
	cout << "The remaining digits (up to 5) represent the work order number." << endl << endl;
	cout << "Enter the work order code: ";
	cin.getline(workOrder, SIZE);
	
	// Call functions to set values of work order component variables
	strLength = static_cast<int>(strlen(workOrder)); // convert long to int
	wPointer = findW(workOrder, strLength);
	custNumber = getCustNum(workOrder, wPointer);
	year = getYear(workOrder, wPointer);
	workOrderNumber = getOrderNum(workOrder, wPointer, strLength);
	
	// Output the components of the work order
	cout << endl << "Work Order Components:" << endl;
	cout << "Length = " << strLength << endl;
	cout << "Location of the 'w' = " << wPointer << endl;
	cout << "Customer number = " << custNumber << endl;
	cout << "Year of the order = " << year << endl;
	cout << "Order number = " << workOrderNumber << endl << endl;

	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	string pause;
	getline(cin, pause);
	return 0;
}

// Find the location of the 'w' in the work order array
int findW(char workOrder[], int strLength)
{
	int wPointer = 0;
	for (int i = 0; i < strLength; i++)
	{
		if (workOrder[i] == 'w')
		{
			wPointer = i;
		}
	}
	return wPointer;
}

// Get the 5-6 digit customer number before the 'w'
long getCustNum(char workOrder[], int wPointer)
{
	char custNum[wPointer];
	for (int i = 0; i < wPointer; i++)
	{
		custNum[i] = workOrder[i];
	}
	return atol(custNum);
}

// Get the 2 digit year after the 'w'
int getYear(char workOrder[], int wPointer)
{
	char year[2];
	year[0] = workOrder[wPointer + 1];
	year[1] = workOrder[wPointer + 2];
	return atoi(year);
}

// Get the up to 5 digit work order number after the 'w'
long getOrderNum(char workOrder[], int w, int strLength)
{
	char orderNum[strLength - w - 2];
	for (int i = 0; i < strLength - w - 2; i++)
	{
		orderNum[i] = workOrder[i + w + 3];
	}
	return atol(orderNum);
}
