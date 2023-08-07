#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kthSmallest(vector<int>& input, int k) {
    int inputSize = input.size();

    // Max Heap using a Priority Queue
    priority_queue<int> heap;

    // insert first k elements to the heap
    for (int i = 0; i < k; i++) {
        heap.push(input[i]);
    }

    /**
     * for the remaining elements, check if an
     * element exist which is smaller than top of
     * the heap, if exists pop the top of heap & add
     * that element to the heap 
     */
    for (int i = k; i < inputSize; i++) {
        if (heap.top() > input[i]) {
            heap.pop();
            heap.push(input[i]);
        }
    }

    // Print the k-th smallest element
    cout << heap.top() << endl;
}

int main() {
    vector<int> input = { 5, 20, 10, 7, 1 };

    // for kth smallest element
    int k = 3;

    kthSmallest(input, k);

    return 0;
}
