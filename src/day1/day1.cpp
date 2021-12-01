#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int sol(vector<int> arr) {
	int count, temp = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		if (temp < arr[i]) {
			count++;
		}
		temp = arr[i];
	}
	return count;
}

int main() {
	// construct array from input file
	ifstream file;
	file.open("./input.txt");
	vector<int> arr; int temp = 0, i = 0;
	while(file >> temp) { arr.push_back(temp); }

	cout << sol(arr) << endl;
}
