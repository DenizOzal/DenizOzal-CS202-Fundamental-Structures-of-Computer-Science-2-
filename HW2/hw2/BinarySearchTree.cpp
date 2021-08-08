/*
* Title: BinarySearchTree.cpp
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 2
* Description: BinarySearchTree.cpp includes insertItem, deleteItem, getHeight,
* numHeightBalanced, numNodesDeeper, heightAnalysis and heightAnalysisNearlySorted functions
* and their implementations.
*/
#include "BinarySearchTree.h"
#include "auxArrayFunctions.h"
#include <cstddef>
#include <cmath> 
#include <iostream>
using namespace std;
// Retrieve
BinarySearchTree::BinarySearchTree() {
	root = NULL;
}
BinaryNode* BinarySearchTree::retrieveItem(const int key) {
	return searchTreeRetrieve(root, key);
}
BinaryNode* BinarySearchTree::searchTreeRetrieve(BinaryNode* treePtr, int searchKey) {
	if (treePtr == NULL)
		return NULL;
	else if (searchKey == treePtr->item) {
		return treePtr;
	}
	else if (searchKey < treePtr->item)
		searchTreeRetrieve(treePtr->leftChildPtr, searchKey);
	else
		searchTreeRetrieve(treePtr->rightChildPtr, searchKey);
}

// Insert
bool BinarySearchTree::insertItem(const int key) {
	 return searchTreeinsert(root, key); 
}
bool BinarySearchTree::searchTreeinsert(BinaryNode*& treePtr, const int& newItem) {
	
	// Position of insertion found; insert after leaf
	if (treePtr == NULL) {
		treePtr = new BinaryNode(newItem, NULL, NULL);
		if (treePtr == NULL)
			return false;
		return true;
	}
	else if(newItem == treePtr->item)
		return false;
	// Else search for the insertion position
	else if (newItem < treePtr->item)
		searchTreeinsert(treePtr->leftChildPtr, newItem);
	else
		searchTreeinsert(treePtr->rightChildPtr, newItem);
}

// Deletion
bool BinarySearchTree::deleteItem(const int key) {
	return searchTreeDelete(root, key);
}

bool BinarySearchTree::searchTreeDelete(BinaryNode*& treePtr, int searchKey) {
	if (treePtr == NULL) { // Empty tree
		return false;
	}
	// Position of deletion found
	else if (searchKey == treePtr->item) {
		deleteNodeItem(treePtr);
		return true;
	}
	// Else search for the deletion position
	else if (searchKey < treePtr->item)
		searchTreeDelete(treePtr->leftChildPtr, searchKey);
	else
		searchTreeDelete(treePtr->rightChildPtr, searchKey);

}
void BinarySearchTree::deleteNodeItem(BinaryNode*& nodePtr) {
	BinaryNode* delPtr;
	int replacementItem;


	// (1)  Test for a leaf
	if ((nodePtr->leftChildPtr == NULL) &&
		(nodePtr->rightChildPtr == NULL)) {
		delete nodePtr;
		nodePtr = NULL;
	}


	// (2)  Test for no left child
	else if (nodePtr->leftChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;
		delete delPtr;
	}

	// (3)  Test for no right child
	else if (nodePtr->rightChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->leftChildPtr;
		delPtr->leftChildPtr = NULL;
		delete delPtr;
	}


	// (4)  There are two children:
	//      Retrieve and delete the inorder successor
	else {
		processLeftMost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}
}

void BinarySearchTree::processLeftMost(BinaryNode*& treePtr, int& treeItem) {
	if (treePtr->leftChildPtr == NULL) {
		treeItem = treePtr->item;
		BinaryNode* delPtr = treePtr;
		treePtr = treePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; // defense
		delete delPtr;
	}
	else
		processLeftMost(treePtr->leftChildPtr, treeItem);
}

// InorderTraversal
void BinarySearchTree::inorderTraversal(int*& array, int& length) {
	inorder(root, array, length);
}

void BinarySearchTree::inorder(BinaryNode* treePtr, int*& array, int& length) {
	if (treePtr != NULL) {
		inorder(treePtr->leftChildPtr, array, length);
		update(treePtr->item, array, length);
		inorder(treePtr->rightChildPtr, array, length);
	}
}
void BinarySearchTree::update(int item, int*& array, int& length) {
	// Creating a pointer which points old array
	int* tempArr = array;

	// Creating dynamically allocated new array
	array = new int[length + 1];

	// Adding new item
	array[length] = item;

	// Copy old items to new array
	for (int i = 0; i < length; i++)
		array[i] = tempArr[i];

	// Delete tempArray
	delete[] tempArr;
	tempArr = NULL;
	// Increment by one length
	++length;
}

// GetHeight
int BinarySearchTree::getHeight() {
	return calculateHeight(root);

}

