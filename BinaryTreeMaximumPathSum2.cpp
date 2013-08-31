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
    int _max;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(root==NULL)
            return 0;
        _max = -1<<28;
        dfs(root);
        return _max;
    }

    int dfs(TreeNode *root) {

        if(!(root->left||root->right)) {
            _max=max(root->val,_max);
            return root->val;
        }
        int leftpath=-1<<28, rightpath=-1<<28;
        if(root->left) {
            leftpath=dfs(root->left);
        }
        if(root->right) {
            rightpath=dfs(root->right);
        }
        int arcsum=0;
        int val=root->val;
        arcsum = max(val, max(val+leftpath,
                max(val+rightpath, max(leftpath, max(rightpath, val+leftpath+rightpath)))));


        _max = max(arcsum, _max);

        return max(leftpath,rightpath)+val;
    }
};