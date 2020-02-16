#include "LeetCodeProblem.h"
#include <unordered_set>
#include <cassert>

class p202 : LeetCodeProblem {
    int squareSumOfDigits(int num) {
        auto res = 0;
        while(num > 0) {
            // Calculate the sum of (digits squared).
            auto newNum = num / 10;
            auto digit = num - newNum * 10;
            res += digit * digit;
            // Remove the digit from the original number.
            num = newNum;
        }
        // Return the sum.
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while(set.count(n) == 0) {
            // The number is 'happy' we have our answer.
            if(n == 1)
                return true;

            // Remember this number so we dont end up in an endless loop.
            set.insert(n);
            // Recurse further.
            n = squareSumOfDigits(n);
        }
        return false;
    }

public:
    void testCase() {
        // should be true
        assert(isHappy(19));
    }
};