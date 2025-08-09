#include <iostream>
#include <queue>
#include <vector>

/**
 * Using auxiliary arrays to mark rows and columns
 * Time complexity: O(m * n)
 * Space complexity: O(m + n)
 */
void setZeroes(std::vector<std::vector<int>>& matrix) {
    int noOfRows = matrix.size();
    if (noOfRows == 0) {
        return;
    }
    int noOfCols = matrix[0].size();

    std::vector<bool> row(noOfRows, false);
    std::vector<bool> col(noOfCols, false);

    for (int i = 0; i < noOfRows; ++i) {
        for (int j = 0; j < noOfCols; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < noOfRows; ++i) {
        for (int j = 0; j < noOfCols; ++j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(matrix);

    // Print the modified matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}