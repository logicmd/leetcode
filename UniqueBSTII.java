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
        if (n==1) {
            TreeNode t = new TreeNode(1);
            l.add(t);
            return l;
        }
        for (int i=1; i<=n; i++) {

        }


    }

}