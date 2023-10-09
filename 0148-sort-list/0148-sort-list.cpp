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

    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(left!=NULL && right != NULL){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        while(left!=NULL){
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }

        while(right != NULL){
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //middle element is at slow pointer
        //divide the list into two sub-lists
        //head to mid
        //mid+1 to high

        ListNode *left = head;
        ListNode *right = slow;
        ListNode *temp = right->next;
        right->next = NULL;
        right = temp;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
        
    }
};