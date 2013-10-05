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
        unordered_map<int, UndirectedGraphNode*> hash_map;
        queue<UndirectedGraphNode *> q;
        queue<UndirectedGraphNode *> qq;
        for(int i=0; i<node->neighbors.size(); i++) {
            UndirectedGraphNode *neighbor;
            if(hash_map.find(node->neighbors[i]->label)==hash_map.end()) {
                neighbor = new UndirectedGraphNode(node->neighbors[i]->label);
                hash_map.insert(make_pair(neighbor->label,neighbor));
            } else {
                neighbor = hash_map[node->neighbors[i]->label];

            }
            q.push(neighbor);
            qq.push(node->neighbors[i]);
            run->neighbors.push_back(neighbor);
        }

        while(!q.empty()) {
            UndirectedGraphNode *cur=qq.front();
            qq.pop();

            run=q.front();
            q.pop();

            for(int i=0; i<cur->neighbors.size(); i++) {
                UndirectedGraphNode *neighbor;
                if(hash_map.find(cur->neighbors[i]->label)==hash_map.end()) {
                    neighbor = new UndirectedGraphNode(cur->neighbors[i]->label);
                    hash_map.insert(make_pair(neighbor->label,neighbor));
                } else {
                    neighbor = hash_map[cur->neighbors[i]->label];

                }
                q.push(neighbor);
                qq.push(cur->neighbors[i]);
                run->neighbors.push_back(neighbor);
            }
        }

        return newnode;
    }
};