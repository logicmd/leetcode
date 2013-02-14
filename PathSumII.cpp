// 开始看错题了
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (root == NULL)
        {
            return ret;
        }

        vector<int> vt;
        dfs(root, sum, vt, ret);
        return ret;
    }

    bool dfs(TreeNode *root, int sum, vector<int> &vt, vector<vector<int> > &list)
    {
        vector<int> vtt(vt);
        int v = root->val;
        if(v > sum)
        {
            return false;
        }

        if (v == sum)
        {
            vtt.push_back(v);
            list.push_back(vtt);
            return true;
        }


        if (root->left != NULL)
        {
            vtt.push_back(v);
            dfs(root->left, sum - v, vtt, list);
            vtt.erase(vtt.end() - 1);
        }

        if (root->right != NULL)
        {
            vtt.push_back(v);
            dfs(root->right, sum - v, vtt, list);
            vtt.erase(vtt.end() - 1);
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    //cout << "hello world!" << endl;
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int> > list = s.pathSum(root, 22);

    for(int i = 0; i < list.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < list[i].size(); ++j)
        {
            cout << list[i][j] << " ";
        }
        cout << "]" << endl;
    }

    system("PAUSE");
    return 0;
}