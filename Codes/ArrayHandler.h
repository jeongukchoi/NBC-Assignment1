#ifndef ARRAYHANDLER_H_
#define ARRAYHANDLER_H_

#include <iostream>
#include <string>

using namespace std;

class ArrayHandler {
private:
	int* Array;
	const int ArraySize;
	const int kNumDigitsMax = 8; // maximum number of digits (i.e. -999,999 ~ 9,999,999)

public:
	ArrayHandler(int* arr, const int size) : Array(arr), ArraySize(size) {}
	void fillArray(); // Validate and save input numbers in an array
	void printArray(); // Print the numbers in the array
};

#endif