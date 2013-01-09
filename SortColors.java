// bitmap  or radix sort
import java.util.Arrays;
public class SortColors {

    public static void main(String args[]){
        SortColors sc = new SortColors();
        int[] a = {1,2,2,2,2,0,0,0,1,1};
        sc.sortColors(a);
    }
    public void sortColors(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] c = new int[3];
        for (int a : A) {
            for (int i=0; i<3; ++i) {
                if (a==i) {
                    c[i]++;
                    break;
                }
            }
        }
        System.out.println(Arrays.toString(c));
        c[1]+=c[0];
        c[2]+=c[1];
        for (int i=0; i<A.length; ++i) {
            for (int k=0; k<3; ++k) {
                if (i<c[k]) {
                    A[i]=k;
                    break;
                }
            }
        }
        System.out.println(Arrays.toString(A));
    }

}