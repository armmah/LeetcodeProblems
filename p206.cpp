#include "LeetCodeProblem.h"
#include "Utility.h"
#include <string>
using namespace std;

// The defenition of the ListNode given by the problem.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static string printVal(ListNode* n) { return to_string(n->val); }
};

class ReverseLinkedList : LeetCodeProblem {
    static ListNode* reverseList(ListNode* head) {
        ListNode* next = NULL;
        while (head != NULL) {
            auto lost = head->next;
            head->next = next;
            next = head;
            head = lost;
        }
        return next;
    }

public:
    static void testCase() {
        ListNode node1(1), node2(2), node3(3);
        node1.next = &node2;
        node2.next = &node3;
        node3.next = NULL;

        Utility::print(reverseList(&node1), ListNode::printVal);
    }
};