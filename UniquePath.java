// 数学题，m-1个0和n-1个1，共可以组成多少个数，nC(m+n) = mC(m+n)
// 直接算C会溢出，直接算阶乘也会溢出，long也会溢出，big decimal应该不会
// 但是没有必要，所以开始把m, n弄有序，再算。
public class UniquePath {

    public static void main(String args[]){
        UniquePath m = new UniquePath();
        System.out.println(
            m.uniquePaths(2,100)
            );
    }
    public int uniquePaths(int m, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (m < n) {
            int temp = m;
            m = n;
            n = temp;
        }
        if (m<1 || n<1) {
            return 0;
        }
        if (m==1 || n==1) {
            return 1;
        }
        return (int) (factorial(m-1, m+n-2) / factorial(n-1));
    }

    public long factorial(int x) {
        long r = 1;
        while(x>0) {
            r*=x;
            x--;
        }
        return r;
    }

    public long factorial(int x, int y) {
        long r = 1;
        while(y>x) {
            r*=y;
            y--;
        }
        return r;
    }

}