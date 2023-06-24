#include <iostream>
#include <unordered_set>
using namespace std;
 
int GetFirst (int arr[], int start, int end, int x) {
    int mid, res = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == x) {
            // important step, at this point we dont know if
            // this occurence is first or not but we save this
            // index in result for later time when we realize
            // this is was the first index
            res = mid;
            end = mid-1;
        } else if (x < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return res;
}
 
int GetLast (int arr[], int start, int end, int x) {
    int mid, res = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == x) {
            // important step, at this point we dont know if
            // this occurence is first or not but we save this
            // index in result for later time when we realize
            // this is was the first index
            res = mid;
            start = mid+1;
        } else if (x < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return res;
}
 
int GetOccurences (int arr[], int size, int x) {
    int firstIndex = GetFirst (arr, 0, size-1, x);
    int lastIndex = GetLast (arr, 0, size-1, x);

    return lastIndex - firstIndex + 1;
}
 
int main() {
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // int x = 2;
    // int x = 3;
    int x = 8;
    cout << "Frequency of " << x << " in given array: " << GetOccurences(arr, n, x);
    return 0;
}