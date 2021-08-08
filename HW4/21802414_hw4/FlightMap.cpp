/*
* Title: Hashing and Graphs
* Author: Deniz Semih Özal
* ID: 21802414
* Section: 1
* Assignment: 4
* Description: This file includes path algorithms and their implementationa (I could not finish this assignment)
*/
#include "FlightMap.h"
FlightMap::FlightMap(const string vertexFile, const string edgeFile) {
    string line;
    string edge;
    string vertex;
    int index = 1; // List starts from 1
  

    // Reading vertexFile
    ifstream myfile(vertexFile);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            size++;
        }
        myfile.close();
    }

    // Initialize hash table
    hashTable = initializeTable(size);
    int hashIndex = 0;

    // Insert vertex items to the hash table
    // Reading vertexFile
    ifstream myfile(vertexFile);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            insert(line, hashTable); // Insert into the hash
        }
        myfile.close();
    }
    
    // Insert vertex items into the adjancency list according to hash index 
    for (int i = 1; i <= size; i++) {
        int properHashIndex = i - 1;
        string temp = retrieve(hashTable, properHashIndex);
        adjList->insert(i, temp);
    }

    // Insert edge items to the adjency list 
    // Reading edgeFile
    ifstream myfile(edgeFile);
    if (myfile.is_open())
    {
        while (getline(myfile, vertex, ',') && getline(myfile, edge, '\n'))
        {
            hashIndex = find(vertex, hashTable);
            int properListIndex = hashIndex + 1;
            adjList[properListIndex].insert(adjList[properListIndex].getLength() + 1, edge); // Insert edge to the vertex in adjList
        }
        myfile.close();
    }
}

FlightMap::~FlightMap() {

}
/*
* This function lists all destination cities that have a direct 
* flight from this source city. Each destination city should be displayed on a separate line
* in the output. Display a warning message if the input city does not exist in the graph.
*/
void FlightMap::findDirectFrom(const string source) {
    bool flag = false;
    for (int i = 1; i <= adjList->getLength(); i++) { 
        string vertex;
        adjList->retrieve(i, vertex);
        if (vertex == source) { // If correct vertex is found
            flag = true;
            for (int j = 1; i <= adjList[j].getLength(); j++) {  // Change maybe later
                string edge;
                adjList[j].retrieve(j, edge);
                cout << "Source City:  " << vertex << " to Destination City: " <<  edge << "\n";
            }
        }
    }
    if (flag == false) {
        cout << "Input city does not exist in the graph";
    }
}


/*
* This function lists all source cities that have a direct
* flight to this destination city. Each source city should be displayed on a separate line in
* the output. Display a warning message if the input city does not exist in the graph.
*/
void FlightMap::findDirectTo(const string destination) {
    bool flag = false;
    for (int i = 1; i <= adjList->getLength(); i++) {
        string vertex;
        adjList->retrieve(i, vertex);
        for (int j = 1; i <= adjList[j].getLength(); j++) {  // Change maybe later
             string edge;
             adjList[j].retrieve(j, edge);
             if (edge == destination) {
                 flag = true;
                 cout << "Source City: " << vertex << " to  Destination  City: " << edge;
             }
        } 
    }
    if (flag == false) {
        cout << "Input city does not exist in the graph";
    }
}


/*
* This function finds and prints
* all paths from the source city to the destination city. Each city on each path should be displayed
* on a separate line in the output. Each path should be clearly separated from the others. Display
* a warning if any one of the input cities does not exist in the graph.
*/
void FlightMap::findPath(const string source, const string destination) {
    bool flag = false;
    visited = new bool[size];
    
    // Find source node index
    int hashIndex = find(source, hashTable);
    int properListIndex = hashIndex + 1;

    // Initialize false to all entries
    for (int i = 0; i < size; i++)
        visited[i] = false;
    
    // Mark visited source node
    visited[hashIndex] = true;

    // Push source node to stack
    stack.push(properListIndex);

    while (!stack.isEmpty()) {
        int currentVertex, i;
        stack.getTop(currentVertex);

        for (int i = 1; i <= adjList[currentVertex].getLength(); i++) {
            string adjacentNode;
            adjList[currentVertex].retrieve(i, adjacentNode);
            int tempHashIndex = find(adjacentNode, hashTable);
            if (!visited[tempHashIndex]) {
                stack.push(tempHashIndex);
                cout << adjacentNode << endl;
                visited[tempHashIndex] = true;
                break;
            }
        }
        // When there is no unvisited vertex adjacent to the current node
        if (i > adjList[currentVertex].getLength())
            stack.pop();
    }
}


/*
* This function finds and prints all paths from the source city to the destination city with the given number
* of stops. The source and destination cities are not counted as stops in this computation. Each
* city on each path should be displayed on a separate line in the output. Each path should be
* clearly separated from the others. Display a warning if any one of the input cities does not exist
* in the graph
*/
void FlightMap::findPath(const string source, const string destination, const int stops) {

}

/*
* This function displays the cities along the shortest path from the source city to the destination city. If there are
* 3 multiple such paths, displaying one of them is sucient. Each city on the path should be dis-
* played on a separate line in the output. Display a warning if any one of the input cities does
* not exist in the graph.
*/
void FlightMap::findShortestPath(const string source, const string destination) {

}