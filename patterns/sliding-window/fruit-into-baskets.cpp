#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int totalFruit(std::vector<int>& fruits) {
    if (fruits.empty()) {
        return 0;
    }

    // Map of <fruit, count> to count the number of each fruit in the current window
    std::unordered_map<int, int> fruit_counts;

    int startIndex = 0;
    int endIndex = 0;
    int max_fruits = 0;

    while (endIndex < fruits.size()) {
        // Add the current fruit to the window
        fruit_counts[fruits[endIndex]]++;
        endIndex++;

        // If the number of fruit types exceeds 2, shrink the window from the left
        while (fruit_counts.size() > 2) {
            fruit_counts[fruits[startIndex]]--;

            // If the count of the fruit at startIndex becomes 0, remove it from the map
            if (fruit_counts[fruits[startIndex]] == 0) {
                fruit_counts.erase(fruits[startIndex]);
            }
            startIndex++;
        }

        // Update the maximum number of fruits
        max_fruits = std::max(max_fruits, endIndex - startIndex);
    }

    return max_fruits;
}

int main() {
    // Test 1: Basic test
    std::vector<int> fruits1 = {1, 2, 1, 2, 3};
    int result1 = totalFruit(fruits1);
    std::cout << "Test 1: " << result1 << " (expected: 4)" << std::endl;
    // [1,2,1,2] is the longest window with at most 2 types

    // Test 2: All same fruit
    std::vector<int> fruits2 = {5, 5, 5, 5};
    int result2 = totalFruit(fruits2);
    std::cout << "Test 2: " << result2 << " (expected: 4)" << std::endl;

    // Test 3: Alternating fruits
    std::vector<int> fruits3 = {1, 2, 1, 2, 1, 2};
    int result3 = totalFruit(fruits3);
    std::cout << "Test 3: " << result3 << " (expected: 6)" << std::endl;

    // Test 4: Three types, longest at the end
    std::vector<int> fruits4 = {1, 2, 3, 2, 2};
    int result4 = totalFruit(fruits4);
    std::cout << "Test 4: " << result4 << " (expected: 4)" << std::endl;
    // [2,3,2,2]

    // Test 5: Only two types
    std::vector<int> fruits5 = {0, 1, 0, 1, 0, 1, 0};
    int result5 = totalFruit(fruits5);
    std::cout << "Test 5: " << result5 << " (expected: 7)" << std::endl;

    // Test 6: Empty input
    std::vector<int> fruits6 = {};
    int result6 = totalFruit(fruits6);
    std::cout << "Test 6: " << result6 << " (expected: 0)" << std::endl;

    // Test 7: Single fruit
    std::vector<int> fruits7 = {42};
    int result7 = totalFruit(fruits7);
    std::cout << "Test 7: " << result7 << " (expected: 1)" << std::endl;

    // Test 8: Three types, longest at the start
    std::vector<int> fruits8 = {1, 1, 2, 2, 3, 3, 3};
    int result8 = totalFruit(fruits8);
    std::cout << "Test 8: " << result8 << " (expected: 5)" << std::endl;
    // [2,2,3,3,3]
    return 0;
}