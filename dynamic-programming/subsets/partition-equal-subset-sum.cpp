#include <iostream>
#include <vector>
using namespace std;

bool partitionEqualSubsetMemoization(vector<int> &input, int n, int i, int target, vector<vector<int>> &dp){
    if (target == 0)
        return true;
 
    if (i == n-1)
        return input[n-1] == target;
 
    if (dp[i][target] != -1)
        return dp[i][target];
 
    bool notPick = partitionEqualSubsetMemoization (input, n, i+1, target, dp);
 
    bool pick = false;
    if (input[i] <= target)
        pick = partitionEqualSubsetMemoization (input, n, i+1, target-input[i], dp);
 
    return dp[i][target] = notPick || pick;
}
 
bool partitionEqualSubsetRecursive(int i, int n, int target, vector<int> &input) {
    if (target == 0)
        return true;

    if(i == n-1)
        return input[n-1] == target;

    bool notPick = partitionEqualSubsetRecursive(i+1, n, target, input);

    bool pick = false;
    if (input[i] <= target)
        pick = partitionEqualSubsetRecursive(i+1, n, target-input[i], input);

    return notPick || pick;
}
 
bool canPartition(vector<int> &input, int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += input[i];
    }

    if (totalSum % 2 == 1) {
        return false;
    } else {
        int target = totalSum / 2;
        int i = 0;
        // return partitionEqualSubsetRecursive(i, n, target, input);

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return partitionEqualSubsetMemoization(input, n, i, target, dp);
    }
}
 
int main() {
    vector<int> input = { 2,3,3,3,4,5 };
    int n = input.size();

    if (canPartition(input, n))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";
}