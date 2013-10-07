/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!node)
            return NULL;
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *run = newnode;
        unordered_map<int, UndirectedGraphNode*> hashmap;
        queue<UndirectedGraphNode *> qq;

        qq.push(node); // IMPORTANT!
        hashmap.insert(make_pair(newnode->label, newnode)); // IMPORTANT!

        while(!qq.empty()) {
            UndirectedGraphNode *cur=qq.front();
            qq.pop();

            run=hashmap[cur->label];

            for(int i=0; i<cur->neighbors.size(); i++) {
                UndirectedGraphNode *m_neighbor;
                if(hashmap.find(cur->neighbors[i]->label)==hashmap.end()) {
                    m_neighbor = new UndirectedGraphNode(cur->neighbors[i]->label);
                    hashmap.insert(make_pair(m_neighbor->label, m_neighbor));
                    qq.push(cur->neighbors[i]); // IMPORTANT!
                } else {
                    m_neighbor = hashmap[cur->neighbors[i]->label];
                }

                run->neighbors.push_back(m_neighbor);
            }
        }

        return newnode;
    }
};