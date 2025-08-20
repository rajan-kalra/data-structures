#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string rankTeams(std::vector<std::string>& votes) {
    // Check for empty input
    if (votes.empty()) {
        return "";
    }

    int num_teams = votes[0].length();
    
    // counts[i][j] stores the number of times team 'A'+i got rank j
    std::vector<std::vector<int>> counts(26, std::vector<int>(num_teams, 0));

    // First, count all votes
    for (const std::string& vote : votes) {
        for (int i = 0; i < num_teams; ++i) {
            counts[vote[i] - 'A'][i]++;
        }
    }
    
    // Get the list of unique teams from the first vote string
    std::vector<char> teams;
    for (char c : votes[0]) {
        teams.push_back(c);
    }

    // Sort the teams with a custom comparator
    std::sort(teams.begin(), teams.end(), [&](char a, char b) {
        // Compare vote counts at each rank
        for (int i = 0; i < num_teams; ++i) {
            if (counts[a - 'A'][i] != counts[b - 'A'][i]) {
                // Higher count at a better rank wins
                return counts[a - 'A'][i] > counts[b - 'A'][i];
            }
        }
        // If all vote counts are the same, sort alphabetically
        return a < b;
    });
    
    // Construct the final ranked string
    std::string result = "";
    for (char team : teams) {
        result += team;
    }
    
    return result;
}

int main() {
    std::vector<std::string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    std::string result = rankTeams(votes);
    std::cout << "Ranked teams: " << result << std::endl;

    return 0;
}