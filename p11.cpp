#include "LeetCodeProblem.h"
#include <algorithm>
#include <vector>
#include <cassert>

// 96.22%, 83.51%
class p11 : LeetCodeProblem {
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        if(j <= i)
            return 0;
        
        int res = 0;
        while(i != j) {
            auto a = height[i],
                b = height[j];
            
            if(a > b) {
                res = std::max((j - i) * b, res);
                -- j;
            } else {
                res = std::max((j - i) * a, res);
                i ++;
            }
        }
        return res;
    }

public:
    void testCase() {
        std::vector<int> v {1,8,6,2,5,4,8,3,7};
        assert(maxArea(v) == 49);
    }
};