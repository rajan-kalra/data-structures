#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::stack<int> s;
        std::unordered_map<int, int> nextGreater;

        for (int num : nums2) {
            // While the stack is not empty and the current number is greater than the top of the stack
            while (!s.empty() && num > s.top()) {
                // The current number is the next greater element for the top of the stack
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // The remaining elements in the stack have no next greater element
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }

        std::vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Basic test
    std::vector<int> nums1_1 = {4, 1, 2};
    std::vector<int> nums2_1 = {1, 3, 4, 2};
    std::vector<int> res1 = sol.nextGreaterElement(nums1_1, nums2_1);
    std::cout << "Test 1: ";
    for (int n : res1) std::cout << n << " ";
    std::cout << "(expected: -1 3 -1)" << std::endl;

    // Test 2: All elements have next greater
    std::vector<int> nums1_2 = {2, 4};
    std::vector<int> nums2_2 = {1, 2, 3, 4};
    std::vector<int> res2 = sol.nextGreaterElement(nums1_2, nums2_2);
    std::cout << "Test 2: ";
    for (int n : res2) std::cout << n << " ";
    std::cout << "(expected: 3 -1)" << std::endl;

    // Test 3: No next greater for any
    std::vector<int> nums1_3 = {6, 5, 4};
    std::vector<int> nums2_3 = {6, 5, 4};
    std::vector<int> res3 = sol.nextGreaterElement(nums1_3, nums2_3);
    std::cout << "Test 3: ";
    for (int n : res3) std::cout << n << " ";
    std::cout << "(expected: -1 -1 -1)" << std::endl;

    // Test 4: nums1 is a subset of nums2
    std::vector<int> nums1_4 = {1, 2};
    std::vector<int> nums2_4 = {1, 2, 3};
    std::vector<int> res4 = sol.nextGreaterElement(nums1_4, nums2_4);
    std::cout << "Test 4: ";
    for (int n : res4) std::cout << n << " ";
    std::cout << "(expected: 2 3)" << std::endl;

    // Test 5: Single element
    std::vector<int> nums1_5 = {42};
    std::vector<int> nums2_5 = {42};
    std::vector<int> res5 = sol.nextGreaterElement(nums1_5, nums2_5);
    std::cout << "Test 5: ";
    for (int n : res5) std::cout << n << " ";
    std::cout << "(expected: -1)" << std::endl;

    return 0;
}