/*
* Title: DictionaryAVLTree.cpp
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 3
* Description: This cpp file includes implementations of insert and search functions that
* are overrired from DictionarySearchTree.
*/
#include "DictionaryAVLTree.h"

DictionaryAVLTree::~DictionaryAVLTree()
{
	deleteFromLeafs(root);
}

void DictionaryAVLTree::deleteFromLeafs(Node* root) {
	if (root == nullptr)
		return;

	deleteFromLeafs(root->left);
	deleteFromLeafs(root->right);
	delete root;
}

DictionaryAVLTree::Node* DictionaryAVLTree::createNode(string item) {
	Node* node = new Node;
	node->left = nullptr;
	node->right = nullptr;
	node->item = item;
	node->height = 1;

	return node;
}

// Insertion 
void DictionaryAVLTree::insert(string word) {
	root = insertRec(root, word);
}

DictionaryAVLTree::Node* DictionaryAVLTree::insertRec(Node* cur, string word) {
	if (cur == nullptr) {
		cur = createNode(word);
	}
	else if (word < cur->item) {
		cur->left = insertRec(cur->left, word);
		balance(cur);
	}
	else
	{
		cur->right = insertRec(cur->right, word);
		balance(cur);
	}
	return cur;
}

void DictionaryAVLTree::balance(Node*& node) {
	node->height = height(node);
	int bf = balanceFactor(node);

	if (bf > 1)
	{
		int lbf = balanceFactor(node->left);

		if (lbf > 0)
		{
			node = rightRotate(node);
		}
		else {
			node = leftRightRotate(node);
		}
	}
	else if (bf < -1) {
		int rbf = balanceFactor(node->right);

		if (rbf > 0)
		{
			node = rightLeftRotate(node);
		}
		else {
			node = leftRotate(node);
		}
	}
}



DictionaryAVLTree::Node* DictionaryAVLTree::leftRotate(Node* parent) {
	Node* tmp = parent->right;

	parent->right = tmp->left;
	tmp->left = parent;

	parent->height = height(parent);
	tmp->height = height(tmp);

	return tmp;
}

DictionaryAVLTree::Node* DictionaryAVLTree::rightRotate(Node* parent) {
	Node* tmp = parent->left;

	parent->left = tmp->right;
	tmp->right = parent;

	parent->height = height(parent);
	tmp->height = height(tmp);

	return tmp;
}

DictionaryAVLTree::Node* DictionaryAVLTree::leftRightRotate(Node* node) {

	Node* tmp = node->left;
	node->left = leftRotate(tmp);
	return rightRotate(node);
}

DictionaryAVLTree::Node* DictionaryAVLTree::rightLeftRotate(Node* node) {
	Node* tmp = node->right;

	node->right = rightRotate(tmp);

	return leftRotate(node);
}

int DictionaryAVLTree::max(int a, int b) {
	return a > b ? a : b;
}

int DictionaryAVLTree::height(Node* node) {
	if (node == nullptr)
		return 0;

	int lh = node->left != nullptr ? node->left->height : 0;
	int rh = node->right != nullptr ? node->right->height : 0;

	return 1 + max(lh, rh);
}

int DictionaryAVLTree::balanceFactor(Node* node) {
	if (node == nullptr)
		return 0;

	int lh = node->left != nullptr ? node->left->height : 0;
	int rh = node->right != nullptr ? node->right->height : 0;

	return lh - rh;
	// return height(node->left) - height(node->right);
}

// Search 
void DictionaryAVLTree::search(string word, int& numComparisons, bool& found) const {
	retrieve(root, word, numComparisons, found);
}

void DictionaryAVLTree::retrieve(Node* cur, string searchKey, int& numComparisons, bool& found) const {
		if (cur == NULL) {
			found = false;
			return;
		}
		else if (searchKey == cur->item) {
			++numComparisons;
			found = true;
			return;
		}
		else if (searchKey < cur->item) {
			++numComparisons;
			retrieve(cur->left, searchKey, numComparisons, found);
		}
		else {
			++numComparisons;
			retrieve(cur->right, searchKey, numComparisons, found);
		}
}
// Search (Summarize)
void DictionaryAVLTree::search(string queryFile, string outputFile) const {
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
	while (getline(MyReadFile, myText)) {
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

