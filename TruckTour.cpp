// TruckTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int truckTour(vector<vector<int>>);

int main()
{
	vector<vector<int>> petrolpumps{
		{ 1, 5},
		{ 2, 2},
		{ 3, 4},
		{10, 3},
	};

	cout << truckTour(petrolpumps) << endl;

	return EXIT_SUCCESS;
}

int truckTour(vector<vector<int>> petrolpumps) 
{
	int start = 0;
	int size = petrolpumps.size();
	int cap = 0;
	
	int end = 0;
	int temp = 0;

	while(end < size)
	{
		cap += petrolpumps[temp][0];

		if (cap < petrolpumps[temp][1])
		{
			start = temp + 1;
			end = 0;
			cap = 0;
			temp++;
			if (start == size)
				start = 0;
		}
		else
		{
			cap -= petrolpumps[temp][1];

			end++;
			temp++;

			if (temp == size)
				temp = 0;
		}
	}

	return start;
}
