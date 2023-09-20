#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int CutRodRecursive(vector<int> &price, int rodLength, int index) {
    if (index == 0) {
        return price[0] * rodLength;
    }

    int notTake = 0 + CutRodRecursive(price, rodLength, index-1);
    int take = INT_MIN;
    // define the array where its index represents length of rod &
    // value at index represents the price of this length. Thus for
    // index 0, we consider rod length as 1, for index 1 its 2 & so on
    int currIndexRodLength = index + 1;

    if (currIndexRodLength <= rodLength)
        take = price[index] + CutRodRecursive(price, rodLength - currIndexRodLength, index);

    return max(take, notTake);
}

int CutRodMemoized(vector<int> &price, int rodLength, int index, vector<vector<int>> &dp) {
    if (index == 0) {
        return price[0] * rodLength;
    }

    if (dp[index][rodLength] != -1)
        return dp[index][rodLength];

    int notTake = 0 + CutRodMemoized(price, rodLength, index-1, dp);
    int take = INT_MIN;
    int currIndexRodLength = index + 1;

    if (currIndexRodLength <= rodLength)
        take = price[index] + CutRodMemoized(price, rodLength - currIndexRodLength, index, dp);

    return dp[index][rodLength] = max(take, notTake);
}

int main() {
    vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = price.size();
    // cout << "Maximum Obtainable Value is " << CutRodRecursive(price, n, n - 1);

    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << "Maximum Obtainable Value is " << CutRodMemoized(price, n, n - 1, dp);
    return 0;
}