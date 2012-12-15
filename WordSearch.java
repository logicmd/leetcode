/*
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
        boolean flag = word.length() == 1 ? true : false;
        if( i-1 >= 0 && board[i-1][j] == word.charAt(0) ) {
            board[i-1][j] = ' ';
            if( flag || find(board, i-1, j, word.substring(1)) )
            {
                return true;
            }
            board[i-1][j] = word.charAt(0);
        }
        if( i+1 < board.length && board[i+1][j] == word.charAt(0) ) {
            board[i+1][j] = ' ';
            if( flag || find(board, i+1, j, word.substring(1)) ) {
                return true;
            }
            board[i+1][j] = word.charAt(0);
        }
        if( j+1 < board[i].length && board[i][j+1] == word.charAt(0) ) {
            board[i][j+1] = ' ';
            if(  flag || find(board, i, j+1, word.substring(1)) ) {
                return true;
            }
            board[i][j+1] = word.charAt(0);
        }
        if( j-1 >= 0 && board[i][j-1] == word.charAt(0) ) {
            board[i][j-1] = ' ';
            if( flag || find(board, i, j-1, word.substring(1)) ) {
                return true;
            }
            board[i][j-1] = word.charAt(0);
        }
        return false;
    }

}