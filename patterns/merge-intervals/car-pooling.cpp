#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        // A difference array to track passenger changes at each location.
        // The maximum location is 1000 according to problem constraints.
        std::vector<int> passengers_change(1001, 0);

        // Populate the difference array based on trip start and end locations.
        for (const auto& trip : trips) {
            int num_passengers = trip[0];
            int start_loc = trip[1];
            int end_loc = trip[2];

            passengers_change[start_loc] += num_passengers;
            passengers_change[end_loc] -= num_passengers;
        }

        int current_passengers = 0;
        // Sweep through all locations to calculate the number of passengers at any given point.
        for (int i = 0; i <= 1000; ++i) {
            current_passengers += passengers_change[i];
            if (current_passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> trips1 = {{2, 1, 5}, {3, 3, 7}};
    int capacity1 = 4;
    std::cout << "Can car pool for trips1 with capacity " << capacity1 << "? "
              << (sol.carPooling(trips1, capacity1) ? "true" : "false") << std::endl;
    // Expected output: false (at location 3, passengers = 2 + 3 = 5 > 4)

    std::vector<std::vector<int>> trips2 = {{2, 1, 5}, {3, 3, 7}};
    int capacity2 = 5;
    std::cout << "Can car pool for trips2 with capacity " << capacity2 << "? "
              << (sol.carPooling(trips2, capacity2) ? "true" : "false") << std::endl;
    // Expected output: true (max passengers = 5)

    return 0;
}