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
        bool f = false;
        bool c = false;
        while(run->next) {
            
            
                if(!f&&head->val == run->next->val) {
                    head = run->next;
                    run = run->next;
                    continue;
                } else {
                    f=true;
                }
                if(f) {
                    if(run->val == run->next->val) {
                        run = run->next;
                        continue;
                    }
                    if(dummy->val == run->val) {
                        dummy = run->next;
                        if(!c && head->val != dummy->val) {
                            head->next = dummy;
                            c=true;
                        }
                    } else {
                        dummy->next = run->next;
                        dummy = run->next;
                    }
    
                    run = run->next;
                }
                
            }

        
        if(run) {
            if(head->val==run->val) {
                head=NULL;
            }
            else if(dummy->val==head->val) {
                head->next = NULL;
            }
            if(dummy->val == run->val) {
                dummy = NULL;
            } else {
                dummy->next = NULL;    
            }
            
        }
        return head;
    }
};
