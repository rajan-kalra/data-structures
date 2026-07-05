#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Edge case: If the array is empty, return 0
        if (nums.empty()) {
            return 0;
        }
        
        // 'i' is the slow pointer tracking the position of unique elements
        int i = 0; 
        
        // 'j' is the fast pointer scanning through the array
        for (int j = 1; j < nums.size(); j++) {
            // If we find a new unique element
            if (nums[j] != nums[i]) {
                i++;             // Move the slow pointer forward
                nums[i] = nums[j]; // Copy the unique element to the new position
            }
        }
        
        // The number of unique elements is the index + 1
        return i + 1;
    }
};

// Driver code to test the solution
int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    
    std::cout << "Example 1 Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        std::cout << nums1[i] << (i == k1 - 1 ? "" : ", ");
    }
    std::cout << "]\n";

    // Example 2
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    
    std::cout << "Example 2 Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        std::cout << nums2[i] << (i == k2 - 1 ? "" : ", ");
    }
    std::cout << "]\n";

    return 0;
}