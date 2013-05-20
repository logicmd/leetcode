//ac
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


struct Node {
public:
    TreeLinkNode *node;
    int level;
    Node() {
        node = NULL;
        level = -1;
    }
    Node(TreeLinkNode *n, int l) {
        node = n;
        level = l;
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<Node> q;
        if (root == NULL)
        {
            return;
        }
        Node r(root, 1);
        q.push(r);

        Node last;
        while(!q.empty()) {
            Node cur = q.front();
            q.pop();
            int lev = cur.level;
            if (cur.node->left != NULL)
            {
                Node left(cur.node->left, lev+1);
                q.push(left);
            }
            if (cur.node->right != NULL)
            {
                Node right(cur.node->right, lev+1);
                q.push(right);
            }
            if (last.node != NULL)
            {
                if (last.level == cur.level)
                {
                    last.node->next = cur.node;
                }
                else
                {
                    last.node->next = NULL;
                }
            }
            last = cur;
            if(q.empty())
            {
                cur.node->next = NULL;
            }
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode *n(0);
    s.connect(n);
    return 0;
}