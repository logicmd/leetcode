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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = head;
        ListNode *run = head;
        while(run->next) {
            if(run->val == run->next->val) {
                run = run->next;
            } else {
                if(head->val == run->val)
                    head = run->next;

                if(dummy->val == run->val) {
                    dummy = run->next;
                } else {
                    dummy->next = run->next;
                    dummy = run->next;
                }

                run = run->next;
            }

        }
        if(run) {
            dummy->next = NULL;
        }
        return head;
    }
};