#include "LeetCodeProblem.h"
#include <vector>
#include <cassert>

class p75 : public LeetCodeProblem {
    // https://leetcode.com/problems/sort-colors/
    // CPU 100%, MEM 90%
    void sortColors(std::vector<int>& nums) {
        int l = 0, c = 0, r = nums.size() - 1;
        while (c <= r && l <= r) {
            if (nums[l] == 0) {
                l++;
                if(l >= c)
                    c = l;
                continue;
            }
            if (nums[r] == 2) {
                --r;
                continue;
            }
            if (nums[l] == 2 && nums[r] == 0) {
                swap(nums, l, r);
                l ++;
                r --;
                if(l >= c)
                    c = l;
                continue;
            }
            if (nums[c] == 0) {
                swap(nums, c, l);
                ++l;
                if(l >= c)
                    c = l;
                continue;
            }
            if (nums[c] == 2) {
                swap(nums, c, r);
                --r;
                continue;
            }
            if(nums[c] == 1)
                ++c;
        }
    }
    void swap(vector<int>& nums, int i, int k) {
        auto tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
    }

    bool equals(std::vector<int>& nums, std::vector<int> rvalue) {
        if(nums.size() != rvalue.size())
            return false;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != rvalue[i])
                return false;
        return true;
    }
public:
    void testCase() {
        std::vector<int> v = {2, 1};
        sortColors(v);
        assert(equals(v, {1, 2}));

        v = {2, 0, 2, 1, 1, 0};
        sortColors(v);
        assert(equals(v, {0, 0, 1, 1, 2, 2}));

        v = {0, 0, 0, 0, 0, 1, 2};
        sortColors(v);
        assert(equals(v, {0, 0, 0, 0, 0, 1, 2}));
        
        v = {0, 0, 0};
        sortColors(v);
        assert(equals(v, {0, 0, 0}));
        
        v = {2, 2, 2};
        sortColors(v);
        assert(equals(v, {2, 2, 2}));
        
        v = {1, 1, 1};
        sortColors(v);
        assert(equals(v, {1, 1, 1}));
        
        v = {0, 1, 0};
        sortColors(v);
        assert(equals(v, {0, 0, 1}));

        v = {1, 0, 0};
        sortColors(v);
        assert(equals(v, {0, 0, 1}));

        v = {1, 1, 0};
        sortColors(v);
        assert(equals(v, {0, 1, 1}));
        
        v = {2, 1, 0};
        sortColors(v);
        assert(equals(v, {0, 1, 2}));
        
        v = {1, 1, 2, 0, 0};
        sortColors(v);
        assert(equals(v, {0, 0, 1, 1, 2}));
    }
};