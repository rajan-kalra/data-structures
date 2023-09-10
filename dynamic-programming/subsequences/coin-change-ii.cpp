#include <iostream>
#include <vector>
using namespace std;
 
long TotalWaysRecursive(vector<int> &denominations, int targetAmount, int currentIndex) {
    // We return 0/1 implying whether
    // targetAmount could be achieved or not
    if (currentIndex == 0) {
        if (targetAmount % denominations[0] == 0)
            return 1;
        else
            return 0;
    }

    long notPick = TotalWaysRecursive(denominations, targetAmount, currentIndex - 1);

    long pick = 0;
    if (denominations[currentIndex] <= targetAmount)
        pick = TotalWaysRecursive(denominations, targetAmount - denominations[currentIndex], currentIndex);

    return pick + notPick;
}
 
long TotalWaysMemoized(vector<int> &denominations, int targetAmount, int currentIndex, vector<vector<int>> &dp) {
    if (currentIndex == 0) {
        return (targetAmount % denominations[0] == 0);
    }

    if (dp[currentIndex][targetAmount] != -1)
        return dp[currentIndex][targetAmount];

    long notPick = TotalWaysMemoized(denominations, targetAmount, currentIndex - 1, dp);
    long pick = 0;
    if (denominations[currentIndex] <= targetAmount)
        pick = TotalWaysMemoized(denominations, targetAmount - denominations[currentIndex], currentIndex, dp);

    return dp[currentIndex][targetAmount] = pick + notPick;
}
 
 
int main() {
    int i, j;
    vector<int> denominations = { 1, 2, 3 };
    int targetAmount = 4;
    int numOfDenominations = denominations.size();

    // cout << " " << TotalWaysRecursive(denominations, targetAmount, coinsSize - 1);

    vector<vector<int>> dp(numOfDenominations, vector<int>(targetAmount + 1, -1));
    cout << " " << TotalWaysMemoized(denominations, targetAmount, numOfDenominations - 1, dp);

    return 0;
}