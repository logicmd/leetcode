public class SortColors {

    public static void main(String args[]){

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
        c[1]+=c[0];
        c[2]+=c[1];
        for (int i=0; i<A.length; ++i) {

        }
    }

}