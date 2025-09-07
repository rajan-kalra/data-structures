#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

    // Helper function to transfer elements
    void transferElements() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    // Enqueue an element
    void enqueue(int x) {
        inStack.push(x);
    }

    // Dequeue an element
    int dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        transferElements();
        int frontElement = outStack.top();
        outStack.pop();
        return frontElement;
    }

    // Get the front element
    int peek() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        transferElements();
        return outStack.top();
    }

    // Check if the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front element is: " << q.peek() << std::endl; // Should be 1

    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Dequeues 1
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Dequeues 2

    q.enqueue(4);

    std::cout << "Front element is: " << q.peek() << std::endl; // Should be 3

    return 0;
}