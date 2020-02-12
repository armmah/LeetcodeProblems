#include "LeetCodeProblem.h"
#include "Utility.h"
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static std::string toString(ListNode* node) { return std::to_string(node->val); }
};
class p24 : LeetCodeProblem {
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        
        auto cur = head;
        auto prev = (ListNode*)NULL;

        if(head->next)
            head = head->next;
        while (cur && cur -> next) {
            auto next = cur->next;
            cur->next = next->next;
            if(prev)
                prev->next = next;
            next->next = cur;

            prev = cur;
            cur = cur -> next;
        }
        return head;
    }

public:
    void testCase() {
        auto a = ListNode(1), b = ListNode(2), c = ListNode(3), d = ListNode(4);
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = NULL;

       Utility::print(&a, ListNode::toString);
       assert(Utility::compare(&a, std::vector<int> {1, 2, 3, 4}));

       auto res = swapPairs(&a);
       Utility::print(res, ListNode::toString);
       assert(Utility::compare(res, std::vector<int> {2, 1, 4, 3}));
    }
};