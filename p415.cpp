#include "LeetCodeProblem.h"
#include "Utility.h"
#include <string>
#include <algorithm>
using namespace std;

class AddStrings {
    static string addStrings(string num1, string num2) {
        string res = "";
        size_t size1 = num1.size(),
            size2 = num2.size();
        auto n = min(size1, size2);
        string* biggerString = (size1 >= size2) ? &num1 : &num2;
        
        char cur;
        bool prev = false;
        for(size_t i = 1; i <= n; i++) {
            prev = addChars(num1[size1 - i], num2[size2 - i], prev, cur);
            res += cur;
        }
        for(size_t i = biggerString->size() - 1; i >= n; i--) {
            prev = addChars((*biggerString)[i], (char)48, prev, cur);
            res += cur;
        }
        if(prev)
            res += 49;
        reverse(res.begin(), res.end());
        return res;
    }
    static bool addChars(char a, char b, bool addOne, char& result) {
        auto res = ((int)a + (int)b + addOne) - 2 * 48;
        if(res >= 10) {
            result = (char)((res - 10) + 48);
            return true;
        }
        result = (char)(res + 48);
        return false;
    }

public:
    static void testCase() {
        auto str = addStrings("9", "99");
        Utility::print(str);
    }
};