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
        set<int> depth;
        int level = 1;
        dfs(root, depth, level);

        if (depth.size() < 2)
        {
            return true;
        }

        int max = *(depth.end()--);
        int min = *(depth.begin());

        return (max-min<2);

    }
    void postorder(TreeNode *root, set<int> & depth, int& level) {


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

        if (root->left == NULL && root->right == NULL)
        {
            depth.insert(level);
        }
    }
};