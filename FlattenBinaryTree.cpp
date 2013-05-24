// ac
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorder(TreeNode *root, queue<TreeNode *> &q) {
        q.push(root);

        if (root->left != NULL)
        {
            preorder(root->left, q);
        }
        if (root->right != NULL)
        {
            preorder(root->right, q);
        }
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
        {
            return;
        }
        queue<TreeNode *> q;
        preorder(root, q);

        TreeNode *last = root;
        q.pop();

        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            last->right = cur;
            last->left = NULL;

            last = cur;
        }
    }
};