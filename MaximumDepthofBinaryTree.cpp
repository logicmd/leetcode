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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int l = 1, m = 0;
        dfs(root, l, m);
        return m;
    }
    void dfs(TreeNode *root, int &l, int &max) {
        if(root != NULL) {

            if(l>max)
                max = l;

            ++l;
            dfs(root->left, l, max);
            dfs(root->right, l, max);
            --l;

        }
    }
};