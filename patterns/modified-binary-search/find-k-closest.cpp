#include <iostream>
#include <queue>
#include <vector>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // Find the index of the element closest to x using binary search
        auto it = std::lower_bound(arr.begin(), arr.end(), x);
        int right = it - arr.begin();
        int left = right - 1;

        // Use two pointers to find the k closest elements
        while (right - left - 1 < k) {
            // Case 1: Left pointer is out of bounds
            if (left < 0) {
                right++;
                continue;
            }
            // Case 2: Right pointer is out of bounds
            if (right >= n) {
                left--;
                continue;
            }
            
            // Compare the distances and move the appropriate pointer
            if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        
        // The k closest elements are from index left + 1 to right - 1
        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    Solution obj;
    std::vector<int> result = obj.findClosestElements(arr, k, x);
    std::cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}