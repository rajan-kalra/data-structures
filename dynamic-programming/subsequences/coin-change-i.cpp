#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int MinCoinsRecursive(vector<int> &denominations, int targetAmount, int currentIndex) {
    if (currentIndex == 0) {
        // Only if remaining value of amount can be accomodated using coin at
        // index 0, we use all coins possible to make this amount.
        // If this amount cannot be made using the coin at index 0, we dont take any
        // coin at all.
        // Look at this from the perspective that given the coin at index 0 can
        // we achieve the amount? We cannot pick as many possible & leave the remaining
        // amount, it has to be either full amount or we dont pick the coins at all.
        if (targetAmount % denominations[0] == 0) {
            return targetAmount / denominations[0];
        }

        return 1e9;
    }

    // recursion of not picking the coin
    int notPickCoin = 0 + MinCoinsRecursive (denominations, targetAmount, currentIndex-1);

    // init the pickCoin value to max as we need to minimize the no of coins
    int pickCoin = INT_MAX;
    if (denominations[currentIndex] <= targetAmount) {
        // here we pick 1 coin at a time & dont move the index to index-1.
        // This means if the current index coin is eligible, we keep taking
        // it in subsequent recursion calls
        pickCoin = 1 + MinCoinsRecursive(denominations, targetAmount - denominations[currentIndex], currentIndex);
    }

    return min(notPickCoin, pickCoin);
}
 
int MinCoinsMemoized(vector<int> &denominations, int targetAmount, int currentIndex, vector<vector<int>> &dp) {
    if (currentIndex == 0) {
        // if the remaining value of amount can be accomodated using coin at
        // index 0, we use as many coins are required for it
        if (targetAmount % denominations[0] == 0) {
            return targetAmount / denominations[0];
        }
        return 1e9;
    }

    if (dp[currentIndex][targetAmount] != -1) {
        return dp[currentIndex][targetAmount];
    }

    int notPickCoin = 0 + MinCoinsMemoized (denominations, targetAmount, currentIndex-1, dp);
    int pickCoin = INT_MAX;
    if (denominations[currentIndex] <= targetAmount) {
        // here 1 is each coin picked
        pickCoin = 1 + MinCoinsMemoized(denominations, targetAmount - denominations[currentIndex], currentIndex, dp);
    }

    return dp[currentIndex][targetAmount] = min(notPickCoin, pickCoin);
}
 
int main() {
    vector<int> denominations = {9, 6, 5, 1};
    int noOfCoins = denominations.size();

    int targetAmount = 11;

    int minNoOfCoins = MinCoinsRecursive(denominations, targetAmount, noOfCoins - 1);
    if (minNoOfCoins >= 1e9)
    	cout << "Minimum coins required is not possible";
    else
    	cout << "Minimum coins required is: " << minNoOfCoins;

    // vector<vector<int>> dp(noOfCoins, vector<int>(targetAmount + 1, -1));
    // int minNoOfCoins = MinCoinsMemoized(denominations, targetAmount, noOfCoins - 1, dp);
    // if (minNoOfCoins >= 1e9)
    //     cout << "Minimum coins required is not possible";
    // else
    //     cout << "Minimum coins required is: " << minNoOfCoins;

    return 0;
}