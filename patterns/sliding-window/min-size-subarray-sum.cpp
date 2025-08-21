#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int minSubArrayLen(int s, std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    
    int left = 0;
    int currentSum = 0;
    int minLength = INT_MAX;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];
        
        while (currentSum >= s) {
            minLength = std::min(minLength, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }
    
    return (minLength == INT_MAX) ? 0 : minLength;
}

int main() {
    // Test 1: Basic example
    int s1 = 7;
    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int result1 = minSubArrayLen(s1, nums1);
    std::cout << "Test 1: " << result1 << " (expected: 2)" << std::endl;
    // [4,3] has sum 7, length 2

    // Test 2: No valid subarray
    int s2 = 15;
    std::vector<int> nums2 = {1, 2, 3, 4};
    int result2 = minSubArrayLen(s2, nums2);
    std::cout << "Test 2: " << result2 << " (expected: 0)" << std::endl;
    // Sum of all elements (10) is less than target (15)

    // Test 3: Single element satisfies
    int s3 = 4;
    std::vector<int> nums3 = {1, 4, 4};
    int result3 = minSubArrayLen(s3, nums3);
    std::cout << "Test 3: " << result3 << " (expected: 1)" << std::endl;
    // Single element 4 satisfies target

    // Test 4: Entire array needed
    int s4 = 11;
    std::vector<int> nums4 = {1, 2, 3, 4, 5};
    int result4 = minSubArrayLen(s4, nums4);
    std::cout << "Test 4: " << result4 << " (expected: 3)" << std::endl;
    // [3,4,5] or [2,4,5] has sum >= 11, length 3

    // Test 5: Empty array
    int s5 = 1;
    std::vector<int> nums5 = {};
    int result5 = minSubArrayLen(s5, nums5);
    std::cout << "Test 5: " << result5 << " (expected: 0)" << std::endl;

    // Test 6: All elements are same
    int s6 = 10;
    std::vector<int> nums6 = {3, 3, 3, 3, 3};
    int result6 = minSubArrayLen(s6, nums6);
    std::cout << "Test 6: " << result6 << " (expected: 4)" << std::endl;
    // Need 4 elements of value 3 to get sum >= 10

    // Test 7: Large single element
    int s7 = 10;
    std::vector<int> nums7 = {15};
    int result7 = minSubArrayLen(s7, nums7);
    std::cout << "Test 7: " << result7 << " (expected: 1)" << std::endl;
    // Single element 15 > 10

    // Test 8: Target is 0
    int s8 = 0;
    std::vector<int> nums8 = {1, 2, 3};
    int result8 = minSubArrayLen(s8, nums8);
    std::cout << "Test 8: " << result8 << " (expected: 1)" << std::endl;
    // Any positive number >= 0, so minimum length is 1

    return 0;
}