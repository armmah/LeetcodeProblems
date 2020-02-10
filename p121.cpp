#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>
#include <algorithm>
using namespace std;

class BuyAndSellStock : LeetCodeProblem {
    static int maxProfit(vector<int>& prices) {
        int buy = prices[0], result = 0;
        for(int i = 1; i < prices.size(); i++) {
            result = max(result, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return result;
    }

public:
    void testCase() {
        vector<int> set = {4, 7, 1, 5, 3, 6, 4};
        Utility::print(maxProfit(set));
    }
};