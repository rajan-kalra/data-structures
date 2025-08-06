#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int k_val;

public:
    KthLargest(int k, const std::vector<int>& nums) {
        k_val = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (min_heap.size() < k_val) {
            min_heap.push(val);
        } else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};
  
int main() {
    // Test 1: Start with empty stream, k = 3
    KthLargest kthLargest1(3, std::vector<int>());
    std::cout << "Test 1 (empty init):" << std::endl;
    std::cout << "Adding 3: " << kthLargest1.add(3) << " (expected: 3)" << std::endl;
    std::cout << "Adding 5: " << kthLargest1.add(5) << " (expected: 3)" << std::endl;
    std::cout << "Adding 10: " << kthLargest1.add(10) << " (expected: 3)" << std::endl;
    std::cout << "Adding 9: " << kthLargest1.add(9) << " (expected: 5)" << std::endl;
    std::cout << "Adding 4: " << kthLargest1.add(4) << " (expected: 5)" << std::endl;

    // Test 2: Initialize with values
    KthLargest kthLargest2(2, std::vector<int>{4, 5, 8, 2});
    std::cout << "\nTest 2 (init with {4,5,8,2}, k=2):" << std::endl;
    std::cout << "Adding 3: " << kthLargest2.add(3) << " (expected: 5)" << std::endl;
    std::cout << "Adding 5: " << kthLargest2.add(5) << " (expected: 5)" << std::endl;
    std::cout << "Adding 10: " << kthLargest2.add(10) << " (expected: 8)" << std::endl;
    std::cout << "Adding 9: " << kthLargest2.add(9) << " (expected: 9)" << std::endl;

    // Test 3: k = 1 (always returns max)
    KthLargest kthLargest3(1, std::vector<int>{2, 1});
    std::cout << "\nTest 3 (init with {2,1}, k=1):" << std::endl;
    std::cout << "Adding 3: " << kthLargest3.add(3) << " (expected: 3)" << std::endl;
    std::cout << "Adding 0: " << kthLargest3.add(0) << " (expected: 3)" << std::endl;
    std::cout << "Adding 5: " << kthLargest3.add(5) << " (expected: 5)" << std::endl;

    return 0;
}