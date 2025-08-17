#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1)
            return nums;
        
        int l = 0, r = size - 1;
        while (l < r) {
            if (nums[l] % 2 != 0) {
                std::swap(nums[l], nums[r]);
                r--;
            } else {
                l++;
            }
        }

        return nums;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 1, 2, 4};
    std::vector<int> sorted = solution.sortArrayByParity(nums);
    std::cout << "Sorted array by parity: ";
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}