#include <iostream>
#include <string>
#include <vector>
#include <set>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> uniqueNums;
        for (int num : nums) {
            uniqueNums.insert(num);
        }

        if (uniqueNums.size() < 3) {
            return *uniqueNums.rbegin(); // Return the largest element
        }

        // The third maximum is the third-to-last element
        auto it = uniqueNums.rbegin();
        std::advance(it, 2);
        return *it;
    }
};
  
int main() {
    Solution solution;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int output = solution.thirdMax(nums);
    std::cout << "Third maximum number: " << output << std::endl;
    return 0;
}