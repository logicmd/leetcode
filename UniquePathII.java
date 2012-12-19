// DP
public class UniquePathII {

    public static void main(String args[]){
        UniquePathII m = new UniquePathII();
        int[][] obstacleGrid = {{0,0}};
        System.out.println(
            m.uniquePathsWithObstacles(obstacleGrid)
            );
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // Start typing your Java solution below
        // DO NOT write main() function

        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        int[][] uniquePath = new int[m][n];
        if(obstacleGrid[m-1][n-1]==1) {
            return 0;
        }
        uniquePath[m-1][n-1] = 1;

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if(obstacleGrid[i][j]==1) {
                    uniquePath[i][j]=0;
                    continue;
                }
                if(i+1<m) {
                    uniquePath[i][j] += uniquePath[i+1][j];
                }
                if(j+1<n) {
                    uniquePath[i][j] += uniquePath[i][j+1];
                }

            }

        }

        return uniquePath[0][0];
    }

}