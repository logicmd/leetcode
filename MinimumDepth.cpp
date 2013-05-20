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

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
        {
            return 0;
        }
        set<int> depth;
        int level = 1;
        dfs(root, depth, level);

        return *(depth.begin()++);

    }
    void dfs(TreeNode *root, set<int> & depth, int& level) {
        if (root->left == NULL && root->right == NULL)
        {
            depth.insert(level);
        }

        if(root->left != NULL)
        {
            level++;
            dfs(root->left, depth, level);
            level--;
        }

        if(root->right != NULL)
        {
            level++;
            dfs(root->right, depth, level);
            level--;
        }
    }
};