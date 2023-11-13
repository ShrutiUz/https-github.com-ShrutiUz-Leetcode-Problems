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
    ListNode* middleNode(ListNode* head) {
        //odd number of nodes -> one node in the middle
        //even number of nodes -> two nodes, return the second one

        ListNode* slow = head;
        ListNode* fast = head;

        //odd -> fast->next becomes NULL
        //even-> fast->next->next becomes NULL

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast->next==NULL){
            return slow;
        }

        return slow->next;
    }
};