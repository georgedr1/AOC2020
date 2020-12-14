#pragma once


#include </Documents/GitHub/AOC2020/AOC2020/Source.h>

using namespace std;


int main()
{
	int day;

	long long ans;
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
	case 5:
		start = clock();
		ans = getHighestSeatID(filename);
		duration = (clock() - start);
		cout << "The highest seat ID is: " << ans << "\n";		
		cout << "Finished in " << duration << " ms\n";
		start = clock();

		ans = findSeatID(filename);
		duration = (clock() - start);
		cout << "Your seat ID is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";

		break;
	case 6:
		start = clock();
		ans = formAnswersSummation(filename);
		duration = (clock() - start);
		cout << "The total yes count is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();

		ans = formAnswersSummationPt2(filename);
		duration = (clock() - start);
		cout << "The other count is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 7:
		start = clock();
		ans = bagShenanigans(filename);
		duration = (clock() - start);
		cout << "The total bag count is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		start = clock();
		ans = bagShenanigansPt2(filename);
		duration = (clock() - start);
		cout << "The total bag count is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		break;
	case 8:
		start = clock();
		ans = findInfiniteInstruction(filename);
		duration = (clock() - start);
		cout << "The final acc is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = fixProgram(filename);
		duration = (clock() - start);
		cout << "The final acc is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 9:
		start = clock();
		ans = findXMASFailure(filename, 25);
		duration = (clock() - start);
		cout << "The first erroneous number is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = findEncryptionWeakness(filename, 25);
		duration = (clock() - start);
		cout << "The weakness is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 10:
		start = clock();
		ans = voltageAdaptors(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = voltageAdaptorsInfiniteCombinations(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 11:
		start = clock();
		ans = gameOfSeats(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = gameOfSeatsPt2(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 12:
		start = clock();
		ans = manhattanDistance(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = waypointMovement(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 13:
		start = clock();
		ans = busDeparture(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = busDepartureSequence(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		break;
	case 14:
		start = clock();
		ans = maskedProgram(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
		cout << "Finished in " << duration << " ms\n";
		start = clock();
		ans = maskedProgramV2(filename);
		duration = (clock() - start);
		cout << "The value is: " << ans << "\n";
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

// Day 5
int getHighestSeatID(string filename) {

	int tempID;
	int highID = 0;
	int r;
	int c;

	ifstream file;
	string line;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			r = binaryPartition(line.substr(0, 7), 'B', 'F');
			c = binaryPartition(line.substr(7, 3), 'R', 'L');
			tempID = getSeatID(r, c);
			highID = tempID > highID ? tempID : highID;
		}
		file.close();
	}
	else cout << "Error Reading";

	return highID;

}

int findSeatID(string filename) {


	int r;
	int c;

	bool Seats[128 * 8] = { false };
	bool previousTaken = false;
	bool previousPossible = false;


	ifstream file;
	string line;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			r = binaryPartition(line.substr(0, 7), 'B', 'F');
			c = binaryPartition(line.substr(7, 3), 'R', 'L');
			Seats[getSeatID(r, c)] = true;
			
		}
		file.close();

		for (int i = 0; i < 127 * 8; i++) {
			if (previousPossible && Seats[i]) return i - 1;
			previousPossible = previousTaken && !Seats[i];
			previousTaken = Seats[i];		
		}
	}
	else cout << "Error Reading";

	return -1;
}

int binaryPartition(string s, char high, char low) {
	int maxValue = int( pow(2, s.size()));
	int change = maxValue / 4;
	int ans = maxValue / 2;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == high) ans += max(change, 1);
		else ans -= change;
		change /= 2;
	}
	return ans - 1;
}

int getSeatID(int r, int c) {
	return r * 8 + c;
}

// Day 6
int formAnswersSummation(string filename) {

	bool answersForGroup[26] = { false };
	int groupSum = 0;
	int totalSum = 0;
	int index;
	ifstream file;
	string line;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line.empty()) {
				totalSum += groupSum;
				groupSum = 0;
				fill(answersForGroup, answersForGroup + 26, false);
			}
			while (!line.empty()) {
				while (!line.empty()) {
					index = line.back() - 97;
					if (!answersForGroup[index]) groupSum++;
					answersForGroup[index] = true;
					line.pop_back();
				}
			}
		}
		totalSum += groupSum;
		file.close();
	}
	else cout << "Error Reading";

	return totalSum;
}

int formAnswersSummationPt2(string filename) {

	int answersForGroup[26] = { 0 };
	int groupCount = 0;
	int numberOfGroups = 0;
	int totalSum = 0;
	bool firstPerson = true;
	int index;
	ifstream file;
	string line;

	

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line.empty()) {
				numberOfGroups++;
				for (int i = 0; i <= 26; i++) {
					totalSum += (answersForGroup[i] == groupCount) ? 1 : 0;
				}
				groupCount = -1;
				fill(answersForGroup, answersForGroup + 26, 0);
			}
			while (!line.empty()) {
				index = line.back() - 97;
				if(answersForGroup[index] == groupCount) answersForGroup[index] = answersForGroup[index] + 1;
				line.pop_back();
			}
			groupCount++;
		}
		for (int i = 0; i <= 26; i++) {
			totalSum += (answersForGroup[i]) == groupCount ? 1 : 0;
		}
		file.close();
	}
	else cout << "Error Reading";

	return totalSum;
}


