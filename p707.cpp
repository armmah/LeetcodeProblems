#pragma once
#include "LeetCodeProblem.h"
#include "Utility.h"
#include <iostream>
#include <cassert>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) : 
        val(val), 
        next(NULL), 
        prev(NULL) {
    }
};
class p707 : public LeetCodeProblem {
    size_t n;

#pragma region private API
    Node* createNode(int val) {
        auto node = new Node(val);
        if(n == 0) {
            head = node;
            tail = node;
        }

        n++;
        return node;
    }
    void deleteNode(Node* node) {
        auto _p = node->prev;
        auto _n = node->next;
        if(_p)
            _p->next = _n;
        if(_n)
            _n->prev = _p;

        if (node == head) {
            head = _n;
        }
        if (node == tail) {
            tail = _p;
        }

        delete node;
        --n;
    }

    void linkPrev(Node* a, Node* b) {
        auto tmp = a->prev;
        b->next = a;
        a->prev = b;
        b->prev = tmp;
        if(tmp)
            tmp->next = b;
    }
    void linkNext(Node* a, Node* b) {
        auto tmp = a->next;
        a->next = b;
        b->prev = a;
        b->next = tmp;
        if(tmp) 
            tmp->prev = b;
    }
    void insertBefore(Node* a, int val) {
        auto b = createNode(val);
        linkPrev(a, b);

        if(a == head)
            head = b;
    }
    void insertAfter(Node* a, int val) {
        auto b = createNode(val);
        linkNext(a, b);

        if(a == tail)
            tail = b;
    }
    void insertHead(int index, int val) {
        if (!head) {
            head = createNode(val);
        }
        else {
            auto cur = getHead(index);
            insertBefore(cur, val);
        }
    }
    void insertTail(int index, int val) {
        if(!tail) {
            tail = createNode(val);
        }
        else {
            auto cur = getTail(index);
            insertAfter(cur, val);
        }
    }
    Node* getTail(int index) {
        auto cur = tail;
        while (cur && index > 0) {
            cur = cur->prev;
            index -= 1;
        }

        return cur;
    }
    //( ͡° ͜ʖ ͡°)
    Node* getHead(int index) {
        auto cur = head;
        while (cur && index > 0) {
            cur = cur->next;
            index -= 1;
        }

        return cur;
    }
#pragma endregion
public:
    Node* head;
    Node* tail;

    /** Initialize your data structure here. */
    p707() : n(0),
        head(NULL),
        tail(NULL) { }
    
