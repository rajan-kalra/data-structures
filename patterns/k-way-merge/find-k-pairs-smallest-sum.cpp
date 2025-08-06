#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;

        // Edge case: if either array is empty or k is non-positive, return an empty result.
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }

        // A min-heap to store tuples of (sum, index_of_nums1, index_of_nums2)
        // The lambda function ensures the heap is ordered by sum in ascending order.
        auto compare = [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] > b[0];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> minHeap(compare);

        // Push the first element of nums1 with every element of nums2 into the heap.
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        // Extract k smallest pairs
        while (k > 0 && !minHeap.empty()) {
            std::vector<int> top = minHeap.top();
            minHeap.pop();

            int sum = top[0];
            int i = top[1];
            int j = top[2];

            result.push_back({nums1[i], nums2[j]});

            // If there's a next element in nums2, push the next pair from the same nums1 element.
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }

            k--;
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 5, 6};
    int k = 3;

    std::vector<std::vector<int>> result = sol.kSmallestPairs(nums1, nums2, k);
    for (const auto& pair : result) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}