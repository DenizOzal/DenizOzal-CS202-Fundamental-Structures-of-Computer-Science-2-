/*
* Title: DictionaryBST.h
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: This header file includes prototypes of insert and search functions that
* are overrired from DictionarySearchTree. This files creates a dictionary using binary 
* search tree structure.
*/
#pragma once
#include "DictionarySearchTree.h"
#include "BinaryNode.h"
class DictionaryBST : public DictionarySearchTree
{
public:
	//Constructor
	DictionaryBST(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
		// Create a text string, which is used to output the text file
		string myText;

		// Read from the text file
		ifstream MyReadFile(dictionaryFile);

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(MyReadFile, myText)) {

			insert(myText);
		}

		// Close the file
		MyReadFile.close();
	};
	
	// Destructor
	~DictionaryBST();
	void destroyTree(BinaryNode*& treePtr);

	// Insertion 
	bool insertItem(const string key);
	bool searchTreeinsert(BinaryNode*& treePtr, const string& newItem);

	//@Override
	void insert(string word);
	
	// Search
	void retrieveItem(const string key, int& numComparisons, bool& found) const;
	void searchTreeRetrieve(BinaryNode* treePtr, string searchKey, int& numComparisons, bool& found) const;

	//@Override
	void search(string word, int& numComparisons, bool& found) const;

	//@Override
	void search(string queryFile, string outputFile) const;

private:
	BinaryNode* root = NULL;
};

