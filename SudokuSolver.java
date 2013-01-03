public class SudokuSolver {

    public static void main(String args[]){
        SudokuSolver m = new SudokuSolver();
        // int[] set = {0,2,4,5,6,7,8,9};
        // int[] candidates = m.getCandidates(set);
        // for ( int c : candidates ) {
        //     System.out.println(c);
        // }

        char[][] b = {
          "..9748...".toCharArray(),
          "7........".toCharArray(),
          ".2.1.9...".toCharArray(),
          "..7...24.".toCharArray(),
          ".64.1.59.".toCharArray(),
          ".98...3..".toCharArray(),
          "...8.3.2.".toCharArray(),
          "........6".toCharArray(),
          "...2759..".toCharArray()
        };
        // for (char[] charArray : b) {
        //     for (char c : charArray ) {
        //         System.out.print(c);
        //     }
        //     System.out.println();
        // }
        m.solveSudoku(b);

        //int[] set = {3,5,6,7,8};
        // int[] set = {0,0,1,0,1,1,1,1,0};
        // int[] c = m.getCandidates(set);
        // for (int i:c) {
        //     System.out.println(i);
        // }

        // int i=0, j=2;
        // getCandidates(board, i, j);
    }

    public void solveSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function

         if(solve(board)) {
             for (char[] charArray : board) {
                 for (char c : charArray ) {
                     System.out.print(c);
                 }
                 System.out.println();
             }
         }
        //solve(board);

    }

    public boolean solve(char[][] board) {
        int size = Integer.MAX_VALUE;
        int[] candidates = {-1};
        int[] pos = {-1,-1};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int[] canTemp = getCandidates(board, i, j);
                    if (canTemp.length == 0) {
                        return false;
                    }
                    if (canTemp.length < size) {
                        pos[0] = i; pos[1] = j;
                        candidates = canTemp;
                        size = canTemp.length;
                    }
                }
            }
        }
        if (size == Integer.MAX_VALUE) {
            return true;
        }
        for ( int i : candidates) {
            board[pos[0]][pos[1]] = (char) (i + '0');
            if (solve(board)) {
                return true;
            }
        }
        return false;

    }

    public int[] getCandidates(char[][] board, int i, int j) {
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
                mat[(mi-i/3*3)*3+mj-j/3*3] = (int) (board[mi][mj] - '0');
            }
        }
        int[] set = getSet(row, col, mat);
        int[] candidates = getCandidates(set);
        // for (int k:candidates ) {
        //     System.out.print(k);
        // }
        return candidates;
    }

    public int[] getSet(int[] row, int[] col, int[] mat) {
        int offset = (int) ('.' - '0');
        int[] re = new int[9];
        int c = 0;
        for (int i = 0; i < 9; ++i) {
            if(row[i]!=offset) {
                if(re[row[i]-1]==0) {
                    c++;
                    re[row[i]-1]=1;
                }
            }
            if(col[i]!=offset) {
                if(re[col[i]-1]==0) {
                    c++;
                    re[col[i]-1]=1;
                }
            }
            if(mat[i]!=offset) {
                if(re[mat[i]-1]==0) {
                    c++;
                    re[mat[i]-1]=1;
                }
            }
        }
        return re;
    }
    public int[] getCandidates(int[] set) {
        int sum = 0;
        for ( int k:set ) {
            sum += k;
        }
        int[] re = new int[9 - sum];
        for ( int i = 0, j = 0; i < set.length; ++i) {
            if(set[i]==0) {
                re[j] = i+1;
                ++j;
            }
        }
        return re;
    }
}