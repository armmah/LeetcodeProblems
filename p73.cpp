#include "LeetCodeProblem.h"
#include <vector>
#include <cassert>

class p73 : public LeetCodeProblem {
    // https://leetcode.com/problems/set-matrix-zeroes/
    // CPU 94%, MEM 81%
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if(matrix.size() == 0)
            return;

        bool firstCol = false, firstRow = false;;
        for (int i = 0; i < matrix.size(); i++) {
            for (int k = 0; k < matrix[0].size(); k++) {
                if(matrix[i][k] == 0) {
                    if(i == 0)
                        firstRow = true;
                    if(k == 0)
                        firstCol = true;

                    matrix[i][0] = 0;
                    matrix[0][k] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int k = 1; k < matrix[i].size(); k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int k = 1; k < matrix[0].size(); k++) {
            if (matrix[0][k] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][k] = 0;
                }
            }
        }

        if (firstRow) {
            for (int k = 1; k < matrix[0].size(); k++) {
                matrix[0][k] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }

    bool equals(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2) {
        auto n = matrix1.size();
        if(n == 0)
            return matrix2.size() == 0;
        if(n != matrix2.size())
            return false;
        auto m = matrix1[0].size();
        if(m != matrix2[0].size())
            return false;

        for (int i = 0; i < n; i++) {
            //Utility::print(matrix1[i], std::to_string);
            for(int k = 0; k < m; k++) {
                if(matrix1[i][k] != matrix2[i][k])
                    return false;
            }
        }
        return true;
    }

public:
    void testCase() {
        std::vector<std::vector<int>> m = {
            {1, 1, 1},
            {0, 1, 2}
        }, res = {
            {0, 1, 1},
            {0, 0, 0}
        };
        setZeroes(m);
        assert(equals(m, res));

        m = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        }, res = {
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1}
        };
        setZeroes(m);
        assert(equals(m, res));

        m = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        }, res = {
            {0, 0, 0, 0},
            {0, 4, 5, 0},
            {0, 3, 1, 0}
        };
        setZeroes(m);
        assert(equals(m, res));
    }
};