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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;
        while(carry!=0 || l1!=NULL || l2!=NULL){
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ListNode* node = new ListNode(carry%10);
            tail->next = node;
            tail = tail->next;

            carry = carry/10;
            if(l1!=NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }

        return dummy->next;
    }
};