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
    void reorderList(ListNode* head) {
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        while(fastPtr != nullptr && fastPtr->next !=nullptr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = slowPtr->next;
        slowPtr->next = nullptr;
        while(curr != nullptr){
            ListNode *x = curr->next;
            curr->next = prev;
            prev = curr;
            curr = x;
        }
        while(prev!=nullptr){
            ListNode *x = head->next;
            ListNode *y = prev->next;
            head->next = prev;
            prev->next = x;
            prev = y;
            head = x;
        }
    }
};
