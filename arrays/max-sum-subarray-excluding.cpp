#include <iostream>
#include <unordered_set>
using namespace std;

int maxSubArraySumExluding(int A[], int sizeA, int B[], int sizeB) {
    int sum = 0;
    int max_sum = INT_MIN;

    // create a map to do quick lookup if elements
    // of B[] exist in A[]
    unordered_set<int> lookUp;
    for(int i = 0; i < sizeB; i++) {
        lookUp.insert(B[i]);
    }

    for (int i = 0; i < sizeA; i++) {
        /**
        * set sum as 0, if:
        * 1. current element is present in hash table of array B
        */
        if (lookUp.find(A[i]) != lookUp.end()) {
            sum = 0;
            continue;
        }
        
        // if current element not present in hash table, add it to sum
        sum += A[i];
        
        // keep adding array elements to sum
        max_sum = max(sum, max_sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return max_sum;
}

int main() {
    int A[] = { 3, 4, 5, -4, 6 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int B[] = { 1, 8, 5 };
    int sizeB = sizeof(B) / sizeof(B[0]);

    // Function Call
    int max_sum = maxSubArraySumExluding(A, sizeA, B, sizeB);
    cout << "Maximum contiguous sum: " << max_sum;
    return 0;
}