#include "LeetCodeProblem.h"
#include "Utility.h"
#include <unordered_set>
#include <vector>

class p1346 : public LeetCodeProblem {
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_multiset<int> set(arr.begin(), arr.end());

        for (auto el : arr) {
            if(el != 0 && set.count(el * 2) > 0 ||
                el == 0 && set.count(el * 2) > 1)
                return true;
        }

        return false;
    }

public:
    void testCase() {
        std::vector<int> arr = {0, 0};
        assert(checkIfExist(arr));

        arr = {10, 2, 5, 3};
        assert(checkIfExist(arr));

        arr = {-10, 12, -20, -8, 15};
        assert(checkIfExist(arr));

        arr = {-2,0,10,-19,4,6,-8};
        assert(!checkIfExist(arr));

        arr = {-95,-299,357,715,-438,-759,255,418,-647,-805,-546,-182,-523,13,-79,-227,537,-655,
            993,-526,-518,679,-420,-53,120,187,-203,-567,-75,464,-472,-324,16,215,-773,862,-563,
            -839,-906,-969,633,-990,756,-17,-346,820,-216,736,188,-412,881,-599,-181,-673,802,688,
            553,323,-689,625,871,-938,-969,-207,-703,794,361,111,-884,156,-223,-480,-734,-838,-53,
            335,720,-379,855,-971,-928,99,-876,75,721,-736,-913,911};
        assert(checkIfExist(arr));
    }
};