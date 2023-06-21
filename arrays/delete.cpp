#include <iostream>
using namespace std;

bool binary_search(int arr[], int n, int element) {
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == element) {
      return true;
    } else if (arr[mid] > element) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return false;
}

// method to find the common elements from 3 sorted arrays using binary search
void findCommon(int a[], int b[], int c[], int n1, int n2, int n3) {
  // Iterating the first array
  for (int i = 0; i < n1; i++) {
    // checking for the duplicate element condition
    if (i != 0 && a[i] == a[i - 1]) {
      continue;
    }

    // checking if current element in arr1 exists
    // in arr2 & arr3
    if (binary_search(b, n2, a[i]) && binary_search(c, n3, a[i])) {
      cout << a[i] << " ";
    }
  }
}

int main() {
  int ar1[] = { 1, 5, 10, 20, 40, 80 };
  int ar2[] = { 6, 7, 20, 80, 100 };
  int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
  int n1 = sizeof(ar1) / sizeof(ar1[0]);
  int n2 = sizeof(ar2) / sizeof(ar2[0]);
  int n3 = sizeof(ar3) / sizeof(ar3[0]);

  cout << "Common Elements are " << endl;
  findCommon(ar1, ar2, ar3, n1, n2, n3);
  return 0;
}
