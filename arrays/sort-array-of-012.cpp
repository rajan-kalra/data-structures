#include <iostream>
using namespace std;
 
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
 
// low: has the index where 0 shall come next
// mid: is the index being explored
// high: is the index where 2 must come next
void sort012(int a[], int size) {
    int low = 0, mid = 0, high = size - 1;

    // condition is that we loop until indexs representing
    // element to be explored becomes equal to the size of
    // the array
    while (mid <= high) {
        switch (a[mid]) {
            case 0:
                swap(a[low], a[mid]);
                low++;mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high]);
                high--;
                break;
        }
    }
}
 
void printArray(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main() {
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before segregation: ";
    printArray(arr, n);

    sort012(arr, n);

    cout << "Array after segregation: ";
    printArray(arr, n);

    return 0;
}