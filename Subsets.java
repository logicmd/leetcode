// 组合数
import java.util.ArrayList;
import java.util.Arrays;

public class Subsets {

    public static void main(String args[]){
        Subsets m = new Subsets();
        int[] S = {1,2,3};

        ArrayList<ArrayList<Integer>> r = m.subsets(S);
        for ( ArrayList<Integer> minor : r) {
            for ( int i : minor) {
                System.out.print(i + ", ");
            }
            System.out.println();
        }
    }
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Arrays.sort(S);
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        int depth = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        dfs(0, list, 0, S, ret);
        return ret;
    }

    public void dfs(int depth, ArrayList<Integer> list, int start, int[] s,
        ArrayList<ArrayList<Integer>> ret) {
        ret.add(list);
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