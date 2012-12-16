// One time accepted!!!
public class ValidateSudoku {

    public static void main(String args[]){
        ValidateSudoku vs = new ValidateSudoku();
        System.out.println(
            "Hello world"
            );
    }
    public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function

        // row
        for(int i = 0; i < 9; i++) {
            char[] array = new char[9];
            for(int j = 0; j < 9; j++) {
                array[j] = board[i][j];
            }
            if(!isValidSet(array)) {
                return false;
            }
        }

        // colomn
        for(int j = 0; j < 9; j++) {
            char[] array = new char[9];
            for(int i = 0; i < 9; i++) {
                array[i] = board[i][j];
            }
            if(!isValidSet(array)) {
                return false;
            }
        }

        // matrix
        for(int k = 0; k < 9; k++) {
            char[] array = new char[9];
            int c = 0;
            for(int i = k/3*3; i < k/3*3+3; i++) {
                for(int j = k%3*3; j < k%3*3+3; j++) {
                    array[c] = board[i][j];
                    c++;
                }
            }
            if(!isValidSet(array)) {
                return false;
            }
        }

        return true;
    }
    public boolean isValidSet(char[] array) {
        int[] set = new int[9];
        for(char c : array) {
            if(c == '.'){
                continue;
            }
            int i = (int)(c - '1');
            if(set[i] == 0) {
                set[i] = 1;
            } else if (set[i] == 1) {
                return false;
            }
        }
        return true;
    }

}