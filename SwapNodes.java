/** 防止出现环
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class SwapNodes {
    public static void main(String args[]){
        SwapNodes m = new SwapNodes();
        ListNode head = new ListNode(1);
        ListNode h2 = new ListNode(2);
        //ListNode h3 = new ListNode(3);
        head.next = h2;
        //h2.next = h3;
        System.out.println(
            m.swapPairs(head)
            );
    }
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (head == null) {
            return null;
        }
        ListNode op = head;
        ListNode pre = null;
        boolean first = true;
        while(op.next!=null) {
            //System.out.println(op.next.val);
            if (first) {
                head = swap(op, pre);
                first = false;
            } else {
                swap(op, pre);
            }

            pre = op;
            op = op.next;
            if(op == null) {
                break;
            }
        }
        return head;
    }
    public ListNode swap(ListNode op, ListNode pre) {
        ListNode opN = op.next;
        if (pre != null) {
            pre.next = opN;
        }
        if (opN.next != null) {
            ListNode opN2 = opN.next;
            op.next = opN2;
        } else {
            op.next = null;
        }
        opN.next = op;
        return opN;
    }
}