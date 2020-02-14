#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>

class p66 : public LeetCodeProblem {
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool carry = true;
        int i = digits.size() - 1;
        do {
            if(i < 0) {
                digits.insert(digits.begin(), 0);
                i = 0;
            }
            auto num = digits[i];

            num += carry;
            if (num >= 10) {
                digits[i] = num - 10;
                carry = true;
            }
            else {
                digits[i] = num;
                carry = false;
            }
            i = i - 1;

        } while(carry);


        return digits;
    }

public:
    void testCase() {
        std::vector<int> v {1, 2, 3};
        v = plusOne(v);
        Utility::print(v, std::to_string);

        v = {4, 3, 2, 1};
        v = plusOne(v);
        Utility::print(v, std::to_string);
        
        v = {9, 9};
        v = plusOne(v);
        Utility::print(v, std::to_string);
    }
};