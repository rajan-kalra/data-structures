#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        int i;
        int j;

        Node (int data, int row, int col) {
            this->data = data;
            i = row;
            j = col;
        }
};

class compare {
    public:
        bool operator() (Node *a, Node *b) {
            return a->data > b->data;
        }
};

vector<int> mergeKArrays (vector<vector<int>> input) {
    int rows = input.size();
    int cols = input[0].size();

    vector<int> output;

    priority_queue<Node*, vector<Node*>, compare> min_heap;

    // insert first elements of all k arrays
    for (int i = 0; i < rows; i++) {
        Node *node = new Node (input[i][0], i, 0);
        min_heap.push(node);
    }

    while (min_heap.size() > 0) {
        Node *node = min_heap.top();
        output.push_back(node->data);
        min_heap.pop();

        int i = node->i;
        int j = node->j;

        if (j+1 < input[i].size()) {
            Node *next = new Node (input[i][j+1], i, j+1);
            min_heap.push(next);
        }
    }

    return output;
}

void printArray (vector<int> mergedArray) {
    int size = mergedArray.size();

    for (int i = 0; i < size; i++) {
        cout << mergedArray[i] << " ";
    }
}

int main() {
    // Change N at the top to change number of elements
    // in an array
    vector<vector<int>> input = { 
                                    { 2, 6, 12, 34 },
                                    { 1, 9, 20, 1000 },
                                    { 23, 34, 90, 2000 }
                                };

    vector<int> mergedArrays = mergeKArrays(input);

    cout << "Merged array: ";
    printArray(mergedArrays);

    return 0;
}