int BinarySearchTree::calculateHeight(BinaryNode* treePtr) {
	if (treePtr == NULL)
		return 0;
	else
	{
		// compute depth of each subtree
		int leftSubTree = calculateHeight(treePtr->leftChildPtr);
		int rightSubTree = calculateHeight(treePtr->rightChildPtr);

		// using greater one
		if (leftSubTree > rightSubTree)
			return(leftSubTree + 1);
		else return(rightSubTree + 1);
	}
}

// Height Balanced
int BinarySearchTree::numHeightBalanced() {
	int noOfNodes = 0;
	heightBalanced(root, noOfNodes);
	return noOfNodes;
}

int BinarySearchTree::heightBalanced(BinaryNode* treePtr, int& noOfNodes) {
	if (treePtr == NULL)
		return 0;
	else
	{
		int leftSubTree = calculateHeight(treePtr->leftChildPtr);
		int rightSubTree = calculateHeight(treePtr->rightChildPtr);

		if (abs(leftSubTree - rightSubTree) <= 1)
			++noOfNodes;

		heightBalanced(treePtr->leftChildPtr, noOfNodes);
		heightBalanced(treePtr->rightChildPtr, noOfNodes);
	}
}

// numNodesDeeper
int BinarySearchTree::numNodesDeeper(int level) {
	int noOfNodes = 0;
	deeperLevels(root, level, noOfNodes);
	return noOfNodes;
}

void BinarySearchTree::deeperLevels(BinaryNode* treePtr, int level, int& noOfNodes) {
	if (treePtr == NULL)
		return;
	else {
		deeperLevels(treePtr->leftChildPtr, level, noOfNodes); // Go Left
		int noOfLevels = 1;
		findLevel(root, treePtr->item, noOfLevels);
		if (noOfLevels >= level) {
			++noOfNodes;
		}
		deeperLevels(treePtr->rightChildPtr, level, noOfNodes);
	}
}

void BinarySearchTree::findLevel(BinaryNode* treePtr, int searchKey, int& noOfLevels) {
	if (treePtr == NULL)
		return;
	else {
		if (treePtr->item == searchKey)
			return;
		else if (searchKey < treePtr->item) {
			++noOfLevels;
			findLevel(treePtr->leftChildPtr, searchKey, noOfLevels);
		}
		else {
			++noOfLevels;
			findLevel(treePtr->rightChildPtr, searchKey, noOfLevels);
		}
	}
}
void heightAnalysis() {
	BinarySearchTree tree;
	int const size = 20000;
	int* arr = new int[size];
	// Creating a random array with size 20000
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() * (RAND_MAX + 1) + rand()) + 1;
	}

	// Insert each item into a bst
	for (int i = 1; i <= size; i++) {
		int correctIndex = i - 1;
		tree.insertItem(arr[correctIndex]);
		if (i % 1000 == 0 && i != 0) {
			cout << "The height of a tree in " << i  << "th insertion: " << tree.getHeight() << endl;
		}
	}

	// Shuffle part
	for (int i = 0; i < size; i++) {
		int index = rand() % size;
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
	cout << endl;
	// Delete each item from bst
	for (int i = 1; i <= size; i++) {
		int correctIndex = i - 1;
		tree.deleteItem(arr[correctIndex]);
		if (i % 1000 == 0 && i != 0) {
			cout << "The height of a tree in " << i  << "th deletion: " << tree.getHeight() << endl;
		}
	}
	delete[] arr;
}

void heightAnalysisNearlySorted(int*& arr1, int*& arr2, int*& arr3, const int size, int k1, int k2, int k3){
	BinarySearchTree tree1;
	BinarySearchTree tree2;
	BinarySearchTree tree3;

	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];

	createNearlySortedArrays(arr1, size, k1);
	createNearlySortedArrays(arr2, size, k2);
	createNearlySortedArrays(arr3, size, k3);
		
	cout << "K = " << k1 << endl;
	// Insert each item into a tree1
	for (int i = 1; i <= size; i++) {
		int correctIndex = i - 1;
		tree1.insertItem(arr1[correctIndex]);
		if (i % 1000 == 0 && i != 0) {
			cout << "The height of a tree in " << i << "th insertion: " << tree1.getHeight() << endl;
		}
	}
	cout << endl;
	delete[] arr1;

	cout << "K = " << k2 << endl;
	// Insert each item into a tree2
	for (int i = 1; i <= size; i++) {
		int correctIndex = i - 1;
		tree2.insertItem(arr2[correctIndex]);
		if (i % 1000 == 0 && i != 0) {
			cout << "The height of a tree in " << i << "th insertion: " << tree2.getHeight() << endl;
		}
	}
	cout << endl;
	delete[] arr2;

	// Insert each item into a tree3
	cout << "K = " << k3 << endl;
	for (int i = 1; i <= size; i++) {
		int correctIndex = i - 1;
		tree3.insertItem(arr3[correctIndex]);
		if (i % 1000 == 0 && i != 0) {
			cout << "The height of a tree in " << i << "th insertion: " << tree3.getHeight() << endl;
		}
	}
	delete[] arr3;
}