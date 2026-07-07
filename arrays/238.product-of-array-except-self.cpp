#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelfWithoutSpace(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);
        
        // Step 1: Calculate prefix products and store them in answer
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // Step 2: Calculate suffix products on the fly and multiply with prefix
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }

    std::vector<int> productExceptSelfWithSpace(std::vector<int>& nums) {
        int n = nums.size();
        
        // Create explicit prefix and suffix arrays
        std::vector<int> prefix(n, 1);
        std::vector<int> suffix(n, 1);
        std::vector<int> answer(n, 1);
        
        // Fill the prefix array
        // prefix[i] contains the product of all numbers to the left of i
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        
        // Fill the suffix array
        // suffix[i] contains the product of all numbers to the right of i
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        
        // Construct the final answer array
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix[i] * suffix[i];
        }
        
        return answer;
    }
};

// Helper function to print the vectors
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;
    
    // Example test case
    std::vector<int> nums = {1, 2, 3, 4};
    
    std::cout << "Input array:  ";
    printVector(nums);
    
    // Call the productExceptSelfWithoutSpace function
    std::vector<int> resultWithoutSpace = solution.productExceptSelfWithoutSpace(nums);
    std::vector<int> resultWithSpace = solution.productExceptSelfWithSpace(nums);
    
    std::cout << "Output array (without extra space): ";
    printVector(resultWithoutSpace);
    std::cout << "Output array (with extra space): ";
    printVector(resultWithSpace);
    
    return 0;
}