#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/intersection-of-two-arrays-ii/
class p350 : public LeetCodeProblem {
    // CPU 75%, MEM 99%.
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        auto map = std::unordered_map<int, int>();
        for(int i : nums2)
            map[i]++;
        
        auto v = std::vector<int>();
        for(int i : nums1) {
            if(map[i]) {
                map[i]--;
                v.push_back(i);
            }
        }
        return v;
    }
};