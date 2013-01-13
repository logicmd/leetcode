/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
import java.util.Queue;
import java.util.LinkedList;
public class PopulatingNextRightPointers {
    public static void main(String[] args) {
        PopulatingNextRightPointers p = new PopulatingNextRightPointers();
        // System.out.println(p.uponEnd(3));
        // System.out.println(p.uponEnd(7));
        // System.out.println(p.uponEnd(12));
        TreeLinkNode r = new TreeLinkNode(0);
        p.connect(r);
    }
    public void connect(TreeLinkNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Queue<TreeLinkNode> q = new LinkedList<TreeLinkNode>();
        q.offer(root);
        int i = 0;
        TreeLinkNode last = null;
        boolean end = false;
        while(q.size() != 0) {
            TreeLinkNode tail = q.poll();
            if (tail != null) {
                i++;
            }
            System.out.println(i);
            if (uponEnd(i)) {

            }
            if (last != null) {
                last.next = tail;
            }
            last = tail;

            if (tail != null) {
               if (tail.left != null) {
                   q.offer(tail.left);
                }
                if (tail.right != null) {
                    q.offer(tail.right);
                }
            }

        }
    }

    boolean uponEnd(int k) {
        if (k == 0) {
            return false;
        }
        int i = 0;
        int k_ = k;
        while(k_ > 0) {
            k_ >>= 1;
            i++;
        }
        //System.out.println(i);
        int m = 1;
        for ( ; i > 0; i--) {
            m <<= 1;
        }
        //System.out.println(m);
        return k == m-1;
    }

}