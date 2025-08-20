#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
    // Step 1: Count the frequency of each number
    std::unordered_map<int, int> num_counts;
    for (int num : arr) {
        num_counts[num]++;
    }

    // Step 2: Check if the occurrence counts are unique
    std::unordered_set<int> occurrence_counts;
    for (auto const& pair : num_counts) {
        occurrence_counts.insert(pair.second);
    }
    
    // If the number of distinct elements is equal to the number of unique counts,
    // all counts must be unique.
    return num_counts.size() == occurrence_counts.size();
}

int main() {
    std::vector<int> arr1 = {1, 2, 2, 1, 1, 2};
    std::cout << "Test 1: " << (uniqueOccurrences(arr1) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4};
    std::cout << "Test 2: " << (uniqueOccurrences(arr2) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    std::vector<int> arr3 = {1, 1, 2, 2, 3, 3};
    std::cout << "Test 3: " << (uniqueOccurrences(arr3) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    // Test 4: Unique occurrences
    std::vector<int> arr4 = {1, 2, 2, 3, 3, 3};
    std::cout << "Test 4: " << (uniqueOccurrences(arr4) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;
    // Counts: 1->1, 2->2, 3->3

    // Test 5: Single element
    std::vector<int> arr5 = {42};
    std::cout << "Test 5: " << (uniqueOccurrences(arr5) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    // Test 6: Two elements, same count
    std::vector<int> arr6 = {7, 8};
    std::cout << "Test 6: " << (uniqueOccurrences(arr6) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    // Test 7: Negative numbers
    std::vector<int> arr7 = {-1, -1, -2, -2, -2};
    std::cout << "Test 7: " << (uniqueOccurrences(arr7) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;
    // Counts: -1->2, -2->3

    // Test 8: Empty array
    std::vector<int> arr8 = {};
    std::cout << "Test 8: " << (uniqueOccurrences(arr8) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    return 0;
}