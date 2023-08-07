#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargestSumSubarray(vector<int> &input, int k) {
    // vector to store all sums
    vector<int> result;
    int inputSize = input.size();

    // Generate all subarrays
    for (int i = 0; i < inputSize; i++) {
        int sum = 0;
        for (int j = i; j < inputSize; j++) {
            sum += input[j];
            result.push_back(sum);
        }
    }

    // sort in decreasing order
    sort(result.begin(), result.end(), greater<int>());

    // return the Kth largest sum
    return result[k - 1];
}

/**
 * Space optimized solution
 */
int kthLargestSumSubarrayUsingHeap(vector<int> &input, int k) {
    // min heap to store k sums
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int inputSize = input.size();

    // Generate all subarrays
    for (int i = 0; i < inputSize; i++) {
        int sum = 0;
        for (int j = i; j < inputSize; j++) {
            sum += input[j];
            if (min_heap.size() < k) {
                min_heap.push(sum);
            } else {
                if (sum > min_heap.top()) {
                    min_heap.pop();
                    min_heap.push(sum);
                }
            }
        }
    }

    // return the Kth largest sum
    return min_heap.top();
}

int main() {
    vector<int> input = { 20, -5, -1 };
    int k = 3;

    cout << "kth largest sum of subarrays: " << kthLargestSumSubarray(input, k) << endl;
    cout << "kth largest sum of subarrays using heap: " << kthLargestSumSubarrayUsingHeap(input, k) << endl;
	return 0;
}