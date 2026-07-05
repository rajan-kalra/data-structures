#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

class Solution {
public:
    // This function moves all zeros in the array to the end while maintaining the relative order of non-zero elements  
    void moveZeroes(std::vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        
        // Move all the non-zero elements to the front of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[lastNonZeroFoundAt], nums[i]);
                lastNonZeroFoundAt++;
            }
        }
    }
};

// Driver code to test the solution
int main() {
    Solution solution;
    
    // Test Case 1
    std::vector<int> nums1 = {0, 1, 0, 3, 12};
    std::cout << "Original array 1: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << "\n";
    
    solution.moveZeroes(nums1);
    
    std::cout << "Modified array 1: ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << "\n\n";

    // Test Case 2
    std::vector<int> nums2 = {0};
    std::cout << "Original array 2: ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << "\n";
    
    solution.moveZeroes(nums2);
    
    std::cout << "Modified array 2: ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}