#include "ArrayHandler.h"

/*	Validate and save input numbers in an array		*/
/*	(i.e. valid input range : -999,999 ~ 9,999,999)	*/
void ArrayHandler::fillArray() {
	// Get an input for each slot in the array
	for (int i = 0; i < ArraySize; ++i) {
		bool valid = true;
		string inStr;
		do {
			if (!valid) cout << "INPUT NOT VALID!" << endl;

			// reset the flags
			valid = true;
			cin.clear();

			// Read input into a string
			cout << "Enter a number between -999,999 ~ 9,999,999 : " << endl;
			getline(cin, inStr);

			// 1. Invalid if input is not received OR too long OR any cin error flag is set
			if (inStr.empty() || inStr.length() >= kNumDigitsMax || !cin.good()) {
				valid = false;
				continue;
			}

			// 2. Invalid if input contains something that's not a digit
			for (int i = 0; i < inStr.length(); i++) {
				// exception : if the first character is minus '-'
				if (i == 0 && inStr[i] == '-') continue;

				if (!isdigit(inStr[i])) {
					valid = false;
					break;
				}
			}
		} while (!valid);

		// Enter the validated input into the array
		int num = stoi(inStr);
		cout << "Entering " << num << " into index " << i << endl;
		Array[i] = num;
	}
}


// Print the numbers in the array
void ArrayHandler::printArray() {
	cout << "Array: [";
	for (int i = 0; i < ArraySize; ++i) {
		cout << "  " << Array[i];
	}
	cout << "  ]" << endl;
}