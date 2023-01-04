#include <iostream>
using namespace std;
 
class Queue {
  int front, rear, capacity, size;
  int* queue;

  public:
    Queue(int c) {
      front = -1;
      rear = -1;
      size = 0;
      capacity = c;
      queue = new int[100];
    }

    ~Queue() { delete[] queue; }
 
    // function to insert an element
    // at the rear of the queue
    void enqueue(int data) {
      // check queue is full or not
      if (capacity == rear) {
        cout << "\nQueue is full\n";
        return;
      }

      if (rear == -1) {
        front = 0;
        rear = 0;
      } else {
        rear = (rear + 1) % capacity;
      }

      cout << "Pushed: " << data << endl;
      // insert element at the rear
      queue[rear] = data;
      size++;
    }
 
  // function to delete an element
  // from the front of the queue
  int dequeue() {
    // if queue is empty
    if (front == -1) {
        cout << "\nQueue is  empty\n";
        return -1;
    }

    int element = queue[front];
    if (size == 1) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % capacity;
    }

    size--;
    return element;
  }
 
  // print front of queue
  void peek() {
    if (front == rear) {
        cout << "Peek attempted.. queue is Empty\n";
        return;
    }

    cout << "Peek attempted.. front Element is: " << queue[front] << endl;;
  }
};
 
int main(void) {
  // Create a queue of capacity 4
  Queue q(4);

  q.peek();

  // inserting elements in the queue
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.peek();

  // insert element in the queue
  q.enqueue(60);

  q.dequeue();
  q.dequeue();

  cout << "After two node deletion" << endl;

  // print front of the queue
  q.peek();

  return 0;
}