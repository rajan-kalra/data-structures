#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        // Step 1: Create a copy and sort it in descending order
        std::vector<int> sorted_score = score;
        std::sort(sorted_score.begin(), sorted_score.end(), std::greater<int>());

        // Step 2: Use a map to store ranks
        std::unordered_map<int, std::string> ranks;
        for (int i = 0; i < sorted_score.size(); ++i) {
            if (i == 0) {
                ranks[sorted_score[i]] = "Gold Medal";
            } else if (i == 1) {
                ranks[sorted_score[i]] = "Silver Medal";
            } else if (i == 2) {
                ranks[sorted_score[i]] = "Bronze Medal";
            } else {
                ranks[sorted_score[i]] = std::to_string(i + 1);
            }
        }

        // Step 3: Populate the result vector based on the original order
        std::vector<std::string> result;
        for (int s : score) {
            result.push_back(ranks[s]);
        }
        return result;
    }
};

void printVector(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::vector<int> scores1 = {5, 4, 3, 2, 1};
    std::vector<std::string> ranks1 = sol.findRelativeRanks(scores1);
    std::cout << "Original scores: [5, 4, 3, 2, 1]" << std::endl;
    std::cout << "Relative Ranks: ";
    printVector(ranks1);

    std::vector<int> scores2 = {10, 3, 8, 9, 4};
    std::vector<std::string> ranks2 = sol.findRelativeRanks(scores2);
    std::cout << "\nOriginal scores: [10, 3, 8, 9, 4]" << std::endl;
    std::cout << "Relative Ranks: ";
    printVector(ranks2);
    
    return 0;
}