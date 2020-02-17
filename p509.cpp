#include "LeetCodeProblem.h"
#include <cassert>

class p509 : public LeetCodeProblem {
    int fib(int N) {
        int a = 1, b = 0;
        for(int i = 0; i < N; i++) {
            auto f = a + b;
            b = a;
            a = f;
        }
        return b;
    }

public:
    void testCase() {
        assert(fib(0) == 0);
        assert(fib(1) == 1);
        assert(fib(2) == 1);
        assert(fib(3) == 2);
        assert(fib(4) == 3);
        assert(fib(5) == 5);
        assert(fib(6) == 8);
    }
};