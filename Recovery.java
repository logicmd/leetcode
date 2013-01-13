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

    public void recoverTree(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode leftWierd = null;
        TreeNode rightWierd = null;
        traverseTree(root, leftWierd, rightWierd);
        int temp = leftWierd.val;
        leftWierd.val = rightWierd.val;
        rightWierd.val = temp;
    }

    void traverseTree(TreeNode root, TreeNode leftWierd, TreeNode rightWierd) {
        if (root.left != null) {
            if (root.left.val > root.val) {
                rightWierd = root.right;
            }
            if (leftWierd != null && rightWierd != null) {
                traverseTree(root.left, leftWierd, rightWierd);
            }

        }

        if (root.right != null ) {
            if (root.right.val > root.val) {
                rightWierd = root.right;
            }
            if (leftWierd != null && rightWierd != null) {
                traverseTree(root.right, leftWierd, rightWierd);
            }
        }
    }
}