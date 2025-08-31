// filepath: /Users/Rajan.Kalra/Documents/data-structures/heaps/k-smallest-pairs.cpp
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        // Min-heap: (pair sum, (index in nums1, index in nums2))
        std::priority_queue<
            std::pair<int, std::pair<int, int>>,
            std::vector<std::pair<int, std::pair<int, int>>>,
            std::greater<>
        > min_heap;

        // Seed the heap with the first element from nums2 for each nums1 (up to k)
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            min_heap.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Extract the smallest pairs up to k times
        while (k-- > 0 && !min_heap.empty()) {
            auto top = min_heap.top();
            min_heap.pop();
            int i = top.second.first;
            int j = top.second.second;
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                min_heap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return result;
    }
};

void printPairs(const std::vector<std::vector<int>>& pairs) {
    std::cout << "[";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "[" << pairs[i][0] << ", " << pairs[i][1] << "]";
        if (i + 1 < pairs.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::vector<int> nums1_1 = {1, 7, 11};
    std::vector<int> nums2_1 = {2, 4, 6};
    int k1 = 3;
    auto result1 = sol.kSmallestPairs(nums1_1, nums2_1, k1);
    std::cout << "For nums1={1,7,11}, nums2={2,4,6}, k=3, the pairs are: ";
    printPairs(result1);

    std::vector<int> nums1_2 = {1, 1, 2};
    std::vector<int> nums2_2 = {1, 2, 3};
    int k2 = 2;
    auto result2 = sol.kSmallestPairs(nums1_2, nums2_2, k2);
    std::cout << "For nums1={1,1,2}, nums2={1,2,3}, k=2, the pairs are: ";
    printPairs(result2);

    return 0;
}