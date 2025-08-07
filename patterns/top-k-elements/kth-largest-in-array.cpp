#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap to store the k largest elements.
        // We use std::greater to make it a min-heap.
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element
            }
        }

        return minHeap.top();
    }
};
  
int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int output = solution.findKthLargest(nums, k);
    std::cout << "Kth largest element: " << output << std::endl;
    return 0;
}