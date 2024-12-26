#include <iostream>

using namespace std;

const int kSize = 5; // Defined size of the array

void fillArray(int arr[]); // Validate and save input numbers in an array
void printArray(const int* arr, int size); // Print the numbers in the array
int getSum(const int* arr, int size); // Sum of the numbers in the array
float getAverage(const int* arr, int size); // Average of the numbers in the array
void mergeSort(int arr[], int size, int order); // Divide the array into two halves recursively and merge them back in order
void merge(const int* leftArray, const int* rightArray, int leftSize, int rightSize, int arr[], int order); // merge two arrays in an ascending order

int main() {
	int Array[kSize] = { 0 };
	fillArray(Array);
	printArray(Array, kSize);

	cout << "Sum: " << getSum(Array, kSize) << endl;
	cout << "Average: " << getAverage(Array, kSize) << endl;

	int order = 0;
	cout << "Sorting - Enter 1 for ascending order / 2 for descending order / no sorting if anything else is entered." << endl;
	cin >> order;
	if (order == 1 || order == 2) {
		cout << "Sorting..." << endl;
		mergeSort(Array, kSize, order);
	}
	else {
		cout << "No Sorting!" << endl;
	}
	printArray(Array, kSize);

	return 0;
}

// Validate and save input numbers in an array
void fillArray(int arr[]) {
	for (int i = 0; i < kSize; ++i) {
		// Ask for an input
		cout << "Enter an integer " << i + 1 << ": \n";
		int num;
		cin >> num;

		// Clear the buffer and ask again until input is valid
		while (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid integer.\n";
			cin >> num;
		}

		// Enter the validated input into the array
		cout << "Entering " << num << endl << endl;
		arr[i] = num;
	}
}

// Print the numbers in the array
void printArray(const int* arr, int size) {
	cout << "Array: [";
	for (int i = 0; i < kSize; ++i) {
		cout << "  " << arr[i];
	}
	cout << "  ]" << endl;
}

// Sum of the numbers in the array
int getSum(const int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

// Average of the numbers in the array
float getAverage(const int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return (float) sum /  size;
}

// Merge Sort - https://www.youtube.com/watch?v=3j0SWDX4AtU 
void mergeSort(int arr[], int size, int order) {
	// base case : when the size of the current half reaches 1
	if (size <= 1) return;

	// not valid if order isn't 1 or 2

	// divide the array into two halves
	int mid = size / 2;
	int leftSize = mid;
	int rightSize = size - mid;
	int* leftArray = new int[leftSize];
	int* rightArray = new int[rightSize];

	// separate index for the right subarray
	int j = 0;

	// start and advance from left
	for (int i = 0; i < size; i++) {
		if (i < mid) { // left of middle --> copy arr[i] into left array
			leftArray[i] = arr[i];
		}
		else { // right of middle --> copy arr[i] into right array
			rightArray[j++] = arr[i];
		}
	}

	// recursion
	mergeSort(leftArray, leftSize, order);
	mergeSort(rightArray, rightSize, order);

	// merge left & right arrays into original array
	merge(leftArray, rightArray, leftSize, rightSize, arr, order);

	delete[] leftArray;
	delete[] rightArray;
}

// Merge - https://www.youtube.com/watch?v=3j0SWDX4AtU
void merge(const int* leftArray, const int* rightArray, int leftSize, int rightSize, int arr[], int order) {
	// left, right, array(to copy into) indices
	int left = 0, right = 0, i = 0;


	// traverse through left & right arrays
	while (left < leftSize && right < rightSize) {
		// ascending order
		if (order == 1) {
			// insert the greater number into arr[]
			if (leftArray[left] <= rightArray[right]) {
				arr[i++] = leftArray[left++];
			}
			else {
				arr[i++] = rightArray[right++];
			}
		}

		// descending order
		else if (order == 2) {	
			// insert smaller number into arr[]
			if (leftArray[left] >= rightArray[right]) {
				arr[i++] = leftArray[left++];
			}
			else {
				arr[i++] = rightArray[right++];
			}
		}
	}

	// copy the rest of the elements (left first)
	while (left < leftSize) {
		arr[i++] = leftArray[left++];
	}

	while (right < rightSize) {
		arr[i++] = rightArray[right++];
	}
}