#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Create a new matrix with dimensions n x m
        std::vector<std::vector<int>> result(n, std::vector<int>(m));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: 3x3 matrix
    std::vector<std::vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    std::vector<std::vector<int>> transposed1 = sol.transpose(matrix1);
    std::cout << "Test 1: Transposed matrix:" << std::endl;
    for (const auto& row : transposed1) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }

    // Test 2: 2x3 matrix
    std::vector<std::vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> transposed2 = sol.transpose(matrix2);
    std::cout << "Test 2: Transposed matrix:" << std::endl;
    for (const auto& row : transposed2) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }

    // Test 3: 1x4 matrix
    std::vector<std::vector<int>> matrix3 = {
        {7, 8, 9, 10}
    };
    std::vector<std::vector<int>> transposed3 = sol.transpose(matrix3);
    std::cout << "Test 3: Transposed matrix:" << std::endl;
    for (const auto& row : transposed3) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }

    // Test 4: 4x1 matrix
    std::vector<std::vector<int>> matrix4 = {
        {11},
        {12},
        {13},
        {14}
    };
    std::vector<std::vector<int>> transposed4 = sol.transpose(matrix4);
    std::cout << "Test 4: Transposed matrix:" << std::endl;
    for (const auto& row : transposed4) {
        for (int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    return 0;
}