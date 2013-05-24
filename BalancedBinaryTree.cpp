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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int d = 0;
        return dfs(root, d);

    }
    bool dfs(TreeNode *root, int& depth)
    {

        if (root == NULL)
        {
            depth = 0;
            return true;
        }

        int left_depth = 0, right_depth = 0;
        bool left_balance = dfs(root->left, left_depth);
        bool right_balance = dfs(root->right, right_depth);

        depth = max(left_depth, right_depth) + 1;

        return left_balance && right_balance && (abs(left_depth - right_depth) <= 1);
    }
};