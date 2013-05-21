//ac
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode *node;
    int level;
    Node(TreeNode *n, int l) {
        n = node;
        l = level;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
        {
            return true;
        }


        return (max-min<2);

    }
    void postorder(TreeNode *root, int& depth)
    {


        if(root->left != NULL)
        {
            depth--;
            dfs(root->left, depth);
            depth++;
        }

        if(root->right != NULL)
        {
            depth--;
            dfs(root->right, depth);
            depth++;
        }

        if (root->left == NULL && root->right == NULL)
        {
            depth = 0;
        }
    }
};