#include "LeetCodeProblem.h"
#include <cassert>

class p1137 : public LeetCodeProblem {
    int tribonacci(int n) {
        int a = 1, b = 1, c = 0;
        for(int i = 0; i < n; i++) {
            auto f = a + b + c;
            c = b;
            b = a;
            a = f;
        }
        return c;
    }

public:
    void testCase() {
        assert(tribonacci(0) == 0);
        assert(tribonacci(1) == 1);
        assert(tribonacci(2) == 1);
        assert(tribonacci(3) == 2);
        assert(tribonacci(4) == 4);
        assert(tribonacci(5) == 7);
        assert(tribonacci(6) == 13);
    }
};