// With help
public class EditDistance {
    public static void main(String[] args) {
        System.out.println(new EditDistance().minDistance("a","a"));
    }

    public int minDistance(String word1, String word2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = word1.length();
        int n = word2.length();
        int[][] mat = new int[m+1][n+1];
        for (int i=0; i<m+1; ++i) {
            mat[i][0] = i;
        }
        for (int j=0; j<n+1; ++j) {
            mat[0][j] = j;
        }
        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                int temp = 1;
                if (word1.charAt(i-1)==word2.charAt(j-1)) {
                    temp = 0;
                }
                mat[i][j] = Math.min(Math.min(mat[i-1][j]+1, mat[i][j-1]+1), mat[i-1][j-1]+temp);
            }
        }

        return mat[m][n];
    }
}