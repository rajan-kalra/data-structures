#include <iostream>
#include <vector>
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

        // O(log n) operation since for each insert, we keep comparing 
        // the child with its parent & keep moving upwards in the heap
        void insertElem (int elem) {
            // update the size including upcoming element
            size = size + 1;

            // create index to insert new element
            int index = size;

            // insert element at the last index of the heap
            arr[index] = elem;

            // We wont go inside the loop for index as 1 & we dont really 
            // need to go inside the loop for index 1 as movement of nodes
            // is required only when there are more than 1 node 
            while (index > 1) {
                // find the parent index of current index
                int parent = index / 2;

                // if element at parent index is less than the
                // newly inserted element, swap both the element
                // to maintain max heap property.
                // Once we swap the child & parent, we move furhter
                // up make parent to maintain the max-heap property
                // Thus we set index as parent index
                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        // O(log n) operation
        // Delete happens always with the root node
        // Delete element happens in 3 steps:
        // 1. Put the last node value at the first index (or we sometimes
        // say swap first index & last index values). To note, once complete 
        // this step could have violated the max-heap property.
        // 2. Remove the last node, as now its duplicate of first element
        // 3. Propagate the root node to its correct position
        void deleteElem () {
            if (size == 0) {
                cout << "Heap is empty!" << endl;
                return;
            }

            // Step 1: put last element into first index
            arr[1] = arr[size];

            // Step 2
            size--;

            // Step 3
            int i = 1;
            while (i < size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if (leftIndex < size && arr[leftIndex] > arr[i]) {
                    swap (arr[i], arr[leftIndex]);
                    i = leftIndex;
                } else if (rightIndex < size && arr[rightIndex] > arr[i]) {
                    swap (arr[i], arr[rightIndex]);
                    i = rightIndex;
                } else {
                    return;
                }
            }
        }

        // Heapify is a process of converting the subtree under the given index a valid heap.
        // We are generally given an index i, we run heapify on index i which takes case of all 
        // the indexes starting from i to size.
        // We solve this problem using the fact that no of leaves in a complete binary tree will
        // always be (n/2)+1 to nth index.
        // We also know that a leaf node is always a valid heap.
        // This function ensures that given an index, we make subtree of this index a valid heap.
        // For this we iterate through the last element of the input array to the first element &
        // establish the fact that each node represents a valid heap, including its child nodes.
        // Using the above fact about leaf nodes exist from (n/2)+1 to nth index, we need not to
        // consider these nodes to be heapified & thus only consider nodes 1 to n/2 nodes to be
        // heapified. Thus we run the loop from i = n/2 to 1.
        void heapify (vector<int>& arr, int n, int i) {
            // given index i, we need to make i as a valid heap
            int largest = i;
            int left = 2*i;
            int right = 2*i + 1;

            if (left <= n && arr[left] > arr[largest])
                largest = left;

            if (right <= n && arr[right] > arr[largest])
                largest = right;
            
            if (largest != i) {
                swap(arr[largest], arr[i]);
                heapify (arr, n, largest);
            }
        }

        void heapsort (vector<int> &input) {
            int size = input.size();

            while (size > 1) {
                // step 1: swap the root element with the last element.
                // This step shall bring the max element at the last i.e
                // it starts sorting the last part of the array.
                // We now reduce the size by 1 & repeat the same procedure
                swap (input[size], input[1]);
                size--;

                // step 2
                heapify (input, size, 1);
            }
        }

        void printHeap () {
            for (int i = 1; i <= size; i++)
                cout << arr[i] << " ";
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

    cout << "Heap before deletion: ";
    h.printHeap();

    h.deleteElem();

    cout << "Heap after deletion: ";
    h.printHeap();

    vector<int> input = { -1, 54, 53, 55, 52, 50 };
    int size = input.size();

    for (int i = size / 2; i > 0; i--) {
        h.heapify(input, size, i);
    }

    cout << "Heapified array: ";
    for (int i = 1; i < size; i++) {
        cout << input[i] << " ";
    }
    cout << endl;


    vector<int> input1 = { -1, 54, 53, 55, 52, 50 };
    int size1 = input1.size();

    cout << "Input before heapsort: ";
    for (int i = 1; i < size1; i++) {
        cout << input1[i] << " ";
    }
    cout << endl;

    h.heapsort(input1);

    cout << "Input after heapsort: ";
    for (int i = 1; i < size1; i++) {
        cout << input1[i] << " ";
    }
    cout << endl;

    return 0;
}
