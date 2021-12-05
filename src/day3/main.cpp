#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename T>
void outVec(vector<T> arr) {
	cout << "[ ";
	for (T a : arr) { cout << a << " "; }
	cout << "]" << endl; 
}

int mostCommon(vector<vector<int> > arr, int j) {
	int rows = arr.size();
	int num_ones = 0, num_zeros = 0;
	for (int i = 0; i < rows; i++) {
		if (arr[i][j] == 1) {
			num_ones++;
		} else if (arr[i][j] == 0) {
			num_zeros++;
		} else {
			cerr << "error not 1 or 0!" << endl;
			return -1;
		}
	}
	return num_ones >= num_zeros ? 1 : 0;
}

vector<int> leastCommon(vector<int> mostCommon) {
	vector<int> leastCommon;
	for (int i : mostCommon) {
		leastCommon.push_back(i^1);
	}

	return leastCommon;
}

int main() {
	// open file stream
	ifstream file ("input.txt");
	file.close(); // close file

	vector<vector<int>> arr = {{1, 0, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}};
	vector<int> apeArr = {1, 0, 0, 1};

	cout << (mostCommon(arr, 0)^1) << endl;
	outVec(leastCommon(apeArr));
}
