#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <cassert>

class p34 : public LeetCodeProblem {
    int min, max;
    
    void findRecurse(std::vector<int>& v, int l, int r, int target) {
        if(l < 0 || r > v.size() || l == r)
            return;

        auto mid = (l + r) / 2;
        if (target == v[mid]) {
            // Found the index, iteratively probe till min and max are found.
            min = mid;
            max = mid;
            while(min - 1 >= 0 && v[min - 1] == target)
                --min;
            while(max + 1 < v.size() && v[max + 1] == target)
                ++max;
            return;
        }
        // Take left half
        if (target < v[mid]) {
            findRecurse(v, l, mid, target);
        }
        // Take right half
        if (target > v[mid]) {
            findRecurse(v, mid + 1, r, target);
        }
    }
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        min = max = -1;

        // Binary search in a sorted array O(logn).
        findRecurse(nums, 0, nums.size(), target);
        return std::vector<int> {min, max};
    }

public:
    void testCase() {
        std::vector<int> v = {5,7,7,8,8,10};
        assert(searchRange(v, 8) == {3, 4});
        assert(searchRange(v, 6) == {-1, -1});

        v = {1};
        assert(searchRange(v, 1) == {0, 0});
    }
};