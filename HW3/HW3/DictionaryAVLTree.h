/*
* Title: DictionaryAVLTree.h
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: This header file includes prototypes of insert and search functions that
* are overrired from DictionarySearchTree. This files creates a dictionary using AVL
* tree structure.
*/
#pragma once
#include "DictionarySearchTree.h"
class DictionaryAVLTree : public DictionarySearchTree
{
	public:
		//Constructor
		DictionaryAVLTree(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
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
		~DictionaryAVLTree();
		//@Override
		void insert(string word); // inserts an element into the tree
		//@Override
		void search(string word, int& numComparisons, bool& found) const;

		//@Override
		void search(string queryFile, string outputFile) const;

	private:
		struct Node
		{
			string item;
			struct Node* left;
			struct Node* right;
			struct Node* parent;
			int height;
		};
		Node* root = NULL;
		Node* createNode(string item);
		void deleteFromLeafs(Node* root);
		Node* leftRotate(Node* node);
		Node* rightRotate(Node* node);
		Node* leftRightRotate(Node* node);
		Node* rightLeftRotate(Node* node);
		int max(int a, int b);
		int height(Node* node);
		int balanceFactor(Node* node);
		void balance(Node*& cur);
		Node* insertRec(Node* cur, string item);
		void retrieve(Node* cur, string searchKey, int& numComparisons, bool& found) const;
};

