/*
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Özal
* ID: 21802414
* Assignment: 1
* Description: This file includes main file which gives the result of elapsed time, key comparison times, and data moves times according to different algorithms with * different sizes and orders.
*/
#include <iostream>
#include "sorting.h"
#include <ctime>
#include <chrono>
using namespace std;
int main() {
	// Arrays with size 5000
	const int size1 = 5000;
	int* arr1 = new int[size1];
	int* arr2 = new int[size1];
	int* arr3 = new int[size1];
	int* arr4 = new int[size1];
	int* arr5 = new int[size1];
	int* arr6 = new int[size1];
	int* arr7 = new int[size1];
	int* arr8 = new int[size1];
	int* arr9 = new int[size1];

	int countComp1 = 0;
	int countComp2 = 0;
	int countComp3 = 0;
	int countComp4 = 0;
	int countComp5 = 0;
	int countComp6 = 0;
	int countComp7 = 0;
	int countComp8 = 0;
	int countComp9 = 0;

	int countMove1 = 0;
	int countMove2 = 0;
	int countMove3 = 0;
	int countMove4 = 0;
	int countMove5 = 0;
	int countMove6 = 0;
	int countMove7 = 0;
	int countMove8 = 0;
	int countMove9 = 0;


	// Creating Random & Ascending & Descending arrays with Size 5000
	createRandomArrays(arr1, arr2, arr3, size1);
	createAscendingArrays(arr4, arr5, arr6, size1);
	createDescendingArrays(arr7, arr8, arr9, size1);

	//Declare necessary variables
	std::chrono::time_point< std::chrono::system_clock > startTime;
	std::chrono::duration< double, milli > elapsedTime;

	// Random Arrays Elapsed Times with size 5000
	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr1, size1, countComp1, countMove1);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed1 = elapsedTime.count();
    

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr2, size1, countComp2, countMove2);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed2 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr3, size1, countComp3, countMove3);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed3 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 5000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr4, size1, countComp4, countMove4);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed4 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr5, size1, countComp5, countMove5);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed5 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr6, size1, countComp6, countMove6);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed6 = elapsedTime.count();

	// Descending Arrays Elapsed Times with size 5000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr7, size1, countComp7, countMove7);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed7 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr8, size1, countComp8, countMove8);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed8 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr9, size1, countComp9, countMove9);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed9 = elapsedTime.count();


	// Arrays with size 10000
	const int size2 = 10000;
	int* arr10 = new int[size2];
	int* arr11 = new int[size2];
	int* arr12 = new int[size2];
	int* arr13 = new int[size2];
	int* arr14 = new int[size2];
	int* arr15 = new int[size2];
	int* arr16 = new int[size2];
	int* arr17 = new int[size2];
	int* arr18 = new int[size2];

	int countComp10 = 0;
	int countComp11 = 0;
	int countComp12 = 0;
	int countComp13 = 0;
	int countComp14 = 0;
	int countComp15 = 0;
	int countComp16 = 0;
	int countComp17 = 0;
	int countComp18 = 0;

	int countMove10 = 0;
	int countMove11 = 0;
	int countMove12 = 0;
	int countMove13 = 0;
	int countMove14 = 0;
	int countMove15 = 0;
	int countMove16 = 0;
	int countMove17 = 0;
	int countMove18 = 0;

	// Creating Random & Ascending & Descending arrays with Size 10000
	createRandomArrays(arr10, arr11, arr12, size2);
	createAscendingArrays(arr13, arr14, arr15, size2);
	createDescendingArrays(arr16, arr17, arr18, size2);


	// Random Arrays Elapsed Times with size 10000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr10, size2, countComp10, countMove10);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed10 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr11, size2, countComp11, countMove11);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed11 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr12, size2, countComp12, countMove12);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed12 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 10000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr13, size2, countComp13, countMove13);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed13 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr14, size2, countComp14, countMove14);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed14 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr15, size2, countComp15, countMove15);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed15 = elapsedTime.count();


	// Descending Arrays Elapsed Times with size 10000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr16, size2, countComp16, countMove16);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed16 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr17, size2, countComp17, countMove17);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed17 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr18, size2, countComp18, countMove18);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed18 = elapsedTime.count();

	// Arrays with size 15000
	const int size3 = 15000;
	int* arr19 = new int[size3];
	int* arr20 = new int[size3];
	int* arr21 = new int[size3];
	int* arr22 = new int[size3];
	int* arr23 = new int[size3];
	int* arr24 = new int[size3];
	int* arr25 = new int[size3];
	int* arr26 = new int[size3];
	int* arr27 = new int[size3];

	// Creating Random & Ascending & Descending arrays with Size 15000
	createRandomArrays(arr19, arr20, arr21, size3);
	createAscendingArrays(arr22, arr23, arr24, size3);
	createDescendingArrays(arr25, arr26, arr27, size3);

	int countComp19 = 0;
	int countComp20 = 0;
	int countComp21 = 0;
	int countComp22 = 0;
	int countComp23 = 0;
	int countComp24 = 0;
	int countComp25 = 0;
	int countComp26 = 0;
	int countComp27 = 0;

	int countMove19 = 0;
	int countMove20 = 0;
	int countMove21 = 0;
	int countMove22 = 0;
	int countMove23 = 0;
	int countMove24 = 0;
	int countMove25 = 0;
	int countMove26 = 0;
	int countMove27 = 0;

	// Random Arrays Elapsed Times with size 15000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr19, size3, countComp19, countMove19);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed19 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr20, size3, countComp20, countMove20);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed20 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr21, size3, countComp21, countMove21);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed21 = elapsedTime.count();


	// Ascending Arrays Elapsed Times with size 15000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr22, size3, countComp22, countMove22);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed22 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr23, size3, countComp23, countMove23);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed23 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr24, size3, countComp24, countMove24);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed24 = elapsedTime.count();


	// Descending Arrays Elapsed Times with size 15000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr25, size3, countComp25, countMove25);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed25 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr26, size3, countComp26, countMove26);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed26 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr27, size3, countComp27, countMove27);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed27 = elapsedTime.count();


	// Arrays with size 20000
	const int size4 = 20000;
	int* arr28 = new int[size4];
	int* arr29 = new int[size4];
	int* arr30 = new int[size4];
	int* arr31 = new int[size4];
	int* arr32 = new int[size4];
	int* arr33 = new int[size4];
	int* arr34 = new int[size4];
	int* arr35 = new int[size4];
	int* arr36 = new int[size4];

	// Creating Random & Ascending & Descending arrays with Size 20000
	createRandomArrays(arr28, arr29, arr30, size4);
	createAscendingArrays(arr31, arr32, arr33, size4);
	createDescendingArrays(arr34, arr35, arr36, size4);

	int countComp28 = 0;
	int countComp29 = 0;
	int countComp30 = 0;
	int countComp31 = 0;
	int countComp32 = 0;
	int countComp33 = 0;
	int countComp34 = 0;
	int countComp35 = 0;
	int countComp36 = 0;

	int countMove28 = 0;
	int countMove29 = 0;
	int countMove30 = 0;
	int countMove31 = 0;
	int countMove32 = 0;
	int countMove33 = 0;
	int countMove34 = 0;
	int countMove35 = 0;
	int countMove36 = 0;

	// Random Arrays Elapsed Times with size 20000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr28, size4, countComp28, countMove28);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed28 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr29, size4, countComp29, countMove29);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed29 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr30, size4, countComp30, countMove30);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed30 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 20000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr31, size4, countComp31, countMove31);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed31 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr32, size4, countComp32, countMove32);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed32 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr33, size4, countComp33, countMove33);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed33 = elapsedTime.count();

	// Descending Arrays Elapsed Times with size 20000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr34, size4, countComp34, countMove34);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed34 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr35, size4, countComp35, countMove35);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed35 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr36, size4, countComp36, countMove36);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed36 = elapsedTime.count();

	// Arrays with size 25000
	const int size5 = 25000;
	int* arr37 = new int[size5];
	int* arr38 = new int[size5];
	int* arr39 = new int[size5];
	int* arr40 = new int[size5];
	int* arr41 = new int[size5];
	int* arr42 = new int[size5];
	int* arr43 = new int[size5];
	int* arr44 = new int[size5];
	int* arr45 = new int[size5];

	// Creating Random & Ascending & Descending arrays with Size 25000
	createRandomArrays(arr37, arr38, arr39, size5);
	createAscendingArrays(arr40, arr41, arr42, size5);
	createDescendingArrays(arr43, arr44, arr45, size5);

	int countComp37 = 0;
	int countComp38 = 0;
	int countComp39 = 0;
	int countComp40 = 0;
	int countComp41 = 0;
	int countComp42 = 0;
	int countComp43 = 0;
	int countComp44 = 0;
	int countComp45 = 0;

	int countMove37 = 0;
	int countMove38 = 0;
	int countMove39 = 0;
	int countMove40 = 0;
	int countMove41 = 0;
	int countMove42 = 0;
	int countMove43 = 0;
	int countMove44 = 0;
	int countMove45 = 0;

	// Random Arrays Elapsed Times with size 25000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr37, size5, countComp37, countMove37);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed37 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr38, size5, countComp38, countMove38);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed38 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr39, size5, countComp39, countMove39);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed39 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 25000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr40, size5, countComp40, countMove40);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed40 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr41, size5, countComp41, countMove41);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed41 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr42, size5, countComp42, countMove42);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed42 = elapsedTime.count();

	// Descending Arrays Elapsed Times with size 25000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr43, size5, countComp43, countMove43);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed43 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr44, size5, countComp44, countMove44);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed44 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr45, size5, countComp45, countMove45);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed45 = elapsedTime.count();

	// Arrays with size 30000
	const int size6 = 30000;
	int* arr46 = new int[size6];
	int* arr47 = new int[size6];
	int* arr48 = new int[size6];
	int* arr49 = new int[size6];
	int* arr50 = new int[size6];
	int* arr51 = new int[size6];
	int* arr52 = new int[size6];
	int* arr53 = new int[size6];
	int* arr54 = new int[size6];

	// Creating Random & Ascending & Descending arrays with Size 30000
	createRandomArrays(arr46, arr47, arr48, size6);
	createAscendingArrays(arr49, arr50, arr51, size6);
	createDescendingArrays(arr52, arr53, arr54, size6);

	int countComp46 = 0;
	int countComp47 = 0;
	int countComp48 = 0;
	int countComp49 = 0;
	int countComp50 = 0;
	int countComp51 = 0;
	int countComp52 = 0;
	int countComp53 = 0;
	int countComp54 = 0;

	int countMove46 = 0;
	int countMove47 = 0;
	int countMove48 = 0;
	int countMove49 = 0;
	int countMove50 = 0;
	int countMove51 = 0;
	int countMove52 = 0;
	int countMove53 = 0;
	int countMove54 = 0;

	// Random Arrays Elapsed Times with size 30000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr46, size6, countComp46, countMove46);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed46 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr47, size6, countComp47, countMove47);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed47 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr48, size6, countComp48, countMove48);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed48 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 30000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr49, size6, countComp49, countMove49);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed49 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr50, size6, countComp50, countMove50);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed50 = elapsedTime.count();



	// Descending Arrays Elapsed Times with size 30000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr52, size6, countComp52, countMove52);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed52 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr53, size6, countComp53, countMove53);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed53 = elapsedTime.count();

	// Arrays with size 35000
	const int size7 = 35000;
	int* arr55 = new int[size7];
	int* arr56 = new int[size7];
	int* arr57 = new int[size7];
	int* arr58 = new int[size7];
	int* arr59 = new int[size7];
	int* arr60 = new int[size7];
	int* arr61 = new int[size7];
	int* arr62 = new int[size7];
	int* arr63 = new int[size7];

	// Creating Random & Ascending & Descending arrays with Size 35000
	createRandomArrays(arr55, arr56, arr57, size7);
	createAscendingArrays(arr58, arr59, arr60, size7);
	createDescendingArrays(arr61, arr62, arr63, size7);

	int countComp55 = 0;
	int countComp56 = 0;
	int countComp57 = 0;
	int countComp58 = 0;
	int countComp59 = 0;
	int countComp60 = 0;
	int countComp61 = 0;
	int countComp62 = 0;
	int countComp63 = 0;

	int countMove55 = 0;
	int countMove56 = 0;
	int countMove57 = 0;
	int countMove58 = 0;
	int countMove59 = 0;
	int countMove60 = 0;
	int countMove61 = 0;
	int countMove62 = 0;
	int countMove63 = 0;

	// Random Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr55, size7, countComp55, countMove55);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed55 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr56, size7, countComp56, countMove56);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed56 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr57, size7, countComp57, countMove57);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed57 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr58, size7, countComp58, countMove58);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed58 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr59, size7, countComp59, countMove59);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed59 = elapsedTime.count();




	// Descending Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr61, size7, countComp61, countMove61);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed61 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr62, size7, countComp62, countMove62);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed62 = elapsedTime.count();

	// Arrays with size 40000
	const int size8 = 40000;
	int* arr64 = new int[size8];
	int* arr65 = new int[size8];
	int* arr66 = new int[size8];
	int* arr67 = new int[size8];
	int* arr68 = new int[size8];
	int* arr69 = new int[size8];
	int* arr70 = new int[size8];
	int* arr71 = new int[size8];
	int* arr72 = new int[size8];

	// Creating Random & Ascending & Descending arrays with Size 40000
	createRandomArrays(arr64, arr65, arr66, size8);
	createAscendingArrays(arr67, arr68, arr69, size8);
	createDescendingArrays(arr70, arr71, arr72, size8);
	
	int countComp64 = 0;
	int countComp65 = 0;
	int countComp66 = 0;
	int countComp67 = 0;
	int countComp68 = 0;
	int countComp69 = 0;
	int countComp70 = 0;
	int countComp71 = 0;
	int countComp72 = 0;

	int countMove64 = 0;
	int countMove65 = 0;
	int countMove66 = 0;
	int countMove67 = 0;
	int countMove68 = 0;
	int countMove69 = 0;
	int countMove70 = 0;
	int countMove71 = 0;
	int countMove72 = 0;

	// Random Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr64, size8, countComp64, countMove64);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed64 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr65, size8, countComp65, countMove65);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed65 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	quickSort(arr66, size8, countComp66, countMove66);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed66 = elapsedTime.count();

	// Ascending Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr67, size8, countComp67, countMove67);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed67 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr68, size8, countComp68, countMove68);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed68 = elapsedTime.count();

    

	// Descending Arrays Elapsed Times with size 35000
	//Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	insertionSort(arr70, size8, countComp70, countMove70);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed70 = elapsedTime.count();

	// Store the starting time
	startTime = std::chrono::system_clock::now();
	//Code block
	mergeSort(arr71, size8, countComp71, countMove71);
	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	double timeElapsed71 = elapsedTime.count();


	// Printing the table
	cout << "           Sorting on Random Arrays         " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Insertion Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed1 << "\t\t" << countComp1 << "\t\t" << countMove1 << "\n";
	cout << size2 << "\t\t" << timeElapsed10 << "\t\t" << countComp10 <<"\t" << countMove10 << "\n";
	cout << size3 << "\t\t" << timeElapsed19 << "\t\t" << countComp19 << "\t" << countMove19 << "\n";
	cout << size4 << "\t\t" << timeElapsed28 << "\t\t" << countComp28 << "\t" << countMove28 << "\n";
	cout << size5 << "\t\t" << timeElapsed37 << "\t\t" << countComp37 << "\t" << countMove37 << "\n";
	cout << size6 << "\t\t" << timeElapsed46 << "\t\t" << countComp46 << "\t" << countMove46 << "\n";
	cout << size7 << "\t\t" << timeElapsed55 << "\t\t" << countComp55 << "\t" << countMove55 << "\n";
	cout << size8 << "\t\t" << timeElapsed64 << "\t\t" << countComp64 << "\t" << countMove64 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Merge Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed2 << "\t\t" << countComp2 << "\t\t" << countMove2 << "\n";
	cout << size2 << "\t\t" << timeElapsed11 << "\t\t" << countComp11 << "\t\t" << countMove11 << "\n";
	cout << size3 << "\t\t" << timeElapsed20 << "\t\t" << countComp20 << "\t\t" << countMove20 << "\n";
	cout << size4 << "\t\t" << timeElapsed29 << "\t\t" << countComp29 << "\t\t" << countMove29 << "\n";
	cout << size5 << "\t\t" << timeElapsed38 << "\t\t" << countComp38 << "\t\t" << countMove38 << "\n";
	cout << size6 << "\t\t" << timeElapsed47 << "\t\t" << countComp47 << "\t\t" << countMove47 << "\n";
	cout << size7 << "\t\t" << timeElapsed56 << "\t\t" << countComp56 << "\t\t" << countMove56 << "\n";
	cout << size8 << "\t\t" << timeElapsed65 << "\t\t" << countComp65 <<"\t\t" << countMove65 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Quick Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed3 << "\t\t" << countComp3 << "\t\t" << countMove3 << "\n";
	cout << size2 << "\t\t" << timeElapsed12 << "\t\t" << countComp12 << "\t\t" << countMove12 << "\n";
	cout << size3 << "\t\t" << timeElapsed21 << "\t\t" << countComp21 << "\t\t" << countMove21 << "\n";
	cout << size4 << "\t\t" << timeElapsed30 << "\t\t" << countComp30 << "\t\t" << countMove30 << "\n";
	cout << size5 << "\t\t" << timeElapsed39 << "\t\t" << countComp39 << "\t\t" << countMove39 << "\n";
	cout << size6 << "\t\t" << timeElapsed48 << "\t\t" << countComp48 << "\t\t" << countMove48 << "\n";
	cout << size7 << "\t\t" << timeElapsed57 << "\t\t" << countComp57 << "\t\t" << countMove57 << "\n";
	cout << size8 << "\t\t" << timeElapsed66 << "\t\t" << countComp66 << "\t\t" << countMove66 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "           Sorting on Ascending Arrays          " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Insertion Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed4 << "\t\t" << countComp4 << "\t" << countMove1 << "\n";
	cout << size2 << "\t\t" << timeElapsed13 << "\t\t" << countComp13 << "\t" << countMove13 << "\n";
	cout << size3 << "\t\t" << timeElapsed22 << "\t\t" << countComp22 << "\t" << countMove22 << "\n";
	cout << size4 << "\t\t" << timeElapsed31 << "\t\t" << countComp31 << "\t" << countMove31 << "\n";
	cout << size5 << "\t\t" << timeElapsed40 << "\t\t" << countComp40 << "\t" << countMove40 << "\n";
	cout << size6 << "\t\t" << timeElapsed49 << "\t\t" << countComp49 << "\t" << countMove49 << "\n";
	cout << size7 << "\t\t" << timeElapsed58 << "\t\t" << countComp58 << "\t" << countMove58 << "\n";
	cout << size8 << "\t\t" << timeElapsed67 << "\t\t" << countComp67 << "\t" << countMove67 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Merge Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed5 << "\t\t" << countComp5 << "\t\t" << countMove5 << "\n";
	cout << size2 << "\t\t" << timeElapsed14 << "\t\t" << countComp14 << "\t\t" << countMove14 << "\n";
	cout << size3 << "\t\t" << timeElapsed23 << "\t\t" << countComp23 << "\t\t" << countMove23 << "\n";
	cout << size4 << "\t\t" << timeElapsed32 << "\t\t" << countComp32 << "\t\t" << countMove32 << "\n";
	cout << size5 << "\t\t" << timeElapsed41 << "\t\t" << countComp41 << "\t\t" << countMove41 << "\n";
	cout << size6 << "\t\t" << timeElapsed50 << "\t\t" << countComp50 << "\t\t" << countMove50 << "\n";
	cout << size7 << "\t\t" << timeElapsed59 << "\t\t" << countComp59 << "\t\t" << countMove59 << "\n";
	cout << size8 << "\t\t" << timeElapsed68 << "\t\t" << countComp68 << "\t\t" << countMove68 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Quick Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed6 << "\t\t" << countComp6 << "\t" << countMove6 << "\n";
	cout << size2 << "\t\t" << timeElapsed15 << "\t\t" << countComp15 << "\t" << countMove15 << "\n";
	cout << size3 << "\t\t" << timeElapsed24 << "\t\t" << countComp24 << "\t" << countMove24 << "\n";
	cout << size4 << "\t\t" << timeElapsed33 << "\t\t" << countComp33 << "\t" << countMove33 << "\n";
	cout << size5 << "\t\t" << timeElapsed42 << "\t\t" << countComp42 << "\t" << countMove42 << "\n";
	
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "           Sorting on Descending Arrays          " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Insertion Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed7 << "\t" << countComp7 << "\t\t" << countMove1 << "\n";
	cout << size2 << "\t\t" << timeElapsed16 << "\t" << countComp16 << "\t\t" << countMove16 << "\n";
	cout << size3 << "\t\t" << timeElapsed25 << "\t" << countComp25 << "\t\t" << countMove25 << "\n";
	cout << size4 << "\t\t" << timeElapsed34 << "\t" << countComp34 << "\t\t" << countMove34 << "\n";
	cout << size5 << "\t\t" << timeElapsed43 << "\t" << countComp43 << "\t\t" << countMove43 << "\n";
	cout << size6 << "\t\t" << timeElapsed52 << "\t" << countComp52 << "\t\t" << countMove52 << "\n";
	cout << size7 << "\t\t" << timeElapsed61 << "\t" << countComp61 <<"\t\t" << countMove61 << "\n";
	cout << size8 << "\t\t" << timeElapsed70 << "\t" << countComp70 << "\t\t" << countMove70 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Merge Sort\nArray Size\tTime Elapsed\t countComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed8 << "\t\t" << countComp8 << "\t\t" << countMove8 << "\n";
	cout << size2 << "\t\t" << timeElapsed17 << "\t\t" << countComp17 << "\t\t" << countMove17 << "\n";
	cout << size3 << "\t\t" << timeElapsed26 << "\t\t" << countComp26 << "\t\t" << countMove26 << "\n";
	cout << size4 << "\t\t" << timeElapsed35 << "\t\t" << countComp35 << "\t\t" << countMove35 << "\n";
	cout << size5 << "\t\t" << timeElapsed44 << "\t\t" << countComp44 << "\t\t" << countMove44 << "\n";
	cout << size6 << "\t\t" << timeElapsed53 << "\t\t" << countComp53 << "\t\t" << countMove53 << "\n";
	cout << size7 << "\t\t" << timeElapsed62 << "\t\t" << countComp62 << "\t\t" << countMove62 << "\n";
	cout << size8 << "\t\t" << timeElapsed71 << "\t\t" << countComp71 << "\t\t" << countMove71 << "\n";
	cout << "--------------------------------------------------" << endl;
	cout << "Analysis of Quick Sort\nArray Size\tTime Elapsed\tcountComp\tcountMove\n";
	cout << size1 << "\t\t" << timeElapsed9 << "\t\t" << countComp9 << "\t" << countMove9 << "\n";
	cout << size2 << "\t\t" << timeElapsed18 << "\t\t" << countComp18 << "\t" << countMove18 << "\n";
	cout << size3 << "\t\t" << timeElapsed27 << "\t\t" << countComp27 << "\t" << countMove27 << "\n";
	cout << size4 << "\t\t" << timeElapsed36 << "\t\t" << countComp36 << "\t" << countMove36 << "\n";
	cout << size5 << "\t\t" << timeElapsed45 << "\t\t" << countComp45 << "\t" << countMove45 << "\n";
	
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
	delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;
    delete[] arr15;
    delete[] arr16;
    delete[] arr17;
    delete[] arr18;
    delete[] arr19;
    delete[] arr20;
    delete[] arr21;
    delete[] arr22;
    delete[] arr23;
    delete[] arr24;
    delete[] arr25;
    delete[] arr26;
    delete[] arr27;
    delete[] arr28;
    delete[] arr29;
    delete[] arr30;
    delete[] arr31;
    delete[] arr32;
    delete[] arr33;
    delete[] arr34;
    delete[] arr35;
    delete[] arr36;
    delete[] arr37;
    delete[] arr38;
    delete[] arr39;
    delete[] arr40;
    delete[] arr41;
    delete[] arr42;
    delete[] arr43;
    delete[] arr44;
    delete[] arr45;
    delete[] arr46;
    delete[] arr47;
    delete[] arr48;
    delete[] arr49;
    delete[] arr50;
    delete[] arr51;
    delete[] arr52;
    delete[] arr53;
    delete[] arr54;
    delete[] arr55;
    delete[] arr56;
    delete[] arr57;
    delete[] arr58;
    delete[] arr59;
    delete[] arr60;
    delete[] arr61;
    delete[] arr62;
    delete[] arr63;
    delete[] arr64;
    delete[] arr65;
    delete[] arr66;
    delete[] arr67;
    delete[] arr68;
    delete[] arr69;
    delete[] arr70;
    delete[] arr71;
    delete[] arr72;
	return 0;
}