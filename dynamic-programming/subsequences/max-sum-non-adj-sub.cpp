#include <iostream>
#include <vector>
using namespace std;

void printConceptArray (vector<int> &conceptArray) {
    int sum = 0;
    cout << "Picked elements: ";
    for (auto i : conceptArray) {
        sum += i;
        cout << i << " ";
    }

    cout << ", Sum of picked elements: " << sum;
    cout << endl;
    cout << "***********************************************";
    cout << endl;
}

// moving from left to right i.e index 0 to n-1
int maxRobberyRecursive(int* houseMoneyArray, int i, int n, vector<int> &conceptArray) {
    /**
     * if last index(n-1), we can say that
     * previous index picked was index (n-3)
     * thus, we must pick this index
     */
    if (i == n-1) {
        // printing conceptArray
        conceptArray.push_back(houseMoneyArray[n-1]);
        printConceptArray (conceptArray);
        conceptArray.pop_back();
        return houseMoneyArray[n-1];
    }

    /**
     * this handles the case when previous picked
     * index was n-1, thus this time it would
     * have gone beyond the element
     */
    if (i >= n) {
        printConceptArray (conceptArray);
        return 0;
    }

    /**
     * for every index we attempt to pick & not-pick. We take the max of pick & 
     * not-pick operation & return it
     */
    // pick current element & then move to current - 2
    conceptArray.push_back(houseMoneyArray[i]);
    int pick = houseMoneyArray[i] + maxRobberyRecursive(houseMoneyArray, i+2, n, conceptArray);
    conceptArray.pop_back();

    // not-pick current element & then move to current - 1
    int notPick = 0 + maxRobberyRecursive(houseMoneyArray, i+1, n, conceptArray);

    // return max of picked and not-pick
    return max(pick, notPick);
}
 
int maxRobberyMemoized(int* houseMoneyArray, int i, int n, vector<int> &dp) {
    /**
     * If its the last index i.e n-1, we can assume that previous index picked
     * was index n-3 thus, we must pick this index
     **/
    if (i == n-1) {
        return houseMoneyArray[n-1];
    }

    /**
     * This handles the case when previous picked index was n-2, thus this time
     * it would have gone beyond the last index i.e n-1
     **/
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    /**
     * for every index we attempt to pick & not-pick. We take the max of pick & 
     * not-pick operation & return it
     */
    // pick current element & then move to current - 2
    int pick = houseMoneyArray[i] + maxRobberyMemoized(houseMoneyArray, i+2, n, dp);

    // not-pick current element & then move to current - 1
    int notPick = 0 + maxRobberyMemoized(houseMoneyArray, i+1, n, dp);

    // return max of picked and not picked
    return dp[i] = max(pick, notPick);
}
 
int maxRobberyTabulation(int* houseMoneyArray, int n, vector<int> &dp) {
    // to work bottom up, populating the dp array with base case
    dp[0] = houseMoneyArray[0];
    int negative = 0;

    for (int i = 1; i < n; i++) {
        int pick = houseMoneyArray[i];
        if (i > 1)
            pick += dp[i-2];

        int notPick = 0 + dp[i-1];

        dp[i] = max(pick, notPick);
    }

    // return max of picked and not picked
    return dp[n-1];
}
 
int maxRobberySpaceOptimized(int* houseMoneyArray, int n) {
    // to work bottom up, populating the dp array with base case
    int prev = houseMoneyArray[0];
    int prev_prev = 0;

    for (int i = 1; i < n; i++) {
        int pick = houseMoneyArray[i];
        if (i > 1)
            pick += prev_prev;

        int notPick = 0 + prev;

        int curr_i = max(pick, notPick);
        prev_prev = prev;
        prev = curr_i;
    }

    // return max of picked and not picked
    return prev;
}
 
 
int main() {
    int houseMoneyArray[] = { 6, 7, 1, 3, 8, 2, 4 };
    int i = 0;
    int n = sizeof(houseMoneyArray) / sizeof(houseMoneyArray[0]);
    vector<int> conceptArray;
    int result = maxRobberyRecursive(houseMoneyArray, i, n, conceptArray);
    cout << "Maximum robbery possible using recursion: " << result;

    // vector<int> dp(n, -1);
    // cout << "Maximum robbery possible using memoization: " << maxRobberyMemoized(houseMoneyArray, i, n, dp);

    // vector<int> dp(n, -1);
    // cout << "Maximum robbery possible using tabulation: " << maxRobberyTabulation(houseMoneyArray, n, dp);

    // cout << "Maximum robbery possible by space optimization: " << maxRobberySpaceOptimized(houseMoneyArray, n);

    return 0;
}
