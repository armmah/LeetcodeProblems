#include <vcruntime.h>

#pragma region Flatten Tree to doubly linked list
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    static Node* main(Node* head) {
        auto cur = head;
        while(cur) {
            if(cur->child) {
                cur = insert(cur);
                continue;
            }
            cur = cur->next;
        }
    }
    static Node* insert(Node* head) {
        auto list = head->child;
        head->child = NULL;
        auto last = link(head, list);
        while (list->next) {
            if (list->child) {
                list = insert(list);
                continue;
            }
            list = list->next;
        }
        link(list, last);
        return last;
    }
    static Node* link(Node* a, Node* b) {
        auto lost = a->next;
        a->next = b;
        b->prev = a;
        return lost;
    }
};
#pragma endregion