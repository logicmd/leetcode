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
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head;
        ListNode *run;

        head->next = run;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                run->val=l1->val;
                ListNode* newrun = new ListNode();
                run->next = newrun;
                run=run->next;
                l1=l1->next;
            } else {
                run->val=l2->val;
                run->next = new *ListNode();
                run=run->next;
                l2=l2->next;
            }
        }

        while(l1) {
            run->val=l1->val;
            run->next = new *ListNode();
            run=run->next;
            l1=l1->next;
        }

        while(l2) {
            run->val=l2->val;
            run->next = new *ListNode();
            run=run->next;
            l2=l2->next;
        }
    }
};