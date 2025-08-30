#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Create a max-heap (priority_queue)
        std::priority_queue<int> max_heap;

        // Push all stone weights into the max-heap
        for (int stone : stones) {
            max_heap.push(stone);
        }

        // Simulate the smashing process
        while (max_heap.size() > 1) {
            int y = max_heap.top();
            max_heap.pop();
            int x = max_heap.top();
            max_heap.pop();

            // If the stones are different, push the difference back into the heap
            if (y > x) {
                max_heap.push(y - x);
            }

            // If the stones are equal, do nothing as they both get smashed
        }

        // Return the final result
        if (max_heap.empty()) {
            return 0;
        } else {
            return max_heap.top();
        }
    }
};

int main() {
    Solution sol;
    
    std::vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    int result1 = sol.lastStoneWeight(stones1);
    std::cout << "For stones {2, 7, 4, 1, 8, 1}, the last stone weight is: " << result1 << std::endl; // Expected: 1

    std::vector<int> stones2 = {1};
    int result2 = sol.lastStoneWeight(stones2);
    std::cout << "For stones {1}, the last stone weight is: " << result2 << std::endl; // Expected: 1

    std::vector<int> stones3 = {3, 1, 1, 3};
    int result3 = sol.lastStoneWeight(stones3);
    std::cout << "For stones {3, 1, 1, 3}, the last stone weight is: " << result3 << std::endl; // Expected: 0

    return 0;
}