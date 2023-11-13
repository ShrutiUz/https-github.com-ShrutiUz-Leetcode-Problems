/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        // the given node could be the first node
        // or any node but not the last one

        //we can change the value of the given node to the value of the next node
        // and we can delete the next node from the list by making appropriate connections

        //node -> del -> next
        //'del' cannot be NULL
        //'next' can be NULL

        ListNode* del = node->next;
        ListNode* nxt = NULL;

        if(del->next!=NULL){
            nxt = del->next;
        }

        node->val = del->val;
        node->next = nxt;

        delete del;
        return;
    }
};