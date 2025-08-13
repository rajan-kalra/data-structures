#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort intervals by start time ascending.
        // If start times are equal, sort by end time descending.
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int count = 0;
        int last_end = -1;

        for (const auto& interval : intervals) {
            int current_end = interval[1];

            // If the current interval's end is greater than the last uncovered interval's end,
            // it means it's not covered by a previous interval.
            if (current_end > last_end) {
                count++;
                last_end = current_end;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    int result = sol.removeCoveredIntervals(intervals);
    std::cout << "Number of non-covered intervals: " << result << std::endl;
    // Expected output: 2 (Intervals [1, 4] and [2, 8] remain, as [3, 6] is covered by [2, 8])

    std::vector<std::vector<int>> intervals2 = {{1, 4}, {2, 3}};
    result = sol.removeCoveredIntervals(intervals2);
    std::cout << "Number of non-covered intervals: " << result << std::endl;
    // Expected output: 1 (Interval [2, 3] is covered by [1, 4])

    return 0;
}