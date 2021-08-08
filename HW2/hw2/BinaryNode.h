/*
* Title: BinaryNode.h
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 2
* Description: BinaryNode is created in this class 
*/
#include <cstddef>
class BinaryNode
{	// a node in the tree
private:
	BinaryNode() { }
	BinaryNode(const int& nodeItem, BinaryNode* left = NULL,
		BinaryNode* right = NULL)
		: item(nodeItem), leftChildPtr(left), rightChildPtr(right) { }
		// a data item in the tree
	BinaryNode* leftChildPtr;	// pointers to children 
	BinaryNode* rightChildPtr;


	// friend class - can access private parts
	friend class BinarySearchTree;
	int item;
};


