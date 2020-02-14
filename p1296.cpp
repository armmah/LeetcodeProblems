#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <set>

class p1296 : LeetCodeProblem {
    bool isPossibleDivide(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)  return false;

        std::multiset<int> set(nums.begin(), nums.end());
        while (n > 0) {
            auto p = set.begin();
            int min = *p;
            set.erase(p);

            for (int i = 1; i < k; i++) {
                p = set.find(min + i);
                if(p == set.end())
                    return false;
                else set.erase(p);
            }

            n = set.size();
        }

        return true;
    }

public:
    void testCase() {
        std::vector<int> v{1, 2, 3, 3, 4, 4, 5, 6};
        assert(isPossibleDivide(v, 4)); // true
        std::cout<<std::endl<<isPossibleDivide(v, 4)<<std::endl;

        v = {1, 2, 3, 2, 3, 4, 3, 4, 5};
        assert(isPossibleDivide(v, 3)); // true
        std::cout<<std::endl<<isPossibleDivide(v, 3)<<std::endl;

        v = {3,2,1,2,3,4,3,4,5,9,10,11};
        assert(isPossibleDivide(v, 3)); // true
        std::cout<<std::endl<<isPossibleDivide(v, 3)<<std::endl;
        
        v = {3,3,2,2,1,1};
        assert(isPossibleDivide(v, 3)); // true
        std::cout<<std::endl<<isPossibleDivide(v, 3)<<std::endl;

        v = {1,2,3,4};
        assert(!isPossibleDivide(v, 3)); // false
        std::cout<<std::endl<<!isPossibleDivide(v, 3)<<std::endl;
    }
};