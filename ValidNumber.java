/**
 * too much trivial stuff
 */
public class ValidNumber {

    public static void main(String args[]){
        ValidNumber vn = new ValidNumber();
        System.out.println(
            vn.isNumber("[")
            );
    }
    public boolean isNumber(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        for ( int i = 0; i < s.length(); i++ ) {
            char c = s.charAt(i);
            if(c>='0' && c<='9') {
                continue;
            } else if( c=='e' || c=='.' || c==' ' ) {
                if( i-1>=0 && s.charAt(i-1)>='0' && s.charAt(i-1)<='9') {
                    continue;
                }
                return false;
            } else {
                return false;
            }
        }
        return true;
    }

}