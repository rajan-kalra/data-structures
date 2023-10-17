#include <iostream>
#include <vector>
using namespace std;

class Heap {
    private:
        int *arr;
        int size;
        int index;
        int capacity;

    public:
        /**
         * we init the 0th index value as -1
         * since we follow 1 based indexing
         */
        Heap (int capacity) {
            arr = new int(capacity);
            arr[0] = -1;
            size = 0;
            index = 0;
            this->capacity = capacity;
        }

        /**
         * O(log n) operation
         * For each insert, we keep comparing the child with
         * its parent & keep moving upwards in the heap.
         * 
         * Insert is a 3 step process:
         * 1. Find the current index where element is to be
         * inserted & insert the element.
         * 2. Find the parent index of current index & compare
         * the current element at parent index element. If parent
         * index element is smaller, swap the current index &
         * parent index elements. Set current index equal to parent
         * index.
         * 3. Repeat above steps until current index is greater than 1.
         */
        void insertElem (int elem) {
            if (size == capacity) {
                cout << "Heap full, can't insert new element!";
                return;
            }

            // Here we intend to insert the element at the end of the
            // heap, thus just insert the element at the incremented
            // index & later push it to correct position
            index++;
            arr[index] = elem;
            size++;

            /**
             * We wont go inside loop for index as 1 as movement of
             * nodes is required only when there are more than 1 node 
             */
            int tempIndex = index;
            while (tempIndex > 1) {
                int parent = tempIndex / 2;

                /**
                 * If element at parent index is less than the newly
                 * inserted element, swap both the element to maintain
                 * max heap property.
                 * Once we swap the child & parent, we move further up
                 * to maintain the max-heap property by setting index
                 * as parent index
                 */
                if (arr[parent] < arr[tempIndex]) {
                    swap(arr[parent], arr[tempIndex]);
                    tempIndex = parent;
                } else {
                    return;
                }
            }
        }
        
        /**
         * O(log n) operation since after each deletion, we bring
         * last element to the top & then keep pushing the root
         * downwards to its correct position.
         * Delete element happens in 3 steps:
         * 1. Put the last node value at the first index. To note, once
         * complete this step could have violated the max-heap property
         * 2. Remove the last node, as now its duplicate of first element
         * 3. Propagate the root node to its correct position
         */
        void deleteElem () {
            if (size == 0) {
                cout << "Heap is empty!" << endl;
                return;
            }

            // Step 1: put last element into first index
            arr[1] = arr[index];

            // Step 2
            size--;

            // Step 3
            int i = 1;
            while (i < size) {
                int leftChildIndex = 2*i;
                int rightChildIndex = 2*i + 1;

                if (leftChildIndex < size && arr[leftChildIndex] > arr[i]) {
                    swap (arr[i], arr[leftChildIndex]);
                    i = leftChildIndex;
                } else if (rightChildIndex < size && arr[rightChildIndex] > arr[i]) {
                    swap (arr[i], arr[rightChildIndex]);
                    i = rightChildIndex;
                } else {
                    return;
                }
            }
        }

        /**
         * Heapify is a process of converting the subtree under the given
         * index a valid heap.
         * We are given an index i, we run heapify on index i which takes
         * care of all the indexes starting from i to size i.e ensures all
         * indexes from i to size form a valid heap.
         * We build the algorithm of heapify using the fact that no of
         * leaves in a complete binary tree will always be present from
         * (n/2)+1 to nth index.
         * We also know that a leaf node is always a valid heap.
         * This function ensures that given an index, we make subtree of
         * this index a valid heap. For this we iterate from the last
         * element of the input array to the first element & establish
         * the fact that each node represents a valid heap, including its
         * child nodes.
         * Using the above fact about leaf nodes exist from (n/2)+1 to nth
         * index, we need not to consider these nodes to be heapified & thus
         * only consider nodes 1 to n/2 nodes to be heapified.
         * Thus we run the loop from i = n/2 to 1.
         */
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
    Heap h(100);

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
