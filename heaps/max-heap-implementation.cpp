#include <iostream>
using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

        // we init the 0th index value as -1 since we need to start
        // from index 1
        Heap () {
            arr[0] = -1;
            size = 0;
        }

        // O(n) operation
        void insertElem (int elem) {
            // update the size including upcoming element
            size = size + 1;

            // create index to insert new element
            int index = size;

            // insert element at the last index of the heap
            arr[index] = elem;

            // iterate through all the indexes starting from last index
            while (index > 1) {
                // find the parent index of current index
                int parent = index / 2;

                // if element at parent index is less than the
                // newly inserted element, swap both the element
                // to maintain max heap property & make parent
                // as current index
                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        // O(log n) operation
        // Delete element happens in 3 steps:
        // 1. Put the last node value at the first index (or we sometimes say swap first index & last index values)
        // 2. Remove the last node, as now its duplicate of first element
        // 3. Propagate the root node to its correct position
        void deleteElem () {
            if (size == 0) {
                cout << "Heap is empty!" << endl;
                return;
            }

            // Step 1
            arr[1] = arr[size];

            // Step 2
            size--;

            // Step 3
            int i = 1;
            while (i < size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if (leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap (arr[i], arr[leftIndex]);
                    i = leftIndex;
                } else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap (arr[i], arr[rightIndex]);
                    i = rightIndex;
                } else {
                    return;
                }
            }
        }

        // This function ensures that given an index, we make subtree of this index a valid heap.
        // For this we iterate through the last element of the input to the first element &
        // establish the fact that each node represents a valid heap, including its child nodes.
        // We also realize that (n/2)+1 to nth nodes can have leaf nodes & since a leaf node is
        // always a valid heap, we need not to consider these nodes to be heapified & thus only
        // consider nodes 1 to n/2 nodes to be heapified
        void heapify (int arr[], int n, int i) {
            int largest = i;
            int left = 2*i;
            int right = 2*i + 1;

            if (left < n && arr[largest] < arr[left])
                largest = left;

            if (right < n && arr[largest] < arr[right])
                largest = right;
            
            if (largest != i) {
                swap(arr[largest], arr[i]);
                heapify (arr, n, largest);
            }
        }

        void printHeap () {
            for (int i = 1; i <= size; i++)
                cout << arr[i];
            cout << endl;
        }
};

int main() {
    Heap h;

    h.insertElem (50);
    h.insertElem (55);
    h.insertElem (53);
    h.insertElem (52);
    h.insertElem (54);

    return 0;
}
