#include <iostream>
using namespace std;
 
int binarySearchRecursive(int arr[], int low, int high, int key) {
  // low & high indexes have crossed each other i.e
  // element not present in the array
  if (low > high)
    return -1;

  int mid = (low + high) / 2; /*low + (high - low)/2;*/

  // mid element is the key being searched
  if (arr[mid] == key)
    return mid;

  // key if exists, exists in the right side search space
  if (key > arr[mid])
    return binarySearchRecursive(arr, (mid + 1), high, key);

  // key if exists, exists in the left side search space
  return binarySearchRecursive(arr, low, (mid - 1), key);
}

int binarySearchIterative(int arr[], int low, int high, int key) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if(key > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
 
int main() {
    // Let us search 3 in below array
    int arr[] = { 5, 6, 7, 8, 9, 10 };
    int n, key;
 
    n = sizeof(arr) / sizeof(arr[0]);
    key = 50;
 
    // Function call
    cout << "Index from binarySearchRecursive: " << binarySearchRecursive(arr, 0, n - 1, key) << endl;
    cout << "Index from binarySearchIterative: " << binarySearchIterative(arr, 0, n - 1, key) << endl;
    return 0;
}