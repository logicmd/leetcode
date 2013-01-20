/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class BinaryTreeMaximumPathSum {
    public static void main(String[] args) {
        BinaryTreeMaximumPathSum p = new BinaryTreeMaximumPathSum();
    }
    public int maxPathSum(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int max = root.val;
        int ret = maxSum(root, max);
        return Math.max(max, ret);
    }

    int maxSum(TreeNode root, int max) {
        if (root == null) {
            return 0;
        }
        int left = maxSum(root.left, max);
        int right = maxSum(root.right, max);
        int localMax = root.val;
        if (left > 0) {
            localMax += left;
        }
        if (right > 0) {
            localMax += right;
        }
        max = Math.max(max, localMax);
        return Math.max(root.val, root.left.val, root.right.val);
    }
}