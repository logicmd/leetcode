// Index是排序后的。。
// 时间在OJ里面看起来没区别，甚至更长。。。
import java.util.Arrays;
public class TwoSumEnchanced {

    public static void main(String args[]){
        TwoSumEnchanced m = new TwoSumEnchanced();
        int[] numbers = {2,1,9,4,4,56,90,3};
        System.out.println(
            m.twoSum(numbers, 8).toString()
            );
    }
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] copy = Arrays.copyOf(numbers, numbers.length);

        Arrays.sort(numbers);

        // for (int i=0; i<numbers.length; ++i) {
        //     System.out.println(numbers[i]);
        // }

        int p = Arrays.binarySearch(numbers, target/2);
        //System.out.println(p);
        int s, e;
        if(p<0) {
            e = -p-1;
            s = e-1;
        } else {
            e = p+1;
            s = p;
        }
        //System.out.println(s+" "+e);

        while(s >= 0 && e < numbers.length) {
            if(numbers[s] + numbers[e] == target) {
                int[] r = new int[2];
                for (int i=0; i<numbers.length; ++i) {
                    if (copy[i]==numbers[s]&&r[0]==0) {
                        r[0] = i+1;
                        continue;
                    }
                    if (copy[i]==numbers[e]&&r[1]==0) {
                        r[1] = i+1;
                        continue;
                    }
                    if (r[1]!=0&&r[0]!=0) {
                        break;
                    }
                }
                Arrays.sort(r);
                return r;
            }
            if(numbers[s] + numbers[e] < target) {
                e++;
                continue;
            }
            if(numbers[s] + numbers[e] > target) {
                s--;
                continue;
            }
        }

        return null;
    }

}