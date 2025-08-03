#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
  int numUniqueEmails(const std::vector<std::string>& emails) {
    // unordered_set to store unique normalized email addresses
    std::unordered_set<std::string> unique_normalized_emails;

    for (const std::string& email : emails) {
        std::string local_name = "";
        std::string domain_name = "";

        // Split the email into local and domain parts
        // The local part is before the '@' and the domain part is after it
        if (email.find('@') == std::string::npos) {
            continue; // Skip invalid emails without '@'
        }
        local_name = email.substr(0, email.find('@'));
        domain_name = email.substr(email.find('@') + 1);

        // Normalize the local name by removing dots and everything after a plus sign
        local_name.erase(std::remove(local_name.begin(), local_name.end(), '.'), local_name.end());
        local_name = local_name.substr(0, local_name.find('+'));

        // Combine the normalized local name with the domain name
        std::string normalized_email = local_name + "@" + domain_name;

        // Insert the normalized email into the set
        unique_normalized_emails.insert(normalized_email);
    }

    return unique_normalized_emails.size();
  }
};

// Example Usage (for testing locally)
int main() {
  Solution sol;
  std::vector<std::string> emails1 = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
  std::cout << "Number of unique emails for emails1: " << sol.numUniqueEmails(emails1) << std::endl; // Expected output: 2

  std::vector<std::string> emails2 = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
  std::cout << "Number of unique emails for emails2: " << sol.numUniqueEmails(emails2) << std::endl; // Expected output: 3

  std::vector<std::string> emails3 = {"test.email@leetcode.com","test.email+alex@leetcode.com"};
  std::cout << "Number of unique emails for emails3: " << sol.numUniqueEmails(emails3) << std::endl; // Expected output: 1
    
    return 0;
}