#include <iostream>
#include <vector>
#include <queue>
#include <functional> // For std::greater

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};

int main() {
    std::vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);
    
    std::cout << "Initial Kth Largest element: " << kthLargest.add(0) << std::endl; // Adds 0, heap is {4, 5, 8}, top is 4
    std::cout << "Kth Largest element after adding 0: " << kthLargest.add(0) << std::endl;
    std::cout << "Kth Largest element after adding 5: " << kthLargest.add(5) << std::endl; // Adds 5, heap is {5, 5, 8}, top is 5
    std::cout << "Kth Largest element after adding 10: " << kthLargest.add(10) << std::endl; // Adds 10, heap is {5, 8, 10}, top is 5
    std::cout << "Kth Largest element after adding 9: " << kthLargest.add(9) << std::endl;  // Adds 9, heap is {8, 9, 10}, top is 8
    std::cout << "Kth Largest element after adding 4: " << kthLargest.add(4) << std::endl;  // Adds 4, heap is {8, 9, 10}, top is 8

    return 0;
}