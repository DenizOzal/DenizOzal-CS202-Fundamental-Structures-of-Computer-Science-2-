#pragma once
#include <string>
using namespace std;
//ReservationList is linked list implementation of reservation codes
class AdjList {
public:
	AdjList();
	AdjList(const AdjList& aList);
	~AdjList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, string& valueTemp) const;
	bool insert(int index, string valueTemp);
	bool remove(int index);
private:
	struct ListNode {
		string value;
		ListNode* next;
	};
	int size;
	ListNode* head;
	ListNode* find(int index) const;
};