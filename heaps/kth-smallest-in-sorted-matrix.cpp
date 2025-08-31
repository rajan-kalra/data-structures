#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        // Get the number of rows
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Min-heap of (value, (row, col))
        using HeapEntry = std::pair<int, std::pair<int, int>>;
        std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>> pq;

        // Push the first element of each row into the heap
        for (int i = 0; i < rows; ++i) {
            pq.push({matrix[i][0], {i, 0}});
        }

        // Extract k-1 times and push the next element from the same row
        for (int i = 0; i < k - 1; ++i) {
            auto [val, rc] = pq.top();
            pq.pop();
            int row = rc.first, col = rc.second;
            if (col + 1 < cols) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return pq.top().first;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> mat1 = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k1 = 8;
    std::cout << "The " << k1 << "th smallest element is: " << sol.kthSmallest(mat1, k1) << std::endl; // Expected: 13
    
    std::vector<std::vector<int>> mat2 = {
        {-5}
    };
    int k2 = 1;
    std::cout << "The " << k2 << "th smallest element is: " << sol.kthSmallest(mat2, k2) << std::endl; // Expected: -5

    return 0;
}