#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        // No meetings, can attend all (none).
        if (intervals.empty()) {
            return true;
        }

        // Sort the intervals based on their start times (intervals[i][0]).
        std::sort(intervals.begin(), intervals.end());

        // Check for overlaps between adjacent intervals.
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i+1][0]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test 1: Overlapping intervals
    std::vector<std::vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    std::cout << "Test 1: " << (sol.canAttendMeetings(intervals1) ? "true" : "false")
              << " (expected: false)" << std::endl;

    // Test 2: No overlap
    std::vector<std::vector<int>> intervals2 = {{7, 10}, {2, 4}};
    std::cout << "Test 2: " << (sol.canAttendMeetings(intervals2) ? "true" : "false")
              << " (expected: true)" << std::endl;

    // Test 3: Single meeting
    std::vector<std::vector<int>> intervals3 = {{1, 5}};
    std::cout << "Test 3: " << (sol.canAttendMeetings(intervals3) ? "true" : "false")
              << " (expected: true)" << std::endl;

    // Test 4: Empty intervals
    std::vector<std::vector<int>> intervals4 = {};
    std::cout << "Test 4: " << (sol.canAttendMeetings(intervals4) ? "true" : "false")
              << " (expected: true)" << std::endl;

    // Test 5: Touching intervals (end == start)
    std::vector<std::vector<int>> intervals5 = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << "Test 5: " << (sol.canAttendMeetings(intervals5) ? "true" : "false")
              << " (expected: true)" << std::endl;

    // Test 6: Overlap at the end
    std::vector<std::vector<int>> intervals6 = {{1, 5}, {4, 6}};
    std::cout << "Test 6: " << (sol.canAttendMeetings(intervals6) ? "true" : "false")
              << " (expected: false)" << std::endl;

    // Test 7: Multiple overlaps
    std::vector<std::vector<int>> intervals7 = {{1, 10}, {2, 6}, {8, 12}};
    std::cout << "Test 7: " << (sol.canAttendMeetings(intervals7) ? "true" : "false")
              << " (expected: false)" << std::endl;

    return 0;
}