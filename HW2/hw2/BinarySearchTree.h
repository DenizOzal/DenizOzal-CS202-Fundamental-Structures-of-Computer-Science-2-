/*
* Title: BinarySearchTree.h
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 2
* Description: BinarySearchTree.h class includes insertItem, deleteItem, getHeight, 
* numHeightBalanced, numNodesDeeper, heightAnalysis and heightAnalysisNearlySorted functions.
*/
#include "BinaryNode.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class BinarySearchTree
{
public:
	BinarySearchTree();
	// Insertion 
	bool insertItem(const int key);
	bool searchTreeinsert(BinaryNode*& treePtr, const int& newItem);

	// Deletion
	bool deleteItem(const int key);

	bool searchTreeDelete(BinaryNode*& treePtr, int searchKey);
	void deleteNodeItem(BinaryNode*& nodePtr);
	void processLeftMost(BinaryNode*& treePtr, int& treeItem);

	// Retrieve
	BinaryNode* retrieveItem(const int key);
	BinaryNode* searchTreeRetrieve(BinaryNode* treePtr, int searchKey);

	// InOrderTraversal
	void inorderTraversal(int*& array, int& length);
	void inorder(BinaryNode* treePtr, int*& array, int& length);
	void update(int item, int*& array, int& length);

	// GetHeight
	int getHeight();
	int calculateHeight(BinaryNode* treePtr);

	// Checking Height balanced or not
	int numHeightBalanced();
	int heightBalanced(BinaryNode* treePtr, int& noOfNodes);

	// Checking no of equal or deeper levels
	int numNodesDeeper(int level);
	void deeperLevels(BinaryNode* treePtr, int level, int& noOfNodes);
	void findLevel(BinaryNode* treePtr, int searchKey, int& noOfLevels);
private:
	BinaryNode* root;
};

// Height analysis
void heightAnalysis();

// Height analysis in nearly sorted array
void heightAnalysisNearlySorted(int*& arr1, int*& arr2, int*& arr3, const int size, int k1, int k2, int k3);