import java.util.ArrayList;

public class SpiralMatrixII {

    public static void main(String args[]){

    }
    public int[][] generateMatrix(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n<=0) {
            return new int[0][0];
        }
        int[][] ret = new int[n][n];
        int[][] direction = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        int i = 0, j = 0, d = 0;
        int c = 1;
        while(i>=0&&i<n&&j>=0&&j<n&&ret[i][j]==0) {
            ret[i][j]=c;
            i+=direction[d][0];
            j+=direction[d][1];
            for (int k = 1; k <= 4; ++k) {
                if (!(i>=0&&i<n&&j>=0&&j<n&&ret[i][j]==0)) {
                    i-=direction[d][0];
                    j-=direction[d][1];
                    d=(d+k)%4;
                    i+=direction[d][0];
                    j+=direction[d][1];
                }
            }
            c++;
        }
        return ret;
    }

}