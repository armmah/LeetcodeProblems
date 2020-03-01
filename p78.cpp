#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>

// https://leetcode.com/problems/subsets/
class p78 : public LeetCodeProblem {
    // 60% 75%
    std::vector<vector<int>> subsets(std::vector<int>& nums) {
        auto res = std::vector<vector<int>>();

        int n = nums.size();
        for(int bk = 0; bk < (1 << n); bk++) {
            std::vector<int> v;
            for (int i = 0; i < n; i++) {
                if(bk & 1 << i)
                    v.push_back(nums[i]);
            }
            res.push_back(v);
        }
        return res;
    }

public:
    void testCase() {
        auto v = std::vector<int> {1, 2, 2};
        auto vv = subsets(v);
        for (int i = 0; i < vv.size(); i++) {
            Utility::print(vv[i], std::to_string);
        }
    }
};