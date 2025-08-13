#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDaysWithoutMeetings(int days, std::vector<std::vector<int>>& meetings) {
        if (meetings.empty()) {
            return days; // No meetings, so all days are free.
        }

        // 1. Sort meetings by start time.
        std::sort(meetings.begin(), meetings.end());

        std::vector<std::vector<int>> merged_meetings;
        merged_meetings.push_back(meetings[0]);

        // 2. Merge overlapping meetings.
        for (size_t i = 1; i < meetings.size(); ++i) {
            std::vector<int>& last_merged = merged_meetings.back();
            const std::vector<int>& current_meeting = meetings[i];

            if (current_meeting[0] <= last_merged[1] + 1) {
                // The meetings overlap or are adjacent, so we merge them.
                last_merged[1] = std::max(last_merged[1], current_meeting[1]);
            } else {
                // The meetings do not overlap, so we add the new one.
                merged_meetings.push_back(current_meeting);
            }
        }

        // 3. Calculate the total duration of merged meetings.
        long long total_meeting_days = 0;
        for (const auto& meeting : merged_meetings) {
            total_meeting_days += (long long)meeting[1] - meeting[0] + 1;
        }

        // 4. Subtract from the total number of days to get the result.
        return days - total_meeting_days;
    }
};

int main() {
    Solution sol;
    int days = 10;
    std::vector<std::vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
    
    int free_days = sol.countDaysWithoutMeetings(days, meetings);
    std::cout << "Number of days without meetings: " << free_days << std::endl;
    // Expected output: 4 (Days 4, 8) -> Wait. No. (1,2,3), (5,6,7), (9,10). That's 3+3+2 = 8 days. So 10-8=2. Wrong.
    // Days: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
    // Meeting 1: [1, 3] -> days 1, 2, 3 (3 days)
    // Meeting 2: [5, 7] -> days 5, 6, 7 (3 days)
    // Meeting 3: [9, 10] -> days 9, 10 (2 days)
    // Total meeting days: 3 + 3 + 2 = 8.
    // Days without meetings: 10 - 8 = 2.
    // Let's take another example.
    
    // Example 2
    int days2 = 10;
    std::vector<std::vector<int>> meetings2 = {{6, 8}, {1, 3}, {2, 5}};
    int free_days2 = sol.countDaysWithoutMeetings(days2, meetings2);
    std::cout << "Number of days without meetings for example 2: " << free_days2 << std::endl;
    // Expected output: 3
    // Meetings: {{1, 3}, {2, 5}, {6, 8}}.
    // Merged: {{1, 5}, {6, 8}}.
    // Merged days: (5-1+1) + (8-6+1) = 5 + 3 = 8.
    // Free days: 10 - 8 = 2. Something is wrong with my example.
    
    // Example 3: `days = 10`, `meetings = {{5, 8}, {1, 3}}`.
    // Sorted: {{1, 3}, {5, 8}}.
    // Total meeting days: (3-1+1) + (8-5+1) = 3 + 4 = 7.
    // Free days: 10 - 7 = 3.
    // Correct! The first example was just poorly calculated by me. 
    // The code logic for merging is correct.
    
    return 0;
}