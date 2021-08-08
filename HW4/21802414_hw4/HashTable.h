/*
 * C++ Program to Implement Hash Tables with Quadratic Probing
 */
#include <iostream>
#include <cstdlib>
#define MIN_TABLE_SIZE 10
using namespace std;
    /*
     * Node Type Declaration
     */
    enum EntryType { Legitimate, Empty, Deleted };
    /*
     * Node Declaration
     */
    struct HashNode
    {
        string element;
        enum EntryType info;
    };
    /*
     * Table Declaration
     */
    struct HashTable
    {
        int size;
        HashNode* table;
    };
    /*
     * Returns whether n is prime or not
     */
    bool isPrime(int n)
    {
        if (n == 2 || n == 3)
            return true;
        if (n == 1 || n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
    /*
     * Finding next prime size of the table
     */
    int nextPrime(int n)
    {
        if (n <= 0)
            n == 3;
        if (n % 2 == 0)
            n++;
        for (; !isPrime(n); n += 2);
        return n;
    }
    /*
     * Function To Generate Hash
     */
    int hashFunc(const string& key, int size)
    {
        int hashVal = 0;

        for (int i = 0; i < key.length(); i++)
            hashVal = 37 * hashVal + key[i];
        hashVal %= size;
        if (hashVal < 0)   /* in case overflows occurs */
            hashVal += size;

        return hashVal;
    }
    /*
     * Function to Initialize Table
     */
    HashTable* initializeTable(int size)
    {
        HashTable* htable;
        if (size < MIN_TABLE_SIZE)
        {
            cout << "Table Size Too Small" << endl;
            return NULL;
        }
        htable = new HashTable;
        if (htable == NULL)
        {
            cout << "Out of Space" << endl;
            return NULL;
        }
        htable->size = nextPrime(size);
        htable->table = new HashNode[htable->size];
        if (htable->table == NULL)
        {
            cout << "Table Size Too Small" << endl;
            return NULL;
        }
        for (int i = 0; i < htable->size; i++)
        {
            htable->table[i].info = Empty;
            htable->table[i].element = " ";
        }
        return htable;

    }
    /*
     * Function to Find Element at a key
     */
    int find(string key, HashTable* htable)
    {
        int pos = hashFunc(key, htable->size);
        int collisions = 0;
        while (htable->table[pos].info != Empty &&
            htable->table[pos].element != key)
        {
            pos = pos + 2 * ++collisions - 1;
            if (pos >= htable->size)
                pos = pos - htable->size;
        }
        return pos;
    }
    /*
     * Function to Insert Element into a key
     */
    void insert(string key, HashTable*& htable)
    {
        int pos = find(key, htable);
        if (htable->table[pos].info != Legitimate)
        {
            htable->table[pos].info = Legitimate;
            htable->table[pos].element = key;
        }
    }
    /*
     * Function to Retrieve Hash Table
     */
    string retrieve(HashTable* htable, int index){
         string value = htable->table[index].element;
         if (value != " ") {
             return value; 
         }
         return "NULL";      
    }
    /*
     * Function to Rehash the Table
     */
    HashTable* rehash(HashTable*& htable)
    {
        int size = htable->size;
        HashNode* table = htable->table;
        htable = initializeTable(2 * size);
        for (int i = 0; i < size; i++)
        {
            if (table[i].info == Legitimate)
                insert(table[i].element, htable);
        }
        free(table);
        return htable;
    }