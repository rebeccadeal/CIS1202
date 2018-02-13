#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int N = 20;
	string names[N];
	
	cout << "Enter number of names to read: ";
	cin >> N;
	
	if (N != 20)
	{
		cout << "Error opening names";
		return 0;
	}
	
	ifstream inFile;
	
	inFile.open("names.txt");
	
	for (int i = 0; i < N; i++) {
		getline(inFile, names[i]);
	}
	
	inFile.close();
	
	return 0;
}
