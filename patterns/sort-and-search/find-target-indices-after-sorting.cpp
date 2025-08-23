#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        // Step 1: Sort the array in non-decreasing order.
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> result;
        
        // Step 2 & 3: Iterate through the sorted array and find target indices.
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                // Step 4: Store the index.
                result.push_back(i);
            }
        }
        
        // Step 5: Return the result.
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    std::vector<int> indices = sol.targetIndices(nums, target);
    for (int index : indices) {
        std::cout << index << " ";
    }
    return 0;
}