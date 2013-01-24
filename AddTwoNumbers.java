// Issue
/**
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
public class AddTwoNumbers {
    public static void main(String[] args) {
        AddTwoNumbers p = new AddTwoNumbers();
        ListNode l1 = new ListNode(9);
        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(9);
        ListNode l = p.addTwoNumbers(l1, l2);
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i1 = 0;
        int c = 0;
        while(l1!=null) {
            int c_ = c;
            int val = l1.val;
            while(c_>0) {
                val *= 10;
                c_--;
            }
            i1 += val;
            l1 = l1.next;
            c++;
        }
        //System.out.println(i1);
        int i2 = 0;
        c = 0;
        while(l2!=null) {
            int c_ = c;
            int val = l2.val;
            while(c_>0) {
                val *= 10;
                c_--;
            }
            i2 += val;
            l2 = l2.next;
            c++;
        }
        //System.out.println(i2);

        int i = i1 + i2;
        ListNode l = new ListNode(0);
        ListNode head = l;
        while(i>0) {

            l.val = i % 10;
            i /= 10;
            if (i>0) {
                l.next = new ListNode(0);
                l = l.next;
            }

        }

        ListNode h = head;
        while(h!=null) {
            System.out.print(h.val);
            if (h.next!=null) {
                System.out.print(", ");
            }
            h = h.next;
        }
        System.out.println();

        return head;

    }
}