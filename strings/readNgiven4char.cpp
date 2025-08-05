#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

/**
 * Mock function to simulate reading 4 characters from a file.
 * In a real scenario, this would read from an actual file or input stream.
 */
int read4(char *buf) {
    // This is just a placeholder. In practice, this function would read
    // from a file or input stream and fill buf with up to 4 characters.
    // For example purposes, let's assume it reads "abcd" each time.
    static const char *data = "abcd";
    static int index = 0;
    
    int count = 0;
    while (count < 4 && data[index] != '\0') {
        buf[count++] = data[index++];
    }
    
    return count; // Return the number of characters read
}

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total_read = 0;
        char buf4[4];
        
        while (total_read < n) {
            // Read up to 4 characters from the file.
            int chars_read = read4(buf4);
            
            // If read4 returns 0, it means we've reached the end of the file.
            if (chars_read == 0) {
                break;
            }
            
            // Determine how many characters to copy from buf4 to the destination buffer.
            // We should copy min(characters available in buf4, characters still needed to reach n)
            int chars_to_copy = std::min(chars_read, n - total_read);
            
            // Copy the characters.
            for (int i = 0; i < chars_to_copy; ++i) {
                buf[total_read++] = buf4[i];
            }
            
            // Optimization: if we've read fewer than 4 characters, it means we've
            // reached the end of the file, so we can break early.
            if (chars_read < 4) {
                break;
            }
        }
        
        return total_read;
    }
};

// Example Usage (for testing locally)
int main() {
  Solution sol;
  char buffer[10];
  int bytesRead = sol.read(buffer, 10);
  std::cout << "Bytes read: " << bytesRead << std::endl;
  std::cout << "Buffer content: ";
  for (int i = 0; i < bytesRead; ++i) {
      std::cout << buffer[i];
  }
  std::cout << std::endl;
  return 0;
}