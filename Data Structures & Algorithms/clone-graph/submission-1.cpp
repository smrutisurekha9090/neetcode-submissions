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
    unordered_map<Node*,Node*>mp;
    Node* dfs(Node* node){

        //already cloned
        if(mp.find(node)!= mp.end()){
            return mp[node];
        }

        //create a clone
        Node* clone = new Node(node->val);

        mp[node] = clone;

        // clone neighbours
        for(auto neigh:node->neighbors){
            clone->neighbors.push_back(dfs(neigh));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL ) return NULL ;
        return dfs(node);
    }
};
