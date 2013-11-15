#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <unordered_map>


using namespace std;


struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache{
public:
    int count;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> hashmap;
    LRUCache(int capacity) {
        count=0;
        size=capacity;
        head = new Node(-1, -1);
        tail = new Node(-10, -10);
        head->next=tail;
        tail->prev=head;
        unordered_map<int, Node*>().swap(hashmap);
    }

    void move_to_tail(Node *cur, bool insert) {
        if(cur->next!=tail) {
            if(!insert) {
                cur->prev->next=cur->next;
                cur->next->prev=cur->prev;
            }


            Node* beforetail=tail->prev;
            beforetail->next=cur;
            tail->prev=cur;
            cur->prev=beforetail;
            cur->next=tail;
        }
        return;
    }


    int get(int key) {
        if(hashmap.find(key)==hashmap.end())
            return -1;
        Node* cur=hashmap[key];
        move_to_tail(cur, false);
        return cur->value;
    }

    void set(int key, int value) {
        if(hashmap.find(key)!=hashmap.end()) {
            Node* cur=hashmap[key];
            cur->value=value;
            move_to_tail(cur, false);
        } else {
            Node* cur = new Node(key, value);
            move_to_tail(cur, true);
            hashmap.emplace(key, cur);
            count++;
            if(count>size){
                Node *bedeleted = head->next;
                head->next=bedeleted->next;
                bedeleted->next->prev=head;
                int key = bedeleted->key;
                hashmap.erase(hashmap.find(key));
                delete bedeleted;

            }
        }
    }
};
int main()
{
    LRUCache *c = new LRUCache(1);
    c->set(2,1);
    cout << c->get(2) << endl;
    c->set(3,2);
    cout << c->get(2) << endl;
    cout << c->get(3) << endl;
    system("PAUSE");
    return 0;
}