// 数学做法不好使。
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
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        if (m < n) {
            int temp = m;
            m = n;
            n = temp;
        }
        int[] t = {4,2,1};
        int sum = 0;
        for (int i=0; i<obstacleGrid.length; i++) {
            for (int j=0; j<obstacleGrid[0].length; j++) {
                if (obstacleGrid[i][j] == 1) {
                    int minus = 0;
                    if(i == 0 || i == obstacleGrid.length - 1) {
                        minus++;
                    }
                    if(j == 0 || j == obstacleGrid[0].length - 1) {
                        minus++;
                    }
                    sum += t[minus];
                }


            }
        }

        return (int) (factorial(m-1, m+n-2) / factorial(n-1)) - sum;
    }

    public long factorial(int x) {
        long r = 1;
        while(x>0) {
            r*=x;
            x--;
        }
        return r;
    }

    public long factorial(int x, int y) {
        long r = 1;
        while(y>x) {
            r*=y;
            y--;
        }
        return r;
    }
}