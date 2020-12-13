



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <regex>
#include <math.h>
#include <map>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;



struct IntArray {
	int length;
	int* values;
};

IntArray ReadIntArray(string filename);


int FindPairWithSum(int* array, int length, int sum);

int FindTripleWithSum(int* array, int length, int sum);


int ParsePasswordFileByCount(string filename);

int ParsePasswordFileByPos(string filename);


double CollisionDetection(string filename, int xMove, int yMove);


int PassportChecker(string filename, bool checkCID, bool validate);

int getFieldCheck(string field, string data, bool validate);

bool checkBYR(string data);

bool checkIYR(string data);

bool checkEYR(string data);

bool checkHGT(string data);

bool checkHCL(string data);

bool checkECL(string data);

bool checkPID(string data);


int getHighestSeatID(string filename);

int findSeatID(string filename);

int binaryPartition(string s, char high, char low);

int getSeatID(int r, int c);


int formAnswersSummation(string filename);

int formAnswersSummationPt2(string filename);


int bagShenanigans(string filename);

int bagShenanigansPt2(string filename);

struct bagContents {
	map<string, int> contents;
};

int getBagCount(map<string, bagContents> ruleList, string bagName);


int findInfiniteInstruction(string filename);

int fixProgram(string filename);

struct Instruction {
	Instruction() : executed(false),flipped(false),triedToFlip(false) {}
	string command;
	int arg;
	bool executed;
	bool flipped;
	bool triedToFlip;
	int lastAt;
};

int backTrack(vector<Instruction>* program, int at, int* acc);

bool runProgram(vector<Instruction> program, int* ans);


int findXMASFailure(string filename, int bufferSize);

int findEncryptionWeakness(string filename, int bufferSize);

int voltageAdaptors(string filename);

long long voltageAdaptorsInfiniteCombinations(string filename);

long long adaptorsRecursion(list<int> adaptors, map<int, long long>* solvedPortion);


int gameOfSeats(string filename);

int gameOfSeatsPt2(string filename);

int checkNeighbors(vector<vector<int>> seats, int row, int col);

int checkLineOfSight(vector<vector<int>> seats, int row, int col);


int manhattanDistance(string filename);

int waypointMovement(string filename);

int busDeparture(string filename);

long long busDepartureSequence(string filename);

long long lcm(long long a, long long b);

long long gcd(long long a, long long b);