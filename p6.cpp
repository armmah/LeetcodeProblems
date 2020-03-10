#include "LeetCodeProblem.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/zigzag-conversion/
class p6 : LeetCodeProblem {
    // CPU 94% MEM 100%
    std::string convert(std::string s, int numRows) {
        std::string result = "";
        int n = s.size();
        int numCols = std::max(n / numRows, n);
        int x2m2 = std::max(numRows * 2 - 2, 1);
        for (int k = 0; k < numRows; ++k) {
            for (int i = 0; i < numCols; ++i) {
                auto r = i * x2m2 + k;
                if (r >= n)
                    break;

                result += s[r];
                if (k > 0 && k < numRows - 1) {
                    auto x = (i + 1) * x2m2 - k;
                    if (x < n)
                        result += s[x];
                }
            }
        }
        return result;
    }
        // rows = 3
        // s[0],        s[4],           s[8],           s[12]
        // s[1], s[3],  s[5],   s[7],   s[9],   s[11],  s[13]
        // s[2],        s[6],           s[10],

        // rows = 4
        // s[0],            s[6],           s[12]
        // s[1],    s[5],   s[7],   s[11],  s[13]
        // s[2],s[4],       s[8],s[10]
        // s[3],            s[9]

        // rows = 5
        // s[0],                s[8],
        // s[1],        s[7],   s[9],
        // s[2],    s[6],       s[10],
        // s[3],s[5],           s[11],s[13]
        // s[4],                s[12],

public:
    void testCase() {
        std::cout<<convert("AB", 1)<<std::endl;
        std::cout<<convert("A", 2)<<std::endl;
        std::cout<<convert("ACD", 2)<<std::endl;
        std::cout<<convert("PAYPALISHIRING", 3)<<std::endl;
        std::cout<<convert("PAYPALISHIRING", 4)<<std::endl;
        std::cout<<convert("PAYPALISHIRING", 5)<<std::endl;
    }
};