#include<iostream>
#include<queue>

using namespace std;

class Stack {
    private:
        queue<int> q;

    public:
        void push(int x) {
            /**
             * get the current size of the queue before pushing
             * any new element
             */
            int s = q.size();

            cout << "Pushed element: " << x << endl;
            q.push(x);

            /**
             * pop & push the 's' no of elements where s is the
             * size of queue before pushing this element
             */
            for (int i = 0; i < s; i++) {
                q.push(q.front());
                q.pop();
            }
        }

        int pop() {
            int n = q.front();
            q.pop();
            
            return n;
        }

        int top() {
            return q.front();
        }

        int size() {
            return q.size();
        }
};

int main() {
    Stack s;
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(1);

    cout << "Top of the stack: " << s.top() << endl;
    cout << "Size of the stack: " << s.size() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top of the stack: " << s.top() << endl;
    cout << "Size of the stack: " << s.size();
}