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

    for (int i = n - 2; i >= 0; i--) {
        int curr = arr[i];
        /**
         * top of stack is either greater than current element
         * or smaller than current element
         * If top of stack is greater than current element, just
         * print this as the greater element
         */
        if (s.top() > curr) {
            cout << curr << " -> " << s.top() << endl;
        /**
         * If top of stack is greater than or equal to current element
         */
        } else {
            /**
             * keep popping the elements until stack is not empty
             * & top of stack is less than or equal to the current
             * element
             */
            while (s.empty() == false && s.top() <= curr) {
                s.pop();
            }

            if (s.empty() == true) {
                cout << arr[i] << " -> -1" << endl;
            } else {    
                cout << curr << " -> " << s.top() << endl;
            }
        }
        // insert the current element at the end always
        s.push(curr);
    }
}

int main() {
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
