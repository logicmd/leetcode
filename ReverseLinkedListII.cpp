//http://zhedahht.blog.163.com/blog/static/2541117420073471124487/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* rhead = NULL;

        ListNode * dummy = NULL;
        dummy->next = head;

        int mm = m;
        while(mm--) {
            dummy = dummy->next;
        }

        ListNode *node = dummy->next;
        ListNode *pre = NULL;
        int nn = n - m;
        while(nn--) {
            ListNode *nxt = node->next;
            if(nxt == NULL)
                rhead = node;


        }
    }
};