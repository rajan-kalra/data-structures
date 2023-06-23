#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int binarySearch (int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = (low+high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }

    return -1;
}

int countDistinctPairs (int arr[], int size, int k) {
    int count = 0;
    sort(arr, arr+size);

    for (int i = 0; i < size; i++) {
        while ((i - 1 >= 0) && (arr[i] == arr[i-1])) {
            i++;
        }

        if (binarySearch(arr, i + 1, size - 1, arr[i] + k) != -1)
            count++;
    }

    return count;
}



int main() {
  int A[] = { 1, 5, 3, 4, 2 };
    int k = 3;
    int size = sizeof(A) / sizeof(A[0]);

    cout << "Number of distinct pairs with difference as " << k << ": " << countDistinctPairs (A, size, k);
    
  return 0;
}
