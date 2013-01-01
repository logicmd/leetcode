import java.util.ArrayList;
public class Triangle {

    public static void main(String args[]){
        // [
        //      [2],
        //     [3,4],
        //    [6,5,7],
        //   [4,1,8,3]
        // ]

        // ArrayList<Integer> t1 = new ArrayList<Integer>();
        // t1.add(1);
        // ArrayList<Integer> t2 = new ArrayList<Integer>();
        // t2.add(2); t2.add(3);
        // ArrayList<Integer> t3 = new ArrayList<Integer>();
        // t3.add(4); t3.add(5); t3.add(6);
        // ArrayList<ArrayList<Integer>> t = new ArrayList<ArrayList<Integer>>();
        // t.add(t1); t.add(t2); t.add(t3);
        ArrayList<Integer> t1 = new ArrayList<Integer>();
        t1.add(2);
        ArrayList<Integer> t2 = new ArrayList<Integer>();
        t2.add(3); t2.add(4);
        ArrayList<Integer> t3 = new ArrayList<Integer>();
        t3.add(6); t3.add(5); t3.add(7);
        ArrayList<Integer> t4 = new ArrayList<Integer>();
        t4.add(4); t4.add(1); t4.add(8); t4.add(3);

        ArrayList<ArrayList<Integer>> t = new ArrayList<ArrayList<Integer>>();
        t.add(t1); t.add(t2); t.add(t3); t.add(t4);

        Triangle m = new Triangle();
        System.out.println(
            m.minimumTotal(t)
            );
    }

    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (triangle==null || triangle.size()==0) {
            return 0;
        }

        int n = triangle.size();

        if (n==1) {
            return triangle.get(0).get(0);
        }
        Integer[] sum = triangle.get(n-1).toArray(new Integer[0]);
        Integer[] sumCopy = triangle.get(n-1).toArray(new Integer[0]);

        for (int i=n-2; i>=0; --i) {

            for (int j=0; j<triangle.get(i).size(); ++j) {
                int min = sum[j] < sum[j+1] ? sum[j] : sum[j+1];
                sumCopy[j] = triangle.get(i).get(j) + min;
            }
            System.arraycopy( sumCopy, 0, sum, 0, triangle.get(i).size() );

        }

        return sum[0];
    }
}