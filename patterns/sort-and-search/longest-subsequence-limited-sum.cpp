#include <iostream>
#include <vector>
#include <algorithm>

class Solution1 {
public:
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::vector<int> sorted_nums(nums); // Make a copy
        sort(begin(sorted_nums), end(sorted_nums));
        int m = queries.size();
        std::vector<int> result;
        for (int &query : queries) {
            if (n == 0) {
                result.push_back(0);
                continue;
            }
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += sorted_nums[j];
                if (sum > query) {
                    result.push_back(j);
                    break;
                }
                if (j == n - 1) {
                    result.push_back(n);
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::vector<int> prefix(nums); // Make a copy
        std::sort(prefix.begin(), prefix.end());
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }
        int m = queries.size();
        std::vector<int> result(m);
        for (int i = 0; i < m; i++) {
            auto it = std::upper_bound(prefix.begin(), prefix.end(), queries[i]) - prefix.begin();
            result[i] = it;
        }
        return result;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;

    // Test 1
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> queries1 = {3, 10, 21};
    std::vector<int> result1_1 = sol1.answerQueries(nums1, queries1);
    std::vector<int> result1_2 = sol2.answerQueries(nums1, queries1);

    std::cout << "Test 1:" << std::endl;
    for (int i = 0; i < queries1.size(); i++) {
        std::cout << "Query " << queries1[i] << ": " << result1_1[i] << " (expected: " << result1_2[i] << ")" << std::endl;
    }

    // Test 2: All elements same
    std::vector<int> nums2 = {2, 2, 2, 2};
    std::vector<int> queries2 = {1, 2, 4, 8, 10};
    std::vector<int> result2_1 = sol1.answerQueries(nums2, queries2);
    std::vector<int> result2_2 = sol2.answerQueries(nums2, queries2);

    std::cout << "Test 2:" << std::endl;
    for (int i = 0; i < queries2.size(); i++) {
        std::cout << "Query " << queries2[i] << ": " << result2_1[i] << " (expected: " << result2_2[i] << ")" << std::endl;
    }

    // Test 3: Single element
    std::vector<int> nums3 = {5};
    std::vector<int> queries3 = {1, 5, 10};
    std::vector<int> result3_1 = sol1.answerQueries(nums3, queries3);
    std::vector<int> result3_2 = sol2.answerQueries(nums3, queries3);

    std::cout << "Test 3:" << std::endl;
    for (int i = 0; i < queries3.size(); i++) {
        std::cout << "Query " << queries3[i] << ": " << result3_1[i] << " (expected: " << result3_2[i] << ")" << std::endl;
    }

    // Test 4: Empty nums
    std::vector<int> nums4 = {};
    std::vector<int> queries4 = {1, 2, 3};
    std::vector<int> result4_1 = sol1.answerQueries(nums4, queries4);
    std::vector<int> result4_2 = sol2.answerQueries(nums4, queries4);

    std::cout << "Test 4:" << std::endl;
    for (int i = 0; i < queries4.size(); i++) {
        std::cout << "Query " << queries4[i] << ": " << result4_1[i] << " (expected: " << result4_2[i] << ")" << std::endl;
    }

    // Test 5: Large query
    std::vector<int> nums5 = {1, 2, 3};
    std::vector<int> queries5 = {100};
    std::vector<int> result5_1 = sol1.answerQueries(nums5, queries5);
    std::vector<int> result5_2 = sol2.answerQueries(nums5, queries5);

    std::cout << "Test 5:" << std::endl;
    for (int i = 0; i < queries5.size(); i++) {
        std::cout << "Query " << queries5[i] << ": " << result5_1[i] << " (expected: " << result5_2[i] << ")" << std::endl;
    }

    return 0;
}