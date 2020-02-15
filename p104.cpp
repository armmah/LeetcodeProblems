#include "LeetCodeProblem.h"
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode : LeetCodeProblem {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    // Came back to this problem a week later.
    static int maxDepth_attempt2(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // First solution.
    static int maxDepth(TreeNode* root) {
        static int count = 0;
        auto leaf = root->left;
        if(leaf != NULL)
            max(count, maxDepth(root->left));

        leaf = root->right;
        if(leaf != NULL)
             max(count, maxDepth(root->right));
        return 1;
    }
    static int depth(TreeNode* node, int c) {
        int l = c, r = c;
        if(node->left != NULL)
            l = depth(node->left, c + 1);
        if(node->right != NULL)
            r = depth(node->right, c + 1);
        return max(l, r);
    }

public:
    void testCase() {
        auto        a = TreeNode(3), 
            b = TreeNode(9), c = TreeNode(20), 
                        d = TreeNode(15), e = TreeNode(7);
    
        a.left = &b;
        a.right = &c;
        c.left = &d;
        c.right = &e;

        cout<<depth(&a, 0)<<endl;
    }
 };