#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>

// https://leetcode.com/problems/minimum-path-sum/
class p64 : LeetCodeProblem {
    // CPU 48%, MEM 100%

    // Memoization of previously calculated values.
    std::vector<std::vector<int>> mem;
    int minPathSum(std::vector<std::vector<int>>& grid) {
        mem = std::vector<std::vector<int>>();
        // Create a matrix of grid dimensions.
        mem.reserve(grid.size());
        for (int i = 0; i < grid.size(); ++i) {
            // Initialize values as INT_MAX
            mem.push_back(std::vector<int>(grid[i].size(), std::numeric_limits<int>::max()));
        }
        // Recurse on grid (right and down only).
        return recurse(grid, 0, 0);
    }
    int recurse(std::vector<std::vector<int>>& g, int i, int k) {
        // Check boundaries.
        if(i >= g.size() || k >= g[0].size())
            return std::numeric_limits<int>::max();
        // Check if already calculated.
        if(mem[i][k] < std::numeric_limits<int>::max())
            return mem[i][k];

        // Recurse left and down.
        auto res = std::min(recurse(g, i + 1, k), recurse(g, i, k + 1));
        // Store newly calculated value and return.
        mem[i][k] = g[i][k] + (res == std::numeric_limits<int>::max() ? 0 : res);
        return mem[i][k];
    }

public:
    void testCase() {
        std::vector<std::vector<int>> grid { 
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        };
        Utility::print_assert(minPathSum(grid), 7);
    }
};