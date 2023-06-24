#include <iostream>
#include <assert.h>
using namespace std;
#define defaultSize 100
template <typename E>
class AStack
{
    int maxSize;  // Maximum size of stack
    int top;      // Index for top element
    E *listArray; // Array holding stack elements

public:
    AStack(int size = defaultSize)
    { // Constructor
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    ~AStack()
    {
        delete[] listArray;
    } // Destructor

    void clear()
    {
        top = 0;
    } // Reinitialize

    void push(const E &it)
    { // Put "it" on stack
        assert(top != maxSize && "Stack is full");
        listArray[top++] = it;
    }

    E pop()
    { // Pop top element
        assert(top != 0 && "Stack is empty");
        return listArray[--top];
    }

    const E &topValue() const
    { // Return top element
        assert(top != 0 && "Stack is empty");
        return listArray[top - 1];
    }

    int length() const { return top; } // Return length
};

int main()
{
    // Write C++ code here
    AStack<int> intStack(10);
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    int poppedValue = intStack.pop();
    cout << "Popped value: " << poppedValue << endl;

    AStack<char> charStack(5);
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    char poppedChar = charStack.pop();
    cout << "Popped character: " << poppedChar << endl;

    return 0;
}