// Day 7
int bagShenanigans(string filename) {

	map<string, bagContents> ruleList;
	string outerBag;
	string innerBag;
	int innerCount = 0;
	int bagsPosn;
	int containPosn;
	int commaPosn;

	ifstream file;
	string line;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			bagsPosn = line.find("bags");
			outerBag = line.substr(0, bagsPosn - 1);
			containPosn = line.find("contain");
			line = line.substr(containPosn + 8, line.npos);
			bagContents temp;
			while (!line.empty()) {
				if (line.find("no other") != line.npos) {
					temp.contents.insert(pair<string, int>("null", 0));
					line.clear();
				}
				else {
					bagsPosn = line.find("bag");
					commaPosn = line.find(",");
					innerBag = line.substr(2, bagsPosn - 3);
					innerCount = line.at(0) - 48;
					if (commaPosn > 0) line = line.substr(commaPosn + 2, line.npos);
					else line.clear();
					temp.contents.insert(pair<string, int>(innerBag, innerCount));
				}
			}
			ruleList.insert(pair<string, bagContents>(outerBag, temp));

		}
		file.close();
	}
	else cout << "Error Reading";

	string bagName;
	list<string> goodBags;
	goodBags.push_back("shiny gold");
	bool newGoodBags = true;
	bool alreadyFound;
	bool canHoldTarget;

	while (newGoodBags) {
		newGoodBags = false;
		for (std::map<string, bagContents>::iterator it = ruleList.begin(); it != ruleList.end(); ++it) {
			outerBag = it->first;
			for (std::map<string, int>::iterator it2 = it->second.contents.begin(); it2 != it->second.contents.end(); ++it2) {
				innerBag = it2->first;
				alreadyFound = find(goodBags.begin(), goodBags.end(), outerBag) != goodBags.end();
				canHoldTarget = find(goodBags.begin(), goodBags.end(), innerBag) != goodBags.end();
				if (canHoldTarget && !alreadyFound) {
					goodBags.push_back(outerBag);
					newGoodBags = true;
				}
			}
		}
	}

	return goodBags.size() - 1;
}

int bagShenanigansPt2(string filename) {

	map<string, bagContents> ruleList;
	string outerBag;
	string innerBag;
	int innerCount = 0;
	int bagsPosn;
	int containPosn;
	int commaPosn;

	ifstream file;
	string line;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			bagsPosn = line.find("bags");
			outerBag = line.substr(0, bagsPosn - 1);
			containPosn = line.find("contain");
			line = line.substr(containPosn + 8, line.npos);
			bagContents temp;
			while (!line.empty()) {
				if (line.find("no other") != line.npos) {
					temp.contents.insert(pair<string, int>("null", 0));
					line.clear();
				}
				else {
					bagsPosn = line.find("bag");
					commaPosn = line.find(",");
					innerBag = line.substr(2, bagsPosn - 3);
					innerCount = line.at(0) - 48;
					if (commaPosn > 0) line = line.substr(commaPosn + 2, line.npos);
					else line.clear();
					temp.contents.insert(pair<string, int>(innerBag, innerCount));
				}
			}
			ruleList.insert(pair<string, bagContents>(outerBag, temp));

		}
		file.close();
	}
	else cout << "Error Reading";


	return getBagCount(ruleList, "shiny gold") - 1;
}


