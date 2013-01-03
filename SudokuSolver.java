import java.util.HashSet;
import java.util.Set;
public class SudokuSolver {

    public static void main(String args[]){
        SudokuSolver m = new SudokuSolver();
        int[] set = {0,2,4,5,6,7,8,9};
        int[] candidates = m.getCandidates(set);
        for ( int c : candidates ) {
            System.out.println(c);
        }

        //System.out.println(m.solveSudoku(b));
    }

    public void solveSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int[] row = new int[9];
                    int[] col = new int[9];
                    int[] mat = new int[9];
                    for (int rj = 0; rj < 9; ++rj) {
                        row[rj] = (int) (board[i][rj] - '0');
                    }
                    for (int ci = 0; ci < 9; ++ci) {
                        col[ci] = (int) (board[ci][j] - '0');
                    }
                    for (int mi = i/3*3; mi < i/3*3+3; ++mi) {
                        for (int mj = j/3*3; mj < j/3*3+3; ++mj) {
                            mat[mi*3+mj] = (int) (board[mi][mj] - '0');
                        }
                    }

                }
            }
        }
    }

    public int getInt(char c) {
        return (int) (c-'0');
    }
    public int[] getSet(int[] row, int[] col, int[] mat) {
        int[] re = new int[10];
        for (int i = 0; i < 9; ++i) {
            if(row[i]!=-2) {

            }
        }
    }

    public int[] getCandidates(int[] set) {
        int[] re = new int[10 - set.length];
        for (int i = 0, j = 0, k = 0; j < set.length; ++i) {
            if (set[j] == i) {
                ++j;
            } else {
                re[k] = i;
                ++k;
            }
        }
        return re;
    }
}