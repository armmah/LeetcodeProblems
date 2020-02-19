#include "LeetCodeProblem.h"
#include <vector>
#include <cassert>

// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class p1351 : LeetCodeProblem {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int nx = grid.size();
        // Check this because we are accessing grid[0].
        if(nx == 0)
            return 0;
        int ny = grid[0].size();
        
        int result = 0;
        // start at the top-right corner.
        int i = 0;
        int k = ny;
        // Start marching in down-left direction. 
        while(i < nx) {
            if(k <= 0) {
                // We know for sure that all elements on this row are negative.
                result += ny;
                i+= 1;
                continue;
            }
                
            // If we have stumbled upon a positive number, this row is dealt with, so go to the next row (down)
            if(grid[i][k - 1] >= 0) {
                result += ny - k;
                i += 1;
            } else {
            // If this element is negative, the row might contain other negative number at the left, so go and check other elements to the right in this row.
                k -= 1;
            }
        }
        return result;
    }
};