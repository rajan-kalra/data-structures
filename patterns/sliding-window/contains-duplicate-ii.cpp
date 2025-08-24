#include <iostream>
#include <vector>
#include <unordered_map>

// Solution using a hash map
class Solution1 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> seen_indices;

        for (int i = 0; i < nums.size(); ++i) {
            int current_num = nums[i];

            // Check if the current number is already in the map.
            if (seen_indices.count(current_num)) {
                // If it exists, get its last seen index.
                int last_index = seen_indices[current_num];
                
                // Check if the distance is at most k.
                if (i - last_index <= k) {
                    return true;
                }
            }

            // Update or insert the current number's index.
            seen_indices[current_num] = i;
        }

        // No duplicates found within the distance k.
        return false;
    }
};

/*
 * Very important approach to learn, using unordered_set
 * to maintain a sliding window of size k.
 */
// Solution using a sliding window
class Solution2 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is already in the set, it's a duplicate within the window.
            if (window.count(nums[i])) {
                return true;
            }
            
            // Add the current element to the set.
            window.insert(nums[i]);
            
            // If the window size exceeds k, remove the oldest element.
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;

    std::vector<int> testArray = {1, 2, 3, 4, 5};
    int k = 2;

    // Test Solution1
    bool result1 = sol1.containsNearbyDuplicate(testArray, k);
    std::cout << "Solution1: " << (result1 ? "Contains Duplicate" : "No Duplicate") << std::endl;

    // Test Solution2
    bool result2 = sol2.containsNearbyDuplicate(testArray, k);
    std::cout << "Solution2: " << (result2 ? "Contains Duplicate" : "No Duplicate") << std::endl;

    return 0;
}