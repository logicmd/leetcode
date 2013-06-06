// inorder.size()是unsigned int
// 0 - 1 = 2^32 - 1；
//
// vector<int> leftin(inorder.begin(), inorder.begin() + ind - 1)
// 左闭右开
//
// MLE


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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() == 0 || postorder.size() == 0) {
            TreeNode *root = NULL;
            return root;
        }
        TreeNode *root = new TreeNode(*(postorder.end()-1));
        dfs(inorder, postorder, root);
        return root;
    }

    void dfs(vector<int> &inorder, vector<int> &postorder, TreeNode *root) {
        int v = root->val;
        int ind = find(inorder, v);


        if(ind >= 1) {
            vector<int> leftin(inorder.begin(), inorder.begin() + ind);
            vector<int> leftpost(postorder.begin(), postorder.begin() + ind);
            root->left = new TreeNode(*(leftpost.end() - 1));
            dfs(leftin, leftpost, root->left);
        }

        if(ind + 2 <= inorder.size()) {
            vector<int> rightin(inorder.begin() + ind + 1, inorder.end());
            vector<int> rightpost(postorder.begin() + ind, postorder.end() - 1);
            root->right = new TreeNode(*(rightpost.end() - 1));
            dfs(rightin, rightpost, root->right);
        }

        return ;

    }
};

int main()
{
    Solution s;
    int a[] = {2, 1};
    vector<int> inorder(a, a + 2);
    vector<int> postorder(a, a + 2);
    TreeNode *node = s.buildTree(inorder, postorder);

    system("PAUSE");
    return 0;
}