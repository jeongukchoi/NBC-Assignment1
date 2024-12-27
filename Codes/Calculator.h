#ifndef CALCULATOR_H_
#define CALCULATOR_H_

class Calculator {
private:
	const int* Array;
	const int ArraySize;

public:
	Calculator(const int* arr, const int size) : Array(arr), ArraySize(size) {}
	int getSum(); // Sum of the numbers in the array
	float getAverage(); // Average of the numbers in the array
};

#endif
