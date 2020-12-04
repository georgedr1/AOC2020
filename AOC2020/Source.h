



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <regex>

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