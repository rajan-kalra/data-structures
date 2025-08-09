#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        // vector to store the result
        std::vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while (top <= bottom && left <= right) {
            // Traverse right
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // Traverse down
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: 3x3 matrix
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<int> result1 = sol.spiralOrder(matrix1);
    std::cout << "Test 1: ";
    for (int val : result1) std::cout << val << " ";
    std::cout << "(expected: 1 2 3 6 9 8 7 4 5)" << std::endl;

    // Test 2: 4x4 matrix
    std::vector<std::vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    std::vector<int> result2 = sol.spiralOrder(matrix2);
    std::cout << "Test 2: ";
    for (int val : result2) std::cout << val << " ";
    std::cout << "(expected: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10)" << std::endl;

    // Test 3: 1x4 matrix
    std::vector<std::vector<int>> matrix3 = {
        {1, 2, 3, 4}
    };
    std::vector<int> result3 = sol.spiralOrder(matrix3);
    std::cout << "Test 3: ";
    for (int val : result3) std::cout << val << " ";
    std::cout << "(expected: 1 2 3 4)" << std::endl;

    // Test 4: 4x1 matrix
    std::vector<std::vector<int>> matrix4 = {
        {1},
        {2},
        {3},
        {4}
    };
    std::vector<int> result4 = sol.spiralOrder(matrix4);
    std::cout << "Test 4: ";
    for (int val : result4) std::cout << val << " ";
    std::cout << "(expected: 1 2 3 4)" << std::endl;

    // Test 5: Empty matrix
    std::vector<std::vector<int>> matrix5 = {};
    std::vector<int> result5 = sol.spiralOrder(matrix5);
    std::cout << "Test 5: ";
    for (int val : result5) std::cout << val << " ";
    std::cout << "(expected: )" << std::endl;
    return 0;
}