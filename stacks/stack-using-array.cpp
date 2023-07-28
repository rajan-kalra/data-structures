#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int capacity;
        int* arr;
 
    public:
        // default constructor
        Stack() {
            top = -1;
            capacity = 1000;
            arr = new int[capacity];
        }

        // parameterized constructor
        Stack(int capacity) {
            top = -1;
            this->capacity = capacity;
            arr = new int[capacity];
        }

        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};
 
bool Stack::push(int x) {
    /**
     * Edge Case: since the array has 0 based indexing, max
     * elements this array can accomodate is capacity-1
     */
    if (top >= (capacity - 1)) {
        cout << "Stack Overflow!";
        return false;
    }

    arr[++top] = x;
    cout << x << " pushed into stack\n";
    return true;
}
 
int Stack::pop() {
    /**
     * Edge Case: since stack is initialised with top = -1, we
     * use the same condition to find if stack has no element
     */
    if (top < 0) {
        cout << "Stack Underflow!";
        return 0;
    }

    int x = arr[top--];
    return x;
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }

    int x = arr[top];
    return x;
}
 
bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;

    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!s.isEmpty()) {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}