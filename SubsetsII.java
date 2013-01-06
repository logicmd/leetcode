import java.util.ArrayList;
import java.util.Arrays;

public class SubsetsII {

    public static void main(String args[]){
        SubsetsII m = new SubsetsII();
        int[] S = {1,2,3};

        ArrayList<ArrayList<Integer>> r = m.subsetsWithDup(S);
        for ( ArrayList<Integer> minor : r) {
            for ( int i : minor) {
                System.out.print(i + ", ");
            }
            System.out.println();
        }
    }
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Arrays.sort(num);
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        int depth = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        dfs(0, list, 0, num, ret);
        return ret;
    }

    public void dfs(int depth, ArrayList<Integer> list, int start, int[] s,
        ArrayList<ArrayList<Integer>> ret) {
        if(!ret.contains(list)) {
            ret.add(list);
        }
        if (depth == s.length) {
            return;
        }
        for (int i = start; i<s.length; ++i) {
            ArrayList<Integer> expandList = new ArrayList<Integer>(list);
            expandList.add(s[i]);
            dfs(depth, expandList, i+1, s, ret);
        }
    }
}