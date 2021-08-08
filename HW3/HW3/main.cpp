#include "DictionaryBST.h"
#include "DictionaryAVLTree.h"

int main() {
	int comp = 0;
	bool found = 0;
	string output;
	DictionarySearchTree* myTrees[3];
	myTrees[0] = new DictionaryBST("dictionary.txt");
	myTrees[1] = new DictionaryAVLTree("dictionary.txt");
	myTrees[0]->search("query.txt", "outBST.txt");
	myTrees[1]->search("query.txt", "outAVLTree.txt");
	return 0;
}