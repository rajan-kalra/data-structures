#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        // Max-heap to store pairs of (distance_squared, point)
        // By default, std::priority_queue is a max-heap
        std::priority_queue<std::pair<int, std::vector<int>>> maxHeap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist_squared = x*x + y*y;

            maxHeap.push({dist_squared, point});
            
            // If the heap size exceeds k, remove the largest element (farthest point)
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract the k closest points from the heap
        std::vector<std::vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
  
int main() {
    Solution solution;
    std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    std::vector<std::vector<int>> output = solution.kClosest(points, k);
    std::cout << "Closest points to origin: ";
    for (const auto& point : output) {
        std::cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    std::cout << std::endl;
    return 0;
}