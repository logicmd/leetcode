public class ValidPalindrome {
    public static void main(String[] args) {
        ValidPalindrome p = new ValidPalindrome();
        System.out.println(p.isPalindrome("A man, a plan, a canal: Panama"));
    }
    public boolean isPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        String n = normalize(s);
        //System.out.println(n);
        for (int i=0; i<n.length()/2; i++ ) {
            if (n.charAt(i) != n.charAt(n.length()-i-1)) {
                return false;
            }
        }
        return true;
    }

    String normalize(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c:s.toCharArray()) {
            if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
                if (c >= 'A' && c <= 'Z') {
                    c -= ('A' - 'a');
                }
                sb.append(c);
            }
        }
        return sb.toString();
    }

}