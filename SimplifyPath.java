// AC
import java.util.ArrayList;

public class SimplifyPath {

    public static void main(String args[]){
        SimplifyPath sp = new SimplifyPath();
        //sp.simplifyPath("/a/./b/../../c/");
        //sp.simplifyPath("/.hidden/");
        sp.simplifyPath("/home/of/foo/../../bar/../../is/./here/.");
    }
    public String simplifyPath(String path) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<String> atoms = new ArrayList<String>();
        for (int i=0; i<path.length(); ) {
            if (i+1>path.length()-1) {
                break;
            }
            if (path.charAt(i)=='/') {
                if (path.charAt(i+1)=='/' || path.charAt(i+1)=='.') {
                    i++;
                    continue;
                }
                int m = path.substring(i+1).indexOf('/') + i;
                if (m - i == -1) {
                    m = path.length()-1;
                }

                if (i < m) {
                    atoms.add(path.substring(i+1, m+1));
                }
                i = m+1;
                continue;
            }
            if (path.charAt(i)=='.') {
                if (path.charAt(i+1)=='/') {
                    i++;
                    continue;
                }
                if (path.charAt(i+1)=='.') {
                    int m = path.substring(i+1).indexOf('/') + i;
                    if (m - i== -1) {
                        m = path.length()-1;
                    }
                    i = m;
                    if (atoms.size()!=0) {
                        atoms.remove(atoms.size()-1);
                    }
                    continue;
                }
                int m = path.substring(i+1).indexOf('/') + i;
                if (m - i == -1) {
                    m = path.length()-1;
                }

                if (i < m) {
                    atoms.add(path.substring(i, m+1));
                }
                i = m+1;
                continue;
            }
        }
        if (atoms.size()==0) {
            return "/";
        }
        StringBuffer sb = new StringBuffer();
        for (String s : atoms) {
            sb.append('/');
            sb.append(s);
        }
        //System.out.println(sb.toString());
        return sb.toString();
    }

}