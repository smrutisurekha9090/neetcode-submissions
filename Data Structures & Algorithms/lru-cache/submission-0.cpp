class LRUCache {
public:
    class Node{
    public:
        int key,val;
        Node *next,*prev;
        Node(int k,int v){
            key =k;
            val =v;
            next=prev=NULL;
        }
    };
    int limit;
    unordered_map<int,Node*>mp;
    Node* head =new Node(-1,-1);
    Node* tail =new Node(-1,-1);
    LRUCache(int capacity) {
        limit =capacity;
        head->next =tail;
        tail->prev =head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next =newNode;
        temp->prev= newNode;
    }
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* ansNode = mp[key];
        deleteNode(ansNode);
        addNode(ansNode);
        return ansNode->val;
    }
    
    void put(int key, int value) {
        // if key is exist 
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
        }
        //capacity reach
        if(mp.size()== limit){
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }
        //newNode insert
        Node* newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
