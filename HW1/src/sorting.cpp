/*
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Özal
* ID: 21802414
* Assignment: 1
* Description: This file includes implementation of Selection Sort, Insertion Sort,
* Bubble Sort, Merge Sort, Quick Sort algorithms. Also for the Part B there are three 
* different implementations of insertion, selection and quick sort algorithms.
*/
#include "sorting.h"
#include <stdlib.h>
#include <iostream>
// Selection Sort
void selectionSort(int theArray[], int n) {
	for (int last = n - 1; last >= 1; --last) {
		int largest = indexOfLargest(theArray, last + 1);
		swap(theArray[largest], theArray[last]);
	}
}
int indexOfLargest(const int theArray[], int size) {
	int indexSoFar = 0;
	for (int currentIndex = 1; currentIndex < size; ++currentIndex)
	{
		if (theArray[currentIndex] > theArray[indexSoFar])
			indexSoFar = currentIndex;
	}
	return indexSoFar;
}


// Insertion Sort
void insertionSort(int theArray[], int n) {

	for (int unsorted = 1; unsorted < n; ++unsorted) {

		int nextItem = theArray[unsorted];
		int loc = unsorted;

		for (; (loc > 0) && (theArray[loc - 1] > nextItem); --loc)
			theArray[loc] = theArray[loc - 1];

		theArray[loc] = nextItem;
	}
}

// Bubble Sort
void bubbleSort(int theArray[], int n) {
	bool sorted = false;

	for (int pass = 1; (pass < n) && !sorted; ++pass) {
		sorted = true;
		for (int index = 0; index < n - pass; ++index) {
			int nextIndex = index + 1;
			if (theArray[index] > theArray[nextIndex]) {
				swap(theArray[index], theArray[nextIndex]);
				sorted = false; // signal exchange
			}
		}
	}
}

// Merge Sort
void mergesort(int theArray[], int first, int last) {

	if (first < last) {

		int mid = (first + last) / 2; 	// index of midpoint

		mergesort(theArray, first, mid);

		mergesort(theArray, mid + 1, last);

		// merge the two halves
		merge(theArray, first, mid, last);
	}
}  

void merge(int theArray[], int first, int mid, int last) {
	const int MAX_SIZE = 8;
	int tempArray[MAX_SIZE]; 	// temporary array

	int first1 = first; 	// beginning of first subarray
	int last1 = mid; 		// end of first subarray
	int first2 = mid + 1;	// beginning of second subarray
	int last2 = last;		// end of second subarray
	int index = first1; // next available location in tempArray

	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (theArray[first1] < theArray[first2]) {
			tempArray[index] = theArray[first1];
			++first1;
		}
		else {
			tempArray[index] = theArray[first2];
			++first2;
		}
	}
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index)
		tempArray[index] = theArray[first1];

	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index)
		tempArray[index] = theArray[first2];

	// copy the result back into the original array
	for (index = first; index <= last; ++index)
		theArray[index] = tempArray[index];

}  // end merge

 // Quick Sort
void quicksort(int theArray[], int first, int last) {
	// Precondition: theArray[first..last] is an array.
	// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

	if (first < last) {

		// create the partition: S1, pivot, S2
		partition(theArray, first, last, pivotIndex);

		// sort regions S1 and S2
		quicksort(theArray, first, pivotIndex - 1);
		quicksort(theArray, pivotIndex + 1, last);
	}
}
void partition(int theArray[], int first, int last, int& pivotIndex) {
	// Precondition: theArray[first..last] is an array; first <= last.
	// Postcondition: Partitions theArray[first..last] such that:
	//   S1 = theArray[first..pivotIndex-1] < pivot
	//   theArray[pivotIndex] == pivot
	//   S2 = theArray[pivotIndex+1..last] >= pivot

	 // place pivot in theArray[first]
	 //choosePivot(theArray, first, last);

	int pivot = theArray[first]; // copy pivot
	// initially, everything but pivot is in unknown
	int lastS1 = first;           // index of last item in S1
	int firstUnknown = first + 1; // index of first item in unknown

	 // move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) {
		// Invariant: theArray[first+1..lastS1] < pivot
		//            theArray[lastS1+1..firstUnknown-1] >= pivot

		// move item from unknown to proper region
		if (theArray[firstUnknown] < pivot) {  	// belongs to S1
			++lastS1;
			swap(theArray[firstUnknown], theArray[lastS1]);
		}	// else belongs to S2
	}
	// place pivot in proper position and mark its location
	swap(theArray[first], theArray[lastS1]);
	pivotIndex = lastS1;
}

