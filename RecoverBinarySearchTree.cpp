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

class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root != NULL) {
            vector<TreeNode*> v;
            vector<TreeNode*>().swap(v);
            check(root, v);

            TreeNode * tmp;
            tmp = v[0];
            v[0] = v[1];
            v[1] = tmp;
        }
        return;

    }
    void check(TreeNode *root, vector<TreeNode*> &v) {
        if(root->left != NULL) {

            if (root->left->val < root->val) {
                check(root->left, v);
            } else {
                v.push_back(root->left);
                if(v.size()==2) {
                    return;
                }
            }
        }
        if(root->right != NULL) {
            if(root->right->val > root->val) {
                check(root->right, v);
            } else {
                v.push_back(root->right);
                if(v.size()==2) {
                    return;
                }
            }
        }

        return;
    }
};

int main() {
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(1);

    Solution s;
    s.recoverTree(root);
}