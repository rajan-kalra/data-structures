#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) {
    int minPrice = prices[0];

    // init this as 0 to return for the edge case
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        int cost = prices[i] - minPrice;
        maxProfit = max(cost, maxProfit);
        minPrice = min(prices[i], minPrice);
    }

    return maxProfit;
}

int main() {
    int prices[] = { 7, 1, 5, 6, 4 };
    int n = sizeof(prices) / sizeof(prices[0]);
    int max_profit = maxProfit(prices, n);
    cout << "Max profit: " << max_profit << endl;
    return 0;
}