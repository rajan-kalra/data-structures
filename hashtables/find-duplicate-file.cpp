#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths) {
        std::unordered_map<std::string, std::vector<std::string>> content_to_paths;

        for (const std::string& path : paths) {
            std::stringstream ss(path);
            std::string root_path;
            std::string file_info;
            
            // Extract root path
            getline(ss, root_path, ' ');

            // Process each file in the directory
            while (getline(ss, file_info, ' ')) {
                // Find the content and filename
                size_t open_paren = file_info.find('(');
                std::string filename = file_info.substr(0, open_paren);
                std::string content = file_info.substr(open_paren + 1, file_info.length() - open_paren - 2);

                // Construct full path and store in the map
                content_to_paths[content].push_back(root_path + "/" + filename);
            }
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& pair : content_to_paths) {
            if (pair.second.size() > 1) {
                result.push_back(pair.second);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Basic test
    std::vector<std::string> paths1 = {
        "root/a 1.txt(content1) 2.txt(content2)",
        "root/b 3.txt(content1) 4.txt(content3)",
        "root/c 5.txt(content2) 6.txt(content4)"
    };
    std::vector<std::vector<std::string>> res1 = sol.findDuplicate(paths1);
    std::cout << "Test 1: ";
    for (const auto& group : res1) {
        for (const auto& file : group) {
            std::cout << file << " ";
        }
        std::cout << std::endl;
    }

    // Test 2: No duplicates
    std::vector<std::string> paths2 = {
        "root/a 1.txt(content1)",
        "root/b 2.txt(content2)",
        "root/c 3.txt(content3)"
    };
    std::vector<std::vector<std::string>> res2 = sol.findDuplicate(paths2);
    std::cout << "Test 2: ";
    for (const auto& group : res2) {
        for (const auto& file : group) {
            std::cout << file << " ";
        }
        std::cout << std::endl;
    }

    // Test 3: All duplicates
    std::vector<std::string> paths3 = {
        "root/a 1.txt(content1)",
        "root/b 2.txt(content1)",
        "root/c 3.txt(content1)"
    };
    std::vector<std::vector<std::string>> res3 = sol.findDuplicate(paths3);
    std::cout << "Test 3: ";
    for (const auto& group : res3) {
        for (const auto& file : group) {
            std::cout << file << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}