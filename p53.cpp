#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>

// https://leetcode.com/problems/maximum-subarray/submissions/
class p53 : public LeetCodeProblem {
    // CPU 73%, MEM 100%
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        auto result = nums[0];
        auto sum = nums[0];
        int i = 0, k = 1;

        // O(2n) solution - in worst case goes over all the elements of the array twice -> O(n).
        while(k < nums.size()) {
            // Slide the left index until the sum is positive (so that nums[i] + nums[i + 1] + ... + nums[k] >= nums[k])
            while (i < k && sum < 0) {
                sum -= nums[i];
                i++;
            }
            // Slide the right index, appending to the window.
            sum += nums[k];
            k++;
            // Store the biggest sum.
            result = std::max(sum, result);
        }

        return result;
    }

public:
    void testCase() {
        std::vector<int> v = { -1 };
        Utility::print_assert(maxSubArray(v), -1);

        v = { 0, 1, 9, -50, 2, -2, 0, 5, 15, -50 };
        Utility::print_assert(maxSubArray(v), 20);
        
        v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        Utility::print_assert(maxSubArray(v), 6);
    }
};