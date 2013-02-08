public class DistinctSubsequences {
    public static void main(String[] args) {

    }
    public int numDistinct(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = S.length();
        int n = T.length();
        int[][] mat = new int[m][n];

        for (int i=0; i<m+1; ++i) {
            mat[i][0] = 0;
        }

        for (int j=0; j<n+1; ++j) {
            mat[0][j] = 0;
        }

        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                if (i<j) {
                    mat[i][j] = 0;
                    continue;
                }

            }
        }
    }


}