#include <iostream>
#include <stack>
using namespace std;

bool isValid (string input) {
    stack<char> s;

    // use this for loop always to iterate through the string
    for (auto c : input) {
    	// if opening bracket, insert into stack
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        /**
         * if closing bracket, check:
         * 1. Stack must not be empty
         * 2. Stack must have corresponding starting bracket to continue
         */
        else {
            // important edge case to remember
            if (s.size() == 0)
                return false;

            char ch = s.top();
            s.pop();
            
            if ((ch == ')' && c == '(') || (ch == ']' && c == '[') || (ch == '}' && c == '{'))
                continue;
            else
                return false;
        }
    }
 
    // edge case, stack must be empty when the input string ends
    return s.empty();
}
 
int main() {
    string s = "()[{}()";
 
    if(isValid(s))
    	cout << "Valid" << endl;
    else
    	cout << "Invalid" << endl;
}