#include <iostream>
using namespace std;

int getMaxSumSubarray(int a[], int size) {
    int sum = 0;
    int max_sum = INT_MIN;
    /**
     * At each step do 2 things:
     * 1. Check if my current sum has becomes greater than max_sum to update max_sum
     * 2. Check if my current sum has become negative, reset the sum to 0
     */
    for (int i = 0; i < size; i++) {
        // add current array element to sum
        sum += a[i];

        // each time we add an element, we check
        // if sum is greater than max_sum & if
        // max_sum can be updated
        max_sum = max(sum, max_sum);

        // at any point if sum becomes negative
        // we reset the sum as it will end up
        // making our further sum smaller. To
        // note, we keep adding the negative nos
        // to the sum but if sum becomes negative
        // we reset the sum
        if (sum < 0)
            sum = 0;
    }

    return max_sum;
}

void printMaxSumSubarrayIndex(int a[], int size) {
    int sum = 0;
    int max_sum = INT_MIN;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        sum += a[i];

        if (sum > max_sum) {
            // update max_sum
            max_sum = sum;
            // update start & end indexes
            start = s;
            end = i;
        }

        /**
         * if sum becomes negative, we reset s as next
         * index since we start with new subarray from
         * next index
         */
        if (sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }

    cout << "Maximum contiguous sum: " << max_sum << endl;
    cout << "Starting index: " << start << ", Ending index: " << end;
}
 
int main() {
  int arr[] = { 8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Max subarray sum: " << getMaxSumSubarray(arr, n) << endl;

  printMaxSumSubarrayIndex (arr, n);
  return 0;
}
