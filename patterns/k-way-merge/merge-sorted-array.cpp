#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p_merge = m + n - 1;

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p_merge] = nums1[p1];
                p1--;
            } else {
                nums1[p_merge] = nums2[p2];
                p2--;
            }
            p_merge--;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    sol.merge(nums1, 3, nums2, 3);
    std::cout << "Merged array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}