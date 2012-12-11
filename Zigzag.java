public class ZigZag {

    public static void main(String args[]){
        System.out.println(convert("PAYPALISHIRING", 3));
        //new java.util.Scanner(System.in).nextLine();
    }

    public static String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(nRows == 1)
            return s;

        int len = s.length();
        StringBuffer sb = new StringBuffer();
        int total = nRows * 2 - 2;

        for (int i=0; i<nRows; i++) {
            int inc = (nRows - 1) * 2, inc1, inc2;
            if(i%(nRows-1)==0) {
                for(int j=i; j<len; j+=inc) {
                    sb.append(s.charAt(j));
                }
            } else {
                inc2 = i * 2;
                inc1 = inc - inc2;
                for(int j=i; j<len; j+=inc) {
                    sb.append(s.charAt(j));
                    if(j+inc1<len) {
                        sb.append(s.charAt(j+inc1));
                    } else {
                        break;
                    }
                }
            }
        }
        return sb.toString();
    }
}