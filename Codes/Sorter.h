#ifndef SORTER_H_
#define SORTER_H_

using namespace std;

class Sorter {
private:
	int* Array;
	const int ArraySize;
	const int SortOrder;

public:
	Sorter(int* arr, int size, int order) : Array(arr), ArraySize(size), SortOrder(order) {}

	// calls mergeSort()
	void sort();

	/* this implementation refers to https://www.youtube.com/watch?v=3j0SWDX4AtU */
	// Divide the array into two halves recursively and merge them back in order
	void mergeSort(int* arr, const int size);
	
	// merge two half arrays back into one in order
	void merge(const int* leftArray, const int* rightArray, int leftSize, int rightSize, int* arr);

};

#endif