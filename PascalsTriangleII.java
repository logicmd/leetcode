public class PascalsTriangleII {
    public static void main(String[] args) {
        PascalsTriangleII p = new PascalsTriangleII();
        // System.out.println(p.uponEnd(3));
        // System.out.println(p.uponEnd(7));
        // System.out.println(p.uponEnd(12));
        TreeLinkNode r = new TreeLinkNode(0);
        p.connect(r);
    }
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(1);

        if (rowIndex == 1) {
            return list;
        }

    }

}