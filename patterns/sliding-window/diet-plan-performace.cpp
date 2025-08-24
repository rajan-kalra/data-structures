#include <iostream>
#include <vector>

class Solution {
public:
    int dietPlanPerformance(std::vector<int>& calories, int k, int lower, int upper) {
        // Edge case: if the array is smaller than k or k is 0
        if (calories.size() < k || k == 0) {
            return 0;
        }

        int points = 0;
        int current_calories = 0;
        // Calculate the sum for the first window
        for (int i = 0; i < k; ++i) {
            current_calories += calories[i];
        }

        // Evaluate the first window
        if (current_calories < lower) {
            points--;
        } else if (current_calories > upper) {
            points++;
        }

        int startIndex = 0;
        int endIndex = k;
        while (endIndex < calories.size()) {
            current_calories -= calories[startIndex];
            startIndex++;
            current_calories += calories[endIndex];
            endIndex++;

            // Evaluate the current window
            if (current_calories < lower) {
                points--;
            } else if (current_calories > upper) {
                points++;
            }
        }

        return points;
    }
};

int main() {
    Solution sol;

    // Test 1: Basic example
    std::vector<int> calories1 = {2000, 2500, 3000, 1500, 1000};
    int k1 = 3;
    int lower1 = 5000;
    int upper1 = 8000;
    int result1 = sol.dietPlanPerformance(calories1, k1, lower1, upper1);
    std::cout << "Test 1: " << result1 << " (expected: 0)" << std::endl;
    // Windows: [2000,2500,3000]=7500 (0), [2500,3000,1500]=7000 (0), [3000,1500,1000]=5500 (0)

    // Test 2: All windows below lower
    std::vector<int> calories2 = {1000, 1000, 1000, 1000};
    int k2 = 2;
    int lower2 = 3000;
    int upper2 = 5000;
    int result2 = sol.dietPlanPerformance(calories2, k2, lower2, upper2);
    std::cout << "Test 2: " << result2 << " (expected: -3)" << std::endl;
    // Windows: [1000,1000]=2000 (-1), [1000,1000]=2000 (-1), [1000,1000]=2000 (-1)

    // Test 3: All windows above upper
    std::vector<int> calories3 = {5000, 5000, 5000};
    int k3 = 2;
    int lower3 = 2000;
    int upper3 = 8000;
    int result3 = sol.dietPlanPerformance(calories3, k3, lower3, upper3);
    std::cout << "Test 3: " << result3 << " (expected: 2)" << std::endl;
    // Windows: [5000,5000]=10000 (+1), [5000,5000]=10000 (+1)

    // Test 4: All windows within range
    std::vector<int> calories4 = {1500, 2000, 1500, 2000};
    int k4 = 2;
    int lower4 = 3000;
    int upper4 = 4000;
    int result4 = sol.dietPlanPerformance(calories4, k4, lower4, upper4);
    std::cout << "Test 4: " << result4 << " (expected: 0)" << std::endl;
    // Windows: [1500,2000]=3500 (0), [2000,1500]=3500 (0), [1500,2000]=3500 (0)

    // Test 5: Single window (k equals array size)
    std::vector<int> calories5 = {1000, 2000, 3000};
    int k5 = 3;
    int lower5 = 5000;
    int upper5 = 7000;
    int result5 = sol.dietPlanPerformance(calories5, k5, lower5, upper5);
    std::cout << "Test 5: " << result5 << " (expected: 0)" << std::endl;
    // Window: [1000,2000,3000]=6000 (0)

    // Test 6: Mixed results
    std::vector<int> calories6 = {6000, 1000, 1500, 3000, 700};
    int k6 = 2;
    int lower6 = 2000;
    int upper6 = 4000;
    int result6 = sol.dietPlanPerformance(calories6, k6, lower6, upper6);
    std::cout << "Test 6: " << result6 << " (expected: 2)" << std::endl;
    // Windows: [6000,1000]=7000 (+1), [1000,1500]=2500 (0), [1500,3000]=4500 (+1), [3000,700]=3700 (0)

    // Test 7: Edge case - very high calories
    std::vector<int> calories7 = {10000};
    int k7 = 1;
    int lower7 = 2000;
    int upper7 = 5000;
    int result7 = sol.dietPlanPerformance(calories7, k7, lower7, upper7);
    std::cout << "Test 7: " << result7 << " (expected: 1)" << std::endl;
    // Window: [10000]=10000 (+1)

    // Test 8: Edge case - very low calories
    std::vector<int> calories8 = {100, 200};
    int k8 = 1;
    int lower8 = 500;
    int upper8 = 1000;
    int result8 = sol.dietPlanPerformance(calories8, k8, lower8, upper8);
    std::cout << "Test 8: " << result8 << " (expected: -2)" << std::endl;
    // Windows: [100]=100 (-1), [200]=200 (-1)

    return 0;
}