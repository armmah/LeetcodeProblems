#include "LeetCodeProblem.h"
#include <vector>

// https://leetcode.com/problems/product-of-the-last-k-numbers/
class p1352 : LeetCodeProblem {
    std::vector<int> stack;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // Push into the stack.
        stack.push_back(num);
    }
    
    int getProduct(int k) {
        int size = stack.size();
        int prod = 1;
        // Calculate the product of the last k elements in the stack.
        for(int i = 0; i < k; i++) {
            prod *= stack[size - i - 1];
        }
        return prod;
    }
};