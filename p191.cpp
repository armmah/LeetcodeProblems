#include <cstdint>
#include "LeetCodeProblem.h"
#include "Utility.h"

class p191 : LeetCodeProblem {
    int hammingWeight(uint32_t n) {
        int res = 0;
        // Iterate over all 32 bits,
        for(int k = 0; k < 32; k++)
            // Create a mask at the k-th bit, and check if the bitwise & gives 0 or not.
            res += ((n & (1 << k)) != 0);
        return res;
    }

public:
    void testCase() {
        uint32_t w = 00000000000000000000000000001011;
        Utility::print(hammingWeight(w));
    }
};