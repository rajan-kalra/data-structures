#include<iostream>
using namespace std;
 
int search(int arr[], int n, int target, int k) {
  if (n == 0)
    return -1;

  // Traverse the given array starting from
  // leftmost element
  int start = 0;
  while (start < n) {

    // If target is found at index start
    if (arr[start] == target)
      return start;

    // Jump the difference between current
    // array element and target divided by k
    int diff = abs(arr[start] - target) / k;

    // We use max here to make sure that i
    // moves at-least one step ahead. This
    // can handle the edge case when k is 0
    // i.e all elements are same
    diff = max(1, diff);

    // move the start index by atleast diff
     start = start + diff;
  }

  cout << "number is not present!";
  return -1;
}
 
int main()
{
  int arr[] = {2, 4, 5, 7, 7, 6};
  int x = 6;
  int k = 2;
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Element " << x << " is present at index "
    << search(arr, n, x, k);
  return 0;
}
