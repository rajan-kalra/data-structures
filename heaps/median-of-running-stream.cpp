// C++ code to implement the approach

#include <iostream>
#include <queue>
using namespace std;

// function to find which heap size needs to be balanced
int myComparator (int a, int b) {
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

void getMedian (int currentElement, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median) {
    switch (myComparator(maxHeap.size(), minHeap.size())) 
    {
    // when both heaps are same size
    case 0:
        if (currentElement > median) {
            minHeap.push((currentElement));
            median = minHeap.top();
        } else {
            maxHeap.push(currentElement);
            median = maxHeap.top();
        }
        break;
    // when maxHeap size > minHeap size
    case 1:
        if (currentElement > median) {
            minHeap.push(currentElement);
            median = (minHeap.top() + maxHeap.top()) / 2;
        } else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push((currentElement));
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
    // when maxHeap size < minHeap size
    case -1:
        if (currentElement > median) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(currentElement);
            median = (minHeap.top() + maxHeap.top()) / 2;
        } else {
            maxHeap.push(currentElement);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
    }
}

vector<int> getAllMedians (vector<int> &input) {
    vector<int> output;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> mindHeap;
    int median = -1;

    for (int i = 0; i < input.size(); i++) {
        getMedian (input[i], maxHeap, mindHeap, median);
        output.push_back(median);
    }

    return output;
}

int main() {
    vector<int> input = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };

    vector<int> output = getAllMedians(input);
    for (auto elem : output) {
        cout << elem << " ";
    }
    
    return 0;
}
