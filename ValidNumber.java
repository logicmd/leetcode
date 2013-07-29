/**
 * too much trivial stuff
 * 2. 34 false
 */
public class Solution {
    public boolean isNumber(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.equals("")) return false;
        boolean allsp=true;
        boolean beforesp=false;
        boolean aftersp=false;
        boolean sp=false;
        int ec=0;
        int dc=0;
        for ( int i = 0; i < s.length(); i++ ) {
            char c = s.charAt(i);
            if(c>='0' && c<='9') {
                allsp = false;
                if(beforesp && aftersp) sp=true;

                continue;
            } else if( c=='e' || c=='.') {
                if(c=='e') ec++;
                if(ec>1) return false;
                if(c=='.') dc++;
                if(dc>1) return false;
                
                if(beforesp && aftersp) sp=true;

                
                if( c=='.' && (i-1<0 || i+1>=s.length() || s.charAt(i+1)==' '))
                    continue;
                if( i-1>=0 && s.charAt(i-1)>='0' && s.charAt(i-1)<='9' &&
                    i+1<s.length() && s.charAt(i+1)>='0' && s.charAt(i+1)<='9') {
                    allsp = false;
                    
                    continue;
                }
                return false;
            } else if(c=='+' || c=='-' ) {
                if( i+1<s.length() && s.charAt(i+1)>='0' && s.charAt(i+1)<='9') {
                    allsp = false;
                    continue;
                }
                return false;
            } else if( c==' ' ) {
                if(!sp)
                {
                    if( i-1>=0 && s.charAt(i-1)>='0' && s.charAt(i-1)<='9') {
                        beforesp = true;
                    }
                    if( i+1<s.length() && s.charAt(i+1)>='0' && s.charAt(i+1)<='9') {
                        aftersp = true;
                    }
                    
                }
                continue;
            } else {
                return false;
            }
        }

        return (!allsp)&&(!sp)&&true;
    }
}
