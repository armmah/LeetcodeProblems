#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
using namespace std;

// 8ms - 98.51% CPU, 9.7MB - 62.50% RAM
class SingleNumberII : LeetCodeProblem {
    static int singleNumber(vector<int>& nums) {
        auto allBits = new int[32];
        for(int i = 0; i < 32; i++)
            allBits[i] = 0;

        for (int n : nums) {
            for (int i = 0; i < 32; i++) {
                allBits[i] += (n & (1 << i)) != 0;
            }
        }

        auto result = 0;
        for (int i = 0; i < 32; i++) {
            result |= (allBits[i] % 3) << i;
        }
        delete[] allBits;
        return result;
    }

public:
    void testCase() {
        auto arr = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
        vector<int> v = vector<int>(arr);
        // Expected answer: -4
        Utility::print(singleNumber(v));

        arr = {0,3,0,3,0,3,99};
        v = vector<int>(arr);
        // Expected answer: 99
        Utility::print(singleNumber(v));
    }
};