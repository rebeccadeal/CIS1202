// Name:			Rebecca Deal
// Due Date:		1/17/18
// Title:			Baseball Statistics
// Description:		A C++ program to generate some important statistics about a
//					college baseball team's players.

#include <iostream>
#include <string>
#include <iomanip> // for decimal precision & alignment
#include <fstream> // for file stream object
#include <cmath> // for rounding
using namespace std;

// Declare function prototypes
void loadArrays(int [], int [], int [], int [], int [], int [], int &);
void calcBatAvg(int [], int [], int [], int);
void printStats(int [], int [], int [], int [], int [], int [], int);
int bestPlayer(int [], int);
int worstPlayer(int [], int);

int main()
{
	// Declare arrays & size
	const int SIZE = 20;
	int playerNum[SIZE], atBats[SIZE], hits[SIZE], runs[SIZE], rbis[SIZE], batAvg[SIZE];
	
	// Declare variables
	int count = -1;
	int best, worst;
	
	// Call functions
	loadArrays(playerNum, atBats, hits, runs, rbis, batAvg, count);
	calcBatAvg(atBats, hits, batAvg, count);
	printStats(playerNum, atBats, hits, runs, rbis, batAvg, count);
	
	// Calculate & display the best & worst players
	best = bestPlayer(batAvg, count);
	worst = worstPlayer(batAvg, count);
	cout << "The Best Player is Player Number: " << playerNum[best]
	<< " with batting average of " << batAvg[best] << endl
	<< "The Worst Player is Player Number: " << playerNum[worst]
	<< " with batting average of " << batAvg[worst] << endl;

	// Begin cross-platform alternative to system("pause")
	cout << endl;
	cout << "Press enter key to continue...";
	cin.ignore();
	string pause;
	getline(cin, pause);
	return 0;
}

// Load arrays from the input file
void loadArrays(int playerNum[], int atBats[], int hits[], int runs[], int rbis[], int batAvg[], int &count)
{
	// Declare input file stream object
	ifstream inFile;
	
	// Open input file stream
	inFile.open("BaseballStats.txt");
	
	// Load data from each line into arrays
	while (!inFile.eof())
	{
		count++;
		inFile >> playerNum[count] >> atBats[count] >> hits[count] >> runs[count] >> rbis[count];
	}

	// Close input file stream
	inFile.close();
}

// Calculate batting average for each player
void calcBatAvg(int atBats[], int hits[], int batAvg[], int count)
{
	for (int i = 0; i < count; i++)
	{
		batAvg[i] = round(hits[i] * 1000 / atBats[i]);
	}
}

// Display statistics
void printStats(int playerNum[], int atBats[], int hits[], int runs[], int rbis[], int batAvg[], int count)
{
	int totBats = 0, totHits = 0, totRuns = 0, totRbis = 0;
	int w = 15;
	
	// Display column headers
	cout << "Baseball Stats" << endl << endl << left
	<< setw(w) << "Player Num" << setw(w) << "At Bats" << setw(w) << "Hits"
	<< setw(w) << "Runs" << setw(w) << "RBIs" << setw(w) << "Bat Avg"
	<< "Comment" << endl;
	
	// Display stats for each player
	for (int i = 0; i < count; i++)
	{
		cout << right << setw(w - 12) << playerNum[i] << setw(w) << atBats[i]
		<< setw(w) << hits[i] << setw(w) << runs[i] << setw(w) << rbis[i]
		<< setw(w) << batAvg[i] << setw(w - 3) << " ";
		if (batAvg[i] < 300)
			cout << "LITTLE LEAGUE";
		else if (batAvg[i] < 500)
			cout << "FARM LEAGUE";
		else
			cout << "WORLD SERIES";
		cout << endl;
		totBats += atBats[i];
		totHits += hits[i];
		totRuns += runs[i];
		totRbis += rbis[i];
	}
	
	// Display totals & team batting average
	cout << "TOTALS:" << setw(w - 4) << totBats << setw(w) << totHits
	<< setw(w) << totRuns << setw(w) << totRbis << endl << endl
	<< "The Team Batting Average is: " << round(totHits * 1000 / totBats) << endl;
}

// Determine the best player
int bestPlayer(int batAvg[], int count)
{
	int best = 0;
	for (int i = 0; i < count; i++)
	{
		if (batAvg[i] > batAvg[best])
			best = i;
	}
	return best;
}

// Determine the worst player
int worstPlayer(int batAvg[], int count)
{
	int worst = 0;
	for (int i = 0; i < count; i++)
	{
		if (batAvg[i] < batAvg[worst])
			worst = i;
	}
	return worst;
}
