#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = 0, total = 0;
        postOrder(root, cur, total);
        return total;
    }

    void postOrder(TreeNode *node, int &cur, int &total) {
        if (node != NULL)
        {
            cur *= 10;
            cur += node->val;
            if (node->left == NULL && node->right == NULL)
            {
                total += cur;
            }

            postOrder(node->left, cur, total);
            postOrder(node->right, cur, total);

            cur -= node->val;
            cur /= 10;
        }
    }
};

int main()
{
    cout << "hello" << endl;
    system("PAUSE");
    return 0;
}