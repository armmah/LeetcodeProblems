#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <string>

// https://leetcode.com/problems/longest-common-prefix/
class p14 : LeetCodeProblem {
    // CPU 96% MEM 100%
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
            
        std::string prefix = "";
        int i = 0;
        while(true) {
            auto c = strs[0][i];
            for(int k = 1; k < strs.size(); k++) {
                if(strs[k].size() <= i || c != strs[k][i])
                    return prefix;                
            }
            prefix += c;
            ++i;
        }    
    }

public:
    void testCase() {
        auto strs = std::vector<std::string> { "flower","flow","flight" };
        auto res = std::string("fl");
        Utility::print_assert(longestCommonPrefix(strs), res);

        strs = { "dog","racecar","car" };
        res = std::string("");
        Utility::print_assert(longestCommonPrefix(strs), res);
    }
};