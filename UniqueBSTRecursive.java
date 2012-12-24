// Recursion -> Iteration
// Wrong
public class UniqueBSTRecursive {

    public static void main(String args[]){
        UniqueBST m = new UniqueBST();
        System.out.println(
            m.uniquePathsWithObstacles(obstacleGrid)
            );
    }
    public int numTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        if(n==0) {
            return 1;
        }
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }


        int r = 0;
        for (int i = 3; i < n+1; ++i) {
            int mid = 0;
            for (int j = 0; j < i/2.0; j++) { // 2.0 is so important or i/2 is a int.
                r += numTrees(j) * numTrees(i-1-j) * 2;
                if(j==i/2) {
                    mid = numTrees(j);
                }
            }
            if (i%2!=0) {
                r -= mid * mid;
            }
        }

        return r;
    }

}