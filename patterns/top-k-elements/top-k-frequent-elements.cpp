#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies of all elements
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Create a min-heap of pairs (frequency, number)
        // std::priority_queue defaults to a max-heap, so we need to use std::greater for a min-heap
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        
        // Step 3: Populate the heap
        for (auto const& pair : freqMap) {
            minHeap.push({pair.second, pair.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 4: Extract the top k elements
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};
  
int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> output = solution.topKFrequent(nums, k);
    std::cout << "Top " << k << " frequent elements: ";
    for (int num : output) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}