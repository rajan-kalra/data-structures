#include <iostream>
#include <vector>

using namespace std;

int mod =(int)1e9+7;

int countPartitionsRecursive(int i, int target, vector<int>& input) {
    // if we are at the last index i.e 0th index, below code handles
    // the case of 0s present in the array
    if (i == 0) {
        if (target == 0 && input[0] == 0)
            return 2;
        if (target == 0 || target == input[0])
            return 1;
        return 0;
    }

    int notPick = countPartitionsRecursive (i-1, target, input);
    
    int pick = 0;
    if (input[i] <= target)
        pick = countPartitionsRecursive (i-1, target-input[i], input);
        
    return (notPick + pick) % mod;
}

int countPartitionsMemoized(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
     if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsMemoized(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsMemoized(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int countPartitions (vector<int>& arr, int d) {
    int n = arr.size();

    int totSum = 0;
    for(int i = 0; i < arr.size(); i++){
        totSum += arr[i];
    }
    
    // since the array has all elements are positive integer, this must not happen
    if(totSum - d < 0)
        return 0;

    // when we subtract d from total sum, we are essentially subtracting the
    // left over array. Now, the remaining array sum must be even so that
    // it can be divided into 2 sets S1 & S2
    if ((totSum - d) % 2 == 1)
        return 0;
    
    int s2 = (totSum - d) / 2;
    

    //return countPartitionsRecursive (n-1, s2, arr);

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsMemoized (n-1, s2, arr, dp);
}

int main() {
  vector<int> arr = { 5,2,6,4 };
  int d=3;
  cout << "The number of subsets found are " << countPartitions(arr, d);
}