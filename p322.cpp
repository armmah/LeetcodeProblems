#include "LeetCodeProblem.h"
#include "Utility.h"
#include <unordered_map>

// https://leetcode.com/problems/coin-change/submissions/
class p322 : public LeetCodeProblem {
    // Recursive - CPU 6%, MEM 14%
    int coin(const std::vector<int>& coins, std::unordered_map<int, int>& memo, int x) {
        // Check if value already calculated.
        if(memo.count(x) > 0)
            return memo[x];

        if(x < 0)
            return -1;
        if(x == 0)
            return 0;

        // Iterate over all coins.
        auto res = std::numeric_limits<int>::max();
        for (auto c : coins) {
            // Calculate cost of each coin pick and take the minimum cost at this step.
            auto cost = coin(coins, memo, x - c);
            if(cost >= 0 && cost != std::numeric_limits<int>::max()) {
                res = std::min(res, cost + 1);
                // Remember the calculated result.
                memo[x] = res;
            }
        }
        return (res == std::numeric_limits<int>::max()) ? -1 : res;
    }
    int coinChange(std::vector<int>& coins, int amount) {
        auto memo = std::unordered_map<int, int>();
        return coin(coins, memo, amount);
    }

public:
    void testCase() {
        auto v = std::vector<int> {1, 2, 5};
        Utility::print_assert( coinChange(v, 11), 3 );
        
        v = {1, 3, 4};
        Utility::print_assert( coinChange(v, 10), 3 );

        v = {2};
        Utility::print_assert( coinChange(v, 3), -1 );
    }
};