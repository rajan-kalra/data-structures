#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> // for std::pair
#include <unordered_set>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        // Step 1: Store pairs of (value, original_index)
        std::vector<std::pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Step 2: Sort by value in descending order
        std::sort(indexedNums.begin(), indexedNums.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        // Step 3: Select the top k elements
        std::vector<std::pair<int, int>> topK = std::vector<std::pair<int, int>>(indexedNums.begin(), indexedNums.begin() + k);
        
        // Step 4: Sort the top k elements by their original index
        std::sort(topK.begin(), topK.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        
        // Step 5: Build the result vector
        std::vector<int> result;
        for (const auto& p : topK) {
            result.push_back(p.first);
        }
        
        return result;
    }
};
  
int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    std::vector<int> output = solution.maxSubsequence(nums, k);
    std::cout << "Max subsequence of length " << k << ": ";
    for (int num : output) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}