#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
using namespace std;

class PascalsTriangle : public LeetCodeProblem {
    vector<vector<int>> run(int numRows) {
        vector<vector<int>> res(numRows);
        for (size_t i = 0; i < numRows; i++) {
            for (size_t k = 0; k <= i; k++) {
                int c = 0;
                if (i > 0) {
                    if (k > 0) {
                        c += res[i - 1][k - 1];
                    }
                    if(k < i)
                        c += res[i - 1][k];
                }
                if(c == 0)
                    c = 1;
                res[i].push_back(c);
            }
        }
        return res;
    }

public:
    void testCase() {
        auto res = run(5);
        for(vector<int> a : res) {
            Utility::print(a);
        }
    }
};