// DP
public class UniquePath {

    public static void main(String args[]){
        UniquePath m = new UniquePath();
        System.out.println(
            m.uniquePaths(2,2)
            );
    }
    public int uniquePaths(int m, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[][] uniquePath = new int[m][n];

        uniquePath[m-1][n-1] = 1;
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if(i+1<m){
                    uniquePath[i][j] += uniquePath[i+1][j];
                }
                if(j+1<n){
                    uniquePath[i][j] += uniquePath[i][j+1];
                }

            }

        }

        return uniquePath[0][0];
    }

}