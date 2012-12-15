/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class ValidateBinarySearchTree {

    public static void main(String args[]){
        ValidateBinarySearchTree bst = new ValidateBinarySearchTree();
        System.out.println(
            "Hello world"
            );
        //TLE...
    }
    public boolean isValidBST(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (root.left != null) {
            if (root.left.val < root.val) {

            }
        }
    }
}