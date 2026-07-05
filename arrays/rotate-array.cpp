#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Handle cases where k is greater than the array size
        k = k % n; 
        
        // If k is 0, no rotation is needed
        if (k == 0) return;

        // Step 1: Reverse the entire array
        std::reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining n - k elements
        std::reverse(nums.begin() + k, nums.end());
    }
};

// Helper function to print the array
void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original array: ";
    printVector(nums);

    solution.rotate(nums, k);

    std::cout << "Rotated array:  ";
    printVector(nums);

    return 0;
}