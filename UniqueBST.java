// Recursion -> Iteration
public class UniqueBST {

    public static void main(String args[]){
        UniqueBST m = new UniqueBST();
        System.out.println(
            m.uniquePathsWithObstacles(obstacleGrid)
            );
    }
    public int numTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function

        if(n==0) {
            return 1;
        }
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }


        int[] array = new int[n+1];
        array[0] = 1;
        array[1] = 1;
        array[2] = 2;

        for (int i = 3; i < n+1; ++i) {
            for (int j = 0; j < i/2.0; j++) { // 2.0 is so important or i/2 is a int.
                array[i] += array[j] * array[i-1-j] * 2;
            }
            if (i%2!=0) {
                array[i] -= array[i/2] * array[i/2];
            }
        }

        return array[n];
    }

}