#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        // Map to store {remainder, earliest_index}
        std::unordered_map<int, int> remainderMap;
        
        // Initialize with remainder 0 at index -1.
        // This handles edge cases where the valid subarray starts from index 0.
        remainderMap[0] = -1;
        
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            
            // Calculate remainder
            int remainder = runningSum % k;
            
            // If the remainder already exists in our map
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if the length of the subarray is at least 2
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                // Only store the index if the remainder is seen for the first time.
                // This ensures we keep the smallest index to maximize subarray length.
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    std::cout << "Test Case 1: " << (solution.checkSubarraySum(nums1, k1) ? "True" : "False") << " (Expected: True)" << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;
    std::cout << "Test Case 2: " << (solution.checkSubarraySum(nums2, k2) ? "True" : "False") << " (Expected: True)" << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;
    std::cout << "Test Case 3: " << (solution.checkSubarraySum(nums3, k3) ? "True" : "False") << " (Expected: False)" << std::endl;

    return 0;
}