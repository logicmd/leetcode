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

    int curMax;

    public int maxPathSum(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        curMax = Integer.MIN_VALUE;
        int pathMax = maxSum(root);
        return curMax;
    }

    int maxSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = maxSum(root.left);
        int right = maxSum(root.right);

        //the max from left child to right child, accross from root
        int arcMax = root.val;
        if (left > 0) {
            arcMax += left;
        }
        if (right > 0) {
            arcMax += right;
        }
        if (arcMax > curMax) {
            curMax = arcMax;
        }

        //the max that end in root
        int pathMax = root.val;
        int subMax = left > right ? left : right;
        if(subMax > 0) {
            pathMax += subMax;
        }
        //curMax = Math.max(curMax, pathMax);
        return pathMax;
    }
}