/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> q;

        Node* first = new Node(node->val);
        cloneMap[node] = first;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* neighbour : curr->neighbors){
                if(cloneMap.find(neighbour) == cloneMap.end()){
                    cloneMap[neighbour] = new Node(neighbour->val);
                    q.push(neighbour);
                }
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbour]);
            }
        }
        return first;
    }
};