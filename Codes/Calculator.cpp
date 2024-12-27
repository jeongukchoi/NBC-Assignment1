#include "Calculator.h"

// Sum of the numbers in the array
int Calculator::getSum() {
	int sum = 0;
	for (int i = 0; i < ArraySize; ++i) {
		sum += Array[i];
	}
	return sum;
}

// Average of the numbers in the array
float Calculator::getAverage() {
	int sum = 0;
	for (int i = 0; i < ArraySize; ++i) {
		sum += Array[i];
	}
	return (float)sum / ArraySize;
}