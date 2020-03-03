#include "LeetCodeProblem.h"
#include "Utility.h"

// https://leetcode.com/problems/valid-palindrome-ii/
class p680 : LeetCodeProblem {
    // CPU 98% MEM 100%
    bool isPalindrome(const std::string& s, int i, int k) {
        while (i < k) {
            if(s[i++] != s[k--])
                return false;
        }
        return true;
    }
    bool validPalindrome(std::string s) {
        int i = 0, k = s.size() - 1;
        while (i < k) {
            if (s[i] != s[k]) {
                return isPalindrome(s, i+1, k) || isPalindrome(s, i, k-1);
            }
            ++i;
            --k;
        }
        return true;
    }

public:
    void testCase() {
        auto v = std::string("aa");
        Utility::print_assert(validPalindrome(v), true);

        v = std::string("aba");
        Utility::print_assert(validPalindrome(v), true);

        v = "abca";
        Utility::print_assert(validPalindrome(v), true);
        
        v = "abbca";
        Utility::print_assert(validPalindrome(v), true);

        v = "ebcbbececabbacecbbcbe";
        Utility::print_assert(validPalindrome(v), true);

        v = "abc";
        Utility::print_assert(validPalindrome(v), false);
        
        v = "abcefg";
        Utility::print_assert(validPalindrome(v), false);

        v = "aaaacccc";
        Utility::print_assert(validPalindrome(v), false);
    }
};