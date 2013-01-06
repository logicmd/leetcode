import java.util.ArrayList;

public class SpiralMatrix {

    public static void main(String args[]){
        SpiralMatrix sm = new SpiralMatrix();
        int[][] m = {{1}};
        sm.spiralOrder(m);
    }
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> ret = new ArrayList<Integer>();

        if (matrix==null) {
            return ret;
        }
        int m = matrix.length;
        if (m==0) {
            return ret;
        }
        int n = matrix[0].length;


        int[][] direction = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        int i = 0, j = 0, d = 0;

        boolean[][] b = new boolean[m][n];
        while(i>=0&&i<m&&j>=0&&j<n&&!b[i][j]) {
            ret.add(matrix[i][j]);
            b[i][j]=true;
            i+=direction[d][0];
            j+=direction[d][1];
            for (int k = 1; k <= 4; ++k) {
                if (!(i>=0&&i<m&&j>=0&&j<n&&!b[i][j])) {
                    i-=direction[d][0];
                    j-=direction[d][1];
                    d=(d+k)%4;
                    i+=direction[d][0];
                    j+=direction[d][1];
                }
            }

        }
        return ret;
    }

}