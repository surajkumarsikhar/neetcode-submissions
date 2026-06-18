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
        map<Node*,Node*> mp;
        Node *prev = new Node(-1);
        Node *dummy = prev;
        Node *headCopy = head;
        while(head!=NULL){
            Node *x = new Node(head->val);
            prev->next = x;
            mp[head] = x;
            prev = x;
            head = head->next;
        }
        Node *copyHead = dummy->next;
        while(headCopy != NULL){
            if(headCopy->random == NULL) copyHead->random = NULL;
            else{
                copyHead->random = mp[headCopy->random];
            }
            copyHead = copyHead->next;
            headCopy = headCopy->next;
        }
        return dummy->next;
    }
};
