#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements for the second and third numbers
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
  Solution solution;
  // Test 1: Basic test
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = solution.threeSum(nums1);
    std::cout << "Test 1: " << std::endl;
    for (const auto& triplet : res1) {
        for (int num : triplet) std::cout << num << " ";
        std::cout << std::endl;
    }
    // Expected: -1 -1 2 and -1 0 1 (order may vary)

    // Test 2: No solution
    std::vector<int> nums2 = {1, 2, 3, 4};
    auto res2 = solution.threeSum(nums2);
    std::cout << "Test 2: " << std::endl;
    for (const auto& triplet : res2) {
        for (int num : triplet) std::cout << num << " ";
        std::cout << std::endl;
    }
    // Expected: (no output)

    // Test 3: All zeros
    std::vector<int> nums3 = {0, 0, 0, 0};
    auto res3 = solution.threeSum(nums3);
    std::cout << "Test 3: " << std::endl;
    for (const auto& triplet : res3) {
        for (int num : triplet) std::cout << num << " ";
        std::cout << std::endl;
    }
    // Expected: 0 0 0

    // Test 4: Large negative and positive numbers
    std::vector<int> nums4 = {-2, 0, 1, 1, 2};
    auto res4 = solution.threeSum(nums4);
    std::cout << "Test 4: " << std::endl;
    for (const auto& triplet : res4) {
        for (int num : triplet) std::cout << num << " ";
        std::cout << std::endl;
    }
    // Expected: -2 0 2 and -2 1 1

    // Test 5: Empty input
    std::vector<int> nums5 = {};
    auto res5 = solution.threeSum(nums5);
    std::cout << "Test 5: " << std::endl;
    for (const auto& triplet : res5) {
        for (int num : triplet) std::cout << num << " ";
        std::cout << std::endl;
    }
    // Expected: (no output)
  return 0;
}