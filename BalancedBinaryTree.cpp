#include <cassert>
#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode> sk;
        if (root == NULL)
        {
            return true;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        sk.push(root);

        while(!sk.empty()) {
            TreeNode *cur = sk.top();
            sk.pop();
            if (cur->left == NULL && cur->right == NULL)
            {

            }
            if (cur->left != NULL)
            {

            }
        }

    }
};