// Insertion Sort in Descending Order
void insertionSort(int* arr, const int size, int& countComp, int& countMove) {
	for (int unsorted = 1; unsorted < size; ++unsorted) {

		int nextItem = arr[unsorted]; //  First data move 
		++countMove; // Increment by 1 countMove
		int loc = unsorted;

		for (; (loc > 0) && (arr[loc - 1] < nextItem); --loc) { // First key comparison & current item needs to be less than next item
			++countComp; // Increment by 1 countComp
			arr[loc] = arr[loc - 1]; // Second data move
			++countMove;
		}
		++countComp; // Increment by 1 countComp
		arr[loc] = nextItem; // Third data move
		++countMove;
	}
}

// Merge Sort in Descending Order
void mergeSort(int* arr, const int size, int& countComp, int& countMove) {
	int first = 0;
	int last = size - 1;
	const int MAX_SIZE = size;
	mergesort(arr, first, last, MAX_SIZE, countComp, countMove);
}

void mergesort(int* arr, int first, int last, const int maxSize, int& keyComp, int& dataMove) {

	if (first < last) {

		int mid = (first + last) / 2; 	// index of midpoint

		mergesort(arr, first, mid, maxSize, keyComp, dataMove);

		mergesort(arr, mid + 1, last, maxSize, keyComp, dataMove);

		// merge the two halves
		merge(arr, first, mid, last, maxSize, keyComp, dataMove);
	}
}  

void merge(int* arr, int first, int mid, int last, const int maxSize, int& keyComp, int& dataMove) {
	int* tempArray = new int[maxSize]; 	// temporary array
	int first1 = first; 	// beginning of first subarray
	int last1 = mid; 		// end of first subarray
	int first2 = mid + 1;	// beginning of second subarray
	int last2 = last;		// end of second subarray
	int index = first1; // next available location in tempArray

	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (arr[first1] > arr[first2]) { // First key comparison
			
			tempArray[index] = arr[first1]; // First data move
			++dataMove;
			++first1;
		}
		else {
			tempArray[index] = arr[first2]; // Second data move
			++dataMove;
			++first2;
		}
		++keyComp;
	}
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index) {
		tempArray[index] = arr[first1]; // Third data move
		++dataMove;
	}

	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index) {
		tempArray[index] = arr[first2]; // Fourth data move
		++dataMove;
	}

	// copy the result back into the original array
	for (index = first; index <= last; ++index) {
		arr[index] = tempArray[index]; // Fifth data move
		++dataMove;
	}

	// delete temp array
	delete[] tempArray;

}  // end merge

// Quick Sort in Descending Order
void quickSort(int* arr, const int size, int& countComp, int& countMove) {
	int first = 0;
	int last = size - 1;
	quicksort(arr, first, last, countComp, countMove);
}

void quicksort(int* arr, int first, int last, int& keyComp, int& dataMove) {
	// Precondition: theArray[first..last] is an array.
	// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

	if (first < last) {

		// create the partition: S1, pivot, S2
		partition(arr, first, last, pivotIndex, keyComp, dataMove);

		// sort regions S1 and S2
		quicksort(arr, first, pivotIndex - 1, keyComp, dataMove);
		quicksort(arr, pivotIndex + 1, last, keyComp, dataMove);
	}
}
void partition(int* arr, int first, int last, int& pivotIndex, int& keyComp, int& dataMove) {
	// Precondition: theArray[first..last] is an array; first <= last.
	// Postcondition: Partitions theArray[first..last] such that:
	//   S1 = theArray[first..pivotIndex-1] < pivot
	//   theArray[pivotIndex] == pivot
	//   S2 = theArray[pivotIndex+1..last] >= pivot

	 // place pivot in theArray[first]
	 //choosePivot(theArray, first, last);

	int pivot = arr[first]; // copy pivot && First data move
	++dataMove;
	// initially, everything but pivot is in unknown
	int lastS1 = first;           // index of last item in S1
	int firstUnknown = first + 1; // index of first item in unknown

	 // move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) {
		// Invariant: theArray[first+1..lastS1] < pivot
		//            theArray[lastS1+1..firstUnknown-1] >= pivot
	
		// move item from unknown to proper region
		if (arr[firstUnknown] > pivot) {  	// belongs to S1 && First key comparison
			++lastS1;
			swap(arr[firstUnknown], arr[lastS1]);
			dataMove += 3;
		}	// else belongs to S2
		++keyComp;
	}
	// place pivot in proper position and mark its location
	// place pivot in proper position and mark its location
	swap(arr[first], arr[lastS1]);
	dataMove += 3; // Third data move
	pivotIndex = lastS1;
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
// Create Random Sorted Arrays with using rand() function
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, const int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = (rand() * (RAND_MAX + 1) + rand()) + 1;
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}
}
// Create Ascending Arrays by beginning 1 and increment by one
void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, const int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = i;
		arr2[i] = i;
		arr3[i] = i;
	}
}
// Create Descending Arrays beginning size and decrement by one
void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, const int size) {
	int cnt = 0;
	for (int i = size  ; i > 0; i--) {
		arr1[cnt] = i;
		arr2[cnt] = i;
		arr3[cnt] = i;
		++cnt;
	}
}