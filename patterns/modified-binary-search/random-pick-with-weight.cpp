#include <iostream>
#include <queue>
#include <vector>

#include <vector>
#include <numeric> // For std::accumulate
#include <cstdlib> // For std::rand
#include <ctime>   // For std::time

class Solution {
private:
    std::vector<int> prefix_sums;
    int total_sum;

public:
    Solution(std::vector<int>& w) {
        // Step 1: Initialize random number generator
        std::srand(std::time(0));
        
        // Step 2: Build the prefix sum array
        prefix_sums.push_back(w[0]);
        for (size_t i = 1; i < w.size(); ++i) {
            prefix_sums.push_back(prefix_sums.back() + w[i]);
        }
        total_sum = prefix_sums.back();
    }
    
    int pickIndex() {
        // Step 3: Generate a random number
        // std::rand() is a C-style function. For better quality random numbers,
        // one might use C++11's <random> library.
        int target = 1 + (std::rand() % total_sum);
        
        // Step 4: Binary search to find the index
        int left = 0;
        int right = prefix_sums.size() - 1;
        int result_index = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (prefix_sums[mid] >= target) {
                // This index could be the answer. Try to find a smaller one.
                result_index = mid;
                right = mid - 1;
            } else {
                // The target is in the range of elements to the right.
                left = mid + 1;
            }
        }
        
        return result_index;
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