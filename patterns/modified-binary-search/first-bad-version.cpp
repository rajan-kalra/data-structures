#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    bool isBadVersion(int version) {
        // Let's assume the first bad version is 4.
        // This is just a sample implementation for local testing.
        return version >= 4;
    }
    
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int firstBad = n; // Initialize with a possible bad version

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                // 'mid' is a bad version, so it could be the first one.
                // We store it and try to find an earlier bad version.
                firstBad = mid;
                right = mid - 1;
            } else {
                // 'mid' is a good version, so the first bad one must be after 'mid'.
                left = mid + 1;
            }
        }

        return firstBad;
    }
};

int main() {
    Solution sol;
    int n = 5; // Total number of versions
    int result = sol.firstBadVersion(n);
    std::cout << "First bad version: " << result << std::endl;
    return 0;
}