int getBagCount(map<string, bagContents> ruleList, string bagName) {
	bagContents contents = ruleList[bagName];
	int ans = 0;

	for (std::map<string, int>::iterator it = contents.contents.begin(); it != contents.contents.end(); ++it) {
		ans += it->second * getBagCount(ruleList, it->first);
	}


	return 1+ ans;

}


// Day 8
int findInfiniteInstruction(string filename) {

	vector<Instruction> program;
	Instruction temp;
	string command;
	int arg;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			command = line.substr(0, 3);
			if (line.find('+') != line.npos) arg = stoi(line.substr(5));
			else arg = -stoi(line.substr(5));
			temp.arg = arg;
			temp.command = command;
			temp.executed = false;
			program.push_back(temp);
		}
		file.close();
	}
	else cout << "Error Reading";


	int acc = 0;
	bool programStalled = false;
	int at = 0;

	// Run program
	while (!program.at(at).executed) {
		program.at(at).executed = true;
		command = program.at(at).command;
		arg = program.at(at).arg;

		//cout << command << " " << arg << "\n";
		if (command.find("acc") != command.npos) {
			acc += arg;
			at++;
		}
		else if (command.find("jmp") != command.npos) {
			at += arg;
		}
		else {
			at++;
		}
		
	}


	return acc;
}

int fixProgram(string filename) {

	vector<Instruction> program;
	Instruction temp;
	string command;
	int arg;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			command = line.substr(0, 3);
			if (line.find('+') != line.npos) arg = stoi(line.substr(5));
			else arg = -stoi(line.substr(5));
			temp.arg = arg;
			temp.command = command;
			program.push_back(temp);
		}
		file.close();
	}
	else cout << "Error Reading";


	int acc = 0;
	bool programStalled = false;
	int at = 0;
	int lastAt = 0;

	for (int i = 0; i < program.size(); i++) {
		command = program.at(i).command;
		if (command.find("jmp") != command.npos) {
			program.at(i).command = "nop";
			//cout << "\n\neditted program at: " << i << " \n";
			//for (int j = 0; j < program.size(); j++) cout << program.at(j).command << " " << program.at(j).arg << "\n";
			if (runProgram(program, &acc)) return acc;
			program.at(i).command = "jmp";
		}
		else if (command.find("nop") != command.npos){
			program.at(i).command = "jmp";
			//cout << "\n\neditted program at: " << i << " \n";
			//for (int j = 0; j < program.size(); j++) cout << program.at(j).command << " " << program.at(j).arg << "\n";
			if (runProgram(program, &acc)) return acc;
			program.at(i).command = "nop";
		}
	
	}



	//// Run program
	////while (at<program.size()) {
	////	program.at(at).lastAt = lastAt;
	////	if (program.at(at).executed) {
	////		at = backTrack(&program, at, &acc);
	////		cout << "\n\neditted program at: " << at<<" \n";
	////		for (int i = 0; i < program.size(); i++) cout << program.at(i).command << " " << program.at(i).arg << "\n";
	////	}
	////	program.at(at).executed = true;
	////	command = program.at(at).command;
	////	arg = program.at(at).arg;
	////	cout << command << " " << arg << "\n";
	////	if (command.find("acc") != command.npos) {
	////		acc += arg;
	////		lastAt = at;
	////		at++;
	////	}
	////	else if (command.find("jmp") != command.npos) {
	////		lastAt = at;
	////		at += arg;
	////	}
	////	else {
	////		lastAt = at;
	////		at++;
	////		
	////	}
	////}

	


	return acc;
}

int backTrack(vector<Instruction>* program, int at, int* acc) {

	string command;
	int arg;
	bool flipped;
	bool triedToFlip;
	int lastAt;

	for (int i = 0; i < (*program).size(); i++) {
		if ((*program).at(i).flipped) {
			if ((*program).at(i).command.find("jmp") != (*program).at(i).command.npos)(*program).at(i).command = "nop";
			else (*program).at(i).command = "jmp";
			(*program).at(i).flipped = false;
			(*program).at(i).triedToFlip = true;
		}
	}

	while (at >= 0 && at < (*program).size()) {

		(*program).at(at).executed = false;
		command = (*program).at(at).command;
		arg = (*program).at(at).arg;
		flipped = (*program).at(at).flipped;
		triedToFlip = (*program).at(at).triedToFlip;
		lastAt = (*program).at(at).lastAt;

		if (command.find("acc") != command.npos) {
			(*acc) -= arg;
			at = lastAt;
		}
		else if (command.find("jmp") != command.npos) {
			if (triedToFlip) at = lastAt;
			else {
				(*program).at(at).command = "nop";
				(*program).at(at).flipped = true;
				return at;
			}
		}
		else {
			if (triedToFlip) at = lastAt;
			else {
				(*program).at(at).command = "jmp";
				(*program).at(at).flipped = true;
				return at;
			}
		}

	}
	return -1;
}

