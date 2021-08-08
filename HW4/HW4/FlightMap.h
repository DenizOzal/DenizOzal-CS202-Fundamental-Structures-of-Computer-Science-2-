/*
* Title: Hashing and Graphs
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 4
* Description: This file includes path algorithms (I could not finish this assignment)
*/
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "HashTable.h"
#include "Stack.h"
#include "AdjList.h"
using namespace std;
class FlightMap {
public:
	FlightMap(const string vertexFile, const string edgeFile);
	~FlightMap();
	void findDirectFrom(const string source);
	void findDirectTo(const string destination);
	void findPath(const string source, const string destination);
	void findPath(const string source, const string destination, const int stops);
	void findShortestPath(const string source, const string destination);
private:
	// define your data members here
	// define private member functions here, if any
	// you MUST use the adjacency list representation
	HashTable* hashTable;
	AdjList* adjList;
	bool* visited;
	Stack stack;
	int size;
};