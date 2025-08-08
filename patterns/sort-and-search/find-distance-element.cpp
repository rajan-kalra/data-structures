#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        int distanceValue = 0;
        
        for (int num1 : arr1) {
            bool foundCloserElement = false;
            for (int num2 : arr2) {
                if (std::abs(num1 - num2) <= d) {
                    foundCloserElement = true;
                    break; 
                }
            }
            if (!foundCloserElement) {
                distanceValue++;
            }
        }
        
        return distanceValue;
    }
};

int main() {
    Solution sol;
    // Test 1
    std::vector<int> arr1 = {1, 4, 2};
    std::vector<int> arr2 = {3, 6, 3};
    int d = 2;
    int result = sol.findTheDistanceValue(arr1, arr2, d);
    std::cout << "Test 1: The distance value is: " << result << " (expected: 1)" << std::endl;

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