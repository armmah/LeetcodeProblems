#include "LeetCodeProblem.h"
#include <vector>
#include <cassert>

// https://leetcode.com/problems/rotate-image/
class p48 : LeetCodeProblem {
    // CPU 82% MEM 100%
    void rotate(std::vector<std::vector<int>>& a) {
        auto n = a.size(), N = n - 1;
        if (n == 0)
            return;

        for (int i = 0; i < n; i++) {
            for (int k = i; k < N - i; k++) {
                auto tmp = a[i][k];
                a[i][k] = a[N - k][i];
                a[N - k][i] = a[N - i][N - k];
                a[N - i][N - k] = a[k][N - i];
                a[k][N - i] = tmp;
            }
        }
    }
    
public:
    void testCase() {
        auto matrix = std::vector<std::vector<int>>{
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        rotate(matrix);

        auto res = std::vector<std::vector<int>>{
          {7,4,1},
          {8,5,2},
          {9,6,3}
        };
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int k = 0; k < matrix.size(); k++) {
                assert(matrix[i][k] == res[i][k]);
            }
        }
    }
};
