#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <cstdlib> // For std::rand
#include <ctime>   // For std::time

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - k;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) {
                // arr[mid] is closer to x or equally close and smaller.
                // The optimal window could start at or before mid.
                right = mid;
            } else {
                // arr[mid + k] is closer to x.
                // The optimal window must start after mid.
                left = mid + 1;
            }
        }

        // 'left' is now the starting index of the k closest elements.
        return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

int main() {
    std::vector<int> weights = {1, 3};
    Solution obj(weights);
    int param_1 = obj.pickIndex();
    std::cout << "Randomly picked index: " << param_1 << std::endl;
    return 0;
}