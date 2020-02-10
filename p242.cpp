#include "LeetCodeProblem.h"
#include "Utility.h"
#include <string>
using namespace std;

class ValidAnagram : public LeetCodeProblem {
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) 
            return false;

        size_t start = (int)'a';
        int size = (int)'z' + 1 - start;
        vector<int> counts(size, 0);

        for (int i = 0; i < s.size(); i++) {
            counts[(int)s[i]- start] += 1;
            counts[(int)t[i]- start] -= 1;
        }
        for (int i = 0; i < size; i++) {
            if(counts[i] != 0) return false;
        }
        return true;
    }

public:
    void testCase() {
        string s = "anagram", 
            t = "nagaram";
        Utility::print(isAnagram(s, t));

        s = "rat";
        t = "car";
        Utility::print(isAnagram(s, t));
    }
};