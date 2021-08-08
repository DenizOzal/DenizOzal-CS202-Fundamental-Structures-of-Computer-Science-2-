#include "AdjList.h"
#include <cstddef>    // for NULL

AdjList::AdjList() : size(0), head(NULL) {

}
AdjList::AdjList(const AdjList& aList) : size(aList.size) {
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new ListNode;
        head->value = aList.head->value;
        // copy rest of list
        ListNode* newPtr = head;  // new list ptr

        for (ListNode* origPtr = aList.head->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->value = origPtr->value;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor
AdjList::~AdjList() {

    while (!isEmpty())
        remove(1);

} // end destructor
bool AdjList::isEmpty() const {

    return size == 0;

}  // end isEmpty
int AdjList::getLength() const {

    return size;

}  // end getLength
AdjList::ListNode* AdjList::find(int index) const {
    // Locates a specified node in a linked list.
    // Precondition: index is the number of the
    // desired node.
    // Postcondition: Returns a pointer to the 
    // desired node. If index < 1 or index > the 
    // number of nodes in the list, returns NULL.

    if ((index < 1) || (index > getLength()))
        return NULL;

    else { // count from the beginning of the list
        ListNode* cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}  // end find
bool AdjList::retrieve(int index, string& valueTemp) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    ListNode* cur = find(index);
    valueTemp = cur->value;

    return true;

} // end retrieve
bool AdjList::insert(int index, string valueTemp) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    ListNode* newPtr = new ListNode;
    size = newLength;
    newPtr->value = valueTemp;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        ListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert
bool AdjList::remove(int index) {

    ListNode* cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ListNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove

