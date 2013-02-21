import java.util.ArrayList;
public class PascalsTriangleII {
    public static void main(String[] args) {
        PascalsTriangleII p = new PascalsTriangleII();
        // System.out.println(p.uponEnd(3));
        // System.out.println(p.uponEnd(7));
        // System.out.println(p.uponEnd(12));
        //TreeLinkNode r = new TreeLinkNode(0);
        //p.connect(r);
        for ( int k : p.getRow(6) ) {
            System.out.println(k);
        }
    }
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> pre = new ArrayList<Integer>();
        ArrayList<Integer> ret = new ArrayList<Integer>();

        if (rowIndex+1 == 1) {
            ret.add(1);
            return ret;
        }
        if (rowIndex+1 == 2) {
            ret.add(1);
            ret.add(1);
            return ret;
        }
        pre.add(1);
        pre.add(1);
        for (int k = 2; k < rowIndex + 2; ++k) {
            ret = new ArrayList<Integer>();
            ret.add(1);
            for (int i = 0; i < k - 2; ++i) {
                ret.add(pre.get(i) + pre.get(i + 1));
            }
            ret.add(1);
            pre = new ArrayList<Integer>(ret);
        }
        return ret;
    }

}