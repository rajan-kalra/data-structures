#include <iostream>
using namespace std;

int findPeak (int arr[], int n) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        // if mid is from 1 to size - 2
        if (mid > 0 && mid < n-1) {
            // if mid element is peak element 
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            // move towards left which has greater element
            } else if (arr[mid] < arr[mid-1]) {
                high = mid-1;
            // move towards right which has greater element
            } else {
                low = mid+1;
            }
        // We handle cases of index as 0 or size-1 separately as for the given
		// problem, for index as 0 or size-1, the comparison happens only with 
		// single adjacent element unlike other indexes where comparison happens
		// with 2 adjacent elements. It also enables us to check for m-1 & m+1
		// freely while being on 0 & size-1 index
		// if index is 0 or size - 1
        } else {
            // if first element of the array
            if (mid == 0) {
                // if arr[mid] is greater, return it
                if (arr[mid] > arr[mid+1])
                    return mid;
                // if arr[mid] is not greater, then element next to it must
				// have been greater as thats why came to this side
                else
                    return mid+1;
            // if last element of the array
            } else {
                // if arr[mid] is greater, return it
                if (arr[mid] > arr[mid-1])
                    return mid;
                // if arr[mid] is not greater, then element next to it must
				// have been greater as thats why came to this side
                else
                    return mid-1;
            }
        }
    }

    return -1;
}

int main() {
    // int arr[] = { 1, 3, 2, 4, 1, 0 };
    // int arr[] = { 1, 1, 1, 1, 1, 1 };
    // int arr[] = { 1, 2, 3, 4, 5, 6 };
    int arr[] = { 6, 5, 4, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point: " << findPeak(arr, n);
    return 0;
}