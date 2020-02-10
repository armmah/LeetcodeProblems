#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
using namespace std;

class MovingZeroes {
    static void moveZeroes(vector<int>& nums) {
        size_t count = 0;
        auto n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            } else if(count > 0) {
                nums[i - count] = nums[i];
            }
        }
        for(size_t i = n - count; i < n; i++)
            nums[i] = 0;
    }
    static void swap(vector<int>& nums, int index1, int index2) {
        auto temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

public:
    void testCase() {
        vector<int> nums {0, 1, 0, 3, 12};
        moveZeroes(nums);
        // Should give 1, 3, 12, 0, 0.
        Utility::print(nums);
    }
};