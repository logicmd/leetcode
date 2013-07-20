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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        ListNode *little_head = head;
        ListNode *little_run = head;
        ListNode* big_head = new ListNode(-1);
        ListNode *big_run = big_head;
        while(!cur) {
            if (cur->val < x) {
                little_run = cur;
                little_run = little_run -> next;
            } else {
                big_run -> next = cur;
                big_run = big_run -> next;
            }
            cur = cur -> next;
        }
        little_run -> next = big_head -> next;
        return little_run;
    }
};