// runs the program returns true if it completes
bool runProgram(vector<Instruction> program, int *ans) {
	vector<Instruction> prgm = program;

	int acc = 0;
	int at = 0;

	string command;
	int arg;

	while (at < prgm.size()) {

		if (prgm.at(at).executed) return false;

		command = prgm.at(at).command;
		arg = prgm.at(at).arg;
		prgm.at(at).executed = true;

		if (command.find("acc") != command.npos) {
			acc += arg;
			at++;
		}
		else if (command.find("jmp") != command.npos) {
			at += arg;
		}
		else {
			at++;
		}

	}

	*ans = acc;
	return true;
}


// Day 9

int findXMASFailure(string filename, int bufferSize) {
	int* buffer;
	buffer = new int[bufferSize];
	int index = 0;
	bool initialized = false;

	int num;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (index >= bufferSize) index = 0;

			num = stoi(line);

			if (!initialized) {
				buffer[index] = num;
				if (index == bufferSize - 1) initialized = true;
			}
			else {
				for (int i = 0; i < bufferSize - 1; i++) {
					for (int j = i + 1; j < bufferSize; j++) {
						//cout << buffer[i] << " + " << buffer[j] << " : " << num << "\n";
						if (buffer[i] + buffer[j] == num) {
							buffer[index] = num;
						}
					}
				}
			}

			if (buffer[index] != num) return num;

			index++;
		}
		file.close();
	}
	else cout << "Error Reading";
}

int findEncryptionWeakness(string filename, int bufferSize) {

	int sum2find = findXMASFailure(filename, bufferSize);

	vector<long long> numbers;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			numbers.push_back(stoll(line));
		}
		file.close();
	}
	else cout << "Error Reading";

	int sum = 0;
	int num;
	int firstIndex = 0;
	int lastIndex = 0;
	

	while (lastIndex < numbers.size()) {
		while (sum < sum2find) {
			num = numbers.at(lastIndex);
			sum += numbers.at(lastIndex);
			
			lastIndex++;
		}
		if (sum == sum2find) break;

		sum -= numbers.at(firstIndex);

		firstIndex++;
	}

	lastIndex--;

	int min = numbers.at(firstIndex);
	int max = numbers.at(firstIndex);

	if (sum == sum2find) {
		for (int i = firstIndex; i <= lastIndex; i++) {
			num = numbers.at(i);
			min = min < num ? min : num;
			max = max > num ? max : num;
		}

		return min + max;
	}

	return -1;

}


// Day 10
int voltageAdaptors(string filename) {

	list<int> adaptors;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			adaptors.push_back(stoi(line));
		}
		file.close();
	}
	else cout << "Error Reading";

	adaptors.sort();

	int last = 0; // start with 0 jolts
	int ones = 0;
	int threes = 1; // always a 3 at the end

	for (list<int>::iterator it = adaptors.begin(); it != adaptors.end(); ++it) {
		
		if (*it - last == 1) ones++;
		else if (*it - last == 3) threes++;
		last = *it;
	}

	return ones * threes;
}


long long voltageAdaptorsInfiniteCombinations(string filename) {

	list<int> adaptors;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			adaptors.push_back(stoi(line));
		}
		file.close();
	}
	else cout << "Error Reading";

	adaptors.sort();

	adaptors.push_front(0);
	adaptors.push_back(adaptors.back() + 3);

	map<int, long long> solvedPortion;
	solvedPortion.insert(pair<int,int>(adaptors.back(), 1));

	long long ans = adaptorsRecursion(adaptors, &solvedPortion);



	
	return ans;
}

