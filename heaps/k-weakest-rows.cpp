#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::vector<std::pair<int, int>> row_strengths;
        
        // Step 1: Calculate strength and store pairs
        for (int i = 0; i < mat.size(); ++i) {
            int strength = 0;
            for (int soldier : mat[i]) {
                if (soldier == 1) {
                    strength++;
                } else {
                    break; // Since rows are sorted, we can stop early
                }
            }
            row_strengths.push_back({strength, i});
        }
        
        // Step 2: Sort the pairs
        std::sort(row_strengths.begin(), row_strengths.end());
        
        // Step 3: Extract the k weakest
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(row_strengths[i].second);
        }
        
        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::vector<std::vector<int>> mat1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k1 = 3;
    std::vector<int> result1 = sol.kWeakestRows(mat1, k1);
    std::cout << "For k=3, the weakest rows are: ";
    printVector(result1); // Expected output: [2, 0, 3]

    std::vector<std::vector<int>> mat2 = {
        {1, 0},
        {1, 0},
        {1, 0},
        {1, 1}
    };
    int k2 = 2;
    std::vector<int> result2 = sol.kWeakestRows(mat2, k2);
    std::cout << "For k=2, the weakest rows are: ";
    printVector(result2); // Expected output: [0, 1]

    return 0;
}