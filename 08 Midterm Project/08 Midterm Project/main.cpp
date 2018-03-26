// Name:			Rebecca Deal
// Date:			3/4/18
// Title:			Midterm Project
// Description:		A menu-driven C++ program to keep track of the inventory
//					and sales for a vending machine company’s machines at
//					various college campuses.

#include <iostream>
#include <string>
#include <iomanip> // for decimal precision & alignment
#include <fstream> // for file stream object
using namespace std;

// Declare global constants
const int MAX_SODA_BRANDS = 5; // max number of soda brands in sodas array
const int MAX_MACHINES = 10; // max number of vending machines in machines array

// Define enumerated data
enum SodaBrands {COKE, DIET_COKE, SPRITE, SPRITE_ZERO, DASANI};

// Define structured data
struct Drinks
{
	double price;
	int numSodas;
};
struct vendingMachine
{
	string location;
	Drinks sodas[MAX_SODA_BRANDS];
};

// Declare function prototypes
void loadVendingMachines(vendingMachine[], int&);
void showVendingMachines(vendingMachine[], int);
void getDrinkName(SodaBrands, string&);
int getLocation(vendingMachine[], int);
int getDrinkSelection();

int main()
{
	// Declare array
	vendingMachine machines[MAX_MACHINES];
	
	// Declare variables
	int numMachines = -1;
	int menuChoice = 0, sodaChoice = 0;
	double paid;
	
	// Call function to load array of vendingMachine structs
	loadVendingMachines(machines, numMachines);
	
	// Call function to show beginning inventory
	cout << "BEGINNING INVENTORY" << endl << endl;
	showVendingMachines(machines, numMachines);
	
	while (menuChoice != 6)
	{
		// Call function to get location choice
		menuChoice = getLocation(machines, numMachines);
		if (menuChoice == 6)
			break;
		
		// Call function to get soda choice
		sodaChoice = getDrinkSelection();
		
		// Display price information for the soda choice
		cout << "Your selected location: " << machines[menuChoice].location << endl;
		string drinkName;
		getDrinkName(static_cast<SodaBrands>(sodaChoice), drinkName);
		cout << "Your selected soda: " << drinkName << endl;
		cout << "The price of your soda: $" << fixed << setprecision(2)
		<< machines[menuChoice].sodas[sodaChoice].price << endl;
		cout << "Please enter amount paid: $";
		cin >> paid;
		while (machines[menuChoice].sodas[sodaChoice].price > paid)
		{
			cout << "Amount paid must be greater than or equal to the price of the soda.";
			cout << endl << "Please enter amount paid again: $";
			cin >> paid;
		}
		cout << "Change due: $" << fixed << setprecision(2)
		<< paid - machines[menuChoice].sodas[sodaChoice].price << endl;
		
		// Decrement the soda choice for the location by one
		machines[menuChoice].sodas[sodaChoice].numSodas--;
		cout << endl;
	}
	
	// Call function to show ending inventory
	cout << "ENDING INVENTORY" << endl << endl;
	showVendingMachines(machines, numMachines);
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	string pause;
	cin.ignore();
	getline(cin, pause);
	return 0;
}

// Read the input file & transfer the input data into the array of vendingMachine structs
void loadVendingMachines(vendingMachine machines[], int &numMachines)
{
	// Declare input file stream object
	ifstream inFile;
	
	// Open input file stream
	inFile.open("vendingMachines.txt");
	
	// Load data from each line into arrays
	char ch;
	string temp;
	for (int i = 0; i < MAX_MACHINES; i++)
	{
		if (inFile.good())
		{
			inFile >> machines[i].location;
			inFile.get(ch);
			while (ch == ' ')
			{
				machines[i].location += ' ';
				inFile >> temp;
				machines[i].location += temp;
				inFile.get(ch);
			}
			for (int j = 0; j < MAX_SODA_BRANDS; j++)
			{
				inFile >> machines[i].sodas[j].price >> machines[i].sodas[j].numSodas;
			}
			numMachines++;
		}
	}
	
	// Close input file stream
	inFile.close();
}

// Display the contents of the array of vendingMachine structs
void showVendingMachines(vendingMachine machines[], int numMachines)
{
	string drinkName;
	for (int i = 0; i < numMachines; i++)
	{
		cout << "Machine location: " << machines[i].location << endl;
		for (int j = 0; j < MAX_SODA_BRANDS; j++)
		{
			getDrinkName(static_cast<SodaBrands>(j), drinkName);
			cout << "\tsoda: " << drinkName << ", price: $" << fixed
			<< setprecision(2) << machines[i].sodas[j].price << ", number: "
			<< machines[i].sodas[j].numSodas << endl;
		}
		cout << endl;
	}
}

// Translate a SodaBrands enum value into a soda brand name string
void getDrinkName(SodaBrands sodaBrand, string &brandName)
{
	switch (sodaBrand) {
		case COKE:
			brandName = "Coke";
			break;
		case DIET_COKE:
			brandName = "Diet Coke";
			break;
		case SPRITE:
			brandName = "Sprite";
			break;
		case SPRITE_ZERO:
			brandName = "Sprite Zero";
			break;
		case DASANI:
			brandName = "Dasani Water";
			break;
	}
}

// Display the list of locations & read in & validate the user-inputted location number
int getLocation(vendingMachine machines[], int numMachines)
{
	int location;
	cout << "Select a location from the following:" << endl;
	for (int i = 0; i < numMachines; i++)
	{
		cout << i << ": " << machines[i].location << endl;
	}
	cout << "6: Exit" << endl << endl;
	cout << "Enter location choice: ";
	cin >> location;
	while ((location < 0) || (location > 6))
	{
		cout << "Location choice must be a number from 0 through 6." << endl;
		cout << "Please enter location choice again: ";
		cin >> location;
	}
	cout << endl;
	return location;
}

// Display the menu of soda choices by looping through the SodaBrands enum values
// & read in & validate the user-inputted soda choice number
int getDrinkSelection()
{
	int drink;
	string drinkName;
	cout << "Select a soda from the following:" << endl;
	for (int i = 0; i < MAX_SODA_BRANDS; i++)
	{
		getDrinkName(static_cast<SodaBrands>(i), drinkName);
		cout << i << ": " << drinkName << endl;
	}
	cout << endl << "Enter soda choice: ";
	cin >> drink;
	while ((drink < 0) || (drink > 4))
	{
		cout << "Soda choice must be a number from 0 through 4." << endl;
		cout << "Please enter soda choice again: ";
		cin >> drink;
	}
	cout << endl;
	return drink;
}
