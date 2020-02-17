#include "LeetCodeProblem.h"
#include <cassert>

class p70 : public LeetCodeProblem {
    int climbStairs(int n) {
        int a = 1, b = 0;
        for(int i = 0; i < n; i++) {
            auto f = a + b;
            b = a;
            a = f;
        }
        return a;
    }

public:
    void testCase() {
        assert(climbStairs(2) == 2);
        assert(climbStairs(3) == 3);
        assert(climbStairs(4) == 5);
        assert(climbStairs(5) == 8);
    }
};