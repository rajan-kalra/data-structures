#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x) {
  if (n == 0)
    return -1;

  int start = 0;
  while (start < n) {
    // If x is found at index start
    if (arr[start] == x)
      return start;

    // find the diff b/w current element & x
    int diff = abs(arr[start] - x);

    // move the start index to start + diff as x
    // cannot be within the range of start to diff.
    // Thus at each step we move by diff steps
    start = start + diff;
  }

  cout << "number is not present!";
  return -1;
}
 
int main() {
  int arr[] = { 8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 3;
  cout << "Element " << x << " is present at index " << search(arr, n, 3);
  return 0;
}
