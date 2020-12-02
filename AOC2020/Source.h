



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

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