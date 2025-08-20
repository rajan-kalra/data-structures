#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    // Map to hold sorted string as key and list of anagrams as value
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
    
    for (const std::string& s : strs) {
        std::string sorted_s = s;
        std::sort(sorted_s.begin(), sorted_s.end());
        anagramGroups[sorted_s].push_back(s);
    }
    
    std::vector<std::vector<std::string>> result;
    for (const auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    // Test 1: Basic test
    std::vector<std::string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups1 = groupAnagrams(strs1);
    std::cout << "Test 1:" << std::endl;
    for (const auto& group : groups1) {
        for (const auto& word : group) std::cout << word << " ";
        std::cout << std::endl;
    }
    // Expected: Groups like ["eat","tea","ate"], ["tan","nat"], ["bat"] (order may vary)

    // Test 2: All anagrams
    std::vector<std::string> strs2 = {"abc", "bca", "cab"};
    auto groups2 = groupAnagrams(strs2);
    std::cout << "Test 2:" << std::endl;
    for (const auto& group : groups2) {
        for (const auto& word : group) std::cout << word << " ";
        std::cout << std::endl;
    }
    // Expected: One group ["abc", "bca", "cab"]

    // Test 3: No anagrams
    std::vector<std::string> strs3 = {"abc", "def", "ghi"};
    auto groups3 = groupAnagrams(strs3);
    std::cout << "Test 3:" << std::endl;
    for (const auto& group : groups3) {
        for (const auto& word : group) std::cout << word << " ";
        std::cout << std::endl;
    }
    // Expected: Each word in its own group

    // Test 4: Empty input
    std::vector<std::string> strs4 = {};
    auto groups4 = groupAnagrams(strs4);
    std::cout << "Test 4:" << std::endl;
    for (const auto& group : groups4) {
        for (const auto& word : group) std::cout << word << " ";
        std::cout << std::endl;
    }
    // Expected: No output

    // Test 5: Single word
    std::vector<std::string> strs5 = {"solo"};
    auto groups5 = groupAnagrams(strs5);
    std::cout << "Test 5:" << std::endl;
    for (const auto& group : groups5) {
        for (const auto& word : group) std::cout << word << " ";
        std::cout << std::endl;
    }
    // Expected: One group ["solo"]

    return 0;
}