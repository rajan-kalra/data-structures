#include <iostream>
#include <vector>
using namespace std;
 
long long int solve (vector<int>& houseMoneyArray, int i, int n) {
    /**
     * If its the last index i.e n-1, we can assume that previous index picked
     * was index n-3 thus, we must pick this index
     **/
    if (i == n-1) {
        return houseMoneyArray[n-1];
    }

    /**
     * This handle the case when previous picked index was n-1, thus this time
     * it would have gone beyond array bound
     **/
    if (i >= n) {
        return 0;
    }

    /**
     * for every index we attempt to pick & not-pick. We take the max of pick & 
     * not-pick operation & return it
     */
    // pick current element & then move to current - 2
    int pick = houseMoneyArray[i] + solve(houseMoneyArray, i+2, n);

    // not-pick current element & then move to current - 1
    int notPick = 0 + solve(houseMoneyArray, i+1, n);

    // return max of picked and not-pick
    return max(pick, notPick);
}
 
long long int robStreet (vector<int> &arr) {
    int n = arr.size();
    vector<int> arr1;
    vector<int> arr2;

    // CASE: if there is just one element / house, we can just rob that
    if (n == 1)
        return arr[0];

    // take care of the last index to be passed in function calls
    long long int ans1 = solve(arr, 0, n-1);
    long long int ans2 = solve(arr, 1, n);

    // return max of ans from arr1 & arr2
    return max(ans1, ans2);
}
 
 
int main() {
    // vector<int> arr{1,5,1,2,6};
    vector<int> arr{1,3,2,0};

    cout << robStreet(arr);
}