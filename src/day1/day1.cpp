#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int sol(vector<int> arr) {
	// init sentinal values
	int count = 0, temp = INT_MIN;

	// iterate through the vector
	for (int i = 1; i < arr.size(); i++) {
		if (temp < arr[i]) {
			// increment count if last < curr
			count++;
		}
		// set last to curr
		temp = arr[i];
	}

	// return the count
	return count;
}

int sol2(vector<int> arr) {
	// init sential values
	int count = 0, temp = INT_MIN; 
	int a_sum = 0, b_sum = 0, c_sum = 0;

	// iterate through the array
	for (int i = 0; i < arr.size(); i++) {
		// 3 windows of size 3
		for (int j = 0; j < 3; j++) {
			a_sum += arr[i + j];
			b_sum += arr[i + j + 1];
			c_sum += arr[i + j + 2];
		}
		if (a_sum < b_sum < c_sum) {
			count++;
		}
		// reset the sums
		a_sum = b_sum = c_sum = 0;
	}
	return count;
}

int main() {
	// construct vector<int> from input file
	ifstream file; file.open("./input.txt");
	vector<int> arr; int temp = 0, i = 0;
	while(file >> temp) { arr.push_back(temp); }

	cout << sol(arr) << endl;
	cout << sol2(arr) << endl;
}