long long adaptorsRecursion(list<int> adaptors, map<int, long long> *solvedPortion) {

	map<int, long long> local = *solvedPortion;

	int start = adaptors.front();

	if (local.find(start) != local.end()) return local.at(start);

	adaptors.pop_front();

	if (adaptors.size() == 1) {
		return 1;
	}

	long long ans = 0;

	while (adaptors.front() - start <= 3) {
		ans += adaptorsRecursion(adaptors, solvedPortion);
		adaptors.pop_front();
	}


	solvedPortion->insert(pair<int, long long>(start, ans));
		
	return ans;
}

// Day 11
int gameOfSeats(string filename) {

	vector<vector<int>> seats; // 0 = floor, 1 = empty, 2 = taken;
	vector<vector<int>> lastIterationSeats;
	vector<int> tempRow;
	int fillLocation = 0;
	int stringLocation = 0;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			stringLocation = 0;
			while (stringLocation<line.size()) {
				tempRow.push_back(line.at(stringLocation)=='L' ? 1:0);
				stringLocation++;
				
			}
			seats.push_back(tempRow);
			tempRow.clear();
			fillLocation++;
		}
		file.close();
	}
	else cout << "Error Reading";

	int occupied = 0;
	bool changeHappened = true;

	while(changeHappened) {
		changeHappened = false;
		lastIterationSeats = seats;
		occupied = 0;
		for (int row = 0; row < fillLocation; row++) {
			for (int col = 0; col < stringLocation; col++) {
				if(seats[row][col] != 0) seats[row][col] = checkNeighbors(lastIterationSeats, row, col);
				occupied += (seats[row][col] == 2);
				changeHappened = changeHappened || seats[row][col] != lastIterationSeats[row][col];
			}
		}
	}

	return occupied;
}
int gameOfSeatsPt2(string filename) {

	vector<vector<int>> seats; // 0 = floor, 1 = empty, 2 = taken;
	vector<vector<int>> lastIterationSeats;
	vector<int> tempRow;
	int fillLocation = 0;
	int stringLocation = 0;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			stringLocation = 0;
			while (stringLocation < line.size()) {
				tempRow.push_back(line.at(stringLocation) == 'L' ? 1 : 0);
				stringLocation++;

			}
			seats.push_back(tempRow);
			tempRow.clear();
			fillLocation++;
		}
		file.close();
	}
	else cout << "Error Reading";

	int occupied = 0;
	bool changeHappened = true;

	while (changeHappened) {
		changeHappened = false;
		lastIterationSeats = seats;
		occupied = 0;
		for (int row = 0; row < fillLocation; row++) {
			for (int col = 0; col < stringLocation; col++) {
				if (seats[row][col] != 0) seats[row][col] = checkLineOfSight(lastIterationSeats, row, col);
				occupied += (seats[row][col] == 2);
				changeHappened = changeHappened || seats[row][col] != lastIterationSeats[row][col];
			}
		}
	}

	return occupied;
}

int checkNeighbors(vector<vector<int>> seats, int row, int col) {
	int current = seats[row][col];
	int ans = current == 2? -1 : 0;

	for(int r = max(0,row-1);r <= min(int(seats.size()-1),row+1); r++) {
		for (int c = max(0, col - 1); c <= min(int(seats[0].size() - 1), col + 1); c++) {
			ans += (seats[r][c] == 2);
		}
	}

	if ( current == 1 && ans == 0) return 2;
	if (current == 2 && ans >= 4) return 1;
	
	return current;
	 
}


