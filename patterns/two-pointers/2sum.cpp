#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Initialize the result vector
        std::vector<int> res;
        // Create a hash map to store the indices of the elements
        std::unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int complement = target - currentNum;
            if (um.find(complement) != um.end()) {
                // If the complement exists in the map, we found a pair
                res.push_back(um[complement]);
                res.push_back(i);
                return res;
            }
            um[currentNum] = i;
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    // Test 1: Basic test
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    auto res1 = solution.twoSum(nums1, target1);
    std::cout << "Test 1: ";
    for (int index : res1) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Test 2: No solution
    std::vector<int> nums2 = {1, 2, 3, 4};
    int target2 = 8;
    auto res2 = solution.twoSum(nums2, target2);
    std::cout << "Test 2: ";
    for (int index : res2) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Test 3: Negative numbers
    std::vector<int> nums3 = {-1, -2, -3, -4};
    int target3 = -6;
    auto res3 = solution.twoSum(nums3, target3);
    std::cout << "Test 3: ";
    for (int index : res3) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}