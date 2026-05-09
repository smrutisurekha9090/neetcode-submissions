/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        //step 1 create the copyNode
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next  = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        //step 2 connect the random pointer
        temp =head;
        while(temp != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        //step 3 back to original list
        Node* dummyNode = new Node(-1);
        temp =head;
        Node* res = dummyNode;
        while(temp != NULL){
            res->next = temp->next;
            res = res->next;
            temp->next =temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;

    }
};
