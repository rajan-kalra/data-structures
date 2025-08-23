#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// Solution 1: Brute force solution
class Solution1 {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        int distanceValue = 0;
        
        for (int num1 : arr1) {
            for (int num2 : arr2) {
                if (std::abs(num1 - num2) <= d) {
                    distanceValue++;
                    break; 
                }
            }
        }
        
        return distanceValue;
    }
};

// Solution 2: Optimized solution using sorting and two pointers for binary search
class Solution2 {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        std::sort(arr2.begin(), arr2.end());

        int distanceValue = 0;

        // Iterate through each element in arr1.
        for (int x : arr1) {
            bool foundMatch = false;

            // Use two pointers on the sorted arr2.
            int low = 0;
            int high = arr2.size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (std::abs(x - arr2[mid]) <= d) {
                    // Found a match, so this element of arr1 doesn't contribute.
                    foundMatch = true;
                    break;
                } else if (arr2[mid] < x) {
                    // The middle element is smaller than x, so search in the right half.
                    low = mid + 1;
                } else {
                    // The middle element is greater than x, so search in the left half.
                    high = mid - 1;
                }
            }

            // If no match was found after binary search, increment the distance value.
            if (!foundMatch) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};

int main() {
    Solution2 sol;
    // Test 1
    std::vector<int> arr1 = {1, 4, 2};
    std::vector<int> arr2 = {3, 6, 3};
    int d = 2;
    int result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 1: The distance value is: " << result << " (expected: 0)" << std::endl;

    // Test 2
    arr1 = {4, 5, 8};
    arr2 = {10, 9, 1, 8};
    d = 2;
    result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 2: The distance value is: " << result << " (expected: 2)" << std::endl;

    // Test 3
    arr1 = {1, 2, 3};
    arr2 = {4, 5, 6};
    d = 3;
    result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 3: The distance value is: " << result << " (expected: 0)" << std::endl;

    // Test 4: Edge case, empty arr2
    arr1 = {1, 2, 3};
    arr2 = {};
    d = 1;
    result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 4: The distance value is: " << result << " (expected: 3)" << std::endl;

    // Test 5: Edge case, empty arr1
    arr1 = {};
    arr2 = {1, 2, 3};
    d = 1;
    result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 5: The distance value is: " << result << " (expected: 0)" << std::endl;
    return 0;
}