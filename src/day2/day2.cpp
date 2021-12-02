#include <iostream>
#include <fstream>

using namespace std;

int part1(string filename) {
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

int part2(string filename) {
	ifstream file;
	file.open(filename);

	string direction = "";
	int pos = 0, dep = 0, aim = 0, value = 0;

	// parse file and do operations
	if (file.is_open()) {
		while (file >> direction >> value) {
			if (direction == "forward") {
				pos += value;
				dep += aim * value;
			} else if (direction == "up") {
				aim -= value;
			} else if (direction == "down") {
				aim += value;
			}
		}
	}

	return pos * dep;
}

int main() {
	cout << part1("input.txt") << endl;
	cout << part2("input.txt") << endl;
}
