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
    // Test 1: 3x3 matrix with a zero in the middle
    std::vector<std::vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(matrix1);
    std::cout << "Test 1: Output:" << std::endl;
    for (const auto& row : matrix1) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Expected:\n1 0 1\n0 0 0\n1 0 1\n" << std::endl;

    // Test 2: 2x2 matrix, all zeros
    std::vector<std::vector<int>> matrix2 = {
        {0, 0},
        {0, 0}
    };
    setZeroes(matrix2);
    std::cout << "Test 2: Output:" << std::endl;
    for (const auto& row : matrix2) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Expected:\n0 0\n0 0\n" << std::endl;

    // Test 3: 2x3 matrix, zero in first row
    std::vector<std::vector<int>> matrix3 = {
        {0, 2, 3},
        {4, 5, 6}
    };
    setZeroes(matrix3);
    std::cout << "Test 3: Output:" << std::endl;
    for (const auto& row : matrix3) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Expected:\n0 0 0\n0 5 6\n" << std::endl;

    // Test 4: 1x4 matrix, no zeros
    std::vector<std::vector<int>> matrix4 = {
        {1, 2, 3, 4}
    };
    setZeroes(matrix4);
    std::cout << "Test 4: Output:" << std::endl;
    for (const auto& row : matrix4) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Expected:\n1 2 3 4\n" << std::endl;

    // Test 5: Empty matrix
    std::vector<std::vector<int>> matrix5 = {};
    setZeroes(matrix5);
    std::cout << "Test 5: Output:" << std::endl;
    for (const auto& row : matrix5) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Expected:\n" << std::endl;

    return 0;
}