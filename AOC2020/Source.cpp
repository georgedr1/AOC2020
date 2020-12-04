#pragma once


#include </Documents/GitHub/AOC2020/AOC2020/Source.h>

using namespace std;


int main()
{
	int day;

	int ans;
	double dans;
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
	case 3:
		dans = CollisionDetection(filename, 3, 1);
		cout << "You hit " << to_string(dans) << " trees.\n";
		dans = dans * CollisionDetection(filename, 1, 1);
		dans = dans * CollisionDetection(filename, 5, 1);
		dans = dans * CollisionDetection(filename, 7, 1);
		dans = dans * CollisionDetection(filename, 1, 2);
		cout << "You hit " << to_string(dans) << " trees.\n";
		break;
	case 4:
		start = clock();
		ans = PassportChecker(filename, false, false);
		cout << "There are " << ans << " valid passports.\n";
		duration = (clock() - start);
		cout << "Finished in " << duration << " ms\n";

		start = clock();
		ans = PassportChecker(filename, false, true);
		cout << "There are " << ans << " validated passports.\n";
		duration = (clock() - start);
		cout << "Finished in " << duration << " ms\n";
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


// Day 3
// x is postive to the right, y is positive down
double CollisionDetection(string filename, int xMove, int yMove) {

	int xPos = 0;
	int yDiff = yMove;

	int xMax;
	string line;

	int trees = 0;

	ifstream file;


	file.open(filename);

	if (file.is_open()) {


		while (getline(file, line)) {
			if (yMove > yDiff) yDiff++;
			else {
				xMax = line.length();
				if (line.at(xPos) == '#') trees++;
				xPos += xMove;
				xPos = xPos >= xMax ? xPos - xMax : xPos;
				yDiff = 1;
			}
		}
		file.close();
	}
	else cout << "Error Reading";

	return trees;
}


// Day 4
int PassportChecker(string filename, bool checkCID, bool validate) {

	ifstream file;
	string line;
	int fieldNum = 0;
	int checkSum = 0;
	int dataEnd;

	string data[12][2];

	int validIDCount = 0;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line.empty()) {
				if (checkSum == 36 || (checkSum == 35 && !checkCID)) validIDCount++;
				checkSum = 0;
				fieldNum = 0;
			}
			while (!line.empty()) {
				data[fieldNum][0] = line.substr(0, line.find_first_of(':'));
				line = line.substr(line.find_first_of(':') + 1, string::npos);
				dataEnd = line.find_first_of(' ');
				data[fieldNum][1] = line.substr(0, dataEnd); // find_first_of will return end of line if no space found
				if (dataEnd == line.npos) line.clear();
				else line = line.substr(dataEnd + 1, string::npos);

				checkSum += getFieldCheck(data[fieldNum][0], data[fieldNum][1], validate);

				//cout << data[fieldNum][0] << ":" << data[fieldNum][1] << "  " << checkSum << "\n";
				fieldNum++;
			}
		}
		if (checkSum == 36 || (checkSum == 35 && !checkCID)) validIDCount++;
		file.close();
	}
	else cout << "Error Reading";

	return validIDCount;
}

int getFieldCheck(string field, string data, bool validate) {
	
	if (!field.compare("cid")) return 1;
	if (!field.compare("byr")) return (!validate || checkBYR(data)) ? 2 : 0;
	if (!field.compare("iyr")) return (!validate || checkIYR(data)) ? 3 : 0;
	if (!field.compare("eyr")) return (!validate || checkEYR(data)) ? 4 : 0;
	if (!field.compare("hgt")) return (!validate || checkHGT(data)) ? 5 : 0;
	if (!field.compare("hcl")) return (!validate || checkHCL(data)) ? 6 : 0;
	if (!field.compare("ecl")) return (!validate || checkECL(data)) ? 7 : 0;
	if (!field.compare("pid")) return (!validate || checkPID(data)) ? 8 : 0;;
	return 0;

}

bool checkBYR(string data) {
	return stoi(data) >= 1920 && stoi(data) <= 2002;
}

bool checkIYR(string data) {
	return stoi(data) >= 2010 && stoi(data) <= 2020;
}

bool checkEYR(string data) {
	return stoi(data) >= 2020 && stoi(data) <= 2030;
}

bool checkHGT(string data) {
	if (data.find("cm") < data.npos) {
		data.pop_back();
		data.pop_back();
		return stoi(data) >= 150 && stoi(data) <= 193;
	}
	if (data.find("in") < data.npos) {
		data.pop_back();
		data.pop_back();
		return stoi(data) >= 59 && stoi(data) <= 76;
	}
	return false;
}

bool checkHCL(string data) {
	return regex_match(data, regex("#[a-f0-9]{6}"));
}

bool checkECL(string data) {
	return string("amb,blu,brn,gry,grn,hzl,oth").find(data) < string::npos;
}

bool checkPID(string data) {
	return regex_match(data, regex("[0-9]{9}"));
}