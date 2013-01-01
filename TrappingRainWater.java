public class TrappingRainWater {

    public static void main(String args[]){
        TrappingRainWater m = new TrappingRainWater();
        int[] A = {0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.println(
            m.trap(A)
            );
    }
    public int trap(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int drop = 0;
        int pos = 0;
        while(pos < A.length) {
            while (A[pos]==0) {
                pos++;
            }
            for (int i = pos; i < A.length; ++i) {
                if (A[i]==0 && i < A.length-1 && A[i+1]!=0) {
                    drop++;
                } else {
                    A[i]--;
                }
            }
        }
    }
}