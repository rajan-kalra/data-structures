#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max

double findMaxAverage(std::vector<int>& nums, int k) {
    // Step 1: Calculate the sum of the first window
    double currentSum = 0;
    for (int i = 0; i < k; ++i) {
        currentSum += nums[i];
    }
    
    double maxSum = currentSum;

    // Step 2: Slide the window
    for (int i = k; i < nums.size(); ++i) {
        // Add the new element and subtract the old one
        currentSum = currentSum + nums[i] - nums[i - k];
        
        // Update the maximum sum
        maxSum = std::max(maxSum, currentSum);
    }

    // Step 3: Calculate and return the maximum average
    return maxSum / k;
}

int main() {
    // Test 1: Basic example
    std::vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    double result1 = findMaxAverage(nums1, k1);
    std::cout << "Test 1: " << result1 << " (expected: 12.75)" << std::endl;
    // Subarray [12, -5, -6, 50] has sum 51, average 12.75

    // Test 2: All negative numbers
    std::vector<int> nums2 = {-1, -2, -3, -4};
    int k2 = 2;
    double result2 = findMaxAverage(nums2, k2);
    std::cout << "Test 2: " << result2 << " (expected: -1.5)" << std::endl;
    // Subarray [-1, -2] has sum -3, average -1.5

    // Test 3: k equals array size
    std::vector<int> nums3 = {5, 6, 7};
    int k3 = 3;
    double result3 = findMaxAverage(nums3, k3);
    std::cout << "Test 3: " << result3 << " (expected: 6)" << std::endl;
    // Only one subarray possible: [5, 6, 7], average 6

    // Test 4: Single element array
    std::vector<int> nums4 = {42};
    int k4 = 1;
    double result4 = findMaxAverage(nums4, k4);
    std::cout << "Test 4: " << result4 << " (expected: 42)" << std::endl;

    // Test 5: All positive numbers
    std::vector<int> nums5 = {1, 2, 3, 4, 5, 6};
    int k5 = 3;
    double result5 = findMaxAverage(nums5, k5);
    std::cout << "Test 5: " << result5 << " (expected: 5)" << std::endl;
    // Subarray [4, 5, 6] has sum 15, average 5

    // Test 6: Mixed positive and negative
    std::vector<int> nums6 = {-1, -12, -5, -6, 50, 3};
    int k6 = 2;
    double result6 = findMaxAverage(nums6, k6);
    std::cout << "Test 6: " << result6 << " (expected: 26.5)" << std::endl;
    // Subarray [50, 3] has sum 53, average 26.5

    // Test 7: Large numbers
    std::vector<int> nums7 = {100, 200, 300, 400};
    int k7 = 2;
    double result7 = findMaxAverage(nums7, k7);
    std::cout << "Test 7: " << result7 << " (expected: 350)" << std::endl;
    // Subarray [300, 400] has sum 700, average 350

    // Test 8: Zeros included
    std::vector<int> nums8 = {0, 0, 10, 0, 0};
    int k8 = 3;
    double result8 = findMaxAverage(nums8, k8);
    std::cout << "Test 8: " << result8 << " (expected: 3.33333)" << std::endl;
    // Subarray [0, 10, 0] has sum 10, average 3.33333

    return 0;
}