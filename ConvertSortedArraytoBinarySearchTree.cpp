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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if (n == 0) {
            return NULL;
        }

        if(n > 0) {
            return dfs(0, n-1, num);
        }

    }
    TreeNode * dfs(int s, int e, vector<int> &num) {
        int m = (s+e)/2;
        TreeNode *root = new TreeNode(num[m]);
        if(s < m) {
            root->left = dfs(s, m-1, num);
        }
        if(m < e) {
            root->right = dfs(m+1, e, num);
        }
        return root;
    }
};