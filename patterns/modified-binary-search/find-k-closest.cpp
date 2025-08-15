#include <iostream>
#include <queue>
#include <vector>
#include <vector>
#include <cmath>
#include <algorithm>

// solution using min-heap
class Solution1 {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        // Use a min-heap to store pairs of {distance, value}
        std::priority_queue<std::pair<int, int>
        , std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

        for (int num : arr) {
            min_heap.push({std::abs(num - x), num});
        }

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};

// solution using binary search
class Solution2 {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - k;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) {
                // arr[mid] is closer to x or equally close and smaller.
                // The optimal window could start at or before mid.
                right = mid;
            } else {
                // arr[mid + k] is closer to x.
                // The optimal window must start after mid.
                left = mid + 1;
            }
        }

        // 'left' is now the starting index of the k closest elements.
        return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution1 obj;

    // Test 1: Basic test
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 4, x1 = 3;
    std::vector<int> result1 = obj.findClosestElements(arr1, k1, x1);
    std::cout << "Test 1: ";
    for (int num : result1) std::cout << num << " ";
    std::cout << "(expected: 1 2 3 4)" << std::endl;

    // Test 2: x smaller than all elements
    std::vector<int> arr2 = {10, 20, 30, 40, 50};
    int k2 = 2, x2 = 5;
    std::vector<int> result2 = obj.findClosestElements(arr2, k2, x2);
    std::cout << "Test 2: ";
    for (int num : result2) std::cout << num << " ";
    std::cout << "(expected: 10 20)" << std::endl;

    // Test 3: x larger than all elements
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int k3 = 3, x3 = 10;
    std::vector<int> result3 = obj.findClosestElements(arr3, k3, x3);
    std::cout << "Test 3: ";
    for (int num : result3) std::cout << num << " ";
    std::cout << "(expected: 3 4 5)" << std::endl;

    // Test 4: k equals array size
    std::vector<int> arr4 = {2, 4, 6, 8};
    int k4 = 4, x4 = 5;
    std::vector<int> result4 = obj.findClosestElements(arr4, k4, x4);
    std::cout << "Test 4: ";
    for (int num : result4) std::cout << num << " ";
    std::cout << "(expected: 2 4 6 8)" << std::endl;

    // Test 5: x is exactly in the array
    std::vector<int> arr5 = {1, 3, 5, 7, 9};
    int k5 = 2, x5 = 5;
    std::vector<int> result5 = obj.findClosestElements(arr5, k5, x5);
    std::cout << "Test 5: ";
    for (int num : result5) std::cout << num << " ";
    std::cout << "(expected: 3 5)" << std::endl;

    return 0;
}