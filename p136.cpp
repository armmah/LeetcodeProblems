#include <vector>
#include "LeetCodeProblem.h"
#include "Utility.h"
using namespace std;

class SingleNumber : LeetCodeProblem {
    static int singleNumber(vector<int>& nums) {
        int bits = 0;
        for(int i : nums)
            bits ^= i;
        return bits;
    }

public:
    void testCase() {
        auto arr = {2, 2, 1};
        vector<int> v = vector<int>(arr);
        Utility::print(singleNumber(v));

        arr = {4, 1, 2, 1, 2};
        v = vector<int>(arr);
        Utility::print(singleNumber(v));
    }
};