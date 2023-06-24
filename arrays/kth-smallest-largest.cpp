#include <iostream>
#include <vector>
using namespace std ;

int partition (vector<int> &arr, int left, int right) {
    // take last element as pivot
    int pivot = arr[right];

    int i = left;
    // condition of j < right is important here
    // since we want to run loop only till elem
    // before pivot
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);

            // increment after swap, in the end
            // we'll use this index to swap the
            // element at ith index with pivot
            i++;
        }
    }
    // swapping the pivot element at last
    swap(arr[i], arr[right]);

    return i;
}

int kthSmallestElement (vector<int> &arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        int currentPivotIndex = partition(arr, left, right);
        // k-1 due to 0 based indexing
        if (currentPivotIndex == k) {
            kth = arr[currentPivotIndex];
            break;
        }

        if (currentPivotIndex < k - 1) {
            left = currentPivotIndex + 1;
        } else {
            right = currentPivotIndex - 1;
        }
    }

    return kth;
}

int kthLargestElement (vector<int> &arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        int currentPivotIndex = partition(arr, left, right);
        // k-1 due to 0 based indexing
        if (k == currentPivotIndex) {
            kth = arr[currentPivotIndex];
            break;
        } else if (k > currentPivotIndex) {
            left = currentPivotIndex + 1;
        } else {
            right = currentPivotIndex - 1;
        }
    }

    return kth;
}

void printArray (vector<int> &arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr ;
    arr.push_back(12) ;
    arr.push_back(3)  ;
    arr.push_back(5) ;
    arr.push_back(7)  ;
    arr.push_back(4) ;
    arr.push_back(19)  ;
    arr.push_back(26) ;

    int n = arr.size();
    int k = 2;

    // printArray (arr, n);

    // we subtract 1 from k while passing so that value of k gets converted into 
    // 0 based indexing & we need not to handle it in out logic. Try on paper
    // how input of kth index is actually the k-1 index in given array
    // cout << "Kth smallest element: " << kthSmallestElement(arr, k-1) << endl;

    // we pass k as (n-k) to handle the requested index. Try on paper, kth
    // largest element index is actually the (n-k)th index in the array if
    // array was sorted
    cout << "Kth largest element: " << kthLargestElement(arr, n - k) << endl;
    return 0 ;
}