import java.util.ArrayList;
public class NQueensII {
    int num;
    boolean[] colFlags;
    boolean[] lDiaFlags;
    boolean[] rDiaFlags;
    public int totalNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        StringBuilder[] chess = new StringBuilder[n];

        num = 0;
        colFlags = new boolean[n];
        lDiaFlags = new boolean[2*n-1];
        rDiaFlags = new boolean[2*n-1];

        for (int k=0; k<n; ++k) {
            chess[k] = new StringBuilder(n);
            for (int j=0; j<n; ++j) {
                chess[k].append('.');
            }
        }

        dfs(chess, 0);

        // for (String[] chess_:ret ) {
        //     for (String s : chess_) {
        //        System.out.println(s);
        //     }
        //     System.out.println();
        // }
        return num;
    }

    void dfs(StringBuilder[] chess, int row) {
        int n = chess.length;
        for (int j=0; j<n; ++j) {
            if (!colFlags[j] && !lDiaFlags[row+j] && !rDiaFlags[j-row+n-1]) {
                chess[row].setCharAt(j, 'Q');

                colFlags[j] = true;
                lDiaFlags[row+j] = true;
                rDiaFlags[j-row+n-1] = true;

                if (row == n-1) {
                    num++;
                } else {
                    dfs(chess, row + 1);
                }

                colFlags[j] = false;
                lDiaFlags[row+j] = false;
                rDiaFlags[j-row+n-1] = false;

                chess[row].setCharAt(j, '.');
            }


        }

        return;
    }

    public static void main(String[] args) {
        NQueensII qs = new NQueensII();
        System.out.println(qs.totalNQueens(12));
    }
}