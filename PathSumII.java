// AC
import java.util.ArrayList;
public class PathSumII {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static void main(String args[]){
        PathSumII p = new PathSumII();
        TreeNode root = p.new TreeNode(5);
        root.left = p.new TreeNode(4);
        root.left.left = p.new TreeNode(11);
        root.left.left.left = p.new TreeNode(7);
        root.left.left.right = p.new TreeNode(2);
        root.right = p.new TreeNode(8);
        root.right.left = p.new TreeNode(13);
        root.right.right = p.new TreeNode(4);
        root.right.right.left = p.new TreeNode(5);
        root.right.right.right = p.new TreeNode(1);
        //http://stackoverflow.com/questions/70324/java-inner-class-and-static-nested-class
        ArrayList<ArrayList<Integer>> list = p.pathSum(root, 22);
        for (ArrayList<Integer> al : list) {
            System.out.print("[ ");
            for (int i : al) {
               System.out.print(i + " ");
            }
            System.out.println("]");
        }
    }

    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        if (root == null) {
            return ret;
        }

        ArrayList<Integer> vt = new ArrayList<Integer>();
        dfs(root, sum, vt, ret);
        return ret;

    }

    boolean dfs(TreeNode root, int sum, ArrayList<Integer> vt, ArrayList<ArrayList<Integer>> list) {
        ArrayList<Integer> vtt = new ArrayList<Integer>(vt);
        int v = root.val;
        if (sum==v && root.left==null && root.right==null) {
            vtt.add(v);
            list.add(vtt);
            return true;
        }

        if (root.left != null) {
            vtt.add(v);
            dfs(root.left, sum - v, vtt, list);
            vtt.remove(vtt.size() - 1);
        }

        if (root.right != null) {
            vtt.add(v);
            dfs(root.right, sum - v, vtt, list);
            vtt.remove(vtt.size() - 1);
        }
        return false;
    }


}