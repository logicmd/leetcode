// AC
public class Sqrt_x {

    public static void main(String args[]){
        Sqrt_x s = new Sqrt_x();
        System.out.println(s.sqrt(2147395599));
    }
    public int sqrt(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        //System.out.println("=" + x);
        int est = estimate(x);
        long ret = (long)est; // ret * ret may bigger than Integer.MAX_VALUE

        while (ret * ret != x) {
            if (ret * ret > x) {
                ret -= est;
            }
            //System.out.println("==" + ret * ret);
            est >>= 1;
            if(est <= 0) {
                break;
            }
            ret += est;
        }
        return (int)ret;
    }

    // get number of digits
    // sqrt is the floor of the half of its digits.
    public int estimate(int x) {
        int n = 0;
        int ret = 1;
        while(x > 0) {
            x >>= 1;
            n++;
        }
        int m = n/2;
        while(m-->0) {
            ret <<= 1;
        }
        //System.out.println(ret);
        return ret;
    }


}