#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class p559 {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        
        int value = 0;
        for(Node* n : root->children) {
            value = max(maxDepth(n), value);
        }
        return value + 1;
    }
};