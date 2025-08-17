#include <iostream>
#include <vector>
#include <algorithm>

int countPairsTwoPointers(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int count = 0;
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        if (nums[left] + nums[right] < target) {
            // All elements from left+1 to right will also form a valid pair with nums[left]
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    // Test 1: Example from code
    std::vector<int> nums1 = {-1, 1, 2, 3, 1};
    int target1 = 2;
    std::cout << "Test 1: " << countPairsTwoPointers(nums1, target1) << " (expected: 3)" << std::endl;
    // Pairs: (-1,1), (-1,1), (-1,2)

    // Test 2: All pairs valid
    std::vector<int> nums2 = {1, 2, 3, 4};
    int target2 = 10;
    std::cout << "Test 2: " << countPairsTwoPointers(nums2, target2) << " (expected: 6)" << std::endl;
    // All pairs: (1,2), (1,3), (1,4), (2,3), (2,4), (3,4)

    // Test 3: No valid pairs
    std::vector<int> nums3 = {5, 6, 7};
    int target3 = 5;
    std::cout << "Test 3: " << countPairsTwoPointers(nums3, target3) << " (expected: 0)" << std::endl;

    // Test 4: Negative numbers
    std::vector<int> nums4 = {-3, -2, -1, 0};
    int target4 = -2;
    std::cout << "Test 4: " << countPairsTwoPointers(nums4, target4) << " (expected: 3)" << std::endl;
    // Pairs: (-3,-2), (-3,-1), (-3,0)

    // Test 5: Duplicates
    std::vector<int> nums5 = {1, 1, 1, 1};
    int target5 = 3;
    std::cout << "Test 5: " << countPairsTwoPointers(nums5, target5) << " (expected: 6)" << std::endl;
    // All pairs: (1,1) six times

    // Test 6: Empty array
    std::vector<int> nums6 = {};
    int target6 = 1;
    std::cout << "Test 6: " << countPairsTwoPointers(nums6, target6) << " (expected: 0)" << std::endl;

    // Test 7: Single element
    std::vector<int> nums7 = {5};
    int target7 = 10;
    std::cout << "Test 7: " << countPairsTwoPointers(nums7, target7) << " (expected: 0)" << std::endl;

    return 0;
}