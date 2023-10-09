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
    bool hasCycle(ListNode *head) {
        //create a temp node
        //as we traverse the list, connect each node to this temp node
        //and if we find the node->next to be connected to temp already, then return true
        //else return false

        if(head == NULL){
            return false;
        }

        ListNode *temp = new ListNode(-1);

        while(head != NULL){
            if(head->next == NULL){
                return false;
            }

            if(head->next == temp){
                return true;
            }

            ListNode* next = head->next;
            head->next = temp;

            head = next;
        
        }

        return false;
    }
};