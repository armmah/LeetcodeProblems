#include "LeetCodeProblem.h"
#include "Utility.h"
#include <cassert>

class p50 : public LeetCodeProblem {
    double recursePow(double x, int n) {
        if(n == 0)
            return 1;

        // The advantage over simple iterative approach here is that we actually have a O(logn) solution here (each recursion x = x * x).
        return recursePow(x * x, n / 2) * (n % 2 ? x : 1);
    }
    double myPow(double x, int n) {
        // Check some edge cases.
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1 / x;

        // Recursively calculate the pow.
        if (n > 0) {
            return recursePow(x, n);
        }
        else {
            return recursePow(1 / x, n);
        }
    }

public:
    void testCase() {
        Utility::print("Should be 3e-05.");
        Utility::print(myPow(2, 10));

        Utility::print("Should be 0.001.");
        Utility::print(myPow(10, -3));

        assert(myPow(2.0, 1) == 2);
        assert(myPow(2.0, -1) == 0.5);
        
        assert(myPow(2.0, 0) == 1);
        assert(myPow(2.0, 10) == 1024);

        assert(myPow(1, -1) == 1);
        assert(myPow(1, 1) == 1);
    }
};