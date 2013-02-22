import java.util.ArrayList;
public class NQueens {
    public ArrayList<String[]> solveNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        ArrayList<String[]> ret = new ArrayList<String[]>();

        StringBuilder[] chess = new StringBuilder[n];

        for (int k=0; k<n; ++k) {
            chess[k] = new StringBuilder(n);
            for (int j=0; j<n; ++j) {
                chess[k].append('.');
            }
        }

        // for (StringBuilder sb : chess) {
        //    //sb = new StringBuilder();
        //    for (int j=0; j<n; ++j) {
        //        sb.append('.');
        //    }
        // }

        dfs(chess, 0, ret);

        // for (String[] chess_:ret ) {
        //     for (String s : chess_) {
        //        System.out.println(s);
        //     }
        //     System.out.println();
        // }
        return ret;
    }

    void dfs(StringBuilder[] chess, int row, ArrayList<String[]> set) {
        int n = chess.length;
        for (int j=0; j<n; ++j) {

            if (validate(chess, row, j)) {
                chess[row].setCharAt(j, 'Q');
                if (row == n-1) {
                    String[] s = new String[n];
                    for ( int k = 0; k < n; ++k ) {
                        s[k] = chess[k].toString();
                    }
                    set.add(s);
                } else {
                    dfs(chess, row + 1, set);
                }
                chess[row].setCharAt(j, '.');
            }

        }

        return;
    }

    boolean validate(StringBuilder[] chess, int row, int col) {
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
        NQueens qs = new NQueens();
        System.out.println(qs.solveNQueens(20).size());

        // String[] chess = {
        //     ".Q..",  // Solution 1
        //     "...Q",
        //     "Q...",
        //     "..Q."
        // };
        // System.out.println(qs.validate(chess, 3, 2));
    }
}