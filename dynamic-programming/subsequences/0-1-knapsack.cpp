#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
// This implementation approaches the problem right to left
int knapsackRecursive(vector<int> &value, vector<int> &weight, int currentIndex, int W) {
    // if its the first element i.e index 0
    if (currentIndex == 0) {
        // if the weight of first element can be accomodated in total weight(W),
        // return the value of first element
        if (weight[0] <= W) {
            return value[0];
        }
        return 0;
    }
 
    // Since in this recursion we dont pick the element, we add value of this 
    // index as 0
    int notTake = 0 + knapsackRecursive(value, weight, currentIndex - 1, W);

    // only if weight of this element can be accomodated in total weight(W),
    // we add the value correspoding to this index
    int take = INT_MIN;
    if (weight[currentIndex] <= W) {
        take = value[currentIndex] + knapsackRecursive(value, weight, currentIndex - 1, W - weight[currentIndex]);
    }

    // this max() function ensures that irrespective of whether weight of this
    // element can be accomodated or not, we pick the max of both recursions
    return max(notTake, take);
}
 
int knapsackMemoized(vector<int> &value, vector<int> &weight, int currentIndex, int W, vector<vector<int>> &dp) {
    // if its the first element i.e index 0
    if (currentIndex == 0) {
        // only if the weight of first element can be accomodated in total
        // weight(W), return the value of first element
        if (weight[0] <= W) {
            return value[0];
        }
        return 0;
    }

    if (dp[currentIndex][W] != -1) {
        return dp[currentIndex][W];
    }

    // Since in this recursion we dont pick the element, we add value of this 
    // index as 0
    int notTake = 0 + knapsackMemoized(value, weight, currentIndex - 1, W, dp);

    // only if weight of this element can be accomodated in total weight(W),
    // we add the value correspoding to this index
    int take = 0;
    if (weight[currentIndex] <= W) {
        take = value[currentIndex] + knapsackMemoized(value, weight, currentIndex - 1, W - weight[currentIndex], dp);
    }

    // this max() function ensures that irrespective of whether weight of this
    // element can be accomodated or not, we pick the max of both recursions
    return dp[currentIndex][W] = max(notTake, take);
}
 
 
int main() {
    vector<int> value = { 60, 100, 120 };
    int valueSize = value.size();

    vector<int> weight = { 10, 20, 30 };
    int weightSize = weight.size();

    int W = 50;

    // cout << knapsackRecursive(value, weight, valueSize - 1, W);


    vector<vector<int>> dp(valueSize, vector<int> (W+1, -1));
    cout << knapsackMemoized(value, weight, valueSize - 1, W, dp);
    return 0;
}