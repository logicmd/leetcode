/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Accepted!
public class ValidateBinarySearchTree {

    public static void main(String args[]){
        ValidateBinarySearchTree bst = new ValidateBinarySearchTree();
        System.out.println(
            "Hello world"
            );
    }
    public boolean isValidBST(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return validateBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public boolean validateBST(TreeNode root, int lowerBound, int upperBound) {
        if (root != null) {
            if (root.left != null) {
                if (root.left.val >= root.val ||
                    root.left.val <= lowerBound ||
                    root.left.val >= upperBound) {
                    return false;
                }
                if ( !validateBST(root.left, lowerBound, root.val) ) {
                    return false;
                }
            }

            if (root.right != null) {
                if (root.right.val <= root.val ||
                    root.right.val <= lowerBound ||
                    root.right.val >= upperBound) {
                    return false;
                }
                if ( !validateBST(root.right, root.val, upperBound) ) {
                    return false;
                }
            }
        }

        return true;
    }

}