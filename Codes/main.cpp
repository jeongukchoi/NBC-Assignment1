#include <iostream>
#include "Calculator.h"
#include "Sorter.h"
#include "ArrayHandler.h"

using namespace std;

const int kSize = 10; // Defined size of the array

int main() {
	// Fill the array with user input and print the array
	int Array[kSize] = { 0 };
	ArrayHandler arrayHand(Array, kSize);
	arrayHand.fillArray();
	arrayHand.printArray();

	// Print the sum and the average
	Calculator calc(Array, kSize);
	cout << "Sum: " << calc.getSum() << endl;
	cout << "Average: " << fixed << calc.getAverage() << endl;

	// Sort the array in a user-specified order (1 - ascending / 2 - descending)
	int order = 0;
	cout << "Sort the array?" << endl << "1 - ascending / 2 - descending / other - no sorting." << endl;
	cin >> order;
	if (cin.good() && (order == 1 || order == 2)) {
		cout << "Sorting..." << endl;
		Sorter sorter(Array, kSize, order);
		sorter.sort();
	}
	else {
		cout << "No Sorting!" << endl;
	}

	cout << "Final ";
	arrayHand.printArray();

	return 0;
}


