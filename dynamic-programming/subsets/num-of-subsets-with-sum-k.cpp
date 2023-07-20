#include <iostream>
#include <vector>
using namespace std;
 
// This implementation doesn't account for the case when set has 0s

int NumOfSubsetsWithSumRecursive (int index, int target, vector<int> &set) {
    // if target has become 0, we have a subset which has sum as target
    if (target == 0) {
        return 1;
    }

    /**
     * if we are at last index & we have value at last index as target
     * we have found a subset which has sum as a target, otherwise we 
     * dont have such a subset
     **/
    if (index == 0) {
        return set[0] == target ? 1 : 0;
    }

    // dont pick the current index element
    int notPick = NumOfSubsetsWithSumRecursive(index - 1, target, set);

    // pick the current index element
    int pick = 0;
    if (set[index] <= target)
        pick = NumOfSubsetsWithSumRecursive(index - 1, target - set[index], set);

    // add return values of all the recursive calls made above to get count
    return pick + notPick;
}
 
int NumOfSubsetsWithSumMemoized (int index, int target, vector<int> &set, vector<vector<int>> &dp) {
    // if target has become 0, we have a subset which has sum as target
    if (target == 0) {
        return 1;
    }

    /**
     * if we are at last index & we have value at last index as target
     * we have found a subset which has sum as a target, otherwise we 
     * dont have such a subset
     **/
    if (index == 0) {
        return set[0] == target ? 1 : 0;
    }

    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    // dont pick the current index element
    int notPick = NumOfSubsetsWithSumMemoized(index-1, target, set, dp);

    // pick the current index element
    int pick = 0;
    if (set[index] <= target)
        pick = NumOfSubsetsWithSumMemoized(index-1, target - set[index], set, dp);

    // add return values of all the recursive calls made above to get count
    return dp[index][target] = pick + notPick;
}
 
int main() {
    vector<int> set = { 1, 2, 3, 4, 5 };
    int n = set.size();
    int target = 9;
    // cout << "Num of subsets with given sum: " << NumOfSubsetsWithSumRecursive(n - 1, target, set);

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout << "Num of subsets with given sum: " << NumOfSubsetsWithSumMemoized(n - 1, target, set, dp);

    return 0;
}