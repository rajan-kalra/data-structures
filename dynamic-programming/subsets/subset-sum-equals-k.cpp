#include <iostream>
#include <vector>
using namespace std;
 
bool isSubsetSumRecursive(vector<int> &input, int n, int i, int target) {
    /**
     * Its one of the base case when we need to break the recursion i.e if at
     * any point while recursing target becomes 0 we know we have got the target
     **/
    if (target == 0) {
        return true;
    }

    /**
     * This is another base case when we need to break the recursion i.e if we
     * are at the other end of the array and the last element is equal to the
     * target, we know we can return true
     **/
    if (i == n-1) {
        return input[n-1] == target;
    }

    bool notPick = isSubsetSumRecursive(input, n, i + 1, target);

    /**
     * In pick case always take default value as false, which becomes true only
     * if the current index value is a valid value i.e input[i] <= target
     **/
    bool pick = false;
    if (input[i] <= target)
        pick = isSubsetSumRecursive(input, n, i + 1, target - input[i]);

    /**
     * Above we made 2 choices to include or exclude the index, now if any one
     * of the choice gives us true, we return true
     **/
    return pick || notPick;
}
 
int isSubsetSumMemoized(vector<int> &input, int n, int i, int target, vector<vector<int>> &dp) {
    /**
     * Its one of the base case when we need to break the recursion i.e if at
     * any point while recursing target becomes 0 we know we have got the target
     **/
    if (target == 0) {
        return true;
    }

    /**
     * This is another base case when we need to break the recursion i.e if we
     * are at the other end of the array, then the last element must be equal
     * to the target to return true
     **/
    if (i == n-1) {
        return (input[n-1] == target);
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    bool notPick = isSubsetSumMemoized(input, n, i+1, target, dp);

    /**
     * In pick case always take default value as false, which becomes true only
     * if the current index value is a valid value i.e input[i] <= target
     **/
    bool pick = false;
    if (input[i] <= target)
        pick = isSubsetSumMemoized(input, n, i+1, target - input[i], dp);

    return dp[i][target] = pick || notPick;
}
 
// Yet to understand
// int isSubsetSumTabulation(vector<int> &input, int n, int target, vector<vector<bool>> &dp) {
//     for (int i = 0; i < n; i++) {
//         dp[i][0] = true;
//     }
 
//     if (input[0] <= target)
//         dp[0][input[0]] = true;
 
//     for (int i = 1; i < n; i++) {
//         for (int k = 1; k <= target; k++) {
//             bool notTaken = dp[i-1][k];
//             bool taken = false;
//     		if(input[i] <= k)
//             	taken = dp[i-1][k-input[i]];
//             dp[i][k]= notTaken || taken;
//         }
//     }
 
//     return dp[n-1][target];
// }

int isSubsetSumUtil (vector<int> &input, int n, int target) {

    int i = 0;
    // cout << "Using Recursion: ";
    // bool isSubsetSumPresent = isSubsetSumRecursive(input, n, i, target);

    cout << "Using Memoization: ";
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    bool isSubsetSumPresent = isSubsetSumMemoized(input, n, i, target, dp);

    // vector<vector<bool>> dp(n, vector<bool>(target+1, false));
    // if (isSubsetSumTabulation(input, n, target, dp))
    // 	cout <<"Using tabulation: Found a subset with given target";
    // else
    // 	cout <<"Using tabulation: No subset with given target found";

    return isSubsetSumPresent;
}

int main() {
    vector<int> input{ 1,2,3,4 };
    int target = 4;
    int n = input.size();
    int i = 0;

    if (isSubsetSumUtil (input, n, target)) {
        cout << "Subset sum with sum as " << target << " found!";
    } else {
        cout << "Subset sum with sum as " << target << " not found!";
    }

    return 0;
}