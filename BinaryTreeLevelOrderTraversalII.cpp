/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
    TreeNode *node;
    int level;
    Node() {
        node = NULL;
        level = -1;
    }
    Node(TreeNode *n, int l) {
        node = n;
        level = l;
    }
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > vv;

        vector<vector<int> >().swap(vv);
        if(root == NULL) {
            return vv;
        }

        queue<Node> q;
        Node r(root, 1);
        q.push(r);
        bfs(r, q, vv);
        return vv;
    }
    void bfs(Node n, queue<Node> &q, vector<vector<int> > &vv) {
        int last = -1;
        vector<int> v;
        vector<int>().swap(v);
        while(!q.empty()) {
            Node cur = q.front();
            q.pop();
            if(cur.node->left != NULL) {
                Node l(cur.node->left, cur.level+1);
                q.push(l);
            }
            if(cur.node->right != NULL) {
                Node r(cur.node->right, cur.level+1);
                q.push(r);
            }
            if(cur.level != last) {
                if(v.size() > 0) {
                    vv.push_back(v);
                }

                vector<int>().swap(v);
                //v.push_back(cur.node->val);
            }
            v.push_back(cur.node->val);
            last = cur.level;
            if(q.empty()) {
                vv.push_back(v);
            }
        }
        reverse(vv.begin(),vv.end());
    }

};