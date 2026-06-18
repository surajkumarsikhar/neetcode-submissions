/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==nullptr) return false;
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;
        if(head->next == head) return true;
        else if (head->next == nullptr) return false;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
        fastPointer = fastPointer->next;
        while(slowPointer != nullptr){
            if(slowPointer == fastPointer){
                return true;
            }
            slowPointer = slowPointer->next;
            if(fastPointer == nullptr || fastPointer->next == nullptr){
                return false;
            }
            fastPointer = fastPointer->next;
            fastPointer = fastPointer->next;
        }
        return false;
    }
};
