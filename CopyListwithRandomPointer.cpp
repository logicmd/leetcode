/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head)
            return NULL;
        RandomListNode *newhead = new RandomListNode(head->label);
        RandomListNode *run = newhead;
        unordered_map<int, RandomListNode*> hash_map;
        hash_map.insert(make_pair(newhead->label, newhead));
        if(head->random) {
            RandomListNode *random;
            if(hash_map.find(head->random->label)==hash_map.end()) {
                random = new RandomListNode(head->random->label);
                hash_map.insert(make_pair(random->label, random));
            } else {
                random = hash_map[head->random->label];
            }
            newhead->random = random;
        }

        while(head->next) {
            RandomListNode *node = new RandomListNode(head->next->label);
            if(head->next->random) {
                RandomListNode *random;
                if(hash_map.find(head->next->random->label)==hash_map.end()) {
                    random = new RandomListNode(head->next->random->label);
                    hash_map.insert(make_pair(random->label, random));
                } else {
                    random = hash_map[head->next->random->label];
                }
                node->random = random;
            }

            run->next = node;
            run = run->next;
            head = head->next;
        }
        return newhead;
    }
};