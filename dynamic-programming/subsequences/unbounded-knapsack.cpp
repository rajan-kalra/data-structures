#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int UnboundedKnapsackRecursive(vector<int> &values, vector<int> &weights, int W, int index) {
    // if 0th index weight divides the total remaining weight completely, take
    // as many weights & multiply it with the corresponding value at index 0
    if (index == 0) {
        return (W / weights[0]) * values[0];
    }

    int notTake = 0 + UnboundedKnapsackRecursive(values, weights, W, index-1);
    int take = 0;

    // if current index weight is less than or equal to remaining weight, take
    // the corresponding value & reduce the total weight by corresponding weight
    if (weights[index] <= W)
        take = values[index] + UnboundedKnapsackRecursive(values, weights, W - weights[index], index);

    return max (notTake, take);
}
 
int UnboundedKnapsackMemoized(vector<int> &values, vector<int> &weights, int W, int index, vector<vector<int>> &dp) {
    // if 0th index weight divides the total remaining weight completely, take
    // as many weights & multiply it with the corresponding value at index 0
    if (index == 0) {
        return (W / weights[0]) * values[0];
    }

    if (dp[index][W] != -1) {
        return dp[index][W];
    }

    int notTake = 0 + UnboundedKnapsackMemoized(values, weights, W, index-1, dp);

    // if current index weight is less than or equal to remaining weight, take
    // the corresponding value & reduce the total weight by corresponding weight
    int take = 0;
    if (weights[index] <= W) {
        take = values[index] + UnboundedKnapsackMemoized(values, weights, W - weights[index], index, dp);
    }

    return dp[index][W] = max(notTake, take);
}
 
int main() {
    int W = 100;
    vector<int> values = { 10, 30, 20 };
    vector<int> weights = { 5, 10, 15 };
    int n = values.size();

    // cout << UnboundedKnapsackRecursive(values, weights, W, n - 1);

    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    cout << UnboundedKnapsackMemoized(values, weights, W, n - 1, dp);
    return 0;
}