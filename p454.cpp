#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/4sum-ii/submissions/
class p454 : public LeetCodeProblem {
    // CPU 61%, MEM 32%
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        std::unordered_map<int, int> map;
        // Build all possible combinations from A and B.
        for(auto i : A)
            for(auto j : B)
                map[i + j]++;

        int c = 0;
        // Check for all possible combinations of C and D, if contained in map(Ai + Bj)
        for(auto k : C)
            for (auto l : D) {
                auto s = 0 - k - l;
                if (map[s] > 0) {
                    c += map[s];
                }
            }
        return c;
    }
    int bruteForce(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        int c = 0;
        for(auto i : A)
            for(auto j : B)
                for(auto k : C)
                    for (auto l : D) {
                        if (i + j + k + l == 0) {
                            std::cout<<"    "<<i+j<<std::endl;
                            ++c;
                        }
                    }
        return c;
    }

public:
    void testCase() {
        std::vector<int> A = {1, 2}, B = {-2, -1}, C = {-1, 2}, D = {0, 2};
        Utility::print_assert(fourSumCount(A, B, C, D), bruteForce(A, B, C, D));

        A = {5, -3}, B = {1, 2}, C = {-1, -2}, D = {-5, 3};
        Utility::print_assert(fourSumCount(A, B, C, D), bruteForce(A, B, C, D));
        
        A = {-1, -1}, B = {-1, 1}, C = {-1, 1}, D = {1, -1};
        Utility::print_assert(fourSumCount(A, B, C, D), bruteForce(A, B, C, D));
    }
};