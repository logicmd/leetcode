import java.util.ArrayList;
public class NQueens {
    public ArrayList<String[]> solveNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        ArrayList<String[]> ret = new ArrayList<String[]>();

        String[] chess = new String[n];

        for (int i=0; i<n; ++i) {
            StringBuffer sb = new StringBuffer();
            for (int j=0; j<n; ++j) {
                sb.append('.');
            }
            chess[i] = sb.toString();
        }

        dfs(chess, 0);

        for (String s:chess ) {
            System.out.println(s);
        }
        return ret;
    }

    void dfs(String[] chess, int row) {
        int n = chess.length;
        if (row >= n) {
            return;
        }
        for (int j=0; j<n; ++j) {
            chess[row].charAt(j) = 'Q';
            if (validate(chess, row, j)) {
                dfs(chess, row + 1);
            }
            chess[row].charAt(j) = '.';
        }
    }

    boolean validate(String[] chess, int row, int col) {
        int n = chess.length;
        //System.out.println(n);
        for (int i=0; i<n; ++i) {
            if (i!=row && chess[i].charAt(col)=='Q') {
                //System.out.println('0');
                return false;
            }
        }

        int i = row, j = col;
        while(i>=0 && j>=0) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                //System.out.println('1');
                return false;
            }
            i--; j--;
        }

        i = row; j = col;
        while(i<n && j<n) {
            if (i!=row && chess[i].charAt(j) == 'Q') {
                //System.out.println('2');
                return false;
            }
            i++; j++;
        }

        return true;
    }

    public static void main(String[] args) {
        NQueens qs = new NQueens();
        qs.solveNQueens(4);

        // String[] chess = {
        //     ".Q..",  // Solution 1
        //     "...Q",
        //     "Q...",
        //     "..Q."
        // };
        // System.out.println(qs.validate(chess, 3, 2));
    }
}