import java.util.ArrayList;
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Recovery {
    ArrayList<TreeNode> v;
    public void recoverTree(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root != null) {
            v = new ArrayList<TreeNode>();
            traverseTree(root);

            System.out.println(v.size());
            TreeNode tmp;
            tmp = v.get(0);
            v.set(0, v.get(1));
            v.set(1, tmp);
        }
        return;
    }

    void traverseTree(TreeNode root) {
        if(root.left != null) {

            if (root.left.val < root.val) {
                traverseTree(root.left);
            } else {
                v.add(root.left);
                if(v.size()==2) {
                    return;
                }
            }
        }
        if(root.right != null) {
            if(root.right.val > root.val) {
                traverseTree(root.right);
            } else {
                v.add(root.right);
                if(v.size()==2) {
                    return;
                }
            }
        }
        return;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(1);

        Recovery s = new Recovery();
        s.recoverTree(root);
    }
}