#pragma once
/*
* Title: BinaryNode.h
* Author: Deniz Semih ?zal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: BinaryNode is created in this class
*/
#include <cstddef>
#include <string>
using namespace std;
class BinaryNode
{	// a node in the tree
private:
	BinaryNode() { }
	BinaryNode(const string& nodeItem, BinaryNode* left = NULL,
		BinaryNode* right = NULL)
		: item(nodeItem), leftChildPtr(left), rightChildPtr(right) { }
	// a data item in the tree
	BinaryNode* leftChildPtr;	// pointers to children 
	BinaryNode* rightChildPtr;

	// friend class - can access private parts
	friend class DictionaryBST;
	string item;
};


