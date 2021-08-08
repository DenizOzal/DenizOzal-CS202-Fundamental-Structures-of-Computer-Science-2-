/*
* Title: main.cpp
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 2
* Description: Different binary search tree functions is tested in 
* this class
*/
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
int main() {
	// Creating a bst object
	BinarySearchTree obj;

	// Insert 5, 3, 9, 4, 8, 6, 1, 7, 2, 10 respectively
	obj.insertItem(5);
	obj.insertItem(3);
	obj.insertItem(9);
	obj.insertItem(4);
	obj.insertItem(8);
	obj.insertItem(6);
	obj.insertItem(1);
	obj.insertItem(7);
	obj.insertItem(2);
	obj.insertItem(10);
	
	// Displaying inorder traversal
	int* arr1 = NULL;
	int length1 = 0;
	obj.inorderTraversal(arr1, length1);
	cout << "Array after insertion: ";
	for (int i = 0; i < length1; i++)
		cout << arr1[i] << " ";
	cout << endl;

	// Display height of a tree before deletion
	cout << "Height (Before Deletion): " << obj.getHeight() << endl;

	// Display balanced height nodes before deletion
	cout << "Balanced height nodes (Before Deletion): " << obj.numHeightBalanced() << endl;

	// Display number of nodes deeper than level 3
	cout << "No of nodes deeper or equal in level 3 (Before Deletion) " << obj.numNodesDeeper(3) << endl;

	// Delete 1, 5, 9, 10, 7 respectively
	obj.deleteItem(1);
	obj.deleteItem(5);
	obj.deleteItem(9);
	obj.deleteItem(10);
	obj.deleteItem(7);

	// Displaying inorder traversal
	int* arr2 = NULL;
	int length2 = 0;
	obj.inorderTraversal(arr2, length2);
	cout << "Array after deletion: ";
	for (int i = 0; i < length2; i++)
		cout << arr2[i] << " ";
	cout << endl;

	// Display height of a tree before deletion
	cout << "Height (After Deletion): " << obj.getHeight() << endl;

	// Display balanced height nodes before deletion
	cout << "Balanced height nodes (After Deletion): " << obj.numHeightBalanced() << endl;

	// Display number of nodes deeper than level 3
	cout << "No of nodes deeper or equal in level 3 (After Deletion) " << obj.numNodesDeeper(3) << endl;

	// Height Analysis
	cout << "Height Analysis with insertion and deletion operations: " << endl;
	heightAnalysis();
	cout << endl;
	
	// Creating 3 empty array with different K values 100, 1000, 10000 respectively.
	int* arr3 = NULL;
	int* arr4 = NULL;
	int* arr5 = NULL;
	int k1 = 100;
	int k2 = 1000;
	int k3 = 10000;
	const int size = 20000;
	// Height Analysis in nearly sorted array
	cout << "Height Analysis with insertion with different K values: " << endl;
	heightAnalysisNearlySorted(arr3, arr4, arr5, size, k1, k2, k3);
	return 0;
}