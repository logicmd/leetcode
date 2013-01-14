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
public class PopulatingNextRightPointersII {
    public static void main(String[] args) {
        PopulatingNextRightPointersII p = new PopulatingNextRightPointersII();
        TreeLinkNode r = new TreeLinkNode(1);
        r.left = new TreeLinkNode(2);
        p.connect(null);
    }
    public void connect(TreeLinkNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Queue<TreeLinkNode> q = new LinkedList<TreeLinkNode>();
        Queue<Integer> level = new LinkedList<Integer>();
        q.offer(root);
        level.offer(1);
        TreeLinkNode last = null;
        int levelLast = 1;
        boolean end = true;
        while(q.size() != 0) {
            TreeLinkNode tail = q.poll();
            int tailLevel = level.poll();

            //System.out.println(i);
            if (!end) {
                last.next = tail;
            }
            if (levelLast!=tailLevel) {
                end = true;
                tail.next = null;
            } else {
                end = false;
            }

            last = tail;
            levelLast = tailLevel;

            if (tail != null) {
                if (tail.left != null) {
                    q.offer(tail.left);
                    level.offer(tailLevel+1);
                }
                if (tail.right != null) {
                    q.offer(tail.right);
                    level.offer(tailLevel+1);
                }
            }

        }
    }



}