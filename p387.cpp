#include "LeetCodeProblem.h"
#include <unordered_map>
#include <cassert>

class p387 : public LeetCodeProblem {
	
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            map[s[i]] ++;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(map[s[i]] == 1)
                return i;
        }
        return -1;
    }

public:
	void testCase() {
        std::string s = "leetcode";
        assert(firstUniqChar(s) == 0);

        s = "loveleetcode";
        assert(firstUniqChar(s) == 2);
	}
};
