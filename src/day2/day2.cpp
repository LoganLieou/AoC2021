#include <iostream>
#include <fstream>

using namespace std;

int solutions(string filename) {
	ifstream file;
	file.open(filename);

	string direction = "";
	int value = 0, horizontal = 0, depth = 0;

	// parse file and do operations
	if (file.is_open()) {
		while (file >> direction >> value) {
			if (direction == "forward") {
				horizontal += value;
			} else if (direction == "down") {
				depth += value;
			} else if (direction == "up") {
				depth -= value;
			}
		}
	}

	return horizontal * depth;
}

int main() {
	cout << solutions("input.txt") << endl;
}
