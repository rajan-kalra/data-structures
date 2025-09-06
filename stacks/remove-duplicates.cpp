#include <string>
#include <iostream>

std::string removeDuplicates(std::string s) {
    std::string result = "";
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    std::string s1 = "abbaca";
    std::cout << "Original string: " << s1 << std::endl;
    std::cout << "String with duplicates removed: " << removeDuplicates(s1) << std::endl; // Output: ca

    std::string s2 = "azxxzy";
    std::cout << "Original string: " << s2 << std::endl;
    std::cout << "String with duplicates removed: " << removeDuplicates(s2) << std::endl; // Output: ay

    return 0;
}