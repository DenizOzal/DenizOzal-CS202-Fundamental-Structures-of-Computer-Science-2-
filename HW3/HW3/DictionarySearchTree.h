/*
* Title: DictionarySearchTree.h
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: This file is a base class and other three filex extends to this class. There are three different
* virtual functions which are insert, search, and search(summarize) and the reason why they are virtual is that
* reaching different overrired functions for three different classes.

*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class DictionarySearchTree {
public:
	//Constructor that constructs the dictionary from the input file
	DictionarySearchTree(string dictionaryFile);
	//Destructor
	virtual ~DictionarySearchTree();
	//Inserts the given word into the dictionary
	virtual void insert(string word);
	//Searches the given word in the dictionary, and returns the number
	//of comparisons made and whether the word is found or not
	virtual void search(string word, int& numComparisons, bool& found) const;
	//Searches all words in the query file in the dictionary, and
	//summarizes the results in the output file
	virtual void search(string queryFile, string outputFile) const;
};