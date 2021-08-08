/*
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Özal
* ID: 21802414
* Assignment: 1
* Description: This file includes header files of Selection Sort, Insertion Sort,
* Bubble Sort, Merge Sort, Quick Sort algorithms. Also for the Part B there are
* three different header files of insertion, selection and quick sort algorithms.
*/
	class sorting
	{
	};
	// Selection Sort 
	void selectionSort(int theArray[], int n);
	int indexOfLargest(const int theArray[], int size);
	

	// Insertion Sort
	void insertionSort(int theArray[], int n);

	// Bubble Sort
	void bubbleSort(int theArray[], int n);

	// Merge Sort
	void mergesort(int theArray[], int first, int last);
	void merge(int theArray[], int first, int mid, int last);

	// Quick Sort
	void quicksort(int theArray[], int first, int last);
	void partition(int theArray[], int first, int last, int& pivotIndex);

	// Insertion Sort in Descending Order
	void insertionSort(int* arr, const int size, int& countComp, int& countMove);

	// Merge Sort in Descending Order
	void mergeSort(int* arr, const int size, int& countComp, int& countMove);
	void mergesort(int* arr, int first, int last, const int maxSize, int& keyComp, int& dataMove);
	void merge(int* arr, int first, int mid, int last, const int maxSize, int& keyComp, int& dataMove);

	// Quick Sort in Descending Order
	void quickSort(int* arr, const int size, int& countComp, int& countMove);
	void quicksort(int* arr, int first, int last, int& keyComp, int& dataMove);
	void partition(int* arr, int first, int last, int& pivotIndex, int& keyComp, int& dataMove);
	void swap(int& x, int& y);

	void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, const int size);
	void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, const int size);
	void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, const int size);

