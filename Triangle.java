import java.util.ArrayList;
public class Triangle {

    public static void main(String args[]){

        ArrayList<ArrayList<Integer>> t = new ArrayList<ArrayList<Integer>>();
        int[] a = {2};
        t.add(new ArrayList<Integer>(a));
        int[] aa = {3,4};
        t.add(new ArrayList<Integer>(aa));
        int[] aaa = {6,5,7};
        t.add(new ArrayList<Integer>(aaa));
        int[] aaaaa = {4,1,8,3};
        t.add(new ArrayList<Integer>(aaaa));

        Triangle m = new Triangle();
        System.out.println(
            m.minimumTotal(t)
            );
    }
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = triangle.size();
        int[] sum = triangle[n-1].toArray();
        for (int i=n-2; i>=0; --i) {
            int[] sumCopy = (int[])sum.clone();
            for (int j=0; j<triangle[i].size(); ++j) {
                sum[j] = triangle[i][j] +
                    min(sumCopy[i+1][j], sumCopy[i+1][j+1]);
            }
        }

        return sum[0];
    }
}