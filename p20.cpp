#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <string>

// https://leetcode.com/problems/valid-parentheses/
class p20 {
    // CPU 100% MEM 100%
    bool isValid(std::string s) {
        std::vector<char> stack;
        for(auto ch : s) {
            // Opening parenthesis.
            if(ch == '(' || ch == '[' || ch == '{')
                stack.push_back(ch);
            // Closing
            else {
                // Stack is empty (closing without opening)
                if(stack.size() == 0)
                    return false;
                
                // Check if opening and closing do match.
                auto pair = stack.back();
                if(abs(ch - pair) > 2)
                    return false;

                // Look for the rest.
                stack.pop_back();
            }
        }
        // If no parenthesis remains in the stack => valid.
        return stack.size() == 0;
    }

public:
    void testCase() {
        Utility::print_assert(isValid("{{)}"), false);
    }
};