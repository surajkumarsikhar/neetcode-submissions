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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;

        while(l1 != nullptr || l2 != nullptr){
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            int sum = l1Val + l2Val + carry;
            cout<<sum<<endl;
            int onesPlace = sum%10;
            carry = sum/10;
            tail->next = new ListNode(onesPlace);
            tail = tail->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if(carry != 0){
            tail->next = new ListNode(carry);
        }
        return head->next;
    }
};
