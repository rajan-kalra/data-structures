#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution1 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int num : nums) {
            // Check if we've seen this number before.
            if (seen.count(num)) {
                // If the element is already in the set, we've found a duplicate.
                return true;
            }
            // If not, add the current element to the set.
            seen.insert(num);
        }

        // If we finish the loop without returning, there were no duplicates.
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Sort the array in-place.
        std::sort(nums.begin(), nums.end());

        // Check for adjacent duplicates.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;

    std::vector<int> testArray = {1, 2, 3, 4, 5};

    // Test Solution1
    bool result1 = sol1.containsDuplicate(testArray);
    std::cout << "Solution1: " << (result1 ? "Contains Duplicate" : "No Duplicate") << std::endl;

    // Test Solution2
    bool result2 = sol2.containsDuplicate(testArray);
    std::cout << "Solution2: " << (result2 ? "Contains Duplicate" : "No Duplicate") << std::endl;

    return 0;
}