#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int totalFruit(std::vector<int>& fruits) {
    if (fruits.empty()) {
        return 0;
    }

    std::unordered_map<int, int> fruit_counts;
    int left = 0;
    int max_fruits = 0;

    for (int right = 0; right < fruits.size(); ++right) {
        // Add the current fruit to the window
        fruit_counts[fruits[right]]++;

        // If the number of fruit types exceeds 2, shrink the window from the left
        while (fruit_counts.size() > 2) {
            fruit_counts[fruits[left]]--;
            if (fruit_counts[fruits[left]] == 0) {
                fruit_counts.erase(fruits[left]);
            }
            left++;
        }

        // Update the maximum number of fruits
        max_fruits = std::max(max_fruits, right - left + 1);
    }

    return max_fruits;
}

int main() {
    std::vector<int> fruits = {1, 2, 1, 2, 3};
    int result = totalFruit(fruits);
    std::cout << "Maximum number of fruits: " << result << std::endl;
    return 0;
}