/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = new ListNode(-1);
        ListNode *run = head;

        while(l1 && l2) {
            if(l1->val<l2->val) {
                run->next=new ListNode(l1->val);
                l1=l1->next;
            } else {
                run->next=new ListNode(l2->val);
                l2=l2->next;
            }
            run=run->next;
        }

        if(l1) {
            run->next=l1;
        }
        if(l2) {
            run->next=l2;
        }

        return head->next;
    }
};