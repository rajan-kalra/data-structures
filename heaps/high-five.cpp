#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional> // For std::greater

class Solution {
public:
    std::vector<std::vector<int>> highFive(std::vector<std::vector<int>>& items) {
        // Map to store student IDs and their top 5 scores (using a min-heap)
        std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> student_scores;

        // Populate the map with top 5 scores for each student
        for (const auto& item : items) {
            int student_id = item[0];
            int score = item[1];
            
            student_scores[student_id].push(score);

            // Ensure the min-heap only contains the top 5 scores
            if (student_scores[student_id].size() > 5) {
                student_scores[student_id].pop();
            }
        }

        std::vector<std::vector<int>> result;

        // Calculate the average of the top 5 scores for each student
        for (const auto& pair : student_scores) {
            int student_id = pair.first;
            auto scores_heap = pair.second;
            int sum = 0;

            while (!scores_heap.empty()) {
                sum += scores_heap.top();
                scores_heap.pop();
            }

            int average = sum / 5;
            result.push_back({student_id, average});
        }

        // Sort the results by student ID
        std::sort(result.begin(), result.end());

        return result;
    }
};

void printResult(const std::vector<std::vector<int>>& result) {
    for (const auto& student : result) {
        std::cout << "[" << student[0] << ", " << student[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    std::vector<std::vector<int>> items = {
        {1, 91}, {1, 92}, {2, 93}, {2, 99}, {2, 84},
        {2, 77}, {1, 60}, {1, 65}, {1, 80}, {1, 85}
    };
    
    std::cout << "Input items: " << std::endl;
    for(const auto& item : items) {
        std::cout << "[" << item[0] << ", " << item[1] << "] ";
    }
    std::cout << "\n\n";

    std::vector<std::vector<int>> result = sol.highFive(items);
    std::cout << "High Five Averages (sorted by ID): ";
    printResult(result);

    return 0;
}