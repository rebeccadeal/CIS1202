#include <iostream>
#include <string>
using namespace std;

int main()
{
	string months[12] = {	"January", "February", "March", "April", "May",
							"June", "July", "August", "September",
							"October", "November", "December"	};
	double rainfall[12];
	
	double rainSum = 0;
	
	for (int i = 0; i < 12; i++) {
		cout << "Enter rainfall for " << months[i] << ": ";
		cin >> rainfall[i];
		rainSum += rainfall[i];
	}
	
	int minIndex, minValue;
	
	for (int start = 0; start < 11; start++)
	{
		minIndex = start;
		minValue = rainfall[start];
		for (int index = start + 1; index < 12; index++)
		{
			if (rainfall[index] < minValue)
			{
				minValue = rainfall[index];
				minIndex = index;
			}
		}
		int temp = rainfall[minIndex];
		rainfall[minIndex] = rainfall[start];
		rainfall[start] = temp;
		string temp2 = months[minIndex];
		months[minIndex] = months[start];
		months[start] = temp2;
	}
	
	cout << "Total rainfall: " << rainSum << endl;
	cout << "Average rainfall: " << rainSum / 12 << endl;
	cout << "Least rainfall in: " << months[0] << endl;
	cout << "Most rainfall in: " << months[11] << endl;
	
	for (int i = 0; i < 12; i++) {
		cout << rainfall[i] << " inches in " << months[i] << endl;
	}
	
	return 0;
}