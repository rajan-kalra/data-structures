#include <iostream>
#include <queue>
#include <vector>

/*
 * Time complexity: O(n * m), where n is the number of rows and m is the number of columns in the grid.
 */
class Solution1 {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Add 4 for each land cell
                    perimeter += 4;

                    // Subtract 2 for each shared edge
                    if (i > 0 && grid[i-1][j] == 1) {
                        perimeter -= 2;
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
    }
};

/*
 * DFS approach
 */
class Solution2 {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Start DFS from the first land cell found
                    return dfs(grid, i, j, rows, cols);
                }
            }
        }
        return 0;
    }

private:
    int dfs(std::vector<std::vector<int>>& grid, int r, int c, int rows, int cols) {
        // Base case: out of bounds or water cell
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 1;
        }

        // Base case: already visited land cell
        if (grid[r][c] == -1) {
            return 0;
        }

        // Mark the current land cell as visited to avoid cycles
        grid[r][c] = -1;

        // Recursively call DFS for all four directions and sum the results
        int perimeter = 0;
        perimeter += dfs(grid, r + 1, c, rows, cols); // Down
        perimeter += dfs(grid, r - 1, c, rows, cols); // Up
        perimeter += dfs(grid, r, c + 1, rows, cols); // Right
        perimeter += dfs(grid, r, c - 1, rows, cols); // Left

        return perimeter;
    }
};

int main() {
    Solution1 sol1;
    std::vector<std::vector<int>> grid1 = {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    int perimeter1 = sol1.islandPerimeter(grid1);
    std::cout << "Island perimeter (Solution1): " << perimeter1 << std::endl;

    Solution2 sol2;
    std::vector<std::vector<int>> grid2 = {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    int perimeter2 = sol2.islandPerimeter(grid2);
    std::cout << "Island perimeter (Solution2): " << perimeter2 << std::endl;

    return 0;
}