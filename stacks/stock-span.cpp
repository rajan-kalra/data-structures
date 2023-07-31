#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void calculateSpan(vector<int>& price, int n, int S[]) {
    // span value of first day is always 1
    S[0] = 1;

    // Calculate span value of remaining days
    // by linearly checking previous days
    for (int i = 1; i < n; i++) {
        int currentDayPrice = price[i];

        S[i] = 1; // Initialize span value

        // traverse left side while the next element
        // on left is smaller than price[i]
        int j = i-1;
        while (j >= 0 && (price[j] <= currentDayPrice)) {
            // increment span value for current day by 1
            // for each smaller element on the left
            S[i]++;
            j--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    vector<int> price = { 10, 4, 5, 90, 120, 80 };
    int n = price.size();
    int S[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);

    return 0;
}
