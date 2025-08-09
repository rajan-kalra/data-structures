#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            int low = 0, high = cols - 1;
            int firstNonNegativeIndex = cols;

            // Binary search for the first non-negative number in the current row
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (grid[i][mid] >= 0) {
                    // This could be the first non-negative number, or it's to the left
                    firstNonNegativeIndex = mid;
                    high = mid - 1;
                } else {
                    // The first non-negative number is to the right
                    low = mid + 1;
                }
            }
            // Add the number of negative elements in the current row to the total count
            count += (cols - firstNonNegativeIndex);
        }

        return count;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, -1},
        {4, 5, -2, -3},
        {-1, -2, -3, -4}
    };
    int count = sol.countNegatives(matrix);
    std::cout << "Count of negative numbers: " << count << std::endl;

    return 0;
}