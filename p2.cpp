#include "LeetCodeProblem.h"
#include "Utility.h"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     static std::string toString(ListNode* node) { return std::to_string(node->val); }
 };
class p2 : LeetCodeProblem {
#pragma region Optimized Code O(n)
    bool add2(ListNode* node, int num) {
        auto newVal = (node->val + num);
        auto carry =(newVal >= 10) ; 
        node->val = carry ? newVal - 10 : newVal;
        return carry;
    }
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        static bool carry = 0;
        if(l2 || carry) {
            auto l2val = l2 ? l2->val : 0;
            carry = add2(l1, carry + l2val);
            if (!l1->next && (carry || (l2 && l2->next))) {
                l1->next = new ListNode(0);
            }
            addTwoNumbers2(l1->next, l2 ? l2->next : NULL);
        }
        return l1;
    }
#pragma endregion
#pragma region Easy to understand solution (can be O(2n) worst case)
    void add(ListNode* node, int num) {
        auto newVal = (node->val + num);
        if (newVal >= 10) {
            newVal %= 10;
            if (node->next == NULL) {
                node->next = new ListNode(0);
            }
            add(node->next, 1);
        }
        node->val = newVal;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l2) {
            if (!l1) {
                l1 = new ListNode(0);
            }
            add(l1, l2->val);
            addTwoNumbers(l1->next, l2->next);
        }
        return l1;
    }
#pragma endregion

public:
    void case1() {
        auto a1 = new ListNode(2), a2 = new ListNode(4), a3 = new ListNode(9);
        auto b1 = ListNode(5), b2 = ListNode(6), b3 = ListNode(9), b4 = ListNode(9);

        a1->next = a2;
        b1.next = &b2;

        a2->next = a3;
        b2.next = &b3;

        b3.next = &b4;

        auto res = addTwoNumbers(a1, &b1);
        Utility::print(res, ListNode::toString);
        
        Utility::freeAlloc(a1);
    }
    void testCase() {
        auto a1 = new ListNode(0);
        auto b1 = ListNode(7), b2 = ListNode(3);

        b1.next = &b2;

        auto res = addTwoNumbers(a1, &b1);
        Utility::print(res, ListNode::toString);

        Utility::freeAlloc(a1);
    }
};