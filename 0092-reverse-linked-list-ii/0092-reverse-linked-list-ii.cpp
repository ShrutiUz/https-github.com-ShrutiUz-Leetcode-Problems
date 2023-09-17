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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *curr = head;
        for(int i=1; i<left; i++){
            prev = curr;
            curr = curr->next;
        }

        ListNode *temp = curr, *prev2 = NULL;
        for(int i=left; i<=right; i++){
            ListNode *next = curr->next;
            curr->next = prev2;
            prev2 = curr;
            curr = next;
        }

        prev->next = prev2;
        temp->next = curr;

        return dummy->next;
    }
};