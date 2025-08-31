#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies using a hash map
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2 & 3: Use a min-heap to keep track of the top k elements
        // The pair is {frequency, number}
        // Use std::greater to make a min-heap by frequency (first element)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

        for (auto const& pair : freq) {
            min_heap.push({pair.second, pair.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Step 4: Extract the results from the heap
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    std::vector<int> result1 = sol.topKFrequent(nums1, k1);
    std::cout << "For nums = {1,1,1,2,2,3} and k=2, top k frequent elements are: ";
    printVector(result1); // Expected: [1, 2]

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = sol.topKFrequent(nums2, k2);
    std::cout << "For nums = {1} and k=1, top k frequent elements are: ";
    printVector(result2); // Expected: [1]
    
    return 0;
}