int checkLineOfSight(vector<vector<int>> seats, int row, int col) {
	int current = seats[row][col];
	int ans = 0;
	int r, c, cur;
	bool noSeat;

	int maxR = seats.size();
	int maxC = seats[0].size();

	// 0 degress (right)
	r = row;
	c = col + 1;
	noSeat = true;
	while (c < maxC && noSeat) {
		cur = seats[r][c];
		if (cur == 0) c++;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 45 degress (up right)
	r = row - 1;
	c = col + 1;
	noSeat = true;
	while (r >= 0 && c < maxC && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r--, c++;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 90 degress (up)
	r = row - 1;
	c = col;
	noSeat = true;
	while (r >= 0 && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r--;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 135 degress (up left)
	r = row - 1;
	c = col - 1;
	noSeat = true;
	while (r >= 0 && c >= 0 && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r--, c--;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 180 degress (left)
	r = row;
	c = col - 1;
	noSeat = true;
	while (c >= 0 && noSeat) {
		cur = seats[r][c];
		if (cur == 0) c--;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 225 degress (down left)
	r = row + 1;
	c = col - 1;
	noSeat = true;
	while (r < maxR && c >= 0 && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r++, c--;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 270 degress (down)
	r = row+1;
	c = col;
	noSeat = true;
	while (r < maxR && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r++;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	// 315 degress (down right)
	r = row + 1;
	c = col + 1;
	noSeat = true;
	while (r < maxR && c < maxC && noSeat) {
		cur = seats[r][c];
		if (cur == 0) r++, c++;
		else if (cur == 1) noSeat = false;
		else ans++, noSeat = false;
	}

	if (current == 1 && ans == 0) return 2;
	if (current == 2 && ans >= 5) return 1;

	return current;

}


int manhattanDistance(string filename) {


	int x = 0;
	int y = 0;
	int dir = 0;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line[0] == 'N') {
				y += stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'S') {
				y -= stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'E') {
				x += stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'W') {
				x -= stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'L') {
				dir += stoi(line.substr(1, line.npos));
				dir = dir % 360;
			}
			else if (line[0] == 'R') {
				dir -= stoi(line.substr(1, line.npos));
				dir = (dir + 360) % 360;
			}
			else if (line[0] == 'F') {
				switch (dir) {
				case 0:
					x += stoi(line.substr(1, line.npos));
					break;
				case 90:
					y += stoi(line.substr(1, line.npos));
					break;
				case 180:
					x -= stoi(line.substr(1, line.npos));
					break;
				case 270:
					y -= stoi(line.substr(1, line.npos));
					break;
				default:
					cout << "shouldn't get here\n";
				}

			}
		}
		file.close();
	}
	else cout << "Error Reading";

	return abs(x) + abs(y);
}

int waypointMovement(string filename) {


	int x = 0;
	int y = 0;
	int wx = 10;
	int wy = 1;
	int dir = 0;
	int temp;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line[0] == 'N') {
				wy += stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'S') {
				wy -= stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'E') {
				wx += stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'W') {
				wx -= stoi(line.substr(1, line.npos));
			}
			else if (line[0] == 'L') {
				dir = stoi(line.substr(1, line.npos));
				switch (dir%360) {
				case 0:
					break;
				case 90:
					temp = wx;
					wx = - wy;
					wy = temp;
					break;
				case 180:
					wx = -wx;
					wy = -wy;
					break;
				case 270:
					temp = wx;
					wx = wy;
					wy = - temp;
					break;
				default:
					cout << "shouldn't get here\n";
			}
			}
			else if (line[0] == 'R') {
				dir = stoi(line.substr(1, line.npos));
				switch (dir % 360) {
				case 0:
					break;
				case 90:
					temp = wx;
					wx = wy;
					wy = -temp;
					break;
				case 180:
					wx = -wx;
					wy = -wy;
					break;
				case 270:
					temp = wx;
					wx = -wy;
					wy = temp;
					break;
				default:
					cout << "shouldn't get here\n";
				}
			}
			else if (line[0] == 'F') {
				dir = stoi(line.substr(1, line.npos));
				x += wx * dir;
				y += wy * dir;
			}
		}
		file.close();
	}
	else cout << "Error Reading";

	return abs(x) + abs(y);
}

int busDeparture(string filename) {

	int startTime;
	int waitTime;
	int bestWait = INT_MAX;
	int bestBus = 0;
	int bus;
	int a;
	int b;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		getline(file, line);
		startTime = stoi(line);

		getline(file, line);
		
		while (!line.empty()) {
			a = line.find_first_not_of("x,");
			b = a + (line.substr(a,line.npos)).find_first_of(',');
			bus = stoi(line.substr(a, b));
			if (b != line.npos) line = line.substr(b + 1);
			else line.clear();

			waitTime = bus - startTime % bus;
			
			if (waitTime < bestWait) bestWait = waitTime, bestBus = bus;
		}
			
		file.close();
	}
	else cout << "Error Reading";

	return bestBus * bestWait;
}

