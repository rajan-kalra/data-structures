#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
        if (nums1.size() == 0)
            return nums2;
        
        if (nums2.size() == 0)
            return nums1;

        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        std::vector<std::vector<int>> result;
        int i = 0, j = 0;

        // Merge the two arrays by summing values with the same first element
        while (i < nums1Size && j < nums2Size) {
            if (nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                i++;
            } else if (nums1[i][0] > nums2[j][0]) {
                result.push_back(nums2[j]);
                j++;
            } else {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            }
        }

        // Append any remaining elements from either array
        while (i < nums1Size) {
            result.push_back(nums1[i]);
            i++;
        }

        // Append any remaining elements from either array
        while (j < nums2Size) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    std::vector<std::vector<int>> nums2 = {{2, 4}, {3, 5}, {5, 6}};
    auto result = solution.mergeArrays(nums1, nums2);
    std::cout << "Merged array: ";
    for (const auto& pair : result) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    std::cout << std::endl;
    return 0;
}