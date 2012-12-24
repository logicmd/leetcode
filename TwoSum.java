public class TwoSum {

    public static void main(String args[]){
        TwoSum m = new TwoSum();
        System.out.println(
            "Hello world"
            );
    }
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        for (int i=0; i<numbers.length-1; ++i) {
            for (int j=i+1; j<numbers.length; ++j) {
                if(numbers[i]+numbers[j]==target) {
                    int[] r = new int[2];
                    r[0] = i + 1;
                    r[1] = j + 1;
                    return r;
                }
            }

        }
        return null;
    }

}