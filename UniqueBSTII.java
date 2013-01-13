public class UniqueBSTII {

    public static void main(String args[]){
        UniqueBSTII m = new UniquUniqueBSTIIeBST();
        System.out.println(
            m.uniquePathsWithObstacles(obstacleGrid)
            );
    }
    public ArrayList<TreeNode> generateTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<TreeNode> l = new ArrayList<TreeNode>();
        if (n==0) {
            l.add(new TreeNode());
            return l;
        }
        ArrayList<TreeNode> list = new ArrayList<TreeNode>();
        dfs(list, 1, n);
    }

    public void dfs(ArrayList<TreeNode> list, int left, int right) {
        for (int i=left; i<=right; ++i) {
            TreeNode root = new TreeNode(i);

        }
    }

}