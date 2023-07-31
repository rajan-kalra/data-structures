#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    stack<int> s;

    /**
     * When starting with last element, next greater elements
     * of last element will always be -1. Print it & push the
     * last element to stack ALWAYS
     */
    cout << arr[n-1] << " -> -1" << endl;
    s.push(arr[n-1]);

    for (int i = n-2; i >= 0; i--) {
        /**
         * keep popping the elements until stack is not empty
         * & top of stack is less than the current element
         */
        while (s.empty() == false && s.top() < arr[i]) {
            s.pop();
        }

        /**
         * either the stack has become empty which means no element
         * was found which is greater than current element or we find
         * the element greater than current element
         */
        if (s.empty()) {
            cout << arr[i] << " -> -1" << endl;
        } else {
            cout << arr[i] << " -> " << s.top() << endl;
        }

        // push the current element to stack irrespective of case above
        s.push(arr[i]);
    }
}

int main() {
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
