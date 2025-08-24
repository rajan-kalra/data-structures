#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // 1. Sort the intervals based on the start time.
        std::sort(intervals.begin(), intervals.end());

        // 2. Initialize with the first interval.
        std::vector<std::vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);

        // 3. Iterate through the remaining intervals to merge.
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int>& last_merged = merged_intervals.back();
            std::vector<int>& current = intervals[i];

            // Check for overlap: If the start of the current interval is <= the end of the last merged one.
            if (current[0] <= last_merged[1]) {
                // Overlap: Update the end of the last merged interval.
                last_merged[1] = std::max(last_merged[1], current[1]);
            } else {
                // No overlap: Add the current interval as a new one.
                merged_intervals.push_back(current);
            }
        }
        
        return merged_intervals;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> merged = sol.merge(intervals);
    std::cout << "Merged intervals: ";
    for (const auto& interval : merged) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;
    return 0;
}