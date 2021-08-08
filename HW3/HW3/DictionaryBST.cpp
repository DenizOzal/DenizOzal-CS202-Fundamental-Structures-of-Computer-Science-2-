/*
* Title: DictionaryBST.cpp
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: This header file includes implementations of insert and search functions that
* are overrired from DictionarySearchTree.
*/
#include "DictionaryBST.h"
#include <cstddef>

// Destructor
DictionaryBST::~DictionaryBST() {
	destroyTree(root);
}


// Uses postorder traversal for the destroy operation
// (Visits first the left and right children and then the node)
void DictionaryBST::destroyTree(BinaryNode*& treePtr) {

	if (treePtr != NULL) {
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}


// Insert
bool DictionaryBST::insertItem(const string key) {
	return searchTreeinsert(root, key);
}
bool DictionaryBST::searchTreeinsert(BinaryNode*& treePtr, const string& newItem) {

	// Position of insertion found; insert after leaf
	if (treePtr == NULL) {
		treePtr = new BinaryNode(newItem, NULL, NULL);
		if (treePtr == NULL)
			return false;
		return true;
	}
	else if (newItem == treePtr->item)
		return false;
	// Else search for the insertion position
	else if (newItem < treePtr->item)
		searchTreeinsert(treePtr->leftChildPtr, newItem);
	else
		searchTreeinsert(treePtr->rightChildPtr, newItem);
}

void DictionaryBST::insert(string word){
	insertItem(word);
}


// Search
void DictionaryBST::retrieveItem(const string key, int& numComparisons, bool& found) const{
	searchTreeRetrieve(root, key, numComparisons, found);
}
void DictionaryBST::searchTreeRetrieve(BinaryNode* treePtr, string searchKey, int& numComparisons, bool& found)const {
	if (treePtr == NULL) {
		found = false;
		return;
	}
	else if (searchKey == treePtr->item) {
		++numComparisons;
		found = true;
		return;
	}
	else if (searchKey < treePtr->item) {
		++numComparisons;
		searchTreeRetrieve(treePtr->leftChildPtr, searchKey, numComparisons, found);
	}
	else{
		++numComparisons;
		searchTreeRetrieve(treePtr->rightChildPtr, searchKey, numComparisons, found);
	}
}


void DictionaryBST::search(string word, int& numComparisons, bool& found) const {
	retrieveItem(word, numComparisons, found);
}
 
// Search (Summarize)
void DictionaryBST::search(string queryFile, string outputFile) const {
	// Properties
	double average = 0;
	int numComparisons = 0;
	int noOfQueries = 0;
	bool found = false;
	string* strArray = NULL;

	// Create a text string, which is used to output the text file
	string myText;

	// Read from the text file
	ifstream MyReadFile(queryFile);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)){
		noOfQueries++;

		string* tempPointer = strArray;

		strArray = new string[noOfQueries];
		
		int currentIndex = noOfQueries - 1;

		strArray[currentIndex] = myText;

		// Copy back other items
		for (int i = 0; i < currentIndex; i++) {
			strArray[i] = tempPointer[i];
		}

		delete[] tempPointer;
	}
	
	// Close the file
	MyReadFile.close();
	
	// New Arrays for storing
	int* boolArr = new int[noOfQueries];
	int* compArr = new int[noOfQueries];

	// Calculate comparisons and founds
	for (int i = 0; i < noOfQueries; i++) {
		search(strArray[i], numComparisons, found);
		boolArr[i] = found;
		compArr[i] = numComparisons;
		numComparisons = 0;
	}
	ofstream myOutputFile;
	myOutputFile.open(outputFile);
	myOutputFile << "Binary Search Tree: \n" << endl;
	myOutputFile << "Queries" << setw(20) << "Found Or Not" << setw(20) << "NoOfComparisons" << "\n";

	// Print output
	
	for (int i = 0; i < noOfQueries; i++) {
		myOutputFile << strArray[i] << setw(20 - strArray[i].length()) << boolArr[i] << setw(20) << compArr[i] << "\n";
	}

	myOutputFile << "\nNumber Of queries: " << noOfQueries << endl;

	int max = compArr[0];
	int totalComp = 0;
	// Calculating max item
	for (int i = 0; i < noOfQueries; i++) {
		if (compArr[i] > max)
			max = compArr[i];
		totalComp += compArr[i];
	}

	// Calculating average item
	average = totalComp / double(noOfQueries);

	myOutputFile << "Maximum number of comparisons: " << max << endl;
	myOutputFile << "Average number of comparisons: " << average << endl;
	myOutputFile.close();
}

