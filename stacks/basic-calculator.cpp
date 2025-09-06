#include <iostream>
#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    int calculate(std::string s) {
        // The main result of the calculation
        int result = 0;

        // The sign of the current number (1 for positive, -1 for negative)
        int sign = 1;
        
        // Stack to store the results and signs of outer expressions
        std::stack<int> signs;
        signs.push(1); // Push an initial positive sign for the outermost expression

        // Iterate through each character of the string
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // If the character is a digit, we need to parse the full number
            if (isdigit(c)) {
                long long currentNumber = 0;
                // Read the full multi-digit number
                while (i < s.length() && isdigit(s[i])) {
                    currentNumber = currentNumber * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Decrement i to correctly handle the loop's increment
                
                // Add the number to the result, applying the current sign
                result += sign * currentNumber;

            // If the character is a '+', we set the sign to positive
            } else if (c == '+') {
                // Update the current sign based on the sign of the current scope
                sign = signs.top();
            
            // If the character is a '-', we set the sign to negative
            } else if (c == '-') {
                // Update the current sign based on the sign of the current scope
                sign = -signs.top();

            } else if (c == '(') {
                // When we see an opening parenthesis, we save the sign of the current scope.
                // We're about to start a new sub-expression.
                signs.push(sign);

            } else if (c == ')') {
                // When we see a closing parenthesis, we've finished the sub-expression.
                // We pop the sign that was pushed when we saw the matching '('.
                signs.pop();
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    std::string test1 = "1 + 1";
    std::cout << "Expression: " << test1 << " -> Result: " << s.calculate(test1) << std::endl;

    std::string test2 = " 2-1 + 2 ";
    std::cout << "Expression: " << test2 << " -> Result: " << s.calculate(test2) << std::endl;

    std::string test3 = "(1+(4+5+2)-3)+(6+8)";
    std::cout << "Expression: " << test3 << " -> Result: " << s.calculate(test3) << std::endl;

    std::string test4 = "- (3 + (4 + 5))";
    std::cout << "Expression: " << test4 << " -> Result: " << s.calculate(test4) << std::endl;

    return 0;
}
