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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr && n==1) return nullptr;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fastPtr = dummy;
        ListNode *slowPtr = dummy;
        for(int i = 0 ; i <=n ; i++){
            fastPtr = fastPtr->next;
        }
        while(fastPtr != nullptr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        slowPtr->next = slowPtr->next->next;
        return dummy->next;
    }
};
