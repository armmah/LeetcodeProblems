#include  "LeetCodeProblem.h"
#include  <vector>

class ReverseAString : LeetCodeProblem {
    static void main(std::vector<char>& s) {
        auto n = s.size();
        for(int i = 0; i < n / 2; i++) {
            auto lost = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = lost;
        }
    }

public:
    void testCase() {

    }
};