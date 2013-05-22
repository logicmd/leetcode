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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        int sum = 0;
        gather(root, sum);
        return sum;
    }

    void gather(TreeNode *root, int &sum) {
        if (root->left != NULL) {
            root->left->val += root->val*10;
            gather(root->left, sum);
        }
        if (root->right != NULL) {
            root->right->val += root->val*10;
            gather(root->right, sum);
        }
        if (root->left == NULL && root->right == NULL){
            sum += root->val;
        }
    }
};