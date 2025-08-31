#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        // Step 1: Count word frequencies
        std::unordered_map<std::string, int> freq_map;
        for (const std::string& word : words) {
            freq_map[word]++;
        }

        // Custom comparator for the min-heap
        auto comp = [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
            // If frequencies are the same, sort by word alphabetically (descending)
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            // Otherwise, sort by frequency (ascending)
            return a.first > b.first;
        };

        // Step 2 & 3: Use a min-heap to find the top k
        std::priority_queue<std::pair<int, std::string>, 
                            std::vector<std::pair<int, std::string>>, 
                            decltype(comp)> min_heap(comp);

        for (const auto& pair : freq_map) {
            min_heap.push({pair.second, pair.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Step 4: Extract results from the heap
        std::vector<std::string> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }

        // The result is in reverse order, so we reverse it
        std::reverse(result.begin(), result.end());
        return result;
    }
};

void printVector(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::vector<std::string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    int k1 = 2;
    std::vector<std::string> result1 = sol.topKFrequent(words1, k1);
    std::cout << "Top " << k1 << " frequent words: ";
    printVector(result1); // Expected: ["i", "love"]

    std::vector<std::string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k2 = 4;
    std::vector<std::string> result2 = sol.topKFrequent(words2, k2);
    std::cout << "Top " << k2 << " frequent words: ";
    printVector(result2); // Expected: ["the", "is", "sunny", "day"]
    
    return 0;
}