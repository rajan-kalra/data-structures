#include <iostream>
#include <unordered_set>
using namespace std;
 
bool HasSum (int arr[], int size, int n) {
  sort(arr, arr + size);
  int left = 0, right = size-1;
  int sum = 0;
  while (left < right) {
    sum = arr[left] + arr[right];
    if (sum == n) {
      return true;
    } else if (sum > n) {
      right--;
    } else {
      left++;
    }
  }

  return false;
}

bool HasSumHashing (int arr[], int size, int n) {
  int sum = 0;
  unordered_set<int> s;
  int i = 0;
  while (i < size) {
    int elem2 = n - arr[i];
    if (s.find(elem2) != s.end()) {
      return true;
    }
    s.insert(arr[i]);
    i++;
  }

  return false;
}

int main() {
  int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 17;
    int size = sizeof(A) / sizeof(A[0]);

    // if (HasSum (A, size, n))
    //   cout << "Array has two elements with given sum";
    // else
    //   cout << "Array doesn't have two elements with given sum";

    if (HasSumHashing (A, size, n))
      cout << "Array has two elements with given sum";
    else
      cout << "Array doesn't have two elements with given sum";
  return 0;
}
