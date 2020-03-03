#include "LeetCodeProblem.h"
#include "Utility.h"
#include <unordered_map>

class p13 : LeetCodeProblem {
    // Benchmark (10000 iterations of this function on small strings): 2.5 times slower than hardcoded solution below.
    std::unordered_map<char, int> map;
    int romanToInt3(std::string s) {
        int res = map[s.back()];
        int n = s.size();
        for (int i = 0; i < n - 1; i ++){
            if (map[s[i]] < map[s[i + 1]]) res -= map[s[i]];
            else res += map[s[i]];
        }
        return res;
    }

    // CPU 100%, MEM 100%
    // Too many conditional jumps, but less hash lookups.
    int romanToInt(std::string s) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
                switch(s[i]) {
                    if (i < s.size() - 1) {
                    case 'I':
                        if (s[i+1] == 'V') {
                            res += 4;
                            ++i;
                            continue;
                        }
                        if(s[i+1] == 'X') {
                            res += 9;
                            ++i;
                            continue;
                        }
                        res += 1;
                        continue;
                
                    case 'X':
                        if(s[i+1] == 'L') {
                            res += 40;
                            ++i;
                            continue;
                        }
                        if(s[i+1] == 'C') {
                            res += 90;
                            ++i;
                            continue;
                        }
                        res += 10;
                        continue;

                    case 'C':
                        if(s[i+1] == 'D') {
                            res += 400;
                            ++i;
                            continue;
                        }
                        if(s[i+1] == 'M') {
                            res += 900;
                            ++i;
                            continue;
                        }
                        res += 100;
                        continue;
                    }                    
                case 'V':
                    res += 5;
                    continue;
                case 'L':
                    res += 50;
                    continue;
                case 'D':
                    res += 500;
                    continue;
                case 'M':
                    res += 1000;
                    continue;
            }
        }
        return res;
    }

public:
    p13() {        
        map = {{'I', 1}, {'V', 5}, {'X', 10}, 
                {'L', 50}, {'C', 100}, 
                {'D', 500}, {'M', 1000}};
    }

    void testCase() {
        auto s = std::string("III");
        Utility::print_assert(romanToInt(s), 3);
        
        s = std::string("IV");
        Utility::print_assert(romanToInt(s), 4);
        
        s = std::string("IX");
        Utility::print_assert(romanToInt(s), 9);
        
        s = std::string("IXX");
        Utility::print_assert(romanToInt(s), 19);
        
        s = std::string("LVIII");
        Utility::print_assert(romanToInt(s), 58);
        
        s = std::string("MCMXCIV");
        Utility::print_assert(romanToInt(s), 1994);
    }
};