#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        // Edge case: No meetings
        if (intervals.empty()) {
            return 0;
        }

        // Separate start and end times vectors
        std::vector<int> starts;
        std::vector<int> ends;

        // Populate start and end times vectors
        for (const auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        // Sort both vectors
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        int rooms = 0;
        int max_rooms = 0;
        int start_ptr = 0;
        int end_ptr = 0;

        while (start_ptr < intervals.size()) {
            // A meeting starts.
            if (starts[start_ptr] < ends[end_ptr]) {
                rooms++;
                start_ptr++;
            } else {
                rooms--;
                end_ptr++;
            }
            max_rooms = std::max(max_rooms, rooms);
        }

        return max_rooms;
    }
};

int main() {
    Solution sol;

    // Test 1: Overlapping intervals
    std::vector<std::vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    std::cout << "Test 1: " << sol.minMeetingRooms(intervals1) << " (expected: 2)" << std::endl;

    // Test 2: No overlap
    std::vector<std::vector<int>> intervals2 = {{7, 10}, {2, 4}};
    std::cout << "Test 2: " << sol.minMeetingRooms(intervals2) << " (expected: 1)" << std::endl;

    // Test 3: Single meeting
    std::vector<std::vector<int>> intervals3 = {{1, 5}};
    std::cout << "Test 3: " << sol.minMeetingRooms(intervals3) << " (expected: 1)" << std::endl;

    // Test 4: Empty intervals
    std::vector<std::vector<int>> intervals4 = {};
    std::cout << "Test 4: " << sol.minMeetingRooms(intervals4) << " (expected: 0)" << std::endl;

    // Test 5: Touching intervals (end == start)
    std::vector<std::vector<int>> intervals5 = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << "Test 5: " << sol.minMeetingRooms(intervals5) << " (expected: 1)" << std::endl;

    // Test 6: Overlap at the end
    std::vector<std::vector<int>> intervals6 = {{1, 5}, {4, 6}};
    std::cout << "Test 6: " << sol.minMeetingRooms(intervals6) << " (expected: 2)" << std::endl;

    // Test 7: Multiple overlaps
    std::vector<std::vector<int>> intervals7 = {{1, 10}, {2, 6}, {8, 12}};
    std::cout << "Test 7: " << sol.minMeetingRooms(intervals7) << " (expected: 2)" << std::endl;
    return 0;
}