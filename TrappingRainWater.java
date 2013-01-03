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
                if(pos==A.length) {
                    break;
                }
            }
            for (int i = pos; i < A.length; ) {
                if (A[i]==0 && i < A.length - 1) {
                    int rain = 0;
                    int back = -1;
                    for (int j = i+1; j < A.length; ++j) {
                        if (A[j]!=0) {
                            back = j;
                            break;
                        } else {
                            rain++;
                        }
                    }
                    if (back!=-1) {
                        drop+=rain;
                        A[back]--;
                        i=back+1;
                    }

                } else if (A[i]!=0) {
                    A[i]--;
                    i++;
                } else {
                    i++;
                    //break;
                }
                System.out.println(i);
            }
            System.out.println(pos + " " + drop);
        }
        return drop;
    }
}