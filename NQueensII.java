import java.util.ArrayList;
public class NQueensII {
    int num;
    public int totalNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        num = 0;

        StringBuilder[] chess = new StringBuilder[n];

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
        if (row >= n) {
            return;
        }
        for (int j=0; j<n; ++j) {
            chess[row].setCharAt(j, 'Q');
            if (validate(chess, row, j)) {
                if (row == n-1) {
                    num++;
                } else {
                    dfs(chess, row + 1);
                }
            }
            chess[row].setCharAt(j, '.');
        }

        return;
    }

    boolean validate(StringBuilder[] chess, int row, int col) {
        int n = chess.length;
        for (int i=0; i<n; ++i) {
            if (i!=row && chess[i].charAt(col)=='Q') {
                return false;
            }
        }

        int i = row, j = col;
        while(i>=0 && j>=0) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                return false;
            }
            i--; j--;
        }

        i = row; j = col;
        while(i<n && j<n) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                return false;
            }
            i++; j++;
        }

        i = row; j = col;
        while(i<n && j>=0) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                return false;
            }
            i++; j--;
        }

        i = row; j = col;
        while(i>=0 && j<n) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                //System.out.println('2');
                return false;
            }
            i--; j++;
        }

        return true;
    }

    public static void main(String[] args) {
        NQueensII qs = new NQueensII();
        System.out.println(qs.totalNQueens(4));
    }
}