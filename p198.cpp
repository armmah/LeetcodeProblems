#include "LeetCodeProblem.h"
#include "Utility.h"
#include <algorithm>

// https://leetcode.com/problems/house-robber/
class p198 : public LeetCodeProblem {
    // CPU 100% MEM 100%

    // Memoization resource, a vector that remembers previous calculations.
    std::vector<int> results;
    int rob(std::vector<int>& nums, int k) {
        // Check k in range of nums.
        if(k >= nums.size())
            return 0;
        // If already calculated.
        if(results[k] > std::numeric_limits<int>::min())
            return results[k];
        // Calculate the three possible paths [k, k + 2, ...], [k, k + 3, ...], [k + 1, ...]
        auto res = std::max(nums[k] + std::max(rob(nums, k + 2), rob(nums, k + 3)), rob(nums, k + 1));
        results[k] = res;
        return res;
    }
    int rob(std::vector<int>& nums) {
        // We will need a vector of the nums's length and all initialized to min int value.
        // Recurse and recalculate will happen on ALL possible paths (which is bad) if the nums array actually has an int min value, but that case can be ignored.
        results = std::vector<int>(nums.size(), std::numeric_limits<int>::min());
        return rob(nums, 0);
    }

public:
    void testCase() {
        auto test = std::vector<int> {2, 7, 9, 3, 1};   // 12
        Utility::print_assert(rob(test), 12);

        test = {1, 2, 3, 1};    // 4
        Utility::print_assert(rob(test), 4);

        test = {};  // 0
        Utility::print_assert(rob(test), 0);

        test = {0, 1};   // 1
        Utility::print_assert(rob(test), 1);

        test = {0, 1, 2};   // 2
        Utility::print_assert(rob(test), 2);

        test = {2, 0, 1, 2};    // 4
        Utility::print_assert(rob(test), 4);
    }
};