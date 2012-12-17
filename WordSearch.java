/**
 * 注意：回溯时候注意标记走过未走过。
 */
public class WordSearch {

    public static void main(String args[]){
        char[][] c = new char[3][4];

        c[0] = "ABCE".toCharArray();
        c[1] = "SFCS".toCharArray();
        c[2] = "ADEE".toCharArray();
        WordSearch ws = new WordSearch();
        boolean b = ws.exist(c, "SEE");
        System.out.println(b);
        //new java.util.Scanner(System.in).nextLine();
    }

    public boolean exist(char[][] board, String word) {
        // Start typing your Java solution below
        // DO NOT write main() function
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[i].length; j++) {
                if(board[i][j]==word.charAt(0)) {
                    board[i][j] = ' ';
                    if ( find(board, i, j, word.substring(1)) ) {
                        return true;
                    }
                    board[i][j] = word.charAt(0);
                }
            }
        }
        return false;
    }

    public boolean find(char[][] board, int i, int j, String word) {
        if (word.length() == 0) {
            return true;
        }
        int[][] direction = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        for ( int m = 0; m < direction.length; m++ ) {
            int ii = i+direction[m][0];
            int jj = j+direction[m][1];
            if( ii >= 0 && ii < board.length &&
                jj >= 0 && jj < board[i].length &&
                board[ii][jj] == word.charAt(0) ) {
                board[ii][jj] = ' ';
                if( word.length() == 1 ||
                    find(board, ii, jj, word.substring(1)) ) {
                    return true;
                }
                board[ii][jj] = word.charAt(0);
            }
        }
        return false;
    }

}