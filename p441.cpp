#include "LeetCodeProblem.h"

class p441 : public LeetCodeProblem {
    int arrangeCoins(int n) {
        // Sk = k / 2 (2 * a + (k - 1)d), where d = 1 and a = 1
        // k (k + 1) = 2 n
        // k ^ 2 + k - 2n = 0
        // D = b ^ 2 - 4ac = 1 - 4 * (-2n) = 1 + 8n
        // 2k = -1 + sqrt(1 + 8n)           negative D is of no consequence to us because the b^2 = 1 and x can't be negative.
        return (sqrt(8 * (long long)n + 1) - 1.0) / 2.0;
    }

    int bruteForce(int n) {
        int c = 0;
        for (int i = 1; ; i += 1) {
            for(int k = 0; k < i; k++) {
                //std::cout<<"[]";
                c ++;
                if(c == n) {
                    //std::cout<<"    "<<(i - 1 + (k == i - 1))<<std::endl<<std::endl;
                    return (i - 1 + (k == i - 1));
                }
            }
            //std::cout<<std::endl;
        }
    }

public:
    void testCase() {
        assert(arrangeCoins(2) == bruteForce(2));
        assert(arrangeCoins(4) == bruteForce(4));
        assert(arrangeCoins(10) == bruteForce(10));
        assert(arrangeCoins(13) == bruteForce(13));
        assert(arrangeCoins(15) == bruteForce(15));
        assert(arrangeCoins(16) == bruteForce(16));
        assert(arrangeCoins(18) == bruteForce(18));
        assert(arrangeCoins(21) == bruteForce(21));
    }
};