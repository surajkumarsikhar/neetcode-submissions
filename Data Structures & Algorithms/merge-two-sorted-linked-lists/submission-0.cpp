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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head ;
        if(curr1 == nullptr && curr2 == nullptr) return curr1;
        else if (curr1 == nullptr) return curr2;
        else if (curr2 == nullptr) return curr1;
        if(curr1->val >= curr2->val){
            head = curr2;
            curr2 = curr2->next;
        } else {
            head = curr1;
            curr1 = curr1->next;
        }
        ListNode* tail = head;
        while(curr1!=nullptr && curr2!=nullptr){
            int val1 = curr1->val;
            int val2 = curr2->val;
            if(val1 >= val2){
                tail->next = curr2;
                curr2 = curr2->next;
            } else {
                tail->next = curr1;
                curr1 = curr1->next;
            }
            tail = tail->next;
        }
        tail->next = curr1 == nullptr ? curr2 : curr1; 
        return head;
    }
};
