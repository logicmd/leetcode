/*
 * WA
 */

public class RegularExpressionMatching {

    public static void main(String args[]){
        RegularExpressionMatching regexp = new RegularExpressionMatching();
        System.out.println(
            regexp.isMatch(
                "aaa",
                "ab*ac*a"));
        //TLE...
    }



    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
        p = normalize(p);
        //System.out.println(p);
        return match(s, p);
    }

    public String normalize(String p) {
        boolean[] asterisk = new boolean[p.length()];
        for (int i=0; i<p.length()-1; i++) {
            if (p.charAt(i)=='*' && p.charAt(i+1)=='*' ) {
                asterisk[i+1] = true;
            }
        }
        StringBuilder p_normalized = new StringBuilder();
        for (int i=0; i<asterisk.length; ++i) {
            if (!asterisk[i]) {
                p_normalized.append(p.charAt(i));
            }
        }
        return p_normalized.toString();
    }

    public boolean match(String s, String p) {
        // p is normalized
        if( s.equals("") && p.equals("") ) {
            return true;
        } else if ( s.equals("") && p.charAt(0) == '*' )  {
            return match(s.substring(0), p.substring(1));
        } else if ( (s.equals("") && !p.equals(""))
            || (p.equals("") && !s.equals("")) ) {
            return false;
        } else {
            if ( p.charAt(0) == '.' || s.charAt(0) == p.charAt(0) ) {
                return match(s.substring(1), p.substring(1));
            } else if ( p.charAt(0) == '*' ) {
                for (int i=0; i<=s.length(); i++) {
                    if ( match(s.substring(i), p.substring(1)) ) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

}