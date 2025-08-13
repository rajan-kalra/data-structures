#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> result;
        int i = 0; // Pointer for firstList
        int j = 0; // Pointer for secondList
        int n1 = firstList.size();
        int n2 = secondList.size();

        while (i < n1 && j < n2) {
            // Find the intersection start and end times
            int intersection_start = std::max(firstList[i][0], secondList[j][0]);
            int intersection_end = std::min(firstList[i][1], secondList[j][1]);

            // Check if an intersection exists (start time <= end time)
            if (intersection_start <= intersection_end) {
                result.push_back({intersection_start, intersection_end});
            }

            // Advance the pointer for the interval that ends first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else if (secondList[j][1] < firstList[i][1]) {
                j++;
            } else {
                // If they end at the same time, advance both
                i++;
                j++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> firstList = {{1, 3}, {5, 10}, {15, 18}};
    std::vector<std::vector<int>> secondList = {{2, 6}, {8, 12}, {17, 20}};
    std::vector<std::vector<int>> intersections = sol.intervalIntersection(firstList, secondList);
    std::cout << "Interval Intersections: ";
    for (const auto& interval : intersections) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}