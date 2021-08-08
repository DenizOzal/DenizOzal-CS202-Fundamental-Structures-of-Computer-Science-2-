#pragma once
#pragma once
#include <string>
using namespace std;
class Stack {

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(int newItem);
    bool pop();
    bool pop(int& stackTop);
    bool getTop(int& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        int item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};


