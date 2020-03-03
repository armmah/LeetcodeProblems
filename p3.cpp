#include "LeetCodeProblem.h"
#include "Utility.h"
#include <unordered_map>
#include <algorithm>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class p3 : public LeetCodeProblem {
    // CPU 65%, MEM 74%
    int lengthOfLongestSubstring(std::string s) {
        int l = 0;
        std::unordered_map<char, int> map;
        auto res = 0;
        for(int r = 0; r < s.size(); r++) {
            while(map[s[r]] > 0) {
                map[s[l++]]--;
            }
            res = std::max(res, r - l + 1);
            map[s[r]]++;
        }
        return res;
    }

public:
    void testCase() {
        Utility::print_assert(lengthOfLongestSubstring(""), 0);
        Utility::print_assert(lengthOfLongestSubstring(" "), 1);
        Utility::print_assert(lengthOfLongestSubstring("abcabcbb"), 3);
        Utility::print_assert(lengthOfLongestSubstring("bbbbb"), 1);
        Utility::print_assert(lengthOfLongestSubstring("pwwkew"), 3);
    }
};