long long busDepartureSequence(string filename) {

	
	vector<int> buses;
	int a;
	int b;
	long long ans = 1;
	string s;

	ifstream file;
	string line;


	// Read file in and store in a list
	file.open(filename);

	if (file.is_open()) {

		getline(file, line);
		getline(file, line);

		while (!line.empty()) {
			a = line.find_first_not_of(",");
			b = line.find_first_of(',');
			s = line.substr(a, b);

			if (s.at(0) != 'x') buses.push_back(stoi(s));
			else buses.push_back(-1);

			if (b != line.npos) line = line.substr(b + 1);
			else line.clear();
		}

		file.close();
	}
	else cout << "Error Reading";

	bool good;
	long long lastGood;
	bool jumpset = false;
	int progress = 0;
	long long jump = buses[0];
	long long index = buses[0];
	while (true) {
		good = true;
		for (int i = 1; i < buses.size(); i++) {
			if (buses[i] == -1 || (i + index) % buses[i] == 0) {
				if (i > progress) {
					progress = i;
					lastGood = index;
					jumpset = false;
				}
				else if (i == progress && !jumpset) {
					jump = index - lastGood;
					jumpset = true;
				}

			}
			else {
				good = false;
				break;
			}
		}
		if (good) return index;
		index += jump;
	}

	return -1;
}


long long lcm(long long a, long long b) {
	return (a / gcd(a, b)) * b;
}

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


long long maskedProgram(string filename) {
	map<long long, long long> mem;
	bool *current;
	int mask[36];
	long long index;
	int length;
	long long sum = 0;

	ifstream file;
	string line;



	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line.find("mask")!=line.npos) {
				length = line.size();
				for (int i = 0; i < length - 7; i++) {
					mask[i] = line[length - 1 - i] - 48;
				}
			}
			else {
				index = stoll(line.substr(4, line.find_first_of(']')));
				current = toBitArray(stoll(line.substr(line.find_last_of(' '))));
				current = applyMask(current, mask);
				if (mem.find(index) == mem.end()) {
					mem.insert(pair<long long, long long>(index, toULLong(current)));
					sum += mem.at(index);
				}
				else {
					sum -= mem.at(index);
					mem.at(index) = toULLong(current);
					sum += mem.at(index);
				}

			}
		}

		file.close();
	}
	else cout << "Error Reading";

	return sum;
}

long long toULLong(bool* input){
	long long output = 0;

	
	for (int i = 0; i < 36; i++) {
		output += input[i] * powl(2, i);
	}
	return output;
}

bool* toBitArray(long long input) {
	static bool output[36];
	for (int i = 0; i < 36; i++) {
		output[i] = (input & (1 << i)) >> i;
	}
	return output;
}

bool* applyMask(bool* input, int* mask) {
	for (int i = 0; i < 36; i++) {
		if (mask[i] != 40) input[i] = mask[i];
		
	}
	return input;
}

long long maskedProgramV2(string filename) {
	map<long long, long long> mem;
	long long current;
	int mask[36];
	long long baseIndex;
	long long index;
	int length;
	long long sum = 0;
	vector<long long> indices;

	ifstream file;
	string line;



	file.open(filename);

	if (file.is_open()) {

		while (getline(file, line)) {
			if (line.find("mask") != line.npos) {
				length = line.size();
				for (int i = 0; i < length - 7; i++) {
					mask[i] = line[length - 1 - i] - 48;
				}
			}
			else {
				baseIndex = stoll(line.substr(4, line.find_first_of(']')));
				indices = applyMaskV2(baseIndex, mask);
				for (long long i = 0; i < indices.size(); i++) {
					index = indices[i];
					current = stoll(line.substr(line.find_last_of(' ')));
					if (mem.find(index) == mem.end()) {
						mem.insert(pair<long long, long long>(index,current));
						sum += mem[index];
					}
					else {
						sum -= mem[index];
						mem.at(index) = current;
						sum += mem[index];
					}
				}

			}
		}

		file.close();
	}
	else cout << "Error Reading";

	return sum;
}

vector<long long> applyMaskV2(long long base, int* mask) {
	vector<long long> returner;
	int startSize;
	bool* memory = toBitArray(base);
	
	returner.push_back(0);

	for (int i = 0; i < 36; i++) {
		switch (mask[i]) {
		case 0:
			for (int k = 0; k < returner.size(); k++) {
				returner[k] += memory[i] * (long long)pow(2, i);
			}
			break;
		case 1:
			for (int k = 0; k < returner.size(); k++) {
				returner[k] += (long long)pow(2, i);
			}
			break;
		case 40:
			startSize = returner.size();
			for (int k = 0; k < startSize; k++) {
				returner.push_back(returner[k] + (long long) pow(2, i));
			}
			break;
		}
	}


	return returner;
	
}