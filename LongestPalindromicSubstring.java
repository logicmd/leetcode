// aaabaaa 不唯一，回溯的顺序 case 2/case 1
// aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa
// TLE
//
public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        //System.out.println(new StringBuffer().append("a").reverse().toString());
        LongestPalindromicSubstring lps = new LongestPalindromicSubstring();
        //System.out.println(lps.longestPalindrome("aaabaaa"));
        System.out.println(lps.longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"));
    }
    public String longestPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        String sr = new StringBuffer().append(s).reverse().toString();
        //System.out.println(sr);
        return getLCS(s, sr);
    }

    public String getLCS(String s, String t) {
        int m = s.length();
        int n = t.length();

        if (m==0 || n==0) {
            return "";
        }
        int[][] mat = new int[m+1][n+1];
        int[][] path = new int[m+1][n+1];
        for (int i=0; i<m+1; ++i) {
            mat[i][0] = 0;
            path[i][0] = 0;
        }
        for (int j=0; j<n+1; ++j) {
            mat[0][j] = 0;
            path[0][j] = 0;
        }



        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                if (s.charAt(i-1)==t.charAt(j-1)) {
                    mat[i][j] = mat[i-1][j-1]+1;
                    path[i][j] = -1;
                } else {
                    mat[i][j] = mat[i][j-1]>mat[i-1][j]?mat[i][j-1]:mat[i-1][j];
                    path[i][j] = mat[i][j-1]>mat[i-1][j]?1:2;
                }

            }
        }

        // Traceback
        StringBuffer ret = new StringBuffer();
        int i=m, j=n;
        boolean bflag = false;
        while(i>-1&&j>-1) {
            if (bflag) {
                break;
            }
            switch(path[i][j]) {
                case 0:
                    bflag=true;
                    break;
                case 2:
                    i--;
                    break;
                case 1:
                    j--;
                    break;

                case -1:
                    ret.append(s.charAt(i-1));
                    i--; j--;
                    break;
            }
        }



        return ret.reverse().toString();
        //return mat[m][n];
    }
}