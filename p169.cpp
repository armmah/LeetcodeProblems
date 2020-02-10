#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
using namespace std;

class MajorityElement : public LeetCodeProblem {
    int majorityElement(vector<int>& nums) {
        auto n = nums.size();
        const int bitN = sizeof(int) * 8;
        // Count all bits
        vector<int> bits(bitN, 0);
        for(int num : nums) {
            for(int i = 0; i < bitN; i++) {
                // += if there is a '1' bit.
                bits[i] += (num & (1 << i)) != 0;
            }
        }

        auto halfSize = (int)ceil(n / 2.0);
        // Reverse calculate the number from all collected bits.
        // If number of '1's is >= n/2, we put '1' there, if not we put 0.
        auto result = 0;
        for (int i = 0; i < bitN; i++) {
            result |= ((bits[i] >= halfSize) << i);
        }
        return result;
    }

public:
    void testCase() {
        vector<int> vec {1,1,1,1,3,3,3};
        Utility::print(majorityElement(vec));
    }
};