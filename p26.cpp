#include "LeetCodeProblem.h"
#include <vector>
#include <cassert>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class p26 : LeetCodeProblem {
    // CPU 95%, RAM 84%
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        int i = 0, k = 1;
        for(;k < n; ++k) {
            if(i + 1 < k) {
                if (nums[i] != nums[k]) {
                    nums[++i] = nums[k++];
                }
            }
            else {
                if (nums[i] != nums[k]) {
                    i++; k++;
                }
            }
        }

        return i + 1;
    }

    int removeDuplicates_MicroOptimization(std::vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        // Obfuscated code, the purpose was to microoptimize it by removing branching (even if we have more writes onto itself), but the leetcode tests return the same runtime metrics.
        // Probably the data sizes are too small for any of this to matter.
        int i = 0, k = 1;
        for(; k < n; ++k) {
            i += (nums[i] != nums[k]);
            nums[i] = nums[k];
        }

        return i + 1;
    }

public:
    void testCase() {
        std::vector<int> v = {1, 2};
        auto l = removeDuplicates(v);
        assert(l == 2);
        assert(v[0] == 1 && v[1] == 2);

        v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        l = removeDuplicates(v);
        assert(l == 5);
        assert(v[0] == 0 && v[1] == 1 && v[2] == 2 && v[3] == 3 && v[4] == 4);

        v = {0, 0, 0, 0, 0, 0, 0, 3, 3, 4};
        l = removeDuplicates(v);
        assert(l == 3);
        assert(v[0] == 0 && v[1] == 3 && v[2] == 4);
    }
};