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
    int find(vector<int> &vec, int v) {
        for(int i=0; i<vec.size(); i++) {
            if(v==vec[i]) {
                return i;
            }
        }
        return -1;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.size() == 0 || inorder.size() == 0) {
            TreeNode *root = NULL;
            return root;
        }
        TreeNode *root = new TreeNode(*(preorder.begin()));
        dfs(preorder, inorder, root);
        return root;
    }

    void dfs(vector<int> &preorder, vector<int> &inorder, TreeNode *root) {
        int v = root->val;
        int ind = find(inorder, v);


        if(ind >= 1) {
            vector<int> leftin(inorder.begin(), inorder.begin() + ind);
            vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + ind);
            root->left = new TreeNode(*(leftpre.begin()));
            dfs(leftpre, leftin, root->left);
        }

        if(ind + 2 <= inorder.size()) {
            vector<int> rightin(inorder.begin() + ind + 1, inorder.end());
            vector<int> rightpre(preorder.begin() + 1 + ind, preorder.end());
            root->right = new TreeNode(*(rightpre.begin()));
            dfs(rightpre, rightin, root->right);
        }

        return ;

    }
};