    Node* getNode(int index) {
        if(index < 0 || index >= n)
            return NULL;

        return (index > n / 2) ? 
            getTail(n - index - 1): 
            getHead(index);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto node = getNode(index);
        return node ? node->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        insertHead(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        insertTail(0, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > n)
            return;

        if (index > n / 2) {
            insertTail(n - index, val);
        }
        else {
            insertHead(index, val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        auto node = getNode(index);
        if(node)
            deleteNode(node);
    }

#pragma region Other
    static std::string toString(Node* node) {
        return std::to_string(node->val);
    }

    bool isEqual(std::vector<int>& set) {
        if(set.size() > n)
            return false;
        for (int i = 0; i < set.size(); i++) {
            if(set[i] != get(i)) {
                std::cout << i << ")  " << set[i] << " != " << get(i) << std::endl;
                return false;
            }
        }
        return true;
    }
#pragma endregion

    void testCase() {
        unitTest();
    }

#pragma region Unit Test
    void unitTest() {
        std::vector<int> v;

        addAtHead(38);
        addAtTail(66);
        addAtTail(61);
        addAtTail(76);
        addAtTail(26);
        addAtTail(37);
        addAtTail(8);
        deleteAtIndex(5);
        assert(isEqual(v = {38, 66, 61, 76, 26, 8}));

        addAtHead(4);
        addAtHead(45);
        assert(isEqual(v = {45, 4, 38, 66, 61, 76, 26, 8}));
        assert(get(4) == 61);

        addAtTail(85);
        addAtHead(37);
        assert(isEqual(v = {37, 45, 4, 38, 66, 61, 76, 26, 8, 85}));
        assert(get(5) == 61);

        addAtTail(93);
        addAtIndex(23, 10);
        addAtTail(21);
        addAtHead(52);
        addAtHead(15);
        addAtHead(47);
        assert(isEqual(v = {47, 15, 52, 37, 45, 4, 38, 66, 61, 76, 26, 8, 85, 93, 21}));
        assert(get(12) == 85);

        addAtIndex(24, 6);
        addAtHead(64);
        assert(isEqual(v = {64, 47, 15, 52, 37, 45, 4, 38, 66, 61, 76, 26, 8, 85, 93, 21}));
        assert(get(4) == 37);

        addAtHead(31);
        deleteAtIndex(6);
        addAtHead(40);
        addAtTail(17);
        addAtTail(15);
        addAtIndex(2, 19);
        addAtTail(11);
        addAtHead(86);
        assert(isEqual(v = {86, 40, 31, 19, 64, 47, 15, 52, 37, 4, 38, 66, 61, 76, 26, 8, 85, 93, 21, 17, 15, 11}));
        assert(get(17) == 93);

        addAtTail(55);
        deleteAtIndex(15);
        addAtIndex(95, 14);
        deleteAtIndex(22);
        addAtHead(66);
        addAtTail(95);
        addAtHead(8);
        addAtHead(47);
        addAtTail(23);
        addAtTail(39);
        assert(isEqual(v = {
            47, 8, 66, 86, 40, 31, 19, 64, 47, 15,
            52, 37, 4, 38, 66, 61, 76, 26, 85, 93,
            21, 17, 15, 11, 55, 95, 23, 39}));
        assert(get(27) == 39);

        addAtHead(0);
        addAtTail(99);
        addAtTail(45);
        addAtTail(4);
        addAtIndex(11, 9);

        assert(isEqual(v = {
            0, 47, 8, 66, 86, 40, 31, 19, 64, 47,
            15, 9, 52, 37, 4, 38, 66, 61, 76, 26,
            85, 93, 21, 17, 15, 11, 55, 95, 23, 39,
            99, 45, 4}));
        assert(get(6) == 31);
        
        addAtHead(81);
        addAtIndex(32, 18);
        addAtHead(20);
        addAtTail(13);
        addAtTail(42);
        addAtIndex(91, 37);
        deleteAtIndex(36);
        addAtIndex(37, 10);
        addAtHead(96);
        addAtHead(57);
        deleteAtIndex(20);
        addAtTail(89);
        deleteAtIndex(18);
        addAtIndex(5, 41);
        addAtTail(23);
        addAtHead(75);
        assert(isEqual(v = {
            75, 57, 96, 20, 81, 0, 41, 47, 8, 66,
            86, 40, 31, 19, 64, 47, 15, 9, 52, 37,
            38, 61, 76, 26, 85, 93, 21, 17, 15, 11,
            55, 95, 23, 39, 99, 18, 45, 4, 42, 10,
            89, 23
            }
        ));
        assert(get(7) == 47);

        addAtIndex(51, 25);
        addAtTail(48);
        addAtHead(46);
        addAtHead(29);
        addAtHead(85);
        addAtHead(82);
        addAtHead(6);
        addAtHead(38);
        deleteAtIndex(14);
        assert(get(1) == 6);
        assert(get(12) == 41);
        addAtHead(42);
        assert(isEqual(v = {
//          0   1   2   3   4   5   6   7   8   9
            42, 38, 6,  82, 85, 29, 46, 75, 57, 96,
            20, 81, 0,  41, 47, 66, 86, 40, 31, 19,
            64, 47, 15, 9,  52, 37, 38, 61, 76, 26,
            85, 93, 21, 17, 15, 11, 55, 95, 23, 39,
            99, 18, 45, 4,  42, 10, 89, 23, 48
            }
        ));
        assert(get(42) == 45);

        addAtTail(83);
        addAtTail(13);
        addAtIndex(20, 14);
        addAtIndex(34, 17);
        addAtHead(36);
        addAtTail(58);
        addAtTail(2);
        assert(isEqual(v = {
//          0   1   2   3   4   5   6   7   8   9
            36, 42, 38, 6,  82, 85, 29, 46, 75, 57, 
            96, 20, 81, 0,  41, 47, 66, 86, 40, 31, 
            19, 14, 64, 47, 15, 9,  52, 37, 38, 61, 
            76, 26, 85, 93, 21, 17, 17, 15, 11, 55, 
            95, 23, 39, 99, 18, 45, 4,  42, 10, 89, 
            23, 48, 83, 13, 58, 2
            }
        ));
        assert(get(38) == 11);

        addAtIndex(59, 33);
        addAtHead(37);
        deleteAtIndex(15);
        addAtTail(64);
        //assert(get(56) == 64);
        addAtHead(0);
        //assert(get(40) == 55);
        addAtHead(92);
        deleteAtIndex(63);
        assert(isEqual(v = {
//          0   1   2   3   4   5   6   7   8   9
            92, 0,  37, 36, 42, 38, 6,  82, 85, 29, 
            46, 75, 57, 96, 20, 81, 0,  47, 66, 86, 
            40, 31, 19, 14, 64, 47, 15, 9,  52, 37, 
            38, 61, 76, 26, 85, 93, 21, 17, 17, 15, 
            11, 55, 95, 23, 39, 99, 18, 45, 4,  42, 
            10, 89, 23, 48, 83, 13, 58, 2, 64
            }
        ));
        assert(get(35) == 93);

        addAtTail(62);
        addAtTail(32);
        assert(isEqual(v = {
//          0   1   2   3   4   5   6   7   8   9
            92, 0,  37, 36, 42, 38, 6,  82, 85, 29, 
            46, 75, 57, 96, 20, 81, 0,  47, 66, 86, 
            40, 31, 19, 14, 64, 47, 15, 9,  52, 37, 
            38, 61, 76, 26, 85, 93, 21, 17, 17, 15, 
            11, 55, 95, 23, 39, 99, 18, 45, 4,  42, 
            10, 89, 23, 48, 83, 13, 58, 2, 64,  62,
            32
            }
        ));
    }
#pragma endregion

#pragma region Test cases
    void assertTest() {
        addAtTail(1);
        addAtTail(2);
        addAtTail(3);
        // 1, 2, 3
        // 0, 1, 2, 3
        addAtHead(0);

        assert(get(0) == 0);
        assert(get(1) == 1);
        assert(get(2) == 2);
        assert(get(3) == 3);

        std::vector<int> v = {0, 1, 2, 3};
        assert(isEqual(v));

        deleteAtIndex(999);
        assert(get(3) == 3);
        assert(isEqual(v = {0, 1, 2, 3}));

        deleteAtIndex(0);
        assert(get(0) == 1);
        assert(get(2) == 3);
        assert(isEqual(v = {1, 2, 3}));

        deleteAtIndex(0);
        assert(get(0) == 2);
        assert(get(1) == 3);
        assert(isEqual(v = {2, 3}));

        deleteAtIndex(1);
        assert(get(0) == 2);
        assert(isEqual(v = {2}));

        deleteAtIndex(0);
        assert(isEqual(v = {}));

        assert(get(0) == -1);
    }
    void complexCase() {
        //["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"]
        //[[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]

        // 2
        addAtHead(2);
        // nothing
        deleteAtIndex(1);
        // 2, 2
        addAtHead(2);
        // 7, 2, 2
        addAtHead(7);
        // 3, 7, 2, 2
        addAtHead(3);
        // 2, 3, 7, 2, 2
        addAtHead(2);
        // 5, 2, 3, 7, 2, 2
        addAtHead(5);
        // 5, 2, 3, 7, 2, 2, 5
        addAtTail(5);
        Utility::print(head, toString);
        // 2
        Utility::print(get(5));
        // 5, 2, 3, 7, 2, 2
        deleteAtIndex(6);
        // 5, 2, 3, 7, 2
        deleteAtIndex(4);
        Utility::print(head, toString);
    }

    void basicCase() {
        addAtHead(1);
        addAtTail(3);
        addAtIndex(1, 2);
        // Should print 1, 2, 3
        Utility::print(head, toString);
        // Should print 2
        Utility::print(get(1));
        deleteAtIndex(1);
        // Should print 3
        Utility::print(get(1));
    }
#pragma endregion

    ~p707() {
        if(!head) 
            return;

        auto next = head;
        while (next) {
            auto tmp = next->next;
            delete next;
            next = tmp;
            n --;
        }
        assert(n == 0);
    }

    static void parse() {
        std::vector<std::string> names = {"addAtHead","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","addAtTail","deleteAtIndex","addAtHead","addAtHead","get","addAtTail","addAtHead","get","addAtTail","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","get","addAtIndex","addAtHead","get","addAtHead","deleteAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","addAtTail","addAtHead","get","addAtTail","deleteAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtTail","addAtHead","addAtHead","addAtTail","addAtTail","get","get","addAtHead","addAtTail","addAtTail","addAtTail","addAtIndex","get","addAtHead","addAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","deleteAtIndex","addAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex","addAtIndex","addAtTail","addAtHead","get","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","deleteAtIndex","get","get","addAtHead","get","addAtTail","addAtTail","addAtIndex","addAtIndex","addAtHead","addAtTail","addAtTail","get","addAtIndex","addAtHead","deleteAtIndex","addAtTail","get","addAtHead","get","addAtHead","deleteAtIndex","get","addAtTail","addAtTail"};
        std::vector<int> nums = {38, 66, 61, 76, 26, 37, 8, 5, 4, 45, 4, 85, 37, 5, 93, 10, 23, 21, 52, 15, 47, 12, 6, 24, 64, 4, 31, 6, 40, 17, 15, 19, 2, 11, 86, 17, 55, 15, 14, 95, 22, 66, 95, 8, 47, 23, 39, 30, 27, 0, 99, 45, 4, 9, 11, 6, 81, 18, 32, 20, 13, 42, 37, 91, 36, 10, 37, 96, 57, 20, 89, 18, 41, 5, 23, 75, 7, 25, 51, 48, 46, 29, 85, 82, 6, 38, 14, 1, 12, 42, 42, 83, 13, 14, 20, 17, 34, 36, 58, 2, 38, 33, 59, 37, 15, 64, 56, 0, 40, 92, 63, 35, 62, 32};
    
        int k = 0;
        const std::string ending = ");\n";
        for (int i = 0; i < names.size(); i++) {
            std::string args = "(";
            if(names[i] == "addAtIndex")
                args += std::to_string(nums[k++]) + ", " + std::to_string(nums[k++]) + ending;
            else args += std::to_string(nums[k++]) + ending;
            std::cout << names[i] << args;
        }
    }

};

