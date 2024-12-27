#include "Sorter.h"

// Calls mergeSort on the initial array
void Sorter::sort() {
	mergeSort(Array, ArraySize);
}

/* Referred to: https://www.youtube.com/watch?v=3j0SWDX4AtU */
// 1. Divide the array into two halves (left & right) recursively
// 2. Base case when the size reaches 1
// 3. Return from base case --> Merging left & right arrays back using merge()
void Sorter::mergeSort(int* arr, const int size) {
	// base case : when the size of the current half reaches 1
	if (size <= 1) return;

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
	mergeSort(leftArray, leftSize);
	mergeSort(rightArray, rightSize);

	// merge left & right arrays into original array
	merge(leftArray, rightArray, leftSize, rightSize, arr);

	delete[] leftArray;
	delete[] rightArray;
}

/* Referred to: https://www.youtube.com/watch?v=3j0SWDX4AtU */
// 1. Compare left & right arrays
// 2. Put greater or smaller number into the upper-level array, according to user-specified order
// 3. Copy the rest of the elements in left & right arrays
// (e.g. when left array size is 2 and right array size is 1 - left array is already sorted thanks to recursion)
void Sorter::merge(const int* leftArray, const int* rightArray, int leftSize, int rightSize, int* arr) {
	// left, right, array(to copy into) indices
	int left = 0, right = 0, i = 0;

	// traverse through left & right arrays
	while (left < leftSize && right < rightSize) {
		// ascending order
		if (SortOrder == 1) {
			// insert the smaller number into arr[]
			if (leftArray[left] <= rightArray[right]) {
				arr[i++] = leftArray[left++];
			}
			else {
				arr[i++] = rightArray[right++];
			}
		}

		// descending order
		else if (SortOrder == 2) {
			// insert the greater number into arr[]
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