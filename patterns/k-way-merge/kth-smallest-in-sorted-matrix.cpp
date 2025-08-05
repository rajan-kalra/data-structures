#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            // Count how many elements are less than or equal to mid
            // We can do this efficiently using a two-pointer approach (from bottom-left)
            int row = n - 1;
            int col = 0;
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += (row + 1);
                    col++;
                } else {
                    row--;
                }
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    std::cout << "The " << k << "th smallest element is: " << sol.kthSmallest(matrix, k) << std::endl;
    return 0;
}