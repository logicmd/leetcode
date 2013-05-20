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
    void preorder(TreeNode *root) {
        cout << root.val;
        if (root->left)
        {
            preorder(root->left);
        }
        if (root->right)
        {
            preorder(root->right);
        }

    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            /* code */
        }
    }
};