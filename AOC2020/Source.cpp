#pragma once


#include </Documents/GitHub/AOC2020/AOC2020/Source.h>

using namespace std;


int main()
{
	int day;
	string filename;
	cout << "What Day is it? ";
	cin >> day;

	clock_t start;
	double duration;
	start = clock();

	filename = "input" + to_string(day) + ".txt";

	IntArray data;

	

	
	switch (day) {
	case 1:
		data = ReadIntArray(filename);

		cout << "\nThere are " << data.length << " values.\n";

		int ans;
		ans = FindPairWithSum(data.values, data.length, 2020);
		cout << "The first answer is: " << ans << "\n";
		ans = FindTripleWithSum(data.values, data.length, 2020);
		cout << "The second answer is: " << ans << "\n";
		break;
	case 2:
		ans = ParsePasswordFileByCount(filename);
		cout << "There are " << ans << " valid passwords by the count rule.\n";
		ans = ParsePasswordFileByPos(filename);
		cout << "There are " << ans << " valid passwords by the position rule.\n";
		break;
	default:
		cout << "Invalid answer\n";
	}

	duration = (clock() - start);

	cout << "Finished in " << duration << " ms\n";
}

IntArray ReadIntArray(string filename)
{
	IntArray ans;
	ans.length = 0;
	int* ArrayBuilder;
	int capacity = 10;
	int* temp;
	
	ArrayBuilder = new int[capacity];

	string line;

	ifstream file;

	
	file.open(filename);

	if (file.is_open()) {


		while (getline(file, line)) {
			if (capacity == ans.length) {
				temp = new int[capacity * 2];
				for (int i = 0; i < capacity; i++) {
					temp[i] = ArrayBuilder[i];
				}
				capacity *= 2;
				delete[] ArrayBuilder;
				ArrayBuilder = temp;
			}
			ArrayBuilder[ans.length] = stoi(line);
			ans.length++;
		}
		file.close();
	}
	else cout << "Error Reading";

	ans.values = ArrayBuilder;

	return ans;
}

// Day 1
int FindPairWithSum(int* array, int length, int sum) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (array[i] + array[j] == sum) {
				return array[i] * array[j];
			}
		}
	}
	
	return 0;
}

// Day 1
int FindTripleWithSum(int* array, int length, int sum) {
	for (int i = 0; i < length - 2; i++) {
		for (int j = i + 1; j < length - 1; j++) {
			for (int k = j + 1; k < length; k++) {

				// gotta go fast, break out if the first two numbers are too high
				if ((array[i] + array[j]) > sum) {
					break;
				}

				// return solution if condition met
				if (array[i] + array[j] + array[k] == sum) 
					return array[i] * array[j] * array[k];
			}
		}
	}

	return 0;
}


// Day 2 TODO: split into parser and processor
int ParsePasswordFileByCount(string filename) {
	size_t dashPlace;
	size_t firstSpacePlace;
	int min;
	int max;
	char toFind;
	int foundCount;
	string line;

	int goodCount = 0;

	ifstream file;


	file.open(filename);

	if (file.is_open()) {


		while (getline(file, line)) {
			foundCount = 0;
			dashPlace = line.find_first_of('-');
			firstSpacePlace = line.find_first_of(' ');

			min = stoi(line.substr(0, dashPlace));
			max = stoi(line.substr(dashPlace + 1, firstSpacePlace));
			toFind = line.at(firstSpacePlace + 1);
			line = line.substr(firstSpacePlace + 4, string::npos);

			for (int i = 0; i < line.length(); i++)
			{
				if (line.at(i) == toFind) {
					foundCount++;
					if (foundCount > max) break;
				}
			}
			if (foundCount >= min and foundCount <= max) goodCount++;
		}
		file.close();
	}
	else cout << "Error Reading";

	return goodCount;
}

// Day 2
int ParsePasswordFileByPos(string filename) {
	size_t dashPlace;
	size_t firstSpacePlace;
	int pos1;
	int pos2;
	char toFind;
	string line;

	int goodCount = 0;

	ifstream file;


	file.open(filename);

	if (file.is_open()) {


		while (getline(file, line)) {
			dashPlace = line.find_first_of('-');
			firstSpacePlace = line.find_first_of(' ');

			pos1 = stoi(line.substr(0, dashPlace));
			pos2 = stoi(line.substr(dashPlace + 1, firstSpacePlace));
			toFind = line.at(firstSpacePlace + 1);
			line = line.substr(firstSpacePlace + 4, string::npos);

			if ((line.at(pos1 - 1) == toFind) != (line.at(pos2 - 1) == toFind)) goodCount++;
		}
		cout << "\n";
		file.close();
	}
	else cout << "Error Reading";

	return goodCount;
}