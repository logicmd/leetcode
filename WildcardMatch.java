/*
 * 注意：string相等用equals
 */

public class WildcardMatch {

    public static void main(String args[]){
        WildcardMatch wm = new WildcardMatch();
        System.out.println(
            wm.isMatch(
                "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab",
                "***bba**a*bbba**aab**b"));
        //TLE...
    }

    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if( s.equals("") && p.equals("") ) {
            return true;
        } else if ( s.equals("") && p.charAt(0) == '*' )  {
            return isMatch(s.substring(0), p.substring(1));
        } else if ( (s.equals("") && !p.equals(""))
            || (p.equals("") && !s.equals("")) ) {
            return false;
        } else {
            if ( p.charAt(0) == '?' || s.charAt(0) == p.charAt(0) ) {
                return isMatch(s.substring(1), p.substring(1));
            } else if ( p.charAt(0) == '*' ) {
                for (int i=0; i<=s.length(); i++) {
                    if ( isMatch(s.substring(i), p.substring(1)) ) {
                        return true;
                    }
                }
                return false;
            } else {
                return false;
            }
        }
    }

}