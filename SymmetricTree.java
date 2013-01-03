public class SymmetricTree {

    public static void main(String args[]){
        SymmetricTree m = new SymmetricTree();
        System.out.println(
            m.isSymmetric(A)
            );
    }
    public boolean isSymmetric(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (root == null) {
            return true;
        }
        if (root.left == null && root.right == null) {
            return true;
        }
        if ( (root.left == null && root.right != null) ||
            (root.left != null && root.right == null) ) {
            return false;
        }

        return isSymmetric(root.left, root.right);
    }
    public boolean isSymmetric(TreeNode leftTN, TreeNode rightTN) {
        // if ( (leftTN.left==null && rightTN.right==null) ||
        //     (leftTN.right==null && rightTN.left==null) ) {
        //     return true;
        // }
        if (leftTN.val != rightTN.val) {
            return false;
        }
        if ( (leftTN.left!=null && rightTN.right==null) ||
            (leftTN.left==null && rightTN.right!=null) ||
            (leftTN.right!=null && rightTN.left==null) ||
            (leftTN.right==null && rightTN.left!=null) ) {
            return false;
        }
        if (leftTN.left!=null) {
            if (!isSymmetric(leftTN.left, rightTN.right)) {
                return false;
            }
        }
        if (leftTN.right!=null) {
            if (!isSymmetric(leftTN.right, rightTN.left)) {
                return false;
            }
        }
        return true